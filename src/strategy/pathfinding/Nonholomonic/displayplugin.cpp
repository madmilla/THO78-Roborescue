#include "displayplugin.h"
displayPlugin::displayPlugin(QObject* parent) :
   QObject(parent),
   initialized(false)
{}

QString displayPlugin::name() const{
   return "Display";
}

QString displayPlugin::group() const{
   return tr("ICS Custom Widgets");
}

QString displayPlugin::toolTip() const{
   return tr("display");
}

QString displayPlugin::whatsThis() const{
   return tr("display");
}

QString displayPlugin::includeFile() const {
   return "display.h";
}

QIcon displayPlugin::icon() const {
   return QIcon();
}

bool displayPlugin::isContainer() const {
   return false;
}

QWidget * displayPlugin::createWidget(QWidget *parent){
   return new Display(parent);
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
  Q_EXPORT_PLUGIN2(ledplugin, LEDPlugin)
#endif
