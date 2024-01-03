QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += /usr/local/include/vtk-9.3 \
                /usr/local/include/opencascade

LIBS += -L/usr/local/lib  \
  -lvtkFiltersCore-9.3 \
  -lvtkCommonDataModel-9.3 \
  -lvtkCommonExecutionModel-9.3 \
  -lvtkCommonColor-9.3 \
  -lvtkCommonCore-9.3 \
  -lvtkFiltersSources-9.3 \
  -lvtkInteractionStyle-9.3 \
  -lvtkRenderingContextOpenGL2-9.3 \
  -lvtkRenderingCore-9.3 \
  -lvtkRenderingFreeType-9.3 \
  -lvtkRenderingGL2PSOpenGL2-9.3 \
  -lvtkRenderingOpenGL2-9.3 \
  -lvtkGUISupportQt-9.3 \
  -lvtksys-9.3 \
  -lTKPrim \
  -lTKIVtk \
  -lTKMath \
  -lTKernel \
  -lTKTopAlgo \
  -lTKGeomAlgo \
  -lTKV3d


SOURCES += \
    #MakeBottle.cpp \
    main.cpp \
    icpcad.cpp

HEADERS += \
    icpcad.h

FORMS += \
    icpcad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
