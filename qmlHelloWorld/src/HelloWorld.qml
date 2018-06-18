import QtQuick 2.0
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0

Item {
    id: world
    width: 400
    height: 200

    // Expose helloText's text property with the name "textThing" here.
    // BEGIN SOLUTION
    property alias textThing: helloText.text
    // END SOLUTION

    Text {
        id: helloText
        x: 38
        y: 41
        width: 325
        height: 99
        color: "blue"
        font.pixelSize: 55
    }
}
