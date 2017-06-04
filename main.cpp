#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDesktopWidget>
#include "mechanics/mechanicsengine.h"
#include <QStyleFactory>
#include "iostream"
#include <functional>
#include <QImage>
#include "render/defaultscene.h"
#include <random>
#include <algorithm>
#include "globaldefines.h"
#include "utils.h"
#include "globalsettings.h"
#include "ui_mainwindow.h"
#include <QVector4D>
#include "lSystem/lsystem.h"
#include "treeLineObject.h"

int main(int argc, char *argv[])
{
	
	//system.getProductions().addSuccessor('F', std::string("FF-[F+FF+F]+[+F-F-FF]"));
	//system.getProductions().addSuccessor('F', std::string("FF-[-F+F+F]+[+F-F-F]"));
	//system.getProductions().addSuccessor('F', std::string("F-[F+F+F]+[+F-F-F]"));
	//system.getProductions().addSuccessor('F', std::string("F-[F+F+F]+[F-F-F]"));
	//system.getProductions().addSuccessor('F', std::string("F-F-F[+++++R]-F-F-F[+++++T]-F-F-F[+++++R]-F-F-F[+++++T]-"));
	//std::cout << system.toString() << std::endl;

	//return 0;
	GlobalSettings* settings(GlobalSettings::getSettings());
    mechanics::MechanicsEngine::StartEngine();

	LSystem system(settings->getSettings()->axiom);
	system.getProductions().addSuccessor(settings->getSettings()->productions);
	for (int a = 0; a < settings->getSettings()->iterations; a++)
		system.update();

    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4,1);
    format.setDepthBufferSize(a.desktop()->depth());
    format.setSamples(2);
    format.setOption(QSurfaceFormat::DebugContext);
    format.setSwapInterval(-1);
	
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow w;
    w.resize(a.desktop()->size().width(), a.desktop()->size().height());
    w.resize(2000, 2000 );
    w.show();
	QVector4D v(0, 0, 0, 0);
	w.getUI()->openGLWidget->setClearColor(v);

	renderer::DefaultScene scene;
	TreeLineObject ogg(
			system.toString(),
		   	settings->getSettings()->angle,
			settings->getSettings()->persistance,
			settings->getSettings()->fade
			);

//	w.getUI()->openGLWidget->getCamera()->setTranslation(10, 10, -10);	
    return a.exec();
}
