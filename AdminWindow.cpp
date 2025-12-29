#include "AdminWindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <functionalities/Exception.h>

AdminWindow::AdminWindow(Service& service, QWidget* parent)
    : QWidget(parent), service(service)
{
    this->setWindowTitle("Admin Mode");
    this->resize(400, 300);

    auto* layout = new QVBoxLayout(this);

    addButton = new QPushButton("Add Tutorial");
    removeButton = new QPushButton("Remove Tutorial");
    updateButton = new QPushButton("Update Tutorial");

    tutorialList = new QListWidget(this);

    layout->addWidget(addButton);
    layout->addWidget(removeButton);
    layout->addWidget(updateButton);
   
    

    displayModeCombo = new QComboBox(this);
    displayModeCombo->addItem("Detailed View");
    displayModeCombo->addItem("Short View");
    layout->addWidget(displayModeCombo);

	connect(displayModeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AdminWindow::handleDisplayModeChanged);
    connect(addButton, &QPushButton::clicked, this, &AdminWindow::handleAdd);
    connect(removeButton, &QPushButton::clicked, this, &AdminWindow::handleRemove);
    connect(updateButton, &QPushButton::clicked, this, &AdminWindow::handleUpdate);

    layout->addWidget(tutorialList);



    refreshTutorialList();
}

void AdminWindow::refreshTutorialList() {
    tutorialList->clear();
    if (detailedView) {
        for (const auto& t : service.getTutorials()) {
            tutorialList->addItem(QString::fromStdString(
                t.get_title_c() + " | " + t.get_presenter_c() + " | " +
                std::to_string(t.get_minutes_c()) + ":" +
                std::to_string(t.get_seconds_c()) + " | Likes: " +
                std::to_string(t.get_likes_c()) + " | " + t.get_link_c()
            ));
        }
    }
    else {
        for (const auto& t : service.getTutorials()) {
            tutorialList->addItem(QString::fromStdString(
                t.get_title_c() + " | " + t.get_presenter_c()
            ));
        }
    }
}

void AdminWindow::handleAdd() {
    try {
        QString title = QInputDialog::getText(this, "Add", "Title:");
        QString presenter = QInputDialog::getText(this, "Add", "Presenter:");
        int minutes = QInputDialog::getInt(this, "Add", "Minutes:");
        int seconds = QInputDialog::getInt(this, "Add", "Seconds:");
        int likes = QInputDialog::getInt(this, "Add", "Likes:");
        QString link = QInputDialog::getText(this, "Add", "Link:");

        service.add(title.toStdString(), presenter.toStdString(), minutes, seconds, likes, link.toStdString());
        refreshTutorialList();
    }
    catch (RepositoryException& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdminWindow::handleRemove() {
    QString link = QInputDialog::getText(this, "Remove", "Enter link of tutorial to remove:");
    try {
        service.remove(link.toStdString());
        refreshTutorialList();
    }
	catch (RepositoryException& e) {
		QMessageBox::warning(this, "Error", e.what());
	}
	catch (const std::exception& e) {
		QMessageBox::warning(this, "Error", e.what());
	}
    catch (...) {
        QMessageBox::warning(this, "Error", "An unknown error occurred.");
    }
}

void AdminWindow::handleUpdate() {
    QString oldLink = QInputDialog::getText(this, "Update", "Old Link:");
    QString title = QInputDialog::getText(this, "Update", "New Title:");
    QString presenter = QInputDialog::getText(this, "Update", "New Presenter:");
    int minutes = QInputDialog::getInt(this, "Update", "New Minutes:");
    int seconds = QInputDialog::getInt(this, "Update", "New Seconds:");
    int likes = QInputDialog::getInt(this, "Update", "New Likes:");
    QString newLink = QInputDialog::getText(this, "Update", "New Link:");

    try {
        service.update(oldLink.toStdString(), title.toStdString(), presenter.toStdString(),
            minutes, seconds, likes, newLink.toStdString());
        refreshTutorialList();
	}
	catch (RepositoryException& e) {
		QMessageBox::warning(this, "Error", e.what());
	}
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdminWindow::handleViewAll() {
    refreshTutorialList();
}

void AdminWindow::handleDisplayModeChanged(int index)
{
	if (index == 0) {
		detailedView = true;
	}
	else {
		detailedView = false;
	}
	refreshTutorialList();
}
