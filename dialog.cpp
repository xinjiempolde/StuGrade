#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pressBtn()));
    QValidator* validator = new QIntValidator(0, 100);
    ui->lineEdit->setValidator(validator);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::pressBtn()
{
    QString data = ui->lineEdit->text();
    if (data == "")
    {
        QMessageBox::warning(this, "警告", "您未输入任何数据！");
        return;
    }
    emit sendData(data);
    this->close();
}
