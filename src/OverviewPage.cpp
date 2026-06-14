#include "OverviewPage.h"
#include "ui_OverviewPage.h"

#include <QTableWidgetItem>
#include <QColor>

static QTableWidgetItem* colorItem(const QString &text, const QString &hex)
{
    auto *item = new QTableWidgetItem(text);
    item->setForeground(QColor(hex));
    return item;
}

OverviewPage::OverviewPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::OverviewPage)
{
    ui->setupUi(this);
    populateTable();
}

OverviewPage::~OverviewPage()
{
    delete ui;
}

void OverviewPage::populateTable()
{
    QTableWidget *t = ui->tableOverview;
    struct Row { QString name, roll, action, time, color; };
    QList<Row> rows = {
        {"Krimud Sainju","08","Attendance","09:02 AM","#2ECC71"},
        {"Alvin Shah","10","Cafeteria","11:45 AM","#F39C12"},
        {"Sanskar Shrestha","23","Attendance","09:05 AM","#2ECC71"},
        {"Pallav Thani","32","Cafeteria","12:10 PM","#F39C12"},
        {"Bishwo Timalsina","37","Attendance","09:08 AM","#2ECC71"},
    };
    for (int r = 0; r < rows.size(); ++r) {
        t->setItem(r,0,new QTableWidgetItem(rows[r].name));
        t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
        t->setItem(r,2,colorItem(rows[r].action, rows[r].color));
        t->setItem(r,3,new QTableWidgetItem(rows[r].time));
        t->setRowHeight(r,46);
    }
}
