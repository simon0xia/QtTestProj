#include "clogin.h"
#include <QMessageBox>

CLogin::CLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CLogin::~CLogin()
{

}

void CLogin::on_btn_login_clicked()
{
	QString strAccount = ui.edit_account->text();
	QString strPwd = ui.edit_password->text();

	if (!check_account(strAccount) || !check_password(strPwd))
	{
		return;
	}
	
	if (check(strAccount, strPwd))
	{
		done(Accepted);
	}
}


bool CLogin::check_account(const QString &str)
{
	bool bOk = true;
	QString title = QStringLiteral("提示");
	QString message;

	if (str.isEmpty() || str.isNull())
	{
		bOk = false;
		message = QStringLiteral("用户名不可为空。");		
	}


	if (!bOk)
	{
		QMessageBox msgBox(QMessageBox::Critical, title, message);
		msgBox.addButton(QStringLiteral(" 是 "), QMessageBox::AcceptRole);
		msgBox.exec();
	}
	
	return bOk;
}

bool CLogin::check_password(const QString &str)
{
	bool bOk = true;
	QString title = QStringLiteral("提示");
	QString message;

	if (str.isEmpty() || str.isNull())
	{
		bOk = false;
		message = QStringLiteral("密码不可为空。");
	}


	if (!bOk)
	{
		QMessageBox msgBox(QMessageBox::Critical, title, message);
		msgBox.addButton(QStringLiteral(" 是 "), QMessageBox::AcceptRole);
		msgBox.exec();
	}

	return bOk;
}

bool CLogin::check(const QString &account, const QString &password)
{
	if (account == "admin" && password == "admin1234")
	{
		return true;
	}

	QString title = QStringLiteral("提示");
	QString message = QStringLiteral("帐号密码不正确");
	QMessageBox msgBox(QMessageBox::Critical, title, message);
	msgBox.addButton(QStringLiteral(" 是 "), QMessageBox::AcceptRole);
	msgBox.exec();
	return false;
}