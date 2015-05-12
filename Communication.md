# Communication and Sample Client #

All communication from the SSL-Vision system to the clients is performed via UDP Multicast on port 10002 and multicast address 224.5.23.2.

Robot and Ball detection results are broadcast immediately when detection completes. Note, that individual cameras run on separate threads, and as such there is **no guarantee about the order of packages originating from different camera processing stacks**.

Note, that the SSL-Vision system does not perform any sensor-merging, thus it will deliver detection results from both cameras independently. It is up to the teams to merge robots and balls which happen to overlap between the two cameras' observations. Similarly, SSL-Vision does not perform any tracking or smoothing of objects. This is left to the teams as it will allow them to integrate their own predicted executions into their respective tracking components.

# Packet Format Definition #

All data-packets are encoded using [Google Protocol Buffers](http://code.google.com/p/protobuf/).

The protobuf packet definitions are defined in the `src/shared/proto/` directory of ssl-vision. Each packet sent through the network is encoded in the wrapper packet, as defined in `messages_robocup_ssl_wrapper.proto`.

## Detection Data ##
The packet defined in `messages_robocup_ssl_detection.proto` contains the complete detection results of one camera's frame, including robots and balls.

## Geometry Data ##
The packet defined in `messages_robocup_ssl_geometry.proto` contains geometry information, namely field dimensions and camera calibration information. This data is currently only sent through the network if the `Publish!` button in the `Publish Geometry` branch is pushed.

# Example client code #
SSL-Vision contains a simple example client in the `src/client` directory. Run it by launching `./bin/client` in ssl-vision's main directory.

# Graphical client #
For a more effective visualization of data, ssl-vision also contains a graphical client. Run it by launching `./bin/graphicalCient` in ssl-vision's main directory.

# Compilation of Google Protocol Buffer Definitions #
Note, that SSL-Vision's make-system will automatically compile the protocol buffer packet definitions into C++ files by invoking `protoc`. The resulting code is located in `src/shared/proto/cpp`.