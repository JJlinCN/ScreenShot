import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: rootApp
    title: qsTr("麒麟截屏")
    width: 900
    height: 480
    minimumHeight: 480
    minimumWidth: 680
    visible: true
    header: ToolBar {
        RowLayout {
            ToolButton {
                id: button1
                icon.source: "qrc:/icons/logo.png"
                onClicked: {
                    recshot.show()
                }
            }
            ToolButton {
                id: button2
                icon.source: "qrc:/icons/logo.png"
                onClicked: {
                    fullshot.show()
                }
            }
        }
    }
}
