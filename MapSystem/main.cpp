#include "mapsystem.h"
#include <QtWidgets/QApplication>
#include <QTime>
#include "clogin.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFont font = a.font();
	font.setPointSize(9);
	a.setFont(font);

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

// 	CLogin *lm = new CLogin;
// 	if (QDialog::Accepted != lm->exec())
// 	{
// 		delete lm;
// 		exit(0);
// 	}
// 	delete lm;

	MapSystem w;
	w.showMaximized();
	return a.exec();
}
