#include "datagraph.h"
#include "ui_datagraph.h"

DataGraph::DataGraph(QMainWindow *parent, const GradeRecord& record) :
    QMainWindow(parent),
    ui(new Ui::DataGraph),
    parent(parent)
{
    ui->setupUi(this);
    this->setCentralWidget(new QChartView(CreateChart(record)));
}

DataGraph::~DataGraph()
{
    delete ui;
}

QChart *DataGraph::CreateChart(const GradeRecord& record)
{
    QBarSet* set0 = new QBarSet("成绩分布");
    *set0<<record.span_lower_60 << record.span_60_to_70 << record.span_70_to_80 << record.span_80_to_90 << record.span_bigger_90;
    QBarSeries* barSerise = new QBarSeries();
    barSerise->append(set0);
    QChart* chart = new QChart();
    chart->addSeries(barSerise);
    chart->setTitle("学生成绩条形图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList str;
    str <<"不及格" << "及格" << "中" << "良" << "优";
    QBarCategoryAxis* axisx = new QBarCategoryAxis();
    axisx->append(str);
    chart->createDefaultAxes();
    chart->setAxisX(axisx);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    return chart;
}

void DataGraph::closeEvent(QCloseEvent *)
{
    parent->show();
}
