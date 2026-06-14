#ifndef DASHBOARDPAGE_H
#define DASHBOARDPAGE_H

#include <QWidget>

namespace Ui { class DashboardPage; }

class OverviewPage;
class AttendancePage;
class CafeteriaPage;
class StudentsPage;
class ReportsPage;
class RegisterCardPage;
class ScanTerminalPage;
// ADD NEW PAGE CLASSES HERE

class DashboardPage : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardPage(QWidget *parent = nullptr);
    ~DashboardPage();

signals:
    void logoutRequested();

private slots:
    void onNavClicked();

private:
    void wireNav();
    void setupPages();

    Ui::DashboardPage *ui;

    OverviewPage     *m_overviewPage;
    AttendancePage   *m_attendancePage;
    CafeteriaPage    *m_cafeteriaPage;
    StudentsPage     *m_studentsPage;
    ReportsPage      *m_reportsPage;
    RegisterCardPage *m_registerPage;
    ScanTerminalPage *m_scanPage;
    // ADD NEW PAGE POINTERS HERE
};

#endif
