QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += c++17
TARGET    = rfid_system
TEMPLATE  = app
VERSION   = 1.0.0

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/LoginPage.cpp \
    src/DashboardPage.cpp \
    src/OverviewPage.cpp \
    src/AttendancePage.cpp \
    src/CafeteriaPage.cpp \
    src/StudentsPage.cpp \
    src/ReportsPage.cpp \
    src/RegisterCardPage.cpp \
    src/ScanTerminalPage.cpp
    # ADD NEW PAGE SOURCES HERE

HEADERS += \
    src/MainWindow.h \
    src/LoginPage.h \
    src/DashboardPage.h \
    src/OverviewPage.h \
    src/AttendancePage.h \
    src/CafeteriaPage.h \
    src/StudentsPage.h \
    src/ReportsPage.h \
    src/RegisterCardPage.h \
    src/ScanTerminalPage.h
    # ADD NEW PAGE HEADERS HERE

FORMS += \
    ui/LoginPage.ui \
    ui/DashboardPage.ui \
    ui/OverviewPage.ui \
    ui/AttendancePage.ui \
    ui/CafeteriaPage.ui \
    ui/StudentsPage.ui \
    ui/ReportsPage.ui \
    ui/RegisterCardPage.ui \
    ui/ScanTerminalPage.ui
    # ADD NEW .ui FILES HERE

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
