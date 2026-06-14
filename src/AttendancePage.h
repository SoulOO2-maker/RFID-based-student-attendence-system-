#ifndef ATTENDANCEPAGE_H
#define ATTENDANCEPAGE_H

#include <QWidget>

namespace Ui { class AttendancePage; }

class AttendancePage : public QWidget
{
    Q_OBJECT
public:
    explicit AttendancePage(QWidget *parent = nullptr);
    ~AttendancePage();

private:
    void populateTable();
    Ui::AttendancePage *ui;
};

#endif
