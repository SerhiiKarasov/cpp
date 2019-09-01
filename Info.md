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
* QImage supports BMP, GIF, JPG, PNG, PBM, PGM, XBM, XPM, PPM. Some of them only read only.
* allGray - method to check if all pixels are shades of gray(all pixels have same rgb values in respective channels)
* bits , constButs - accessing underlying image data, may be used to convert QImage to Mat
```
        QImage image("c:/dev/test.jpg"); 
        image = image.convertToFormat(QImage::Format_RGB888); 
        Mat mat = Mat(image.height(),image.width(),CV_8UC(3),image.bits(),image.bytesPerLine()); 
```
## QImage methods
* byteCount - number of bytes occupied by the image data
* bytesPerLine - (similar to step in Mat)
* convertToFormat - convert to another format(e.g. from rgb to grb)
* copy - copy all or part of image to QImage class
* depth - bits per pixel
* fill - fill all pixels with same color
* format - get current format of QImage
* hasAlphaChannel - does image has transparency channel
* height, width, size
* isNull - true if no image data is present
* load, loadFromData,  fromData - retrieve image from disk or from buffer(similar to imdecode in opencv)
* mirrored - flips image verticalluy
* pixel - similar to at in opencv, access pixel
* pixelColor - returns QColor
* rect - return QRect
* rgbSwapped - swaps blue and red(analog ot cvtColor)
* save - save to file
* scaled, scaledToHeihgt, scaledToWidth - resize image to a given size. May be used options Qt::IgnoreAspectRatio, Qt::KeepAspectRatio, Qt::KeepAspectRatioByExpanding
* setPixel, setPixelColor
* setText - set a text value in the image formats that support it
* text - retrieve text value set to an image
* transformed - transforms image, takes QMatrix ot QTransform class and returns the transformed image. 
```
       QImage image("/tmp/test.jpg"); 
       QTransform trans; 
       trans.rotate(45); 
       image = image.transformed(trans); 
```
* trueMatrix - can be used to retrieve the transformation matrix used for transform
* valid - takes a point(x,y) and returns true if the point is a valid position on the image


## The QPixmap class
* is used when need to show image on the screen, not so flexible about manipulation on the image data, still maybe used in same way as QImage
* convertFromImage, fromImage - fill QPixmap with data from a QImage

## QT application example with QPixmap
* new project -> Qt Widgets Application
* add events in mainwindow.hpp in protected:
```
        void dragEnterEvent(QDragEnterEvent *event); 
        void dropEvent(QDropEvent *event); 
```
* implement void dragEnterEvent() by accessing file that is dragged
```
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile()); 
    if(acceptedFileTypes.contains(file.suffix().toLower())) 
    { 
        event->acceptProposedAction(); 
    }
```
* implement void dropEvent() by accessing file that is dragged
```
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile()); 
    if(pixmap.load(file.absoluteFilePath())) 
    { 
       ui->label->setPixmap(pixmap.scaled(ui->label->size(), 
       Qt::KeepAspectRatio, 
       Qt::SmoothTransformation)); 
    } 
```

## The QPainter class
*  class can be used to draw (and basically paint) on any Qt class that is a subclass of the QPaintDevice class(e.g. QWidget)
### QPainter methods
* draw 
* fillRect
* drawArc
* drawEllipse
* drawImage

### example using QPainter class
* Qt Widgets Application
* new c++ class QBlinkingWidget (base class QWidget)
* add protected method for new class
```
   protected:
      void paintEvent(QPaintEvent *event);
```
and slot
```
   private slots: 
      void onBlink(); 
```
and
```
   private: 
      QTimer blinkTimer; 
      bool blink; 
```
* in widget source file add in constructor
```
      connect(&blinkTimer, SIGNAL(timeout), this, SLOT(onBlink()));
      blinkTimer.start(500);
```
* paintEvent implement
```          
      QPainter painter(this); 
      painter.fillRect(this->rect(), 
      QBrush(Qt::red)); 
```
* onBlink implement
```
          blink = !blink; 
          this->update();
```
* in Design tab add QWidget and right click -> promote to QBlinkingWidget


## Camera and video handling in Qt
* requires       QT += multimedia 
* QCamera: This provides access to cameras available on a platform.
* QCameraInfo: This can be used to get information about the available cameras on a platform.
* QMediaPlayer: This can be used to play video files and other types of recorded media.
* QMediaRecorder: This class is useful when recording videos or other media types.
* QVideoFrame: This class can be used to access individual frames grabbed by the camera.
* QVideoProbe: This can be used to monitor frames from a camera or video source. This class can also be used to process frames further in Qt.
* QVideoWidget: This can be used to display incoming frames from a camera or video source.



# Chapter 5. The Graphics View Framework
* The Scene (QGraphicsScene class). The Scene or QGraphicsScene manages the Items or instances of QGraphicsItem (its subclasses), contains them, and propagates events (such as mouse clicks and so on) into the items.
* The View (QGraphicsView widget). The View or the QGraphicsView widget is used to visualize and display the contents of QGraphicsScene. It's also responsible for propagating events to QGraphicsScene. Different coordinate systems that QGraphicsScene and QGraphicsView have.
* Graphical Items (QGraphicsItem and its subclasses). The Items, or instances of the QGraphicsItem subclasses, are the items contained within QGraphicsScene. They can be lines, rectangles, images, text, and so on.

## example of graphics view gramework usage
* Qt Widgets Application
* add a Graphics View widge
* add in mainwindow
```
    QGraphicsScene scene; 
```
* in mainwindow constructor 
```
    ui->graphicsView->setScene(&scene); 
```
* read somehow pixmap and add it to the scene
```
    scene.addPixmap(pixmap); 
```
* we can delete the item
```
    delete item; 
```
* debug message
```
    qDebug() << scene.items().count(); 
```
## The Scene, QGraphicsScene
### Methods
* addEllipse -> return QGraphicsEllipseItem
* addLine -> returns QGraphicsLineItem
* addRect -> returns QGraphicsRectItem
* addPolygon -> returns QGraphicsPolygonItem
* addPath -> can be used to add QPainterPath to the scene with the given QPen or QBrush, returns QGraphicsPathItem
* addSimpleText, addText - adding text and formatted text into the scene. Returning QGraphicsSimpleTextItem, QGraphicsTextItem.
* addPixmap - returns QGraphicsPixmapItem
* addItem - returns QGraphicsItem
* addWidget - 
```
        QPushButton *button = new QPushButton(Q_NULLPTR); 
        connect(button, SIGNAL(pressed()), this, SLOT(onAction())); 
        button->setText(tr("Do it!")); 
        QGraphicsProxyWidget* proxy = scene.addWidget(button); 
        proxy->setGeometry(QRectF(-200.0, -200, 400, 100.0)); 
```
* setBackgroundBrush, backgroundBrush, setForegroundBrush, and foregroundBrush - allows QBrush to brush background and foreground on the scene
* font and setFont - get and set QFont for the scene
* minimunRenderSize and setMinimumRenderSize - choose the minimum size of object that will be drawn on the sceen
* sceneRect and setSceneRect - specify bounding rectangular on the scene, sceneRect returns the biggest rectangular that can cover all items on the scene
* stickyFocus and setStickyFocus functions can be used to enable or disable the Sticky Focus mode for the scene. If Sticky Focus is enabled, clicking on an empty space in the scene will not have any effect on the focused item
* collidingItems is a function that finds out if an item shares some part of its area (or in other words collides) with any other items. 
* createItemGroup and destroyItemGroup functions can be used to create and remove QGraphicsItemGroup class instances. 
* QGraphicsItemGroup is basically another QGraphicsItem that is used to group items.
* hasFocus, setFocus, focusItem, and setFocusItem functions are all used to deal with the currently focused item in the graphics scene.
* width and height
* invalidate - can be used to request a redraw of the scene wholly or partially
* itemAt - to find a pointer to theQGraphicItem at a certain position in the scene
* item - returns the list of items added to the scene. Basically, QList of QGraphicsItem
* itemsBoundingRect - can be used to get a QRectF class, or simply the smallest rectangle that can contain all of the items on the scene
* mouseGrabberItem - can be used to get the item that is currently clicked on without the mouse button being released.
* removeItem - function can be used to remove an item from the scene
* render - can be used to Render the scene on QPaintDevice
* selectedItems, selectionArea, and setSelectionArea functions - handling one or multiple item selections. 
* sendEvent - function can be used to send QEvent classes to items on the scene
* style and setStyle - functions are used to set and get the styling of the scene.
* update -  function can be used to redraw part or all of the scene
* views - function can be used to get a QList class containing QGraphicsView
* dragEnterEvent, dragLeaveEvent, dragMoveEvent, and dropEvent functions can be overridden to add drag and drop functionality to the scene.
* drawBackground and drawForeground functions should be overridden if we need to add a custom background or foreground to the whole scene
* mouseDoubleClickEvent, mouseMoveEvent, mousePressEvent, mouseReleaseEvent, and wheelEvent functions can be used to take care of different mouse events in the scene
* event can be overridden to process all events received by the scene

## The Items, QGraphicsItem
* QGraphicsEllipseItem
* QGraphicsLineItem
* QGraphicsPathItem
* QGraphicsPixmapItem
* QGraphicsPolygonItem
* QGraphicsRectItem
* QGraphicsSimpleTextItem
* QGraphicsTextItem
* acceptDrops and setAcceptDrops functions can be used to make an item accept drag and drop events
* acceptHoverEvents, setAcceptHoverEvents, acceptTouchEvents, setAcceptTouchEvents, acceptedMouseButtons, and setAcceptedMouseButtons functions all deal with the item interaction and its response to mouse clicks 
* example 
```
QGraphicsRectItem *item = 
           new QGraphicsRectItem(0, 
                                 0, 
                                 100, 
                                 100, 
                                 this); 
        item->setAcceptDrops(true); 
```
* boundingRegion - function can be used to get a QRegion class describing the region of the graphical item. 
* childItems - function can be used to get a QList filled with the QGraphicsItem classes that are children of this item.
* childrenBoundingRect, boundingRect, and sceneBoundingRect functions can be used to retrieve a QRectF class containing the bounding rect of the children of this item, the item itself, and the scene.
* clearFocus, setFocus and hasFocus functions can be used to remove, set, and get the focus status of this item.
* collidesWithItem, collidesWithPath, and collidingItems functions can be used to check if this item is in a collision  with other item
* contains function takes a point location (QPointF class to be precise) and checks if this item contains that point.
* cursor, setCursor, unsetCursor, and hasCursor functions are useful for setting, getting, and unsetting a specific mouse cursor type for this item.
* hide, show, setVisible, isVisible, opacity, setOpacity, and effectiveOpacity functions are all related to the visibility (and opacity) of the item. 
* flags, setFlags, and setFlag functions can be used to get or set the flags for this item(ItemIsFocusable , ItemIsMovable)
* setGraphicsEffect and graphicsEffect - can set or get effects on items(QGraphicsBlurEffect, QGraphicsColorizeEffect, GraphicsDropShadowEffect,QGraphicsOpacityEffect)
* group and setGroup - functions to add an item to a group or get the group class containing the item  to any groups.
* isAncestorOf function can be used to check if this item is a parent
* setParentItem and parentItem and be set and retrieve the parent item of the current item
* isSelected and setSelected functions can be used to change the selected mode of an item
* mapFromItem, mapToItem, mapFromParent, mapToParent, mapFromScene, mapToScene, mapRectFromItem, mapRectToScene, mapRectFromParent, mapRectToParent, mapRectFromScene, and mapRectToScene - functions to convert the coordinates from or to the scene, another item, or the parent. 
* moveBy, pos, setPos, x, setX, y, setY, rotation, setRotation, scale, and setScale functions can be used to get or set different geometric properties of the item
* transform, setTransform, setTransformOriginPoint, and resetTransform functions can be used to apply or retrieve any geometric transformation to the item. 
* scenePos function can be used to get the position of the item in the scene. It's the same as calling mapToScene(0,0)
* data and setData functions can be used to set and retrieve any custom data in and from an item
* zValue and setZValue functions can be used to modify and retrieve the Z value of an item. Z value decides which items should be drawn in front of the items and so on. 
* contextMenuEvent
* dragEnterEvent, dragLeaveEvent, dragMoveEvent, dropEvent
* focusInEvent, focusOutEvent
* hoverEnterEvent, hoverLeaveEvent, hoverMoveEvent
* keyPressEvent, keyReleaseEvent
* mouseDoubleClickEvent, mouseMoveEvent, mousePressEvent, mouseReleaseEvent, wheelEvent

## The View, QGraphicsView
* QGraphicsView class is a Qt Widget class that can be placed on a window to display QGraphicsScene
* alignment and setAlignment functions can be used to set the alignment of the scene in the view.
* dragMode and setDragMode functions can be used to get and set the drag mode of the view. 
* isInteractive and setInteractive functions allow retrieving and modifying the interactive behavior of the view
* optimizationFlags, setOptimizationFlags, renderHints, setRenderHints, viewportUpdateMode, and setViewportUpdateMode functions are used respectively to get and set parameters related to both performance and render quality of the view
* rubberBandSelectionMode and setRubberBandSelectionMode functions can be used to set the item selection mode of the view in case dragMode are set to RubberBandDrag mode. 
* sceneRect and setSceneRect functions are useful for getting and setting the visualized area of the scene in the view
* centerOn function can be used to make sure a specific point or item is in the center of the view
* ensureVisible function can be used to scroll the view to a specific area (with given margins) to make sure it's in the view
* fitInView function, quite similar to centerOn and ensureVisible but with the major difference that this function also scales the contents of the view to fit in the view
* itemAt function can be used to retrieve the item at a specific position in the view.
* mapFromScene and mapToScene functions can be used to convert a position from and to the scene coordinate system
* items functions can be used to get a list of items in the scene.
* render function is useful for performing a render of the whole view or part of it
* rubberBandRect function can be used to get the rubber band selected rectangle.
* setScene and scene functions can be used to set and get a scene for the view
* setMatrix, setTransform, transform, rotate, scale, shear, and translate

# 6.Image Processing in OpenCV
## Border types
*    BORDER_CONSTANT   
*    BORDER_REPLICATE  
*    BORDER_REFLECT    
*    BORDER_WRAP       
*    BORDER_REFLECT_101
*    BORDER_TRANSPARENT
*    BORDER_ISOLATED

# Filtering methods:
* bilateralFilter - depends o sigma value and diameter it is possible to get cartoonish image
* blur - These are all used for getting a smoothed version of the input image. All of these functions use a kernel size parameter, which is basically the same as a diameter parameter, and it's used to decide the diameter of the neighboring pixels from which the filtered pixel will be calculated. (
* boxFilter - same as blur
* sqrBoxFilter- same as blur
* GaussianBlur- requires Gaussian kernel standart deviation(sigma) in X and Y directions
* medianBlur- same as blur
```
        Size kernelSize(5,5); 
        blur(inpMat,outMat,kernelSize); 
        int depth = -1; // output depth same as source 
        Size kernelSizeB(10,10); 
        Point anchorPoint(-1,-1); 
        bool normalized = true; 
        boxFilter(inutMat,outMat,depth, 
           kernelSizeB,anchorPoint, normalized); 
        double sigma = 10; 
        GaussianBlur(inpMat,outMat,kernelSize,sigma,sigma); 
        int apertureSize = 10; 
        medianBlur(inpMat,outMat,apertureSize); 
```
* filter2D - apply custom filter on the image
```
    // Sharpening image 
        Matx33f f2dkernel(0, -1, 0, 
                         -1, 5, -1, 
                          0, -1, 0); 
        int depth = -1; // output depth same as source 
        filter2D(inpMat,outMat,depth,f2dkernel); 
```
* Laplacian, Scharr, Sobel, and spatialGradient: These functions deal with image derivatives. Image derivatives are very important in computer vision since they can be used to detect regions with changes, or, better yet, significant changes (since that's one of the use cases of derivatives) in an image.
```
        int depth = -1; 
        int dx = 1; int dy = 1; 
        int kernelSize = 3; 
        double scale = 5; double delta = 220; 
        Sobel(inpMat, outMat, depth,dx,dy,kernelSize,scale,delta); 
```
* erode and dilate  - for getting an erosion and dilation effect.
* morphologyEx - function can be used to perform various morphological operations. Possible arguments: MORPH_ERODE, MORPH_DILATE, MORPH_OPEN(dilate eroded image - remove small artifacts), MORPH_CLOSE(erode dilated image - remove small disconnections), MORPH_GRADIENT(diff between erroded and dilated), MORPH_TOPHAT(diff between image and its opened morph), MORPH_BLACKHAT(diff between closing image and image itself)

## Image transformation capabilities
* geometric transformation functions need to be provided with a cv::BorderType and cv::InterpolationFlags parameter 

* interpolation methods(cv::InterpolationFlags)
INTER_NEAREST: This is for the nearest neighbor interpolation  
INTER_LINEAR: This is for bilinear interpolation  
INTER_CUBIC: This is for bicubic interpolation  
INTER_AREA: This is for a pixel area relation resampling  
INTER_LANCZOS4: This is for the Lanczos interpolation over a neighborhood of 8x8  

### Geometric transformations
*     resize: This function can be used to resize an image. Here's an example of how it's used:
```
        // Resize to 320x240, with default interpolation mode 
        resize(inMat, outMat, Size(320,240)); 
```
* warpAffine - This function can be used to perform an affine transformation. You need to provide this function with a proper transform matrix, which can be obtained using the getAffineTransform function. The getAffineTransform. Can be used to perform a rotation of the source image
* warpPerspective - This function is useful for performing a perspective transform. transform matrix that can be obtained using the findHomography function. findHomography function can be used to calculate homography changes between two set of points.
* remap: This function is a very powerful geometric transformation function that can be used to perform a remapping of pixels from the source to the output image. 
* remap also may be use to correct lens distortion. Need to get mapping using initUndistortRectifyMap and initWideAngleProjMap

### Colors and color spaces
* cvtColor
* cv::ColorConversionCodes
```
   // Convert BGR to HSV color space 
   cvtColor(inputImage, outputImage, CV_BGR2HSV); 
   // Convert Grayscale to RGBA color space 
   cvtColor(inputImage, outputImage, CV_GRAY2RGBA); 
```
* applyColorMap  - to map colors from the input image to other colors in the output image
```
 applyColorMap(inputImage, outputImage, COLORMAP_JET); 
```

### Image thresholding 
* thresholding  - is image segmentation, which itself is the process of distinguishing between groups of related pixels, either in terms of intensity, color, or any other image properties 
* threshold - function can be used to apply a fixed-level threshold to an image
```
        cvtColor(inputImage, grayScale, CV_BGR2GRAY); 
        threshold(grayScaleIn, 
                 grayScaleOut, 
                 45, 
                 255, 
                 THRESH_BINARY_INV); 
        cvtColor(grayScale, outputImage, CV_GRAY2BGR); 
```
* adaptiveThreshold: This can be used to apply an adaptive threshold to a grayscale image. This function, depending on the adaptive method passed to it (cv::AdaptiveThresholdTypes)

## Drawing in OpenCV
### common parameters of drawing functions
* color: This parameter is simply the color of the object being drawn on the image. It can be created using scalar and needs to be in BGR format (for color images) as it is the default color format for most OpenCV functions.
* thickness: This parameter, which is set to 1 by default, is the thickness of the outlines of the object being drawn on the image. This parameter is specified in terms of pixels.
* lineType: This can be one of the entries in the cv::LineTypes enum, and it decides the detailing of the outlines of the object being drawn
* shift - This parameter is used only in case the points and locations provided to drawing functions include fractional bits. 

### drawing functions
* line
```
        cv::line(img, 
                 Point(0,0), 
                 Point(img.cols-1,img.rows-1), 
                 Scalar(0,0,255), 
                 3, 
                 LINE_AA); 
```
* arrowedLine 
* rectangle
* putText


## Template matching
* matchTemplate - searches image in another image
* cv::TemplateMatchModes  
    TM_SQDIFF  
    TM_SQDIFF_NORMED  
    TM_CCORR  
    TM_CCORR_NORMED  
    TM_CCOEFF  
    TM_CCOEFF_NORMED  
* usage      
```
matchTemplate(img, templ, result, TM_CCORR_NORMED); 
```
* how to show on the image where is a template
```
    double minVal, maxVal; 
    Point minLoc, maxLoc; 
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc); 
    rectangle(img, 
              Rect(maxLoc.x, maxLoc.y, templ.cols, templ.rows), 
              Scalar(255,255,255), 
              2); 
```

# Chapter 7. Features and Descriptors
* features(keypoint) - some descriptive points on image
* descriptor - are handles of features that could extracted from image and used to compare with features/descriptors on another image.
## Algorithm class - is the base class of almost all algos in openCV
```
 class Algorithm 
    { 
      public: 
      Algorithm(); 
      virtual ~Algorithm(); 
      virtual void clear(); 
      virtual void write(FileStorage& fs) const; 
      virtual void read(const FileNode& fn); 
      virtual bool empty() const; 
      template<typename _Tp> static Ptr<_Tp> read(const FileNode& fn); 
      template<typename _Tp> static Ptr<_Tp> load(const String& filename, const String& objname=String()); 
      template<typename _Tp> static Ptr<_Tp> loadFromString(const String& strModel, const String& objname=String()); 
      virtual void save(const String& filename) const; 
      virtual String getDefaultName() const; 
      protected: 
      void writeFormat(FileStorage& fs) const; 
    }; 
```
* FileStorage - read and write to XML, YAML, JSON
* FileNode - represent a single element in FileStorage class.
* read: This has a few overloaded versions that can be used to read the state of an algorithm.
* write: This is similar to read, except it is used to save the state of an algorithm.
* clear: This can be used to clear the state of an algorithm.
* empty: This can be used to determine if an algorithm's state is empty. This means, for example, if it is correctly loaded (read) or not.
* load: This is almost the same as read.
* loadFromString: This is quite similar to load and read, except it reads and loads the state of an algorithm from a string.read: This has a few overloaded versions that can be used to read the state of an algorithm.

## The 2D Features Framework
* Feature2D is a subclass of Algorithm
* Feature2D has 2 subclasses FeatureDetector and DescriptorExtractor
* Feature2D methods  
    The detect function can be used to detect features (or keypoints) from an image or a set of images.  
    The compute function can be used to extract (or compute) descriptors from keypoints.  
    The detectAndCompute function can be used to perform both detect and compute with a single function.  
    descriptorSize, descriptorType, and defaultNorm are algorithm dependent values and they are reimplemented in eachFeature2D subclass that is capable of extracting descriptors.  

### Detecting features
* KeyPoint class - is actually another name for feature
* KeyPoint fields:  
      pt, or simply point: This contains the position of the keypoint (X and Y) in the image.  
      angle: This refers to the clockwise rotation (0 to 360 degrees) of the keypoint, that is, if the algorithm detecting the keypoint is capable of finding it; otherwise, it will be set to -1.  
      response: This is the strength of the keypoint, and it can be used to sort or filter weak keypoints, and so on.  
      size: This refers to a diameter specifying a neighborhood of the keypoint that can be used for further processing.  
      octave: This is the octave level (or pyramid level) of the image, from which this specific keypoint was detected.   
* AgastFeatureDetector - can be used for detection using Adaptive and Generic Accelerated Segment Test algo
```
        Ptr<AgastFeatureDetector> agast = AgastFeatureDetector::create(); 
        vector<KeyPoint> keypoints; 
        agast->detect(inputImage, keypoints); 
 ```
 * drawKeypoints - draws keypoints
 ```
     Ptr<AgastFeatureDetector> agast = AgastFeatureDetector::create(); 
    vector<KeyPoint> keypoints; 
    agast->detect(inputImage, keypoints); 
    drawKeypoints(inputImage, keypoints, outputImage); 
 ```
 * parameters for agast algo
      threshold  - The higher the threshold means the lower the number of detected features, and vice versa  
      NonmaxSuppression - filters unwanted keypoints  
      type - one of the values AGAST_5_8, AGAST_7_12d, AGAST_7_12s, OAST_9_16  
 ```
     Ptr<AgastFeatureDetector> agast =  
       AgastFeatureDetector::create(); 
    vector<KeyPoint> keypoints; 
    agast->setThreshold(ui->agastThreshSpin->value()); 
    agast->setNonmaxSuppression(ui->agastNonmaxCheck->isChecked()); 
    agast->setType(ui->agastTypeCombo->currentIndex()); 
    agast->detect(inputImage, 
                  keypoints); 
    drawKeypoints(inputImage, 
                  keypoints, 
                  outputImage); 
  ```
 ## KAZE and AKAZE(Accelerated KAZE)
 * Main parameters:  
      nOctaves the maximum octave levels of an image  
      nOctaveLayers the number of sub-levels per octave (or per scale level)  
      Diffusivity may be DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT, DIFF_CHARBONNIER  
      Threshold  
      Descriptor Type  on of the following DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_KAZE, DESCRIPTOR_MLDB_UPRIGHT
      descriptor_size  
      descriptor_channels  
 * example: 
 ```
       Ptr<AKAZE> akaze = AKAZE::create(); 
      akaze->setDescriptorChannels(3); 
      akaze->setDescriptorSize(0); 
      akaze->setDescriptorType( 
        ui->akazeDescriptCombo->currentIndex() + 2); 
      akaze->setDiffusivity(ui->kazeDiffCombo->currentIndex()); 
      akaze->setNOctaves(ui->kazeOctaveSpin->value()); 
      akaze->setNOctaveLayers(ui->kazeLayerSpin->value()); 
      akaze->setThreshold(ui->kazeThreshSpin->value()); 
      akaze->detect(inputImage, keypoints); 
    drawKeypoints(inputImage, keypoints, outputImage); 
```
## The BRISK(Binary Robust Invariant Scalable Keypoints) class
```
    vector<KeyPoint> keypoints; 
    Ptr<BRISK> brisk = 
        BRISK::create(ui->briskThreshSpin->value(), 
                      ui->briskOctaveSpin->value(), 
                      ui->briskScaleSpin->value()); 
    drawKeypoints(inputImage, keypoints, outputImage); 
```
## FAST (Features from Accelerated Segment Test)

## GFTT (Good Features to Track)
```
    vector<KeyPoint> keypoints; 
    Ptr<GFTTDetector> gftt = GFTTDetector::create(); 
    gftt->setHarrisDetector(ui->harrisCheck->isChecked()); 
    gftt->setK(ui->harrisKSpin->value()); 
    gftt->setBlockSize(ui->gfttBlockSpin->value()); 
    gftt->setMaxFeatures(ui->gfttMaxSpin->value()); 
    gftt->setMinDistance(ui->gfttDistSpin->value()); 
    gftt->setQualityLevel(ui->gfttQualitySpin->value()); 
    gftt->detect(inputImage, keypoints); 
    drawKeypoints(inputImage, keypoints, outputImage); 
```

## ORB  (Oriented BRIEF (Binary Robust Independent Elementary Features) )
```
    vector<KeyPoint> keypoints; 
    Ptr<ORB> orb = ORB::create(); 
    orb->setMaxFeatures(ui->orbFeaturesSpin->value()); 
    orb->setScaleFactor(ui->orbScaleSpin->value()); 
    orb->setNLevels(ui->orbLevelsSpin->value()); 
    orb->setPatchSize(ui->orbPatchSpin->value()); 
    orb->setEdgeThreshold(ui->orbPatchSpin->value()); // = patch size 
    orb->setWTA_K(ui->orbWtaSpin->value()); 
    orb->setScoreType(ui->orbFastCheck->isChecked() ? 
                      ORB::HARRIS_SCORE 
                    : 
                      ORB::FAST_SCORE); 
    orb->setPatchSize(ui->orbPatchSpin->value()); 
    orb->setFastThreshold(ui->orbFastSpin->value()); 
    orb->detect(inputImage, keypoints); 
    drawKeypoints(inputImage, keypoints, outputImage); 
```

## Extracting and matching descriptors
* DescriptorExtractor is a subclass of Algorithm
```
     using namespace cv; 
      using namespace std; 
      Mat image1 = imread("image1.jpg"); 
      Mat image2 = imread("image2.jpg"); 
      Ptr<AKAZE> akaze = AKAZE::create(); 
      // set AKAZE params ... 
      vector<KeyPoint> keypoints1, keypoints2; 
      akaze->detect(image1, keypoints1); 
      akaze->detect(image2, keypoints2);         
      Mat descriptor1, descriptor2; 
      akaze->compute(image1, keypoints1, descriptor1); 
      akaze->compute(image2, keypoints2, descriptor2); 
      descMather = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED); 
      vector<DMatch> matches; 
      descMather->match(descriptor1, descriptor2, matches); 
      drawMatches(image1, 
                    keypoints1, 
                    image2, 
                    keypoints2, 
                    matches, 
                    dispImg); 
```
 
 # Chapter 8. Multithreading
 ## Multithreading in Qt
* QThread - is the base of all threads in the Qt framework. It can be subclassed to create new threads, in which case, you need to override the run method, or you can create new instances of it and move any Qt object (the QObject subclass) into a new thread by calling the moveToThread function.
* QThreadPool - to manage threads and help reduce thread creation costs by allowing existing threads to be reused for new purposes. Every Qt application contains a global QThreadPool instance that can be accessed by using the QThreadPool::globalInstance() static function. This class is used in conjunction with the QRunnable class instances to control, manage, and recycle runnable objects in a Qt application.
* QRunnable: This provides another way of creating threads, and it is the base of all runnable objects in Qt. Unlike QThread, QRunnable is not a QObject subclass and is used as an interface for a piece of code that needs to be run. You need to subclass and override the run function to be able to use QRunnable. QRunnable instances are managed by the QThreadPool class.
* QMutex, QMutexLocker, QSemaphore, QWaitCondition, QReadLocker, QWriteLocker, and QWriteLocke: These classes are used to deal with inter-thread synchronization tasks
* QtConcurrent: This namespace can be used to create multithreaded applications using a high-level API. 
* QFuture, QFutureWatcher, QFututeIterator, and QFutureSynchronizer: These classes are all used in conjunction with the QtConcurrent namespace to handle multithreaded and asynchronous operation results.

## QThread subclass example
* create an application
* add new class from QObject -> then change to Qthread
* add two signals to this class
```
    void inDisplay(QPixmap pixmap); 
    void outDisplay(QPixmap pixmap); 
```

* override it's run method:
```
void VideoProcessorThread::run() 
{ 
using namespace cv; 
VideoCapture camera(0); 
Mat inFrame, outFrame; 
while(camera.isOpened() && !isInterruptionRequested()) 
{ 
camera >> inFrame; 
if(inFrame.empty()) 
continue; 
bitwise_not(inFrame, outFrame); 
emit inDisplay(QPixmap::fromImage(QImage(inFrame.data,inFrame.cols,inFrame.rows,inFrame.step, QImage::Format_RGB888)               .rgbSwapped())); 
emit outDisplay(QPixmap::fromImage(QImage(outFrame.data,outFrame.cols,outFrame.rows,outFrame.step,QImage::Format_RGB888) .rgbSwapped())); 
} 
}  
```
* in mainwindow constructor add
```
    VideoProcessorThread processor; 
    connect(&processor,SIGNAL(inDisplay(QPixmap)),ui->inVideo,SLOT(setPixmap(QPixmap)));  
    connect(&processor, SIGNAL(outDisplay(QPixmap)),ui->outVideo, SLOT(setPixmap(QPixmap))); 
    processor.start(); 
```
* add in mainwindow destuctor
```
    processor.requestInterruption(); 
    processor.wait(); 
```
## important functions
* start: This can be used to start a thread if it is not already started. 
* start uses following options:  
    QThread::IdlePriority (this is scheduled when no other thread is running)  
    QThread::LowestPriority  
    QThread::LowPriority  
    QThread::NormalPriority  
    QThread::HighPriority  
    QThread::HighestPriority  
    QThread::TimeCriticalPriority (this is scheduled as much as possible)  
    QThread::InheritPriority (this is the default value, which simply inherits priority from the parent)  

## moveToThread function example
* create an application
* add new class from QObject 
* add members to this new class
```
    signals: 
      void inDisplay(QPixmap pixmap); 
      void outDisplay(QPixmap pixmap); 
    public slots: 
      void startVideo(); 
      void stopVideo(); 
   private: 
      bool stopped; 
```
* implement     void VideoProcessor::startVideo() in same way as run() from thread example
* stopVideo to set stopped to true
* add a private member to mainwindow
```
    VideoProcessor *processor; 
```
* in mainwindow constructor connect slots with signals
```
   processor = new VideoProcessor(); 
   processor->moveToThread(new QThread(this)); 
   connect(processor->thread(), SIGNAL(started()), processor, SLOT(startVideo())); 
   connect(processor->thread(), SIGNAL(finished()), processor, SLOT(deleteLater())); 
   connect(processor, SIGNAL(inDisplay(QPixmap)), ui->inVideo, SLOT(setPixmap(QPixmap))); 
   connect(processor, SIGNAL(outDisplay(QPixmap)), ui->outVideo, SLOT(setPixmap(QPixmap))); 
   processor->thread()->start(); 
```
* in mainwindow destructor add: 
```
    processor->stopVideo(); 
    processor->thread()->quit(); 
    processor->thread()->wait(); 
```

## Thread synchronization tools
* QMutex
```
    forever 
    { 
      imageMutex.lock(); 
      image = imread("image.jpg"); 
      imageMutex.unlock(); 
    } 
```
* QMutexLocker
```
    forever 
    { 
      QMutexLocker locker(&imageMutex); 
      image = imread("image.jpg"); 
    } 
```
* QReadWriteLock.lockForRead
* QReadWriteLock.lockForWrite
```
    forever 
    { 
       lock.lockForRead(); 
       read_image(); 
       lock.unlock(); 
    } 
```
* QReadLocker
```
    forever 
    { 
      QReadLocker locker(&lock); 
      Read_image(); 
    }  
```
* QSemaphore ( semaphores are used for thread synchronization based on the number of available resources)  
    acquire: This can be used to acquire a specific amount of resources that are needed. If there are not enough resources, then the thread will be blocked and has to wait until there are enough resources.  
    release: This can be used to release a specific amount of resources that are already used and not needed anymore.  
    available: This can be used to get the number of available resources. This function can be used in case we want our threads to perform another task instead of waiting for resources.  
```
    QSemaphore memSem(100); 
    ...
    memSem.acquire(X); 
    process_image(); // memory intensive process 
    memSem.release(X); 
```
## Wait conditions
* problem - certain thread must wait for some condition other than the thread being executed by the operating system. In such cases, if quite naturally, a mutex or a read-write lock is used by the thread, it can block all other threads because it is simply the thread's turn to run and it is waiting for some specific condition
* QWaitCondition
* example  
one thread may release mutex if function is not finished imageExistsCond  
```
    forever 
    { 
      mutex.lock(); 
      imageExistsCond.wait(&mutex); 
      read_image(); 
      mutex.unlock(); 
    } 
```
another thread will wake this thread(may be wakeOne)  
```
   forever 
    { 
      if(QFile::exists("image.jpg")) 
          imageExistsCond.wakeAll(); 
    }
```

## High-level multithreading using QtConcurrent

