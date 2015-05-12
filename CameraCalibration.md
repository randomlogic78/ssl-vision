# Field Configuration and Camera Calibration #

## Coordinate System ##

To be written...

## Calibration Procedure ##

In order to obtain information about the action on the field from
the camera images, a camera calibration routine has to be performed.
The following step-by-step instructions will guide you through the calibration process:

  1. **Set Corner Points** Activate the Camera Calibration tab on the right side of the user interface. Now you are able to drag the four points constraining a half field to the location in the image plane. The four points are called _Left Corner, Right Corner, Left Centerline, Right Centerline_ and have to be placed as someone would look from the field's center to the goal.
  1. **Adjust the height** Adjust the camera height according to your setup. Due to nature of this calibration problem, the algorithm does not know, if the depth in the image is caused by the focal length or the distance between the camera and the object of interest. Therefore, a manual measurement of the camera height from the field has to be made and has to adjusted in the Camera Calibration tab.
  1. **Perfrom initial calibration**  Press the button "Do initial calibration" in the Camera Calibration Tab to perform an initial calibration based on the image position of the four points of the half-field. After the initial calibration finished, you should see a field and a grid  drawn from red lines in the image, which only matches the real field very roughly.
  1. **Adjust distortion**  The initial setup using the four points does not take distortion into account. Therefore, manually adjust the distortion using the slider in the Camera Calibration Tab (values between  0 and 1 worked for us) and, again, press "Do initial calibration". After that, the red field lines and the grid should reflect the distortion.
  1. **Incorporate additional feature points** As you can see, using just these four points does not lead to a very accurate calibration. Based on these calibration results, additional feature points of the field can be extracted and incorporated in the optimization of the calibration routine. Depending on whether or not your field has markings for the center circle and defense areas, you can opt to sample points from their markings. Under Calibration Parameters, you can choose the number of points to sample from each line and arc. From the Field Half Configuration sub-tree, you can disable center circle and defense area sampling if so desired. Adjust the Line Search Corridor slider in the Camera Calibration Tab to your needs. Then, click "Detect additional calibration points"  and small red boxes should appear along the lines indicating the additional feature points. To perform the optimization using these additional points, press "Do full calibration" and the camera geometry should be calibrated.
  1. **Reset** By pressing "Reset", default values will be assigned to the camera geometry parameters.

![http://ssl-vision.googlecode.com/svn/wiki/calibration-result.png](http://ssl-vision.googlecode.com/svn/wiki/calibration-result.png)

The calibration routine can be tested using the sample image from the
"test-data" directory. Unfortunately, this image shows a 2008 SSL-field,
therefore, the projected red lines will not exactly match the actual
field lines, but it should be sufficient to get the idea how the routine
is performed.

## Data-Tree Parameters ##
You will finde the calibratin parameters as well as several other values related to the calibration process in the Data-Tree under "Camera X->Camera Calibrator" where X stands for the camera number.

To be written...

## Technical background ##
Here are a couple of words for the technically interested reader. The camera calibration is based on a least-squares optimization using the four outer points of a half-field and points along the four lines between these four points to optimize the focal length, the principal point, the lens distortion, and the cameras 3D-pose relative to the field parameterized as a quaternion and a three-dimensional vector. Since the coordinates on the half-field of the four points are known, they provide an absolute relationship between the actual points on the field and their projection in the image plane. Of course, four point do not provide a very robust set of parameters. Therefore additional points on the lines of the field, which are not absolutely known, are integrated. The fact that these points lie on the line segment between two known points is exploited, so that for each point on a line segment its relative position is estimated.

A more detailed explanation of the mathematical terms will be given in near future.