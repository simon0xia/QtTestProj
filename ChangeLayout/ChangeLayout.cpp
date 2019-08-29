#include "ChangeLayout.h"
#include <QGridLayout>

ChangeLayout::ChangeLayout(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	wins.append(ui.lbl_w1);
	wins.append(ui.lbl_w2);
	wins.append(ui.lbl_w3);
	wins.append(ui.lbl_w4);
	wins.append(ui.lbl_w5);
	wins.append(ui.lbl_w6);
	wins.append(ui.lbl_w7);
	wins.append(ui.lbl_w8);
	wins.append(ui.lbl_w9);
}

void ChangeLayout::on_btn_layout_2x2_clicked()
{
	delete this->centralWidget()->layout();
	showDispWindow(-1, false);

	setLayout_2x2();
}
void ChangeLayout::on_btn_layout_3x3_clicked()
{
	delete this->centralWidget()->layout();
	showDispWindow(-1, false);

	setLayout_3x3();
}
void ChangeLayout::on_btn_layout_1_5_clicked()
{
	delete this->centralWidget()->layout();
	showDispWindow(-1, false);

	setLayout_1_5();
}

void ChangeLayout::showDispWindow(int count, bool bShow)
{
	if (count > wins.count() || count <= 0)
	{
		count = wins.count();
	}

	for (auto i=0; i<count; i++)
	{
		wins.at(i)->setHidden(!bShow);
	}
}

bool ChangeLayout::setLayout_2x2()
{
	auto lay_btn = new QHBoxLayout();
	lay_btn->addWidget(ui.btn_layout_2x2);
	lay_btn->addWidget(ui.btn_layout_3x3);
	lay_btn->addWidget(ui.btn_layout_1_5);

	auto lay_win = new QGridLayout();
	lay_win->addWidget(ui.lbl_w1, 0, 0);
	lay_win->addWidget(ui.lbl_w2, 0, 1);
	lay_win->addWidget(ui.lbl_w3, 1, 0);
	lay_win->addWidget(ui.lbl_w4, 1, 1);

	auto lay_main = new QVBoxLayout();
	lay_main->addItem(lay_btn);
	lay_main->addItem(lay_win);
	this->centralWidget()->setLayout(lay_main);

	showDispWindow(4, true);
	this->show();
	return true;
}

bool ChangeLayout::setLayout_3x3()
{
	auto lay_btn = new QHBoxLayout();
	lay_btn->addWidget(ui.btn_layout_2x2);
	lay_btn->addWidget(ui.btn_layout_3x3);
	lay_btn->addWidget(ui.btn_layout_1_5);

	auto lay_win = new QGridLayout();
	lay_win->addWidget(ui.lbl_w1, 0, 0);
	lay_win->addWidget(ui.lbl_w2, 0, 1);
	lay_win->addWidget(ui.lbl_w3, 0, 2);
	lay_win->addWidget(ui.lbl_w4, 1, 0);
	lay_win->addWidget(ui.lbl_w5, 1, 1);
	lay_win->addWidget(ui.lbl_w6, 1, 2);
	lay_win->addWidget(ui.lbl_w7, 2, 0);
	lay_win->addWidget(ui.lbl_w8, 2, 1);
	lay_win->addWidget(ui.lbl_w9, 2, 2);
	
	auto lay_main = new QVBoxLayout();
	lay_main->addItem(lay_btn);
	lay_main->addItem(lay_win);
	this->centralWidget()->setLayout(lay_main);

	showDispWindow(9, true);
	this->show();
	return true;
}

bool ChangeLayout::setLayout_1_5()
{
	auto lay_btn = new QHBoxLayout();
	lay_btn->addWidget(ui.btn_layout_2x2);
	lay_btn->addWidget(ui.btn_layout_3x3);
	lay_btn->addWidget(ui.btn_layout_1_5);

	auto lay_tr = new QVBoxLayout();
	lay_tr->addWidget(ui.lbl_w2);
	lay_tr->addWidget(ui.lbl_w3);

	auto lay_t = new QHBoxLayout();
	lay_t->addWidget(ui.lbl_w1);
	lay_t->addItem(lay_tr);
	lay_t->setStretch(0, 2);
	lay_t->setStretch(1, 1);

	auto lay_b = new QHBoxLayout();
	lay_b->addWidget(ui.lbl_w4);
	lay_b->addWidget(ui.lbl_w5);
	lay_b->addWidget(ui.lbl_w6);

	auto lay_win = new QVBoxLayout();
	lay_win->addItem(lay_t);
	lay_win->addItem(lay_b);
	lay_win->setStretch(0, 2);
	lay_win->setStretch(1, 1);

	auto lay_main = new QVBoxLayout();
	lay_main->addItem(lay_btn);
	lay_main->addItem(lay_win);
	this->centralWidget()->setLayout(lay_main);

	showDispWindow(6, true);
	this->show();
	return true;
}