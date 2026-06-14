#include "CafeteriaPage.h"
#include "ui_CafeteriaPage.h"

#include <QTableWidgetItem>
#include <QColor>

static QTableWidgetItem* colorItem(const QString &text, const QString &hex)
{
    auto *item = new QTableWidgetItem(text);
    item->setForeground(QColor(hex));
    return item;
}

CafeteriaPage::CafeteriaPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::CafeteriaPage)
{
    ui->setupUi(this);
    populateTable();
}

CafeteriaPage::~CafeteriaPage()
{
    delete ui;
}

void CafeteriaPage::populateTable()
{
    QTableWidget *t = ui->tableCafeteria;
    struct Row { QString name,roll,item,amt,time; };
    QList<Row> rows = {
        {"Krimud Sainju","08","Lunch Set","Rs. 180","12:05 PM"},
        {"Alvin Shah","10","Tea + Snacks","Rs. 65","10:30 AM"},
        {"Pallav Thani","32","Lunch Set","Rs. 180","12:15 PM"},
        {"Bishwo Timalsina","37","Tea","Rs. 30","09:45 AM"},
        {"Ram Sharma","41","Breakfast","Rs. 120","08:10 AM"},
    };
    for (int r = 0; r < rows.size(); ++r) {
        t->setItem(r,0,new QTableWidgetItem(rows[r].name));
        t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
        t->setItem(r,2,new QTableWidgetItem(rows[r].item));
        t->setItem(r,3,colorItem(rows[r].amt, "#F39C12"));
        t->setItem(r,4,new QTableWidgetItem(rows[r].time));
        t->setRowHeight(r,46);
    }
}
