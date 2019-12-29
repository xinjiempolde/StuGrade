#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
signals:
    /* 子窗口向父窗口发送数据 */
    void sendData(QString str);
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    /* 当子窗口确认按钮被单击时的槽函数 */
    void pressBtn();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
