#include "mapsystem.h"


MapSystem::MapSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.axWidget->setControl("Shell.Explorer");

	QDir dir;
	webPath = dir.currentPath();
	webPath += "/bmap.html";
	actionloadSlot();

	connect(ui.actionload, SIGNAL(triggered()), this, SLOT(actionloadSlot()));
	connect(ui.actionreload, SIGNAL(triggered()), this, SLOT(actionloadSlot()));
	connect(ui.actionmove, SIGNAL(triggered()), this, SLOT(actionmoveSlot()));
	connect(ui.actionzoom, SIGNAL(triggered()), this, SLOT(actionzoomSlot()));
}

MapSystem::~MapSystem()
{

}

void MapSystem::actionloadSlot()
{
	ui.axWidget->dynamicCall("Navigate(QString)", webPath);
}

void MapSystem::runningJS(BSTR strName)
{
	QAxObject *document = ui.axWidget->querySubObject("Document");
	IHTMLDocument2 *doc2;
	document->queryInterface(QUuid(IID_IHTMLDocument2), (void**)&doc2);
	if (doc2)
	{
		IHTMLWindow2 *win2 = nullptr;
		if (doc2->get_parentWindow(&win2) == S_OK)
		{
			BSTR s2 = SysAllocString(L"JavaScript");
			VARIANT ret;
			win2->execScript(strName, s2, &ret);
			SysFreeString(s2);

		}
	}
}

void MapSystem::actionmoveSlot()
{
	BSTR whats;
	if (ui.actionmove->isChecked())
	{
		whats = SysAllocString( L"add_scale()");
	}
	else
	{
		whats = SysAllocString(L"delete_scale()");
	}

	runningJS(whats);
	SysFreeString(whats);
	
}

void MapSystem::actionzoomSlot()
{
	BSTR whats;
	if (ui.actionzoom->isChecked())
	{
		whats = SysAllocString(L"add_navigation()");
	}
	else
	{
		whats = SysAllocString(L"delete_navigation()");
	}

	runningJS(whats);
	SysFreeString(whats);
}