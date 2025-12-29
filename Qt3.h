#pragma once  
#include <QMainWindow>  
#include <QPushButton>  
#include <QVBoxLayout>  
#include <QWidget>  
#include "functionalities/Service.h"  
#include <functionalities/UserService.h>  

class Qt3 : public QMainWindow {  
   Q_OBJECT  

public:  
   Qt3(Service& service, UserService& service_u, QWidget* parent = nullptr);  

private slots:  
   void onMyButtonClicked();  

private:  
   QPushButton* myButton;  
   Service& serv;  
   UserService& serv_u;
};