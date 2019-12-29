#ifndef DATAGRAPH_H
#define DATAGRAPH_H

#include <QDialog>
#include <QtCharts>
#include "bin_sorted_tree.h"
namespace Ui {
class DataGraph;
}

class DataGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataGraph(QMainWindow *parent = nullptr);
    DataGraph(QMainWindow *parent, const GradeRecord& record);
    ~DataGraph();
    /*
     * 函数名:CreateChart
     * 功  能:构造一个条形图
     * 输  入:学生成绩记录结构体
     * 输  出:无
     * 返回值:图标指针
     */
    QChart* CreateChart(const GradeRecord& record);

private:
    Ui::DataGraph *ui;
    QMainWindow* parent;

protected:
    /* 当当前窗口被关闭时 */
    void closeEvent(QCloseEvent* event);
};

#endif // DATAGRAPH_H
