#include "DashboardPage.h"
#include "ui_DashboardPage.h"

#include "OverviewPage.h"
#include "AttendancePage.h"
#include "CafeteriaPage.h"
#include "StudentsPage.h"
#include "ReportsPage.h"
#include "RegisterCardPage.h"
#include "ScanTerminalPage.h"
// ADD NEW PAGE INCLUDES HERE

#include <QDateTime>
#include <QPushButton>

DashboardPage::DashboardPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::DashboardPage)
{
    ui->setupUi(this);

    ui->labelTopDate->setText(QDateTime::currentDateTime().toString("ddd, dd MMM yyyy"));

    setupPages();
    wireNav();

    connect(ui->pushButtonLogout, &QPushButton::clicked, this, &DashboardPage::logoutRequested);
}

DashboardPage::~DashboardPage()
{
    delete ui;
}

// ── Instantiate each page and add it to the stacked widget ──────────────────
void DashboardPage::setupPages()
{
    m_overviewPage   = new OverviewPage(this);
    m_attendancePage = new AttendancePage(this);
    m_cafeteriaPage  = new CafeteriaPage(this);
    m_studentsPage   = new StudentsPage(this);
    m_reportsPage    = new ReportsPage(this);
    m_registerPage   = new RegisterCardPage(this);
    m_scanPage       = new ScanTerminalPage(this);

    ui->stackedWidget->addWidget(m_overviewPage);   // index 0
    ui->stackedWidget->addWidget(m_attendancePage); // index 1
    ui->stackedWidget->addWidget(m_cafeteriaPage);  // index 2
    ui->stackedWidget->addWidget(m_studentsPage);   // index 3
    ui->stackedWidget->addWidget(m_reportsPage);    // index 4
    ui->stackedWidget->addWidget(m_registerPage);   // index 5
    ui->stackedWidget->addWidget(m_scanPage);       // index 6
    // ADD NEW PAGES HERE: ui->stackedWidget->addWidget(m_newPage); // index 7

    ui->stackedWidget->setCurrentWidget(m_overviewPage);
}

// ── Sidebar navigation wiring ─────────────────────────────────────────────────
void DashboardPage::wireNav()
{
    connect(ui->navBtnOverview,   &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnAttendance, &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnCafeteria,  &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnStudents,   &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnReports,    &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnRegister,   &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    connect(ui->navBtnScan,       &QPushButton::clicked, this, &DashboardPage::onNavClicked);
    // ADD NEW NAV BUTTON CONNECTIONS HERE
}

void DashboardPage::onNavClicked()
{
    QObject *sender_ = sender();

    ui->navBtnOverview->setChecked(sender_ == ui->navBtnOverview);
    ui->navBtnAttendance->setChecked(sender_ == ui->navBtnAttendance);
    ui->navBtnCafeteria->setChecked(sender_ == ui->navBtnCafeteria);
    ui->navBtnStudents->setChecked(sender_ == ui->navBtnStudents);
    ui->navBtnReports->setChecked(sender_ == ui->navBtnReports);
    ui->navBtnRegister->setChecked(sender_ == ui->navBtnRegister);
    ui->navBtnScan->setChecked(sender_ == ui->navBtnScan);
    // ADD NEW NAV BUTTONS HERE

    if (sender_ == ui->navBtnOverview)        ui->stackedWidget->setCurrentWidget(m_overviewPage);
    else if (sender_ == ui->navBtnAttendance) ui->stackedWidget->setCurrentWidget(m_attendancePage);
    else if (sender_ == ui->navBtnCafeteria)  ui->stackedWidget->setCurrentWidget(m_cafeteriaPage);
    else if (sender_ == ui->navBtnStudents)   ui->stackedWidget->setCurrentWidget(m_studentsPage);
    else if (sender_ == ui->navBtnReports)    ui->stackedWidget->setCurrentWidget(m_reportsPage);
    else if (sender_ == ui->navBtnRegister)   ui->stackedWidget->setCurrentWidget(m_registerPage);
    else if (sender_ == ui->navBtnScan)       ui->stackedWidget->setCurrentWidget(m_scanPage);
    // ADD NEW PAGE SWITCHES HERE
}
