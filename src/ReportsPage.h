#ifndef REPORTSPAGE_H
#define REPORTSPAGE_H

#include <QWidget>

namespace Ui { class ReportsPage; }

class ReportsPage : public QWidget
{
    Q_OBJECT
public:
    explicit ReportsPage(QWidget *parent = nullptr);
    ~ReportsPage();

private:
    void populateTables();
    Ui::ReportsPage *ui;
};

#endif
