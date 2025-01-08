# iShapes Demonstrator 
[TOC]

# What is it? 
iShapes is an interactive GUI based Zenoh (Zero Network Overhead) Application to learn, demonstate and test Zenoh key concepts.

It shows and demonstrates the key Zenoh concepts.
It has also been used at the Eclipse Foundation to test the interoperability of the Zettascale products (zenoh & cyclone dds).

Each geometrical shape is represented by a dedicated key expression


The shape dataType is characterized by its color, its position in a 2D space and its Size. 
Shapes with different colors are considered different data objects, i,e different data instances, as the color data attribute is considered the @Key of the dataType. Each data instance has its unique identity, its own lifecycle and its state.


# Building iShapes

ishapes can be rely on Zenoh C++ API, 

For the Zenoh Ishape demo, the Zenoh C core, Zenoh C++ binding for Zenoh need to be installed before proceeding.   
You can get Zenog C Core from https://github.com/eclipse-zenoh/zenoh-c, and the related C++ APIs from hhttps://github.com/eclipse-zenoh/zenoh-cpp

zenoh-ishapes utilizes the Cyclone DDS CDR library for serialization and deserialization. Ensure that Eclipse Cyclone DDS is installed: https://github.com/eclipse-cyclonedds/cyclonedds , https://github.com/eclipse-cyclonedds/cyclonedds-cxx


To clone the ishape demo application in your locale repository, do  

      $ git clone https://github.com/ZettaScaleLabs/zenoh-ishapes   
      $ cd zenoh-ishapes   


## Building Zenoh iShapes

From now one, we assume Zenoh and QT6 are installed

### Building on Linux/MacOS with cmake
To build the iShapes demo you need to have installed a QT6 development environment. The following QT6 environment variables has to be set in order to build and run ishapes:
      
      $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<qt6_install-location>
      
       Where <qt6_install-location> is the installation directory of your QT6 installation , e.g (/usr/lib/x86_64_linux-gnu/qt6)  

then you need to simply do the following from the iShape demo root directory:

      $ mkdir zenoh_demo_ishapes && cd zenoh_demo_ishapes  
      $ cmake .. -DCYCLONE_INSTALLED_DIR="<cxx_install-location>"  
      $ cmake --build . --config Release  
      
     <cxx_install-location> is, again, the location of Cyclone DDS C++ package 
     Note: please use '--config Debug' if you are using zenoh debug build to build this iShape application.

### Building on Windows with cmake
To build the demo you need to have installed a QT6 development environment. The following QT6 environment variables has to be set in order to build and run ishapes:

      C:\> set QTDIR=<QT6-INSTALLATION-DIR> 
      C:\> set QT_PLUGIN_PATH=<QT6-INSTALLATION-DIR>\plugins  
      C:\> set PATH=<QT6-INSTALLATION-DIR>\bin;%PATH%   
      
      Where <QT6-INSTALLATION-DIR> is the installation directory of your QT6 installation , e.g (<C:\Qt\6.2.4> )  

then you need to simply do the following from the iShape demo root directory:

      $ mkdir zenoh_demo_ishapes && cd zenoh_demo_ishapes  
      $ cmake .. -DCYCLONE_INSTALLED_DIR="<cxx_install-location>"  -G "<generator-name>"  
      $ cmake --build . --config Release  
      
 Where ``<cxx_install-location>`` is the location of the Cyclone DDS C++ package and ``<generator-name>`` by one of the ways CMake [generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)
offer for generating build files. For  example, "Visual Studio 15 2017 Win64" would target a 64-bit build using Visual Studio 2017.

Note: please use '--config Debug' if you are using zenoh debug build to build this iShape application.
      

# Running iShapes

The iShapes demo allows you to publish and subscribe instances of various shapes. The demo is didactic if you run it as at least into two application instances, thus from a shell do one of the below then have one of the applications publish some shapes and press the subscribe button on the other application to receive them.

image-20201022104103958

## Running Zenoh iShapes
### Linux/MacOS:
To run it  you  need to simply do the following:

      $ <build_directory>/zenoh_demo_ishapes &  
      $ <build_directory>/zenoh_demo_ishapes &  

### Windows: 
      
      C:\> start <build_directory>/zenoh_demo_ishapes  
      C:\> start <build_directory>/zenoh_demo_ishapes  
      
Note: You can pass endpoints to connect to, endpoints to listen to, mode, configuration file, no-multicast-scouting as command line arguments as given below:
      
      $ <build_directory>/zenoh_demo_ishapes -h  
	Usage: zenoh_demo_ishapes [OPTIONS]
	Options:
	  -c, --config <CONFIG_FILE>  Configuration file [default: ]
	  -e, --connect <CONNECT>  Endpoints to connect to
	  -l, --listen <LISTEN>  Endpoints to listen to
	  -m, --mode <MODE>  Zenoh session mode (peer | client) [default: peer]
	  --no-multicast-scouting  Disable the multicast-based scouting mechanism
	  -h, --help  Print help
  
