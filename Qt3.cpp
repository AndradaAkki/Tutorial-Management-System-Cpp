
#include "Qt3.h"
#include <QApplication>
#include <QMessageBox>
#include "AdminWindow.h"
#include "UserWindow.h"
Qt3::Qt3(Service& service, UserService& service_u, QWidget* parent)
    : QMainWindow(parent), serv(service), serv_u(service_u)
{
    this->setWindowTitle("Qt3 Example - Main Menu");
    this->resize(300, 150);

    
    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    
    auto* adminButton = new QPushButton("Admin");
    auto* userButton = new QPushButton("User");
    auto* exitButton = new QPushButton("Exit");

    layout->addWidget(adminButton);
    layout->addWidget(userButton);
    layout->addWidget(exitButton);

    
    this->setCentralWidget(centralWidget);

   
    connect(adminButton, &QPushButton::clicked, this, [=]() {
        AdminWindow* adminWin = new AdminWindow(serv);
        adminWin->show();
        });

    connect(userButton, &QPushButton::clicked, this, [=]() {
        UserWindow* userWin = new UserWindow(serv_u);
        userWin->show();
        });

    connect(exitButton, &QPushButton::clicked, []() {
        QApplication::quit();
        });
}


void Qt3::onMyButtonClicked()
{
    QMessageBox::information(this, "Hello", "Hello from onMyButtonClicked()");
}