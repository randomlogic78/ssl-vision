# Classes Involved #

There are several classes involved in camera calibration:
  1. **PluginCameraCalibration** (src/app/plugins/plugin\_cameracalib.h) inherits from VisionPlugin, and is one of the plugins on the ssl-vision processing stack. Its purpose is to perform the edge detection on the image when the "detect\_edges" indicator bool in CameraCalibrationWidget is true (set when the "Detect Edges" button is pressed), store the correspondences between the detected edge points and the field markings into CameraParameters::calibrationsegments, and then reset CameraCalibrationWidget::detect\_edges.
  1. **PluginVisualize** (src/app/plugins/plugin\_visualize.h) inherits from VisionPlugin, and is one of the plugins on the ssl-vision processing stack. Its purpose is to overlay the camera image with visualization primitives, including (among other things) the detected edge points, the expected field markings on the image (based on the latest camera calibration parameters), and the control point handles.
  1. **CameraCalibrationWidget** (src/app/gui/cameracalibwidget.h) is the GUI widget shown on the "Camera Calibration" tab of camera view pane.
  1. **CameraParameters** (src/shared/util/camera\_calibration.h) maintains the camera intrinsics and extinsics as pointers to the VarXML tree, provides functions to convert between image and field coordinates, and the actual calibration procedure. It includes as sub-classes:
    1. AdditionalCalibrationInformation, which maintains the control points for initial camera calibration, and other parameters for edge detection and calibration, again maintained as pointers to nodes in the VarXML tree.
    1. CalibrationData, which contains the detected edge points and their corresponding world field markings.

# Flow of Control #

The flow of control involved in geometry calibration is as follows:

  1. The control points are initialized interactively by dragging their markers in the **CameraCalibrationWidget** .
  1. Subsequent steps assume that the camera height, radial distortion, and other parameters have been initialized.
  1. For the initial calibration, **CameraParameters::calibrate** is called with cal\_type = INITIAL\_ESTIMATION. This estimates the camera parameters using only 4 constraints, corresponding to the control points.
  1. The user then visually inspects the results and accordingly sets the edge detection margins.
  1. When the "Detect Edges" button is clicked, the images are searched for edges in the vicinity of the field markings in **PluginCameraCalibration::detectEdges**.


# Initial Calibration #

In the main trunk (2-cam setup), there are currently four control points per camera, which are hard-coded to mean the corners of the field halves. They are contained in the VarXML tree **CameraParameters::AdditionalCalibrationInformation**, and are called:
  1. left\_corner\_image(_x,_y)
  1. right\_corner\_image(_x,_y)
  1. left\_centerline\_image(_x,_y)
  1. left\_centerline\_image(_x,_y)

These control points can be manually dragged around for initial calibration. The mouse interaction is implemented by calling **mousePressEvent**, **mouseMoveEvent**, and **mouseReleaseEvent** of **PluginCameraCalibration**. Note that the SSL=-Vision stack passes the mouse events to all existing plugins, and it is up to the individual plugins to decide when to hand these events or ignore them. The PluginCameraCalibration plugin is hard-coded to accept these events only if the CameraCalibrationWidget is the currently visible tab widget (see PluginCameraCalibration::mousePressEvent).

When a mouse press event occurs, the PluginCameraCalibration::mousePressEvent event handler selects the appropriate node (drag\_x, drag\_y) from the VarXML tree corresponding to the control point in question by selects the closest control point within a threshold of the mouse pointer.

When the mouse is dragged around, the drag\_x, drag\_y node values are updated accordingly.

When the "Do Initial Calibration" button in CameraCalibrationWidget is pressed, the 4 control points are used to perform calibration by calling **CameraParameters::do\_calibration** with cal\_type = FOUR\_POINT\_INITIAL .