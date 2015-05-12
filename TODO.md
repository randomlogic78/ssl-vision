# TODO #
This page is a TODO list of new features and improvements for ssl-vision. If you would like to suggest other wishes/features or are interested in working on an unassigned issue, please let us know by becoming a member of the email-list http://groups.google.com/group/ssl-vision.

## Bugs ##
For bugs and other problems, please use the "Issue" tracker: http://code.google.com/p/ssl-vision/issues/list

## Currently Open Tasks ##

### TCP-server ###
Relying on UDP has some risks of interference by other teams. An
optional TCP server mode would be nice.

### UDP port selection from within GUI ###
Allowing to select the UDP server port from within SSL-Vision would be
extremely beneficial, especially if 1) will not be used.

### Packet information ###
One item that we might want to add  to the vision packet is what framerate it is capturing at. I know teams can measure this themselves, but it might be helpful to provide this data in the packet.

### Definition of ball-detection results ###
We need to define how many balls (the "Max Ball Count" parameter) the
system will return when used during RoboCup 2010. Some teams like to
receive more than just the biggest blob, and then perform filtering
themselves. Maybe 10 is a good value?

### Performance review ###
Some people have reported instances of high CPU usage. We need to
determine whether this originates in the image processing stack or the
GUI components. One idea is to use SSE instructions to speed up the color thresholding task.

### LUT cloning / synching ###
We still need a feature where we can copy the state from one LUT to
the other one, for either a single color, or all colors.

### Global team height override ###
If we use SSL-Vision with a single pattern at RoboCup 2010, then we
will need the ability to quickly enter the robot height for a team
into the system. Right now the heights are obtained from the pattern
template image, but there also is a "team height" value that is
currently only used if no heights are found in the pattern. It would
be nice to have a checkbox that ensures this global team height is
always used if checked.

### Competition-Mode Plugin ###
A plugin that ensures that all parameters are reasonable for max
performance (e.g. visualizations off, etc..) to be used during
competition.

### Fast GL-based Graphical Client ###
The graphical client uses excessive amounts of CPU. I think we should
switch to a GL-based rendering method that runs at a constant
framerate. It could then also be integrated as a plugin into
SSL-Vision.

### Masking Plugin ###
A plugin that allows masking out certain areas in the field. I believe some teams (Plasma-Z?) have already implemented this?

### Improving Camera Calibration ###
Consider center circle and goal area for camera calibration to provide
more precise results.

### Referee Box ###
Delete the old "Referee Box" and write a new Application based on Qt and
Google Protocol Buffers. This application should be part of the
SSL-Vision repository and might offer a plug-in mode for SSL-Vision.

### Support additional capture methods ###
(e.g., video4linux)