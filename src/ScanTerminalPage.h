#ifndef SCANTERMINALPAGE_H
#define SCANTERMINALPAGE_H

#include <QWidget>

namespace Ui { class ScanTerminalPage; }

class ScanTerminalPage : public QWidget
{
    Q_OBJECT
public:
    explicit ScanTerminalPage(QWidget *parent = nullptr);
    ~ScanTerminalPage();

private:
    void wireButtons();
    Ui::ScanTerminalPage *ui;
};

#endif
