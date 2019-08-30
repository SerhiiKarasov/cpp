#  Chapter 1. Introduction to OpenCV and Qt
##  Introduction to OpenCV

### Main modules
* core (e.g. Mat)
* imgproc
* features2d
* video
* others

### Extra modules
* text
* OCR(Optical Character Recognition)
* others

## For installing OpenCV download 
1. download cmake-gui from https://cmake.org/download/
2. copy archive "sources" from http://opencv.org/releases.html and unpack
3. sudp apt-get install libgtk2.0-dev and pkg-config
4. run cmake gui(choose folder with sources and sources/build), choose unix make
5. run configure
6. set BUILD_opencv_world and run configure again
7. run generate
8. cd sources/build
9. sudo make
10. sudo make install



## Introduction to Qt
[qt documentation on modules](http://doc.qt.io/qt-5/qtmodules.html)

### Qt Essentials modules(supported on all platforms)
* Qt Core
* Qt Gui(including OpenGl)
* Qt Multimedia(audio, video, radio, camera)
* Qt Multimedia Widgets
* Qt Network
* Qt Qml(including Javascript)
* Qt Quick
* Qt Quick Controls
* Qt Quick Layouts
* Qt SQL
* Qt Widgets
* Qt Test

### Qt Add-Ons modules(may be unsupported on some platforms) 
* Qt 3D
* Qt Print Support
* Qt WebEngine
* Qt Bluetooth
* others

### Value-Add Modules(offered under commercial license) 

### Technology Preview Modules (not guaranteed to work)

## For installing QT download and run [qt-opensource-linux-x64-X.X.X.run](https://download.qt.io/official_releases/)

# Chapter 2. Creating Our First Qt and OpenCV Project
1. New Project
2. Application
3. Qt widgets application
4. dynamically link opencv in pro file
```
      CONFIG += link_pkgconfig 
      PKGCONFIG += opencv 
``` 
and include module in pro file: 
```
    QT += widgets 
```
5. Use layouts(horizontal or vertical) to set elements properly
6. You may use MVC pattern to communicate data to views using ListView, TreeView, TableView, ColumnView
7. Add QWidget, QPushButton etc in Design tab
8. Go to Designer, right click on QPushButton -> Go to slot -> pressed() (private slot was created in mainwindow header and source)
9. Go to mainwindow.cpp and implement inputPushButton_pressed(), to access the widgets or other elements on the user interface, just use the ui
10. Go to mainwindow source and header and add :
```
    protected: 
      void closeEvent(QCloseEvent *event); 
```
11. Implement 
```
    void loadSettings(); 
```
in mainwindow constructor
```
   void saveSettings(); 
```
in closeEvent()

12. include opencv:
```
    #include "opencv2/opencv.hpp"  
```

