#ifndef DISPLAYPLUGIN_H
#define DISPLAYPLUGIN_H

#include <QObject>
#include <QtDesigner/QDesignerCustomWidgetInterface>
#include "display.h"

class displayPlugin : public QObject, public QDesignerCustomWidgetInterface
{
   Q_OBJECT
   Q_INTERFACES(QDesignerCustomWidgetInterface)
   #if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
   Q_PLUGIN_METADATA(IID "com.ics.Qt.CustomWidgets")
   #endif

public:
   displayPlugin(QObject* parent=0);

   QString name() const;
   QString group() const;
   QString toolTip() const;
   QString whatsThis() const;
   QString includeFile() const;
   QIcon icon() const;

   bool isContainer() const;

   QWidget *createWidget(QWidget *parent);

private:
   bool initialized;
};

#endif // DISPLAYPLUGIN_H
