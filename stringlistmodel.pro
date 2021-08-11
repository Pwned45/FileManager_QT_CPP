QT += qml quick

SOURCES += main.cpp \
    filemanagerbutton.cpp \
    filemanagercontrolmodel.cpp \
    filemanagermodel.cpp
RESOURCES += stringlistmodel.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/models/stringlistmodel
INSTALLS += target

HEADERS += \
    filemanagerbutton.h \
    filemanagercontrolmodel.h \
    filemanagermodel.h
