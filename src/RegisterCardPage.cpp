#include "RegisterCardPage.h"
#include "ui_RegisterCardPage.h"

#include <QDateTime>

RegisterCardPage::RegisterCardPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::RegisterCardPage)
{
    ui->setupUi(this);
    wireForm();
}

RegisterCardPage::~RegisterCardPage()
{
    delete ui;
}

void RegisterCardPage::wireForm()
{
    connect(ui->pushButtonScanCard, &QPushButton::clicked, this, [this]() {
        // Placeholder: simulate a scanned RFID card ID
        ui->lineEditRfidId->setText("RFID-" + QString::number(QDateTime::currentMSecsSinceEpoch() % 100000000));
        ui->labelRegStatus->setStyleSheet("color:#3498DB; font-size:12px; background:transparent; border:none;");
        ui->labelRegStatus->setText("Card scanned. Fill in the student details and click Save.");
    });

    connect(ui->pushButtonRegisterClear, &QPushButton::clicked, this, [this]() {
        ui->lineEditRfidId->clear();
        ui->lineEditRegName->clear();
        ui->lineEditRegRoll->clear();
        ui->lineEditRegSection->clear();
        ui->lineEditRegBalance->clear();
        ui->labelRegStatus->setText("");
    });

    connect(ui->pushButtonRegisterSave, &QPushButton::clicked, this, [this]() {
        if (ui->lineEditRfidId->text().trimmed().isEmpty() ||
            ui->lineEditRegName->text().trimmed().isEmpty() ||
            ui->lineEditRegRoll->text().trimmed().isEmpty()) {
            ui->labelRegStatus->setStyleSheet("color:#E74C3C; font-size:12px; background:transparent; border:none;");
            ui->labelRegStatus->setText("Please fill in RFID Card ID, Name, and Roll No.");
            return;
        }
        // TODO: Persist to database
        ui->labelRegStatus->setStyleSheet("color:#2ECC71; font-size:12px; background:transparent; border:none;");
        ui->labelRegStatus->setText("Student registered successfully (UI only — not saved).");
    });
}
