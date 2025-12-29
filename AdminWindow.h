#pragma once
#include <QWidget>
#include <QLabel>
#include "functionalities/Service.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QComboBox>

class AdminWindow : public QWidget {
    Q_OBJECT

public:
     AdminWindow(Service& service, QWidget* parent = nullptr);

private:
    Service& service;

    QPushButton* addButton;
    QPushButton* removeButton;
    QPushButton* updateButton;
    QPushButton* viewButton;
    QListWidget* tutorialList;
    QComboBox* displayModeCombo;
    bool detailedView = true;
    void refreshTutorialList();

private slots:
    void handleAdd();
    void handleRemove();
    void handleUpdate();
    void handleViewAll();
    void handleDisplayModeChanged(int index);
};
