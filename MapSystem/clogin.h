#ifndef CLOGIN_H
#define CLOGIN_H

#include <QDialog>
#include "ui_clogin.h"

class CLogin : public QDialog
{
	Q_OBJECT

public:
	CLogin(QWidget *parent = 0);
	~CLogin();

private slots:
	void on_btn_login_clicked();

private:
	bool check_account(const QString &str);
	bool check_password(const QString &str);
	bool check(const QString &account, const QString &password);

private:
	Ui::CLogin ui;
};

#endif // CLOGIN_H
