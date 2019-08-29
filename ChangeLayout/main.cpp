#include "ChangeLayout.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChangeLayout w;
	w.show();
	return a.exec();
}
