#include "icpcad.h"

#include <QApplication>
//#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication a(argc, argv);
    ICPCAD w;
    w.show();
    return a.exec();
}
