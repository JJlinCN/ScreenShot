QT += quick
QT += gui
QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        shot.cpp \
        main.cpp \
        recscreen.cpp \

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    shot.h \
    RecScreen.h \
FORMS += \
    shot.ui \
