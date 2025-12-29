#pragma once

#include <QWidget>
#include <QLabel>
#include "functionalities/Service.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QComboBox>
#include <functionalities/UserService.h>

class UserWindow : public QWidget {
Q_OBJECT

public:

UserWindow(UserService& service, QWidget* parent = nullptr);

private:
UserService& service;

QPushButton* removeButton;
QPushButton* displayFromPresentorButton;
QListWidget* tutorialList;
QComboBox* displayModeCombo;
bool watchListView = true;


private slots:

void handleRemove_u();
void handledisplayFromPresentor() ;
void handleDisplayModeChanged_u(int index);
void initialiseTutorialList();
};