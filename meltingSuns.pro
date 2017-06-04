#-------------------------------------------------
#
# Project created by QtCreator 2016-08-20T12:53:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = engine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mechanics/characteristic.cpp \
        mechanics/rawbonus.cpp \
        render/glwidget.cpp \
        mechanics/entity.cpp \
    render/renderobject.cpp \
    render/transform3d.cpp \
    render/device.cpp \
    render/test/testquad.cpp \
    render/input.cpp \
    render/camera3d.cpp \
    render/engineobject.cpp \
    render/defaultinputmanager.cpp \
    render/scene.cpp \
    render/defaultscene.cpp \
    render/texturedobject.cpp \
    render/dottedobject.cpp \
    render/textureswarmobject.cpp \
    render/linesobject.cpp \
    render/trisobject.cpp \
    mechanics/action.cpp \
    mechanics/timer.cpp \
    mechanics/stockpile.cpp \
    mechanics/mechanicsengine.cpp \
    mechanics/enginemodule.cpp \
    mechanics/entitycharacteristic.cpp \
    mechanics/entitystockpile.cpp \
    mechanics/persistentaction.cpp \
    mechanics/entityaction.cpp \
    mechanics/Widgets/stockpileentitywidget.cpp \
    mechanics/Widgets/characteristicentitywidget.cpp \
    mechanics/Widgets/actionentitywidget.cpp \
    mechanics/Widgets/dialogentity.cpp \
	lSystem/lsystem.cpp \
	parser/parser.cpp \ 
    utils.cpp \
	globalsettings.cpp \
	treeLineObject.cpp \ 



HEADERS  += mainwindow.h \
    mechanics/characteristic.h \
    mechanics/rawbonus.h \
    render/renderState/renderstate.h \
    render/renderState/blending.h \
    render/renderState/colormask.h \
    render/renderState/depthrange.h \
    render/renderState/depthtest.h \
    render/renderState/faceculling.h \
    render/renderState/primitiverestart.h \
    render/renderState/scisortest.h \
    render/renderState/stenciltest.h \
    render/renderState/stenciltestface.h \
    render/glwidget.h \
    mechanics/entity.h \
    render/renderobject.h \
    render/transform3d.h \
    render/device.h \
    render/test/testQuad.h \
    render/input.h \
    render/camera3d.h \
    render/engineobject.h \
    render/defaultinputmanager.h \
    render/scene.h \
    render/defaultscene.h \
    render/texturedobject.h \
    render/dottedobject.h \
    render/textureswarmobject.h \
    render/linesobject.h \
    render/trisobject.h \
    render/floatingquad.h \
    render/dot.h \
    mechanics/action.h \
    mechanics/timer.h \
    mechanics/stockpile.h \
    mechanics/mechanicsengine.h \
    mechanics/enginemodule.h \
    mechanics/entitycharacteristic.h \
    mechanics/informativeobject.h \
    mechanics/entitystockpile.h \
    mechanics/persistentaction.h \
    mechanics/entityaction.h \
    mechanics/Widgets/stockpileentitywidget.h \
    mechanics/Widgets/characteristicentitywidget.h \
    mechanics/Widgets/actionentitywidget.h \
    mechanics/Widgets/dialogentity.h \
	parser/parser.h \
	lSystem/lsystem.h \
    globaldefines.h \
    utils.h \
    render/renderdefines.h \
	globalsettings.h \
	treeLineObject.cpp 

FORMS    += mainwindow.ui \
    mechanics/Widgets/stockpileentitywidget.ui \
    mechanics/Widgets/characteristicentitywidget.ui \
    mechanics/Widgets/actionentitywidget.ui \
    mechanics/Widgets/dialogentity.ui

RESOURCES += \
    resources.qrc

CONFIG += c++14

DISTFILES += \
    shaders/appearinglines.vert
