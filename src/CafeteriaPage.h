#ifndef CAFETERIAPAGE_H
#define CAFETERIAPAGE_H

#include <QWidget>

namespace Ui { class CafeteriaPage; }

class CafeteriaPage : public QWidget
{
    Q_OBJECT
public:
    explicit CafeteriaPage(QWidget *parent = nullptr);
    ~CafeteriaPage();

private:
    void populateTable();
    Ui::CafeteriaPage *ui;
};

#endif
