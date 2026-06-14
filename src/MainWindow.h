#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

class LoginPage;
class DashboardPage;
// ADD NEW PAGES: class ReportsPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum Page { LOGIN = 0, DASHBOARD = 1 };

    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void goToDashboard();
    void goToLogin();

private:
    QStackedWidget  *m_stack;
    LoginPage       *m_loginPage;
    DashboardPage   *m_dashboardPage;
};

#endif
