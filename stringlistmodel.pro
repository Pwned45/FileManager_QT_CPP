QT += qml quick

SOURCES += main.cpp \
    filemanagermodel.cpp
RESOURCES += stringlistmodel.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/models/stringlistmodel
INSTALLS += target

HEADERS += \
    filemanagermodel.h
