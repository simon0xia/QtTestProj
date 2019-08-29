#ifndef MAPSYSTEM_H
#define MAPSYSTEM_H

#include <QtWidgets/QMainWindow>
#include "ui_mapsystem.h"

#include <QDir>
#include <MsHTML.h> 
#include <QUuid>
#include <QAxObject>

class MapSystem : public QMainWindow
{
	Q_OBJECT

public:
	MapSystem(QWidget *parent = 0);
	~MapSystem();

private slots:
	void actionloadSlot();
	void actionmoveSlot();
	void actionzoomSlot();

private:
	void runningJS(BSTR strName);

private:
	Ui::MapSystemClass ui;

	QString webPath;
};

#endif // MAPSYSTEM_H
