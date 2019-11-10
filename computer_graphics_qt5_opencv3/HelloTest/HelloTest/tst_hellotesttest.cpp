#include <QString>
#include <QtTest>
#include "pixelcounter.hpp"

class HelloTestTest : public QObject
{
    Q_OBJECT

public:
    HelloTestTest();

private Q_SLOTS:
    void testPixelCount();
    void testPixelCount2();
    void testPixelCount2_data();
};

HelloTestTest::HelloTestTest()
{
}

void HelloTestTest::testPixelCount()
{
    int width = 640, height = 427;
    QString fname = "/home/computer/Downloads/test.jpg";
    PixelCounter c;
    QVERIFY2(c.countPixels(fname) == width*height, "Failure");

    QBENCHMARK
    {
        c.countPixels(fname);
    }
}

void HelloTestTest::testPixelCount2()
{
    PixelCounter c;
    QFETCH(QString, filename);
    QFETCH(int, pixelcount);
    QCOMPARE(c.countPixels(filename), pixelcount);
}

void HelloTestTest::testPixelCount2_data()
{
    QTest::addColumn<QString>("filename");
    QTest::addColumn<int>("pixelcount");

    QTest::newRow("huge image") <<"/home/computer/Downloads/test.jpg" << 273280;
    QTest::newRow("small image")<<"/home/computer/Downloads/test.jpg" << 273280;
}



QTEST_APPLESS_MAIN(HelloTestTest)

#include "tst_hellotesttest.moc"
