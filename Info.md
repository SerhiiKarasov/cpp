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

# Chapter 3. Creating a Comprehensive Qt+OpenCV Project
* qmake a tool to automate Makefiles creation(is make-makefile tool, or makemake for short)
## Pro File
* QT  - modules to include(link)
* Target - name of application
* Template - whether the output of the build process will be an application, a library, or a plugin
* SOURCES - source files
* HEADERS - header files
* FORMS - ui files

## Main.cpp
* include of QApplication - main class for control application's workflow
* Event loop 
```
   QApplication a(argc, argv);     
   return a.exec(); 
 ```
 ## MOC(meta-object compiler)
 * converts QT things(signals, slots, macros) to c++ code
 * requires Q_OBJECT(mainwindow.hpp, private) for generation of QOBject-inherited class.
 
 ## UIC(user interface compliler)
 * converts .ui files to c++ code(e.g.     #include "ui_mainwindow.h" )
 
 
## Design patters
* Abstract Factory - for factory classes that are creating objects and controling creation of new objects
* Command - represent actions as objects
* Composite - create objects that consist of child objects(Qobject and QWidget)
* Facade - encapsulate low-level capabilities of an OS by providing simpler interface(QFile)
* Flyweight(Bridge, Private-Implementation) - don't copy data shared between objects(QString)
* Memento - save and load objects
* MetaObject(Reflection) = metaboject describes the details of the object(QMetaObject)
* Monostate -  attempts to hide the fact that a class is only operating on a single instance of data by using static data members((QSettings)
* MVC (Model-view-controller) - separate data storage mechanism(Model) from UI(view) and data manipulation(controller) (QTreeView and QFileSystemModel)
* Observer (or Publish/Subscribe) - used to make objects that can listen or observe changes in other objects and respond to them(QEvent, signal and slot)
* Serializer - class that can be used to read or write other objects(QTextStream, QDataStream)
* Singleton - only one instance(QApplication)

## Qt Resource System
* .qrc - resource collection file, xml that include info about resource files to be included in application
* file -> new file or project -> qt -> qt resource file -> choose -> name it resources ->  click on resources.qrc -> Add prefix -> images -> add files -> add any jpg -> now use path to this file ":/images/test.jpg"

 ## Styling applications
 * Qt Style Sheets are almost identical in syntax to HTML CSS (Cascading Style Sheets)
 * click in designer on widget -> styleSheet property -> set it :
 ```
     border: 2px solid #222222; 
    border-radius: 10px; 
    background-color: #9999ff; 
    min-width: 80px; 
    min-height: 35px; 
 ```
  ## Multi-language support
  * all literals need to embrace in a tr()
  * need to add TRANSLATIONS in pro
  ```
        TRANSLATIONS = translation_lt.ts translation_la.ts 
  ```
  * run QtLinguist tool from IDE or lupdate from terminal -> translate files -> run lrelease tool  -> add QM files to resources
  
## Creating and using plugins
* create cvplugininterface.hpp with   
```
   #define CVPLUGININTERFACE_IID "com.sk.cvplugininterface" 
   Q_DECLARE_INTERFACE(CvPluginInterface, CVPLUGININTERFACE_IID) 
```
* run new project -> library -> c++ library(Shared Library), copy interface hpp to project 
* in pro file
```
    CONFIG += plugin 
```
* create class that inherits from QObject and CvPluginInterface. And add to this class in header:
```
      Q_OBJECT 
      Q_PLUGIN_METADATA(IID "com.sk.cvplugininterface") 
      Q_INTERFACES(CvPluginInterface) 
```
* create application and use plugin using :
```
QLibrary::isLibrary(filter.absoluteFilePath());
QPluginLoader pluginLoader(filter.absoluteFilePath(), this); 
if(dynamic_cast<CvPluginInterface*>(pluginLoader.instance())) 
{
      //code
      pluginLoader.unload()
}

```
# Chapter 4. Mat and QImage
## All about the Mat class
* Mat class(Matrix) is an n-dimensional array capable of storing and handling different mathematical data types in single or multiple channels. Grayscale image is matrix where each cell represents pixel(0 for balack, 255 for white)
* Example, 10x10 matrix, with each element a single channel 8-bit unsigned integer (or byte):: 
```
    Mat matrix(10, 10, CV_8UC(1)); 
    or 
    Mat matrix(10, 10, CV_8UC(1), Scalar(0); 
```
* 'CV_<bits><type>C(<channels>)' -  Mixed value for type, bit count, number of channesl 
<bits>  - 8, 16, 32, 64
<type>  - U (unsigned), S(signed), F(signed float)
<channels> - it may be 1,2,3,4 etc
* imread - read Mat from file
* region of interest (ROI) - part of Mat object
```
          Mat roi(image, Rect(25,25,50,50)); //doesn't perform deep copy
```
* clone - deep copy of Mat object
* Scalar - template class for a 4-element vector derived from Vec, can be used to pass pixel value
* row - copy one row from Mat object
```
     Mat r = image.row(0); // first row 
```
* column - copy one column from Mat object
* rowRange, columnRange - copy range of columns or rows
```
   Mat centralRows = image.rowRange(image.rows/2 - 10, image.rows/2 + 10); 
```
* locateRoi - method to find your roi on the image(Mat object)
```
    centralRows.locateROI(parentSize, offset); 
```
## Mat properties 
* depth (i.e. type and bit count of Mat) it may be CV_8U, CV_8S, CV_16U, CV_16S, CV_32S, CV_32F, CV_64F
* channels 
* type , e.g. U
* cols - number of columns
* rows - number of rows
* elemSize - size of each element in bytes
* elemSize1 - size of each element in bytes regardless of the channel count
* empty - is empty?
* isContinuous
* isSubmatrix - true if Mat is submatrix of another Mat(roi is submatrix of initial Mat)
* total - amount of elements (width * height)
* step, in standard image that is width
      
##  Useful methods to run on Mat      
* at - access method
* begin, end - retrieve and access elements via iterators
* forEach
* adjustRoi - to change siuze of roi matrix
* clone - deep copy
* convertTo - change the data type of Mat(may be used to scale images)
* copyTo -copy all or part of image to another Mat object
* ptr - pointer to get access to Mat data
* release - clean up Mat object's memory
* reserve - reserve memory for number of rows
* reserveBuffer - reserve memory for number of bytes
* reshape - change number of channels
* resize - change number of rows of Mat object
* setTo - set elements of Mat object to some value
* cross - compute cross product of two three-dimensional matrices
* diag - extract a diagonal of matrix
* dot - compute dot producct of two matrices
* eye - create an identity matrix
* inv - inverse matrix
* mul - compute an element-wise multiplication or division of two matrices
* ones - create a matrix with all elements eq 1
* t - transpose matrix(for image that is rotation)
* zeroes - create a matrix with all elements eq 0

## The Mat_<_Tp> class
* a subclass of the Mat class (and a template class) with identical members, but it can be quite helpful when the type of the matrix (or elements in an image) is known at compile time
```
    Mat_<Vec3b> imageCopy(image); // image is a Mat class 
```
## Matx< _Tp, m, n >
* is used for small matrices for which type, width, height are known at complile time

## UMat class
* will use OpenCL implementation if possible(better to use this class then raw Mat)
* can be converted to Mat and vice verse
```
    Mat::getUMat 
    UMat::getMat 
```
## InputArray, OutputArry, InputOutputArray
* those are proxy types that are introduced for better readability
* they are interchangeable with (Mat, Mat_<T>,Matx<T, m, n>,std::vector<T>,std::vector<std::vector<T> >,std::vector<Mat>,std::vector<Mat_<T> >,UMat,std::vector<UMat>,double)

# Reading images using OpenCV
* example
```
   Mat image = imread("/tmp/test.jpg", IMREAD_GRAYSCALE | IMREAD_IGNORE_ORIENTATION); 
```
* supports (    Windows bitmaps: \*.bmp, \*.dib
    JPEG files: \*.jpeg, \*.jpg, \*.jpe
    JPEG 2000 files: \*.jp2
    Portable Network Graphics: \*.png
    WebP: \*.webp
    Portable image format: \*.pbm, \*.pgm, \*.ppm, \*.pxm, \*.pnm
    Sun rasters: \*.sr, \*.ras
    TIFF files: \*.tiff, \*.tif
    OpenEXR Image files: \*.exr
    Radiance HDR: \*.hdr, \*.pic
    Raster and Vector geospatial data supported by Gdal)
* ImreadModes enum provides list of flags(e.g. IMREAD_IGNORE_ORIENTATION)
* mreadmulti - reads multipage image files(e.g tifs)
* imdecode - read from memory buffer


# Writing images using OpenCV
* example
```
    std::vector<int> params; 
    params.push_back(IMWRITE_JPEG_QUALITY); 
    params.push_back(20); 
    params.push_back(IMWRITE_JPEG_PROGRESSIVE); 
    params.push_back(1); // 1 = true, 0 = false 
    imwrite("c:/dev/output.jpg", image, params);
```
or default parameters
```
    std::vector<int> params; 
    imwrite("c:/dev/output.jpg", image, params); 
```
* imencode - writes to memory buffer

# Reading and writing videos in OpenCV
* class VideoCapture
```
    VideoCapture video; 
    video.open("/tmp/test.avi"); //maybe set of jpegs, url, etc
    while(video.read(frame)) 
    {             
    } 
    video.release();
```
* video properties(Full list in the documentation - VideoCaptureProperties)
```
    double frameCount = video.get(CAP_PROP_FRAME_COUNT); 
    video.set(CAP_PROP_POS_FRAMES, 100);
```
* class VideoWriter - writes video in video file
```
    VideoWriter video; 
    video.open("/tmp/output.avi", CAP_ANY, CV_FOURCC('M','P', 'G','4'), 30.0, Size(640, 480), true); 
    if(video.isOpened()) 
    { 
      while(framesRemain()) 
      { 
        video.write(getFrame()); 
      } 
    } 
    video.release();
```
* [FourCC docs](http://www.fourcc.org/codecs.php)


## The HighGUI module in OpenCV
* imshow - shows image in window

## Image and video handling in Qt
* QImage
```
    QImage image(320, 240, QImage::Format_RGB888); 
```
* QImage::Format may be (QImage::Format_MonoLSB, QImage::Format_Mono, QImage::Format_Indexed8, QImage::Format_ARGB32_Premultiplied, QImage::Format_RGB666 etc)
* how to convert cv::Mat(BGR) to Qt::QImage(RGB)
```
    Mat mat = imread("/tmp/test.jpg"); 
    cvtColor(mat, mat, CV_BGR2RGB); //swaps blue and red channels
    QImage image(mat.data,mat.cols,mat.rows,QImage::Format_RGB888); 
```
or even more correct with ByterPerLine option
```
    Mat mat = imread("/tmp/test.jpg"); 
    cvtColor(mat, mat, CV_BGR2RGB); //swaps blue and red channels
    QImage image(mat.data,mat.cols,mat.rows,mat.step, QImage::Format_RGB888); 
```
* read image from disk
```
      QImage image("/tmp/test.jpg"); 
```
* Qt supports BMP, GIF, JPG, PNG, PBM, PGM, XBM, XPM, PPM. Some of them only read only.
