

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import Kyrsovay

Rectangle {
    width: 800
    height: 600
    color: "#595959"
    border.width: 0

    Rectangle {
        id: rectangle
        x: 93
        y: 216
        width: 126
        height: 152
        color: "#fcfcfc"
        radius: 15
        border.width: 1

        Text {
            id: text2
            x: 24
            y: 28
            text: qsTr("R")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 24
            y: 106
            text: qsTr("B")
            font.pixelSize: 12
        }

        Text {
            id: text4
            x: 24
            y: 68
            text: qsTr("G")
            font.pixelSize: 12

            Text {
                id: text6
                x: 35
                y: 0
                text: qsTr("=")
                font.pixelSize: 12

                Text {
                    id: text7
                    x: 0
                    y: 38
                    text: qsTr("=")
                    font.pixelSize: 12

                    Rectangle {
                        id: rectangle2
                        x: 16
                        y: -38
                        width: 39
                        height: 20
                        color: "#ffffff"
                        radius: 2
                        border.width: 1
                    }
                }

                Rectangle {
                    id: rectangle1
                    x: 16
                    y: -40
                    width: 39
                    height: 20
                    visible: true
                    color: "#ffffff"
                    radius: 2
                    border.width: 1

                    Rectangle {
                        id: rectangle3
                        x: 0
                        y: 78
                        width: 39
                        height: 20
                        color: "#ffffff"
                        radius: 2
                        border.width: 1

                        TextInput {
                            id: textInput
                            x: 0
                            y: -78
                            width: 39
                            height: 20
                            text: qsTr("1.00")
                            font.pixelSize: 11
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    TextInput {
                        id: textInput2
                        x: 0
                        y: 78
                        width: 39
                        height: 20
                        text: qsTr("1.00")
                        font.pixelSize: 11
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    TextInput {
                        id: textInput1
                        x: 0
                        y: 40
                        width: 39
                        height: 20
                        text: qsTr("1.00")
                        font.pixelSize: 11
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Text {
            id: text5
            x: 59
            y: 28
            width: 8
            height: 16
            text: qsTr("=")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: rectangle4
        x: 93
        y: 161
        width: 126
        height: 49
        color: "#ffffff"
        radius: 8
        border.width: 1

        Text {
            x: 12
            y: 85
            width: 82
            height: 16
            text: qsTr("Налаштування ")
            rotation: 0
            anchors.verticalCenterOffset: -9
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            font.family: Constants.font.family
        }

        Text {
            id: text1
            x: 7
            y: 23
            text: qsTr("Чутливості каналів")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: rectangle5
        x: 56
        y: 57
        width: 200
        height: 40
        color: "#ffffff"
        radius: 1
        border.width: 1

        Text {
            id: text8
            x: 8
            y: 8
            width: 184
            height: 24
            text: qsTr("Додати відео")
            font.pixelSize: 17
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            id: mouseArea1
            x: 0
            y: 0
            width: 200
            height: 40
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
        }
    }

    Rectangle {
        id: rectangle6
        x: 281
        y: 57
        width: 40
        height: 40
        color: "#ffffff"
        border.width: 3

        Loader {
            id: loader
            x: -226
            y: 0
            width: 266
            height: 40
        }

        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 40
            height: 40
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
        }

        Image {
            id: image
            x: 0
            y: 0
            width: 40
            height: 40
            source: "../../../Desktop/Курсач/images.png"
            fillMode: Image.PreserveAspectFit
        }
    }

    Button {
        id: button
        x: 347
        y: 57
        width: 40
        height: 40
        text: qsTr("")
        checkable: true
        checked: false

        Image {
            id: image1
            x: 0
            y: 0
            width: 40
            height: 40
            source: "../../../Desktop/Курсач/Без названия.png"
            fillMode: Image.PreserveAspectFit
        }

        MouseArea {
            id: mouseArea2
            x: 0
            y: 0
            width: 40
            height: 40
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
        }
    }

    Frame {
        id: frame
        x: 432
        y: 51
        width: 318
        height: 498

        Rectangle {
            id: rectangle7
            x: -12
            y: -12
            width: 318
            height: 500
            color: "#ffffff"
        }
    }

    RoundButton {
        id: roundButton
        x: 8
        y: 477
        width: 30
        height: 30
        text: ""
        autoRepeat: true
        autoExclusive: false
        checked: false
        checkable: false
        icon.cache: false
        display: AbstractButton.IconOnly
        icon.color: "#ffdcca"

        Text {
            id: text12
            x: 5
            y: 9
            width: 21
            height: 13
            text: qsTr("?")
            font.pixelSize: 18
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }

        MouseArea {
            id: mouseArea3
            x: 0
            y: 1
            width: 34
            height: 29
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
        }
    }

    RoundButton {
        id: roundButton1
        x: 8
        y: 532
        width: 30
        height: 30
        radius: 12
        text: ""
        checked: false
        checkable: false
        icon.color: "#ffdcca"
        autoRepeat: true
        display: AbstractButton.IconOnly
        icon.cache: false
        autoExclusive: false

        Text {
            id: text11
            x: 2
            y: 6
            width: 27
            height: 18
            text: qsTr("!")
            font.pixelSize: 19
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.italic: false
            font.bold: true
        }

        MouseArea {
            id: mouseArea4
            x: 0
            y: 1
            width: 34
            height: 29
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
        }
    }

    Text {
        id: text9
        x: 49
        y: 479
        width: 106
        height: 27
        text: "Допомога"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text10
        x: 49
        y: 538
        width: 72
        height: 17
        text: qsTr("Про розробників")
        font.pixelSize: 14
    }
}
