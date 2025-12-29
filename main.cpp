#include "Qt3.h"
#include <QtWidgets/QApplication>

#include "Qt3.h"
#include "functionalities/Service.h"
#include "functionalities/UserService.h"
#include "functionalities/Repo.h"    


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    

    // Initialize the repository
    Repo repo("tutorials.txt");  

    // Initialize the services
    Service service(repo);

    //UserService userService(service);
    UserService user(repo);

  
    Qt3 mainWindow(service,user);
    mainWindow.show();

    return app.exec();
}
