# Requirements and Installation #


## Operating System ##
SSL-Vision is a Linux application. We do not plan to support any other operating system in the future. The current reference distribution is Ubuntu / Kubuntu 8.10 (Intrepid Ibex). The application will probably run on any other up to date Linux distribution without problems. For the reference distribution, we made sure that all software dependencies are part of the distribution and have a compatible version, thus no downloads from additional sources will be needed.


## Software Requirements ##
The following tools and libraries are required to get and compile SSL-Vision:
  * subversion
  * g++
  * QT >= 4.3 with opengl and networking support
  * cmake
  * Eigen2
  * Google protocol buffers (protoc)
  * OpenGL
  * GLU
  * libdc1394 Version >= 2.0
  * libjpeg
  * libpng
To get all these packages in (Ku,U)buntu, run:
```
sudo apt-get install subversion g++ libqt4-dev libeigen2-dev protobuf-compiler libprotobuf-dev libdc1394-22 libdc1394-22-dev cmake libjpeg-dev libpng12-dev
```


## Hardware Requirements ##
SSL-Vision has been developed and tested on x86-compatible computers. Any more or less up to date machine should run the application smoothly. Since the application is multi-threaded, having multiple CPU cores is an advantage.

The system currently supports 1394B / FireWire 800 as well as 1394A / FireWire 400. The support of Video4Linux and Gigabit Ethernet cameras is intended for the future (see [list of open issues](TODO.md)).

In theory, all FireWire cameras should work with SSL-Vision. Here is a list of all cameras we actually use for testing and thus _know_ how they perform:
| **Camera** | **Resolution** | **Frame rate** | **Image encoding** |
|:-----------|:---------------|:---------------|:-------------------|
| _AVT Stingray F046C_ `*` | 780x580 | 60Hz | YUV422 |
| _AVT Marlin F046C_ | 780x580 | 36Hz | YUV422 |
| _AVT Guppy F036C_ | 780x480 | 59Hz | Raw8 |

`*` _recommended model_

We recommend using a PCIx dual-OHCI FireWire 800 card like the following:
http://www.alliedvisiontec.com/us/products/accessories/firewire-accessories/view/pci-express-dual-ohci-4-ports-1394b.html


## Getting and Compiling SSL-Vision ##
There are currently no official releases (neither binary nor source) of SSL-Vision but you can check out the most recent version from the [Subversion repository on Google Code](http://code.google.com/p/ssl-vision/source/checkout).

After having checked out the code, the code can be built by executing:
```
make
```
The project **should** build without errors or warnings.

## Starting the Applications ##

Depending on the configuration of your OS, you might need to ensure that you have full access to the FireWire devices `/dev/fw*`. This _might_ require logging in as root.

To run the application as non-root user in Ubuntu-based distributions, you should add your non-root user to the "disk" and "video" groups, and then logout/login to reflect these changes.

After a successful compilation process, the `./bin` directory will contain three binaries:

  * **vision** - The SSL-Vision application
  * **client** - A simple sample client
  * **graphicalClient** - A graphical sample client

You can start these applications without any further preparations. The usage of these applications is described in further sections: [Usage of  SSL-Vision](ApplicationOverview.md); [Usage of clients](Communication.md).