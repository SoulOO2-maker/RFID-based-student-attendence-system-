#include "ScanTerminalPage.h"
#include "ui_ScanTerminalPage.h"

ScanTerminalPage::ScanTerminalPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScanTerminalPage)
{
    ui->setupUi(this);
    wireButtons();
}

ScanTerminalPage::~ScanTerminalPage()
{
    delete ui;
}

void ScanTerminalPage::wireButtons()
{
    auto setState = [this](const QString &icon, const QString &msg, const QString &detail,
                            const QString &color, const QString &borderColor) {
        ui->labelStatusIcon->setText(icon);
        ui->labelStatusMessage->setText(msg);
        ui->labelStatusMessage->setStyleSheet(
            QString("color:%1; font-size:28px; font-weight:800; background:transparent; border:none;").arg(color));
        ui->labelStatusDetail->setText(detail);
        ui->scanStatusFrame->setStyleSheet(
            QString("QFrame#scanStatusFrame{background-color:#24243A;border:2px solid %1;border-radius:16px;}").arg(borderColor));
    };

    connect(ui->pushButtonDemoMarked, &QPushButton::clicked, this, [this, setState]() {
        setState("✅", "Attendance Marked", "Krimud Sainju (Roll 08) — 09:02 AM", "#2ECC71", "#2ECC71");
    });
    connect(ui->pushButtonDemoAlready, &QPushButton::clicked, this, [this, setState]() {
        setState("⚠️", "Already Recorded", "Attendance for this session was already marked at 09:02 AM", "#F39C12", "#F39C12");
    });
    connect(ui->pushButtonDemoInvalid, &QPushButton::clicked, this, [this, setState]() {
        setState("❌", "Invalid Card", "Card not recognized — please contact the administrator", "#E74C3C", "#E74C3C");
    });
    connect(ui->pushButtonDemoCafeteria, &QPushButton::clicked, this, [this, setState]() {
        setState("🍽️", "Payment Successful", "Rs. 180 deducted — Remaining balance: Rs. 1,020", "#3498DB", "#3498DB");
    });
    connect(ui->pushButtonDemoReset, &QPushButton::clicked, this, [this, setState]() {
        setState("📡", "Waiting for Card...", "Tap an RFID card on the reader to begin", "#E8E8F0", "#3A3A5A");
    });
}
