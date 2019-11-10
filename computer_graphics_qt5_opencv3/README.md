# ComputerVisionQT5andOpenCV3
Computer vision with QT5 and OpenCV 3



# How to build openCV
1) download cmake-gui from https://cmake.org/download/
2) copy archive "sources" from http://opencv.org/releases.html and unpack
3) sudp apt-get install libgtk2.0-dev and pkg-config
4) run cmake gui(choose folder with sources and sources/build), choose unix make
5) run configure
6) set BUILD_opencv_world and run configure again
7) run generate
8) cd sources/build
9) sudo make
10) sudo make install


# How to link openCV in QT

1) Bad way: create opencv.pri
INCLUDEPATH += /usr/local/include 
 LIBS += -L/usr/local/lib \ 
    -lopencv_world 
and include pri file in qt project    
    
2) Good way: add this in your pro file
   unix: !macx { 
      CONFIG += link_pkgconfig 
      PKGCONFIG += opencv 
   } 
