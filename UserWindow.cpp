#include "UserWindow.h"
#include <QInputDialog>
#include <QMessageBox>

#include <QLinearGradient> 

UserWindow::UserWindow(UserService& service, QWidget* parent)
   : QWidget(parent), service(service)
{

   QLinearGradient gradient(0, 0, 400, 300); 
   gradient.setColorAt(0.0, QColor(255, 154, 158));
   gradient.setColorAt(1.0, QColor(254, 207, 239));

   QPalette pal = this->palette();
   pal.setBrush(QPalette::Window, QBrush(gradient));
   this->setAutoFillBackground(true);
   this->setPalette(pal);

   this->setWindowTitle("User Mode");
   this->resize(400, 300);

   auto* layout = new QVBoxLayout(this);

   removeButton = new QPushButton("Remove Tutorial");
   displayFromPresentorButton = new QPushButton("Present Tutorial");
   tutorialList = new QListWidget(this);

   displayModeCombo = new QComboBox(this);
   displayModeCombo->addItem("Tutorial List");
   displayModeCombo->addItem("Watch Later List");

   layout->addWidget(displayFromPresentorButton);
   layout->addWidget(removeButton);
   layout->addWidget(displayModeCombo);

   connect(displayModeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &UserWindow::handleDisplayModeChanged_u);
   connect(removeButton, &QPushButton::clicked, this, &UserWindow::handleRemove_u);
   connect(displayFromPresentorButton, &QPushButton::clicked, this, &UserWindow::handledisplayFromPresentor);

   initialiseTutorialList();
   layout->addWidget(tutorialList);
}

void UserWindow::handledisplayFromPresentor() {
    
    QString qpresenter = QInputDialog::getText(this, "Presenter Name", "Enter presenter name (leave empty for all):");
    std::string presenter = qpresenter.toStdString();

   
    std::vector<Tutorial> tutorials = service.getAllTutorials(); // You'll need to implement this if not already present

   
    for (const auto& tutorial : tutorials) {
        if (presenter.empty() || tutorial.get_presenter_c() == presenter) {
            
            std::string link = tutorial.get_link_c();
            service.open_link(link);  

            
            QString info = QString("Title: %1\nPresenter: %2\nDuration: %3:%4\nLikes: %5\nLink: %6\n\nDo you wish to add this tutorial to the watch list?")
                .arg(QString::fromStdString(tutorial.get_title_c()))
                .arg(QString::fromStdString(tutorial.get_presenter_c()))
                .arg(tutorial.get_minutes_c())
                .arg(tutorial.get_seconds_c())
                .arg(tutorial.get_likes_c())
                .arg(QString::fromStdString(tutorial.get_link_c()));

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Add to Watch List", info, QMessageBox::Yes | QMessageBox::No);

            int command = (reply == QMessageBox::Yes) ? 1 : 0;
            
            service.display_single_tutorial_decision(tutorial, command);
        }
    }
}
void UserWindow::handleRemove_u()
{
	QString link = QInputDialog::getText(this, "Remove", "Enter link of tutorial to remove:");
	if (link.isEmpty()) {
		QMessageBox::warning(this, "Error", "Link cannot be empty!");
		return;
	}
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Like", "Like thi video :'< ? ", QMessageBox::Yes | QMessageBox::No);
    int command = (reply == QMessageBox::Yes) ? 1 : 0;
	service.delete_tutorial_s(link.toStdString(), command); 
	initialiseTutorialList();
}

void UserWindow::handleDisplayModeChanged_u(int index)
{
	if (index == 0) {
		watchListView = true;
	}
	else {
		watchListView = false;
	}
	initialiseTutorialList();
}

void UserWindow::initialiseTutorialList()
{
	if (watchListView) {
	tutorialList->clear();
	for (const auto& t : service.getAllTutorials()) {
		tutorialList->addItem(QString::fromStdString(
			t.get_title_c() + " | " + t.get_presenter_c() + " | " +
			std::to_string(t.get_minutes_c()) + ":" +
			std::to_string(t.get_seconds_c()) + " | Likes: " +
			std::to_string(t.get_likes_c()) + " | " + t.get_link_c()
		));
	}
	}
    else {
        tutorialList->clear();
        for (const auto& t : service.getWatchLater()) {
            tutorialList->addItem(QString::fromStdString(
                t.get_title_c() + " | " + t.get_presenter_c() + " | " +
                std::to_string(t.get_minutes_c()) + ":" +
                std::to_string(t.get_seconds_c()) + " | Likes: " +
                std::to_string(t.get_likes_c()) + " | " + t.get_link_c()
            ));
        }
    }
}


