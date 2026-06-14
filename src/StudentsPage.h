#ifndef STUDENTSPAGE_H
#define STUDENTSPAGE_H

#include <QWidget>

namespace Ui { class StudentsPage; }

class StudentsPage : public QWidget
{
    Q_OBJECT
public:
    explicit StudentsPage(QWidget *parent = nullptr);
    ~StudentsPage();

private:
    void populateTable();
    Ui::StudentsPage *ui;
};

#endif
