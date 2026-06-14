#include "LoginPage.h"
#include "ui_LoginPage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->pushButtonSignIn, &QPushButton::clicked, this, &LoginPage::onLoginClicked);
    connect(ui->lineEditUsername, &QLineEdit::returnPressed, this, &LoginPage::onLoginClicked);
    connect(ui->lineEditPassword, &QLineEdit::returnPressed, this, &LoginPage::onLoginClicked);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::onLoginClicked()
{
    QString user = ui->lineEditUsername->text().trimmed();
    QString pass = ui->lineEditPassword->text();

    if (user.isEmpty() || pass.isEmpty()) {
        ui->labelError->setText("Please enter both username and password.");
        return;
    }

    if (validateCredentials(user, pass)) {
        ui->labelError->setText("");
        ui->lineEditUsername->clear();
        ui->lineEditPassword->clear();
        emit loginSuccess();
    } else {
        ui->labelError->setText("Invalid username or password.");
        ui->lineEditPassword->clear();
    }
}

bool LoginPage::validateCredentials(const QString &username, const QString &password)
{
    // TODO: Replace with real MySQL authentication
    return (username == "admin" && password == "admin123");
}
