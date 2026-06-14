#include "ReportsPage.h"
#include "ui_ReportsPage.h"

#include <QTableWidgetItem>
#include <QColor>

static QTableWidgetItem* colorItem(const QString &text, const QString &hex)
{
    auto *item = new QTableWidgetItem(text);
    item->setForeground(QColor(hex));
    return item;
}

ReportsPage::ReportsPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ReportsPage)
{
    ui->setupUi(this);
    populateTables();
}

ReportsPage::~ReportsPage()
{
    delete ui;
}

void ReportsPage::populateTables()
{
    // Attendance % report
    {
        QTableWidget *t = ui->tableAttendanceReport;
        struct Row { QString name,roll,attended,total,pct; bool good; };
        QList<Row> rows = {
            {"Krimud Sainju","08","27","31","87%",true},
            {"Alvin Shah","10","28","31","90%",true},
            {"Sanskar Shrestha","23","19","31","61%",false},
            {"Pallav Thani","32","30","31","97%",true},
            {"Bishwo Timalsina","37","27","31","87%",true},
        };
        for (int r = 0; r < rows.size(); ++r) {
            t->setItem(r,0,new QTableWidgetItem(rows[r].name));
            t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
            t->setItem(r,2,new QTableWidgetItem(rows[r].attended));
            t->setItem(r,3,new QTableWidgetItem(rows[r].total));
            t->setItem(r,4,colorItem(rows[r].pct, rows[r].good ? "#2ECC71" : "#E74C3C"));
            t->setRowHeight(r,46);
        }
    }

    // Monthly expenditure report
    {
        QTableWidget *t = ui->tableExpenditureReport;
        struct Row { QString name,roll,txns,spent,balance; };
        QList<Row> rows = {
            {"Krimud Sainju","08","18","Rs. 2,340","Rs. 1,200"},
            {"Alvin Shah","10","12","Rs. 1,580","Rs. 850"},
            {"Sanskar Shrestha","23","9","Rs. 1,120","Rs. 2,100"},
            {"Pallav Thani","32","21","Rs. 2,890","Rs. 500"},
            {"Bishwo Timalsina","37","15","Rs. 1,940","Rs. 1,750"},
        };
        for (int r = 0; r < rows.size(); ++r) {
            t->setItem(r,0,new QTableWidgetItem(rows[r].name));
            t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
            t->setItem(r,2,new QTableWidgetItem(rows[r].txns));
            t->setItem(r,3,colorItem(rows[r].spent, "#F39C12"));
            t->setItem(r,4,colorItem(rows[r].balance, "#2ECC71"));
            t->setRowHeight(r,46);
        }
    }
}
