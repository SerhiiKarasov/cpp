import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow
{
    id: mainWindow
    visible: true
    width: 300
    height: 500
    title: "Hello QML"

    ColumnLayout
    {
        anchors.fill: parent
        Button
        {
            text: "First Button - close"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onPressed:
            {
                mainWindow.close()
            }
        }
        Button
        {
            text: "Second Button"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        Button
        {
            text: "Third Button"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        MyRadios
        {
            width: 100
            height: 200
        }
    }

    MouseArea {
        id: mouseArea
        x: 156
        y: 320
        width: 100
        height: 100
    }
}
