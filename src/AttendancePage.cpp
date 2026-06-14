#include "AttendancePage.h"
#include "ui_AttendancePage.h"

#include <QTableWidgetItem>
#include <QColor>

static QTableWidgetItem* colorItem(const QString &text, const QString &hex)
{
    auto *item = new QTableWidgetItem(text);
    item->setForeground(QColor(hex));
    return item;
}

AttendancePage::AttendancePage(QWidget *parent)
    : QWidget(parent), ui(new Ui::AttendancePage)
{
    ui->setupUi(this);
    populateTable();
}

AttendancePage::~AttendancePage()
{
    delete ui;
}

void AttendancePage::populateTable()
{
    QTableWidget *t = ui->tableAttendance;
    struct Row { QString name,roll,status,time,sess; bool present; };
    QList<Row> rows = {
        {"Krimud Sainju","08","Present","09:02 AM","3/4",true},
        {"Alvin Shah","10","Present","09:05 AM","3/4",true},
        {"Sanskar Shrestha","23","Absent","—","0/4",false},
        {"Pallav Thani","32","Present","09:08 AM","4/4",true},
        {"Bishwo Timalsina","37","Present","09:12 AM","3/4",true},
    };
    for (int r = 0; r < rows.size(); ++r) {
        t->setItem(r,0,new QTableWidgetItem(rows[r].name));
        t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
        t->setItem(r,2,colorItem(rows[r].status, rows[r].present ? "#2ECC71" : "#E74C3C"));
        t->setItem(r,3,new QTableWidgetItem(rows[r].time));
        t->setItem(r,4,new QTableWidgetItem(rows[r].sess));
        t->setRowHeight(r,46);
    }
}
