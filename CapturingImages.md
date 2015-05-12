# Capturing Images #

## Capture Control ##
Capturing is controlled by the "Start Capture" and "Stop Capture" buttons in the `Camera i/Image Capture/Capture Control` branch. "Capture Module" selects which capture method to use. "Reset Bus" is depending on the capture method. For DC1394-based cameras it will trigger a full bus reset, which is only recommended if the bus was frozen accidentally. "Auto refresh params" and "Re-Read Params" are explained further below in the "Camera Parameters" section

**To start immediate capture with ssl-vision, without clicking the "Start Capture" buttons for each camera, simply run the program with the `-s` flag, e.g. `./bin/vision -s`.**

## Using DC1394 Capture (Firewire / DCAM) ##

### Capture Settings ###
Capture parameters are located in the branch `Image Capture/DC1394/Capture Settings`. Here, you can select the desired framerate, resolution, and capture mode. Note that internally, SSL-Vision operates in YUV-space. As such, **we strongly recommend setting "capture mode" to "yuv422\_uyvy"**.

Capturing supports both DCAM native modes and Format7 modes which can be selected in the "capture format" field. Leaving it on "auto" will attempt native mode first, then format7\_0. By default, ISO800 support is disabled. To enable it, mark the field "use ISO800" as true.

### Conversion Settings ###
These settings configure the conversions from the camera's delivered images to SSL-Vision's internal format, used for further processing. **Currently, "convert to mode" should always be set to "yuv422\_uyvy".**

If you desire, you can do de-bayering in software, but this will take extra CPU cycles. To do so, you would set the DC1394 capture mode to e.g. "raw8" and the convert mode to "yuv422\_uyvy". Finally, you will need to set "de-bayer" to true, and select the correct
de-bayer pattern and desired method.

### Camera Parameters ###
Once you start capturing, you should be able to expand the "Camera Parameters" item by double-clicking on it, and it should show all of the camera's available DCAM parameters.

You can adjust all of these parameters in real-time.

Note that the read-out of these parameters from the camera only happens automatically if "auto refresh params" in the Capture Control is set to true. Otherwise, you can use the "re-read params" "Refresh" button to refresh them manually. For performance reasons, it might make sense to set auto refresh to false, so the bus is not being flooded with too much control data and has full bandwidth available for the video streaming.

## Reading Images from Files ##
If you want to test the application on a computer which does not have any camera connected, you can select the capture mode "Read from files" in the "Capture Control" menu.

Before starting to capture, a directory containing the images needs to be configured. This is done by setting the "directory" parameter in the "Read from files" submenu. The directory needs to be specified relative to the directory from which the application is executed.

All images (being in BMP, JPG, or PNG format) in that directory are read into memory and will be looped. The current repository version already includes one test image (of a half of a 2008 SSL field) in the `test-data` directory.

## Recording Images to Files ##
Recording images is useful for (among other things) debugging ssl-vision configurations on a different computer than the one connected to the cameras, and for color calibration of moving objects (e.g. calibrating the orange color of a moving ball).

To record images, you need to first set up camera capture for your cameras (See the "Capture Control" section above). Next, click on the "DVR" tab on the camera control pane (on the right hand edge of the SSL-Vision window) for the camera that you wish to record from. Click on the "DVR recorder mode" button (it looks like a [clapperboard](https://www.google.com/search?q=clapperboard&hl=en&tbo=d&tbm=isch)) to enable the recording controls.

Use the controls under "Record and Playback" to record a sequence of images. Note that if the maximum number of images is exceeded, the oldest frames will be dropped, and new frames added. Once you're satisfied with a recording, you can save the recording using the save button under the "Manage Recordings" section.