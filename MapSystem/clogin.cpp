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
	QString title = QStringLiteral("��ʾ");
	QString message;

	if (str.isEmpty() || str.isNull())
	{
		bOk = false;
		message = QStringLiteral("�û�������Ϊ�ա�");		
	}


	if (!bOk)
	{
		QMessageBox msgBox(QMessageBox::Critical, title, message);
		msgBox.addButton(QStringLiteral(" �� "), QMessageBox::AcceptRole);
		msgBox.exec();
	}
	
	return bOk;
}

bool CLogin::check_password(const QString &str)
{
	bool bOk = true;
	QString title = QStringLiteral("��ʾ");
	QString message;

	if (str.isEmpty() || str.isNull())
	{
		bOk = false;
		message = QStringLiteral("���벻��Ϊ�ա�");
	}


	if (!bOk)
	{
		QMessageBox msgBox(QMessageBox::Critical, title, message);
		msgBox.addButton(QStringLiteral(" �� "), QMessageBox::AcceptRole);
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

	QString title = QStringLiteral("��ʾ");
	QString message = QStringLiteral("�ʺ����벻��ȷ");
	QMessageBox msgBox(QMessageBox::Critical, title, message);
	msgBox.addButton(QStringLiteral(" �� "), QMessageBox::AcceptRole);
	msgBox.exec();
	return false;
}