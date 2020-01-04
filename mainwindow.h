/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 王崧霖

Date: 2019-12-20

Description: 主窗口

**************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datagraph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*
     * 函数名:set_one_button_unenable
     * 功  能:设置选项按钮组有一个不被选中
     * 输  入:不被选中的按钮
     * 输  出:无
     * 返回值:无
     */
    void set_one_button_unenable(QPushButton *button);

    /*
     * 函数名:set_input_enable
     * 功  能:设置键盘输入栏日否可操作
     * 输  入:逻辑值true or false
     * 输  出:无
     * 返回值:无
     */
    void set_input_enable(bool flag);

    /*
     * 函数名:set_grade_layout
     * 功  能:设置成绩分布的数值
     * 输  入:成绩记录结构体
     * 输  出:无
     * 返回值:无
     */
    void set_grade_layout(const GradeRecord &record);

private slots:
    /* 从子窗口接受数据 */
    void get_data_from_dialog(QString);

    /* 当提交按钮被单击时 */
    void on_submit_push_button_clicked();

    /* 当清除本次操作按钮被单击时 */
    void on_clear_this_time_button_clicked();

    /* 当从文件读取数据按钮被单击时 */
    void on_read_file_button_clicked();

    /* 当现实条形图按钮被单击时 */
    void on_show_graph_button_clicked();

    /* 当随机输入数据按钮被单击时 */
    void on_random_button_clicked();

    /* 当从键盘输入数据按钮被单击时 */
    void on_keyboard_button_clicked();

    /* 当清除所有操作按钮被单击时 */
    void on_clear_all_button_clicked();

private:
    Ui::MainWindow *ui;
    BST bst;
    bool isFirstSubmit; // 是否是第一次按下提交按钮
};
#endif // MAINWINDOW_H
