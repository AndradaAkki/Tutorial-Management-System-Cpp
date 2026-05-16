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
   

   

   layout->addWidget(displayFromPresentorButton);
   layout->addWidget(removeButton);
  

   
   connect(removeButton, &QPushButton::clicked, this, &UserWindow::handleRemove_u);
   connect(displayFromPresentorButton, &QPushButton::clicked, this, &UserWindow::handledisplayFromPresentor);


  
   


   

   layout->addWidget(tableView); 
   refreshTutorialList(); 
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
	refreshTutorialList(); 
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
	refreshTutorialList(); 
}

void UserWindow::refreshTutorialList()
{
    // Close old window if open
    if (tableWindow) {
        tableWindow->close();
        delete tableWindow;
        tableWindow = nullptr;
        externalTableView = nullptr;
        externalTableModel = nullptr;
    }

    openTableWindow(); 
}

void UserWindow::openTableWindow() {
    tableWindow = new QWidget;
    tableWindow->setWindowTitle("Watch Later List");
    tableWindow->resize(600, 400);

    QVBoxLayout* layout = new QVBoxLayout(tableWindow);
    externalTableView = new QTableView(tableWindow);
    externalTableModel = new TutorialTableModel(service.getWatchLater());

    externalTableView->setModel(externalTableModel);
    externalTableView->resizeColumnsToContents();

    layout->addWidget(externalTableView);
    tableWindow->setLayout(layout);

    tableWindow->show();
}
