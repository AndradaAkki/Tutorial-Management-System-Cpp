#pragma once

#include <QWidget>
#include <QLabel>
#include "functionalities/Service.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QComboBox>
#include <functionalities/UserService.h>
#include <QTableView>
#include "TutorialTableModel.h"

class UserWindow : public QWidget {
Q_OBJECT

public:

UserWindow(UserService& service, QWidget* parent = nullptr);



private:
UserService& service;
QTableView* tableView;
TutorialTableModel* tableModel;
QPushButton* removeButton;
QPushButton* displayFromPresentorButton;


bool watchListView = true;
QWidget* tableWindow = nullptr;
QTableView* externalTableView = nullptr;
TutorialTableModel* externalTableModel = nullptr;

private slots:

void handleRemove_u();
void handledisplayFromPresentor() ;

void refreshTutorialList();

void openTableWindow();


};