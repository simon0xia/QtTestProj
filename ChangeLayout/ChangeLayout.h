#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChangeLayout.h"

class ChangeLayout : public QMainWindow
{
	Q_OBJECT

public:
	ChangeLayout(QWidget *parent = Q_NULLPTR);

private slots:
	void on_btn_layout_2x2_clicked();
	void on_btn_layout_3x3_clicked();
	void on_btn_layout_1_5_clicked();

private:
	void showDispWindow(int count,bool bShow);
	bool setLayout_2x2();
	bool setLayout_3x3();
	bool setLayout_1_5();

private:
	Ui::ChangeLayoutClass ui;

	QList<QLabel *> wins;
};
