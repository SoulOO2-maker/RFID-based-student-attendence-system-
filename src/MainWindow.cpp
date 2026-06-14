#include "MainWindow.h"
#include "LoginPage.h"
#include "DashboardPage.h"

#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("KU RFID — Student Attendance & Cafeteria System");
    setMinimumSize(1100, 700);

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect geo = screen->availableGeometry();
        resize(int(geo.width() * 0.85), int(geo.height() * 0.85));
        move((geo.width() - width()) / 2, (geo.height() - height()) / 2);
    }

    m_stack = new QStackedWidget(this);
    setCentralWidget(m_stack);

    m_loginPage = new LoginPage(this);
    m_dashboardPage = new DashboardPage(this);

    m_stack->addWidget(m_loginPage);     // index 0 -> LOGIN
    m_stack->addWidget(m_dashboardPage); // index 1 -> DASHBOARD
    // ADD NEW PAGES: m_stack->addWidget(m_newPage); // index 2

    connect(m_loginPage, &LoginPage::loginSuccess, this, &MainWindow::goToDashboard);
    connect(m_dashboardPage, &DashboardPage::logoutRequested, this, &MainWindow::goToLogin);

    m_stack->setCurrentIndex(LOGIN);
}

void MainWindow::goToDashboard() { m_stack->setCurrentIndex(DASHBOARD); }
void MainWindow::goToLogin()     { m_stack->setCurrentIndex(LOGIN); }
