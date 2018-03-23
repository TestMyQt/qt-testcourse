import QtQuick 2.9
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0

Item {
    id: cookieClicker
    anchors.fill: parent

    // Write correct properties and aliases here
    // BEGIN SOLUTION
    property int click: 0
    property string welcome : "Generic welcome!"
    property alias status: cookieText
    property string clickedType : "Cookie"
    // END SOLUTION

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "qrc:/cookie.jpg"

        // Write something clickable here!
        // BEGIN SOLUTION
        MouseArea {
            anchors.fill: parent
            onClicked: {
                click++;
                cookieText.text = clickedType + "s clicked: " + click;
            }
        }
        // END SOLUTION
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        id: cookieText
        x: 0
        y: 0
        text: welcome
        color: "brown"
        font.pixelSize: 30
    }
}
