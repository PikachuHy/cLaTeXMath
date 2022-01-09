#include "latex.h"

#include "qt_mainwindow.h"

#include <QApplication>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

#ifdef BUILD_SKIA
  initGL();
#endif
  // todo
  const tex::FontSpec math{
    "xits",
    "/home/nano/Downloads/xits/XITSMath-Regular.otf",
    "../../res/XITSMath-Regular.clm"
  };
  tex::LaTeX::init(math);

  tex::PlatformFactory::registerFactory("qt", std::make_unique<tex::PlatformFactory_qt>());
  tex::PlatformFactory::activate("qt");

  tex::LaTeX::setRenderGlyphUsePath(true);

  MainWindow win;
  win.show();
  int ret = app.exec();

  tex::LaTeX::release();
  return ret;
}
