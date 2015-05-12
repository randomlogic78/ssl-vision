There are several filtering parameters used for ball detection which can be found in the data-tree branch `Global/Ball Detection`. The different parameter branches are as follows:

## Ball Properties ##
These parameters act as the first filtering stage for any potential ball-blobs. Most of these should be self-explanatory.

  * **Ball Z-Height** is the height of the ball which is used to down-project the ball's coordinates onto the field surface. As the ball is spherical, a value somewhere between its mid-height and max-height usually works well.

## Gaussian Size Filter ##
If enabled, this filter will adjust the ball's detection confidence based on the following formula: `confidence = gaussian(actual_area_deviation / expected_area_deviation)`

## Near Robot Filter ##
If enabled, this filter will ignore any balls which are seen closer than `Distance` to a detected robot, where the distance is measured between the centroid of the robot's center marker and the centroid of the ball. This filter is effectively used to ignore the mis-detection of balls inside of robots.

## Histogram Filter ##
If enabled, the histogram checker will sample surrounding pixels to the ball and compute their "greenness" as well as their "markeryness".
  * **Markeryness** is indicative as to how many pink and yellow pixels there are in comparison to orange ones. If the computed markeryness exceeds the value defined in the data-tree then the ball-detection is ignored, as it is likely not an actual ball, but rather a blurring between robot markers.
  * **Greenness** is defined as the number of field-colored pixels over the number of orange pixels. If the detected greenness is greater than the value in the data tree, then the ball is accepted as valid by this filter, ignoring the "markeryness" test described above.

### Geometry Filters ###
  * **Ball-In-Field Filter** ignores any balls which are outside of the playable field (note, that "playable field" includes the outer boundary, but NOT the referee walking area)
  * **Ball-In-Goal Filter** ignores any balls which are further than half-way into the goal. This is helpful to ignore false detections caused by the painted insides of the goal.
Note that both of these filters assume a finished [Camera Geometry Calibration](CameraCalibration.md)