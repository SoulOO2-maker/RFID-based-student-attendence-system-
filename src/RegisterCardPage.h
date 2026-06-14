#ifndef REGISTERCARDPAGE_H
#define REGISTERCARDPAGE_H

#include <QWidget>

namespace Ui { class RegisterCardPage; }

class RegisterCardPage : public QWidget
{
    Q_OBJECT
public:
    explicit RegisterCardPage(QWidget *parent = nullptr);
    ~RegisterCardPage();

private:
    void wireForm();
    Ui::RegisterCardPage *ui;
};

#endif
