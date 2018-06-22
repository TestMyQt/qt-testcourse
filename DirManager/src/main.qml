import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Dir manager")

    Grid {
        id: basicDataGrid
        width: parent.width
        columns: 2

        Text {
            text: qsTr("Directory name  ")
            font.pointSize: 24
            width: window.width / 2
            elide: Text.ElideRight
        }
        Text {
            text: dirManager.dirName
            font.pointSize: 24
            width: window.width / 2
            elide: Text.ElideRight
        }
        Text {
            text: qsTr("Entries in directory  ")
            font.pointSize: 24
            width: window.width / 2
            elide: Text.ElideRight
        }
        Text {
            text: dirManager.filesInDir
            font.pointSize: 24
            width: window.width / 2
            elide: Text.ElideRight
        }
    }
    MouseArea {
        anchors.fill: basicDataGrid
        onClicked: dirManager.sort();
    }

    ListView {
        id: listView
        anchors { top: basicDataGrid.bottom; left: parent.left; right: parent.right; bottom: parent.bottom; margins: 15 }
        model: dirManager.model();
        delegate: Component {
            Text {
                text: model.modelData
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        dirManager.entryClicked(text);
                    }
                }
            }
        }
        Connections {
            target: dirManager
            onDataChanged: listView.model = dirManager.model();
        }
    }
    Rectangle {
        id: fileContentView
        visible: false
        anchors.fill: listView
        border { width: 3; color: "white" }
        color: "darkGreen"
        TextArea {
            id: content
            anchors { fill: parent; margins: 10 }
            color: "white"
        }
        MouseArea {
            anchors.fill: parent
            onClicked:
                fileContentView.visible = false;
        }
        Connections {
            target: dirManager
            onFileContentChanged: {
                content.text = dirManager.fileContent();
                fileContentView.visible = true;
            }
        }
    }
}

