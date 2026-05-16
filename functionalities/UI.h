#pragma once
#include "Service.h"
#include "UserService.h"
class UI {
private:
	void printMenuAdmin();
	void printMenuUser();
	void printAll();
	void add_tutorial();
	void printMenu2();
	void start_admin();
	void start_user();
	void printWatchLater();
	void delete_tutorial();
	Service& service;
	UserService& user_service;
public:
	UI(Service& service, UserService& user_service) : service(service), user_service(user_service) {}
	void start();
	void remove_tutorial();
	void update_tutorial();
	 
};
