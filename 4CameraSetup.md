# Introduction #

The 4cam\_experimental branch uses a different setup for specifying field markings, and for calibrating the cameras.

# Field Markings #
The field markings are specified as two lists, one of named line segments, and one of named circular arcs. To add / remove markings, change the number under the "Number of Line Segments" or "Number of Arcs" text entry. To reset the field markings to their defaults, click on the "Reset" button.

![https://ssl-vision.googlecode.com/svn/wiki/images/4cam_field_markings.png](https://ssl-vision.googlecode.com/svn/wiki/images/4cam_field_markings.png)


The default 4-camera field markings are as prescribed by the double-size field description in the rules book of RoboCup 2014:
http://robocupssl.cpe.ku.ac.th/_media/rules:ssl-rules-2014.pdf

![https://raw.githubusercontent.com/joydeep-b/ssl-rules/master/img/double-size-field.png](https://raw.githubusercontent.com/joydeep-b/ssl-rules/master/img/double-size-field.png)

# Camera Calibration #

## Reset Field Markings ##
First, click on "Reset SSL 2014" to reset the field markings.

## Initial Calibration ##
The initial calibration of the cameras is performed by specifying control points in the image and their corresponding coordinates in the world. The default control points in the 4cam\_experimental branch are the corners of each quadrant of the field, but the locations of the control point j for camera i may be changed to any other location from the setting "Camera i / Camera Calibrator / Calibration Parameters / Control point j", as shown in the screenshot below. To move the control points around in the image, make sure that the "Calibration" option under visualizations is checked, and that the camera calibration tab on the right is active.

![https://ssl-vision.googlecode.com/svn/wiki/images/4cam_control_points.png](https://ssl-vision.googlecode.com/svn/wiki/images/4cam_control_points.png)

## Complete Step-by-Step Calibration ##
  1. Enable the camera visualization and check the "camera calibration" and "calibration result" options.
  1. Select the camera calibration tab on the right, and click on "Reset".
![https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step1.png](https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step1.png)
  1. Drag the control points to the locations in the image that correspond to the specified world locations. In the screenshot below, the control points include the center of the field and the intersection of the defense arc and the goal line.
  1. Click on "Do Initial Calibration".
![https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step2.png](https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step2.png)
  1. Drag the camera height and camera distortion markers till the calibration result roughly approximates the actual field lines. Click on "Do Initial Calibration" again to update the initial calibration guess. Repeat to refine if required.
![https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step3.png](https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step3.png)
  1. Under the visualizations, turn on "Detected edges" and drag the "Line Search Corridor Width" slider on the calibration tab to increase the search corridors till they include the field markings. Click on "Detect additional points".
![https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step4.png](https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step4.png)
  1. The detected edges will be displayed. Now click on "Do full calibration" to calibrate using all detected points.
  1. If necessary, repeat the last 2 steps with a smaller corridor width to refine the calibration result. The final result should match will with the image, as shown below.
![https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step5.png](https://ssl-vision.googlecode.com/svn/wiki/images/calibration_step5.png)