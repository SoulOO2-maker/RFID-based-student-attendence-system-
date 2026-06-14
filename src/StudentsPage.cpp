#include "StudentsPage.h"
#include "ui_StudentsPage.h"

#include <QTableWidgetItem>
#include <QColor>
#include <QFont>

static QTableWidgetItem* colorItem(const QString &text, const QString &hex)
{
    auto *item = new QTableWidgetItem(text);
    item->setForeground(QColor(hex));
    return item;
}

StudentsPage::StudentsPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentsPage)
{
    ui->setupUi(this);
    populateTable();
}

StudentsPage::~StudentsPage()
{
    delete ui;
}

void StudentsPage::populateTable()
{
    QTableWidget *t = ui->tableStudents;
    struct Row { QString name,roll,rfid,bal,att; bool good; };
    QList<Row> rows = {
        {"Krimud Sainju","08","A1B2C3D4","Rs. 1,200","87%",true},
        {"Alvin Shah","10","E5F6G7H8","Rs. 850","91%",true},
        {"Sanskar Shrestha","23","I9J0K1L2","Rs. 2,100","62%",false},
        {"Pallav Thani","32","M3N4O5P6","Rs. 500","95%",true},
        {"Bishwo Timalsina","37","Q7R8S9T0","Rs. 1,750","88%",true},
    };
    QFont mono("Courier New");
    for (int r = 0; r < rows.size(); ++r) {
        t->setItem(r,0,new QTableWidgetItem(rows[r].name));
        t->setItem(r,1,new QTableWidgetItem(rows[r].roll));
        auto *rfidItem = colorItem(rows[r].rfid, "#3498DB");
        rfidItem->setFont(mono);
        t->setItem(r,2,rfidItem);
        t->setItem(r,3,new QTableWidgetItem(rows[r].bal));
        t->setItem(r,4,colorItem(rows[r].att, rows[r].good ? "#2ECC71" : "#E74C3C"));
        t->setRowHeight(r,46);
    }
}
