#pragma once
#include <memory>
#include "Repo.h"
#include <QDesktopServices>
#include <QUrl>
#include "FileWriter.h"

class UserService {
private:
	Repo& repository;
	vector<Tutorial> watchLater;
	
public:
	UserService(Repo& repository)
		: repository(repository) { }

	
	//Constructor
	//Input: repository
	void display_videos_from_presenter(string presenter, int command);
	//Display all the videos from a given presenter
	//Input: presenter
	void open_link(string& link);
	//Open the link of a tutorial
	const vector<Tutorial>& getWatchLater();
	//Get the watch later list
	void delete_tutorial_s(string link, int ans);
	vector<Tutorial>& getWatchLater_nc();
	vector<Tutorial>& getWatchLater_c() const;
	void display_single_tutorial_decision(const Tutorial& t, int command);
	std::vector<Tutorial> getAllTutorials(); 
	
	

};