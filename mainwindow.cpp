#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bin_sorted_tree.h"
#include "dialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
#include<QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bst()
{
    ui->setupUi(this);
    isFirstSubmit = true;
    setWindowTitle("学生成绩条形统计");
    ui->grade_edit->setValidator(new QIntValidator(0, 99, this));
    set_input_enable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_one_button_unenable(QPushButton* button)
{
    ui->read_file_button->setEnabled(true);
    ui->random_button->setEnabled(true);
    ui->keyboard_button->setEnabled(true);
    button->setEnabled(false);
}

void MainWindow::set_input_enable(bool flag)
{
    ui->name_edit->setEnabled(flag?true:false);
    ui->grade_edit->setEnabled(flag?true:false);
    ui->submit_push_button->setEnabled(flag?true:false);
}

void MainWindow::set_grade_layout(const GradeRecord &record)
{
    ui->notpass_edit->setText(QString::number(record.span_lower_60));
    ui->pass_edit->setText(QString::number(record.span_60_to_70));
    ui->zhong_edit->setText(QString::number(record.span_70_to_80));
    ui->liang_edit->setText(QString::number(record.span_80_to_90));
    ui->you_edit->setText(QString::number(record.span_bigger_90));
}

void MainWindow::get_data_from_dialog(QString data)
{
    bst.ClearBST();
    int count = data.toInt();   // 随机数的个数
    ui->textBrowser->clear();
    QString content = "随机生成的数据如下：\n姓名\t成绩\n";
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 1; i <= count; i++)
    {
        int grade = qrand() % 101;
        bst.InsertBST(grade, QString::number(i));
        content += QString::number(i) + "\t" + QString::number(grade) + "\n";
    }
    bst.PreOrderTraverse(0);
    set_grade_layout(bst.GetRecord());
    ui->textBrowser->setText(content);
}

void MainWindow::on_submit_push_button_clicked()
{
    if (ui->name_edit->text() == "" || ui->grade_edit->text() == "")
    {
        QMessageBox::warning(this, "警告", "姓名或者成绩不能为空！");
        return;
    }
    bool flag = false;
    QString name = ui->name_edit->text();
    QString grade = ui->grade_edit->text();
    if (!isFirstSubmit)
    {
        bst.InorderTraverse(0, name, flag);
        if (flag)
        {
            QMessageBox::warning(this, "警告", "该名字已经重复！");
            return;
        }
    }
    QString text_browser = ui->textBrowser->toPlainText();
    text_browser += name + "\t" + grade + '\n';
    bst.InsertBST(grade.toInt(), name);
    bst.ClearRecord();
    bst.PreOrderTraverse(0);
    set_grade_layout(bst.GetRecord());
    ui->textBrowser->setText(text_browser);
    isFirstSubmit = false;
}

void MainWindow::on_clear_this_time_button_clicked()
{
    ui->name_edit->clear();
    ui->grade_edit->clear();
}

void MainWindow::on_read_file_button_clicked()
{
    bst.ClearBST();
    set_one_button_unenable(ui->read_file_button);
    set_input_enable(false);
    QFile file(":/StuDB.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr, "提示", "文件打开失败");
        return;
    }
    QString content = "您从文件中读取了以下数据：\n";
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line_data = QString(in.readLine());
        content += line_data + "\n";
        QStringList split_list = line_data.split(' ');
        bst.InsertBST(split_list[1].toInt(), split_list[0]);
    }
    ui->textBrowser->setText(content);
    bst.PreOrderTraverse(0);    // 根节点为0
    set_grade_layout(bst.GetRecord());
    file.close();
}


void MainWindow::on_show_graph_button_clicked()
{
    setVisible(false);
    DataGraph* graph = new DataGraph(this, bst.GetRecord());
    graph->show();
}

void MainWindow::on_random_button_clicked()
{
    set_input_enable(false);
    set_one_button_unenable(ui->random_button);
    QDialog* dialog = new Dialog(this);
    connect(dialog, SIGNAL(sendData(QString)),this,SLOT(get_data_from_dialog(QString)));
    dialog->exec();

}

void MainWindow::on_keyboard_button_clicked()
{
    set_input_enable(true);
    set_one_button_unenable(ui->keyboard_button);
    ui->textBrowser->clear();
    bst.ClearBST();
    QString content = "您正在手动输入数据:\n姓名\t成绩\n";
    ui->textBrowser->setText(content);
    set_grade_layout(bst.GetRecord());
    isFirstSubmit = true;
}

void MainWindow::on_clear_all_button_clicked()
{
    bst.ClearBST();
    set_grade_layout(bst.GetRecord());
    ui->textBrowser->clear();
    ui->name_edit->clear();
    ui->grade_edit->clear();
}
