#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qimageprocessor.hpp"
#include "qimageviewer.hpp"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<QImageProcessor>("com.sk.classes",
                                     1, 0, "ImageProcessor");
    qmlRegisterType<QImageViewer>("com.sk.classes",
                                  1, 0, "ImageViewer");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
