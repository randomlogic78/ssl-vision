## Color Thresholding ##
The first step of SSL-Vision's image processing pipeline is the conversion of the colored video input to a color-thresholded version.

To perform this conversion, SSL-Vision requires that the user defines a mapping from the continuous YUV color-space (http://en.wikipedia.org/wiki/YUV) into the discrete RoboCup color-labels. This mapping is defined in a 3D-Lookup-Table (LUT) which is visualized in the "YUV Calibration"-tab on the right side of the GUI.
To visualize the 3D LUT in the 2D interface, the color-cube is essentially "sliced" among the 'Y'-component axis into multiple images, each representing the 'U' and 'V' components of that particular slice. To scroll through the multiple slices, it is possible to use the mouse wheel, or the 'a' and 'z' keys on the keyboard.

To edit the mapping in the LUT, you simply have to select a desired RoboCup color label on the right, (e.g. "Pink" or "Field Green", ...) and then draw directly into the LUT by holding your left mouse button. To speed up the mapping of entire regions, simply draw an outline with the left mouse-button and then flood-fill that particular area with the right mouse-button. The LUT features "Undo/Redo" buttons in case you make a mistake during editing. To erase a mapping, either select the `<`Clear`>` color on the right, or - as a shortcut - simply hold the "Shift"-key while drawing. To draw with a 9-pixel wide stroke, use the "Ctrl" modifier.

To actually get an idea of where to define LUT color mappings, you should collect color-samples from the video input stream. To do so, make sure visualizations are enabled by setting both `enable` and `image` to `true` in the `Camera i/Visualization` branch of the data-tree. You should now see the live video stream in the GUI. To collect color samples, simply left click onto the pixel which you would like to sample in the video window. Note, that it is possible to zoom (mousewheel) and pan (right mouse-button) the image (use "space" to reset to normal view). Color samples will be marked by an "x" in the YUV LUT display. Alternatively to sampling individual pixels, you can also sample all pixels in the image by selecting the video widget and pressing "i", effectively providing you with a YUV histogram. To clear the color sampler, press "c" or use the "Clear Sampler" button above the YUV LUT.

To check the thresholding results of your LUT, you might want to enable the thresholded visualization of the video stream by checking "thresholded" in the data-tree's visualization options.

The LUT data is automatically saved when the application is quit normally by clicking the close button (not by pressing Ctrl-C in the console!).

## Blob Detection ##

The next step in the image processing pipeline is "Blob Finding" which will identify connected components of the thresholded image and compute their bounding boxes and centroids. The only parameter for this process is the "min\_blob\_area" value in the data-tree (under `Camera i/Blob Finding`) which acts as a global filter, discarding any blobs with fewer pixels than "min\_blob\_area". To view the blob-finding results in real-time, enable "blobs" in the `Camera i/Visualization` branch.

Once your color-segmentation and blob-finding has been correctly defined, you can move on to configure the modules which make use of this information, namely the [Team Detector](TeamConfiguration.md) and the [Ball Detector](BallConfiguration.md).