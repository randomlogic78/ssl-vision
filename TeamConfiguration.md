# Team Configuration and Detection #

## Defining the Team's Pattern Image ##
SSL-Vision's supplied pattern detector should be able to support any arbitrary color-based multi-segment pattern as typically used in the Small Size League. A team's patterns are defined through a .png file in the directory `ssl-vision/patterns`. As an example, the system comes with the CMDragons team pattern which is defined in `ssl-vision/patterns/CMDragons.png`. This team image contains a grid of individual robot covers, and it is parsed in row-major order, with increasing robot IDs, starting at 0. This image will then be automatically parsed, and the pattern detector will use the areas and relative angles of all markers defined in this image for pattern detection. For the image to be parseable, each robot should contain a blue center marker. Furthermore, as shown in the example image, each cover image should be accompanied by a single pixel width yellow vertical bar which indicates the height of the robot with its height in pixels corresponding to the robot's height in mm.

## Creating the Team in the Data-tree ##
Once this pattern image has been defined, it is possible to create a new team-definition through the GUI. To do so, open the branch `Global/Team Config/` in the Data-Tree. Next, click on `Add Team...`. This should create a new entry in the `Global/Team Config/Teams` branch labeled `New Team n`. After opening this team's branch, you can rename the team as desired.

## Using the Pattern Image ##
To make use of the png file, make sure to check "Unique Patterns" and "Have Angles" in the team's config branch. Then open the branch "Marker Image", make sure "Load Marker Image" is checked, and enter the path to the png file as seen from the ssl-vision main directory. For example: `patterns/teams/CMDragons.png`. Next, make sure that the number of robot rows and columns are correct. Finally, uncheck any of the robot IDs which are not being used in your robot definition file, in the "Valid Patterns" field.

## Configuring the Pattern Matcher Parameters ##
To use your new team pattern definition effectively, some parameters might need to be tweaked. Each team definition is able to carry a unique set of parameters as follows:

### Center Marker Settings ###
This defines the parameters of the blob-filter used to detect the Blue or Yellow center markers. Most of these parameters should be self-explanatory, except the following ones:
  * **Uniform, Exp. Area Mean, Exp. Area StdDev.** are all used to compute the confidence of the marker based on its measured deviation from its expected area. The confidence is computed using the following formula: `conf = gaussian(measured_area_deviation, expected_area_std_deviation) / (gaussian(measured_area_std_deviation, expected_area_std_deviation) + Uniform)` where `measured_arae_std_deviation` is the absolute difference between the markers measured area and "Exp. Area Mean".
  * **Duplicate Merge Distance** means the maximum distance where two detected center blobs should be merged into one.

### Other Marker Settings ###
This defines the parameters of the blob-filter for all surrounding markers (i.e. not the center marker). All of these should be self-explanatory.

### Histogram Settings ###
**Note that the Histogram is currently only used for detecting Unknown teams (i.e. teams without a marker image)**

The Histogram checker validates whether the detected blue or yellow center markers (of team's for which the surrounding patterns are unknown) are plausible to belong to an actual robot. It does so by computing a color-histogram of surrounding pixels to the marker which allows to check for the "markeryness", "field-greenness", and "black/whiteness". Markeryness is defined as the ratio of the total number of pink,bright green,and cyan pixels over the number of pixels colored in the color of the corresponding center marker (blue or yellow). Field-Greenness is the ratio of the number of dark green pixels over the number of all pixels in the histogram. Black/Whiteness is the ratio of all black, clear, and white pixels over the number of total pixels in the histogram.

### Pattern Fitting Settings ###
These settings control the evaluation of the actual pattern matching algorithm which uses the pattern definitions as previously defined in the team's .png file.

  * **Max Marker Center Dist** is the maximum distance of any surrounding pattern's centroid from the central team marker's centroid.
  * **Weight Area** is the weight of the "area matching" error component (i.e. how well do the detected areas match the ones in the pattern definition)
  * **Weight Center-Dist** is the weight of the "distance from center marker to surrounding markers" error component
  * **Weight Next-Dist** is the weight of the "distance from one surrounding marker to the next" error component
  * **Max Error** is the maximum allowed total weighted error of the three components described above, to count as a fully confident detection.
  * **Expected StdDev** is the expected deviation on the error
  * **Uniform** is the uniform component against which the error and deviation are compared, similar as described to the formula further above in the "Center Marker Settings" section.

## Selecting Your Team ##
Once you have fully configured your team, you can select it under the `Global/Blue Team` and `Global/Yellow Team` branches.