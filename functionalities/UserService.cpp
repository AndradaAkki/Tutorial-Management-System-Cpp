#include "UserService.h"
#include <iostream>

void UserService::display_videos_from_presenter(string presenter, int command)
{
	if (presenter == "")
	{
		vector<Tutorial> myTutorials = this->repository.getTutorials();
		for (int i = 0; i < myTutorials.size(); i++)
		{
			
			string link = myTutorials[i].get_link();
			open_link(link);
			
			if (command == 1)
			{
				this->watchLater.push_back(myTutorials[i]);
				
			}
			else if (command == 0)
			{
				
			}
			else
			{
				
			}

			
		}
	}
	else
	{
		vector<Tutorial> myTutorials = this->repository.getTutorials();
		for (int i = 0; i < myTutorials.size(); i++)
		{
			if (myTutorials[i].get_presenter() == presenter)
			{
				string link = myTutorials[i].get_link();
				open_link(link);

				if (command == 1)
				{
					this->watchLater.push_back(myTutorials[i]);

				}
				else if (command == 0)
				{

				}
				else
				{

				}
			}
		}
	}
}

void UserService::open_link(string& link){
	QUrl url(QString::fromStdString(link));
	QDesktopServices::openUrl(url);
}
const vector<Tutorial>& UserService::getWatchLater() {
	return this->watchLater;
}

void UserService::delete_tutorial_s(string link, int ans)
{
	
	for (int i = 0; i < this->watchLater.size(); i++)
	{
		if (this->watchLater[i].get_link() == link)
		{
			vector<Tutorial> tutorials = this->repository.getTutorials();
			for (int j = 0; j < tutorials.size(); j++) {
				if (tutorials[j].get_link() == link) {
					//cout << "Do you wish to like the video?\n";
					//cout << "1 - Yes\n";
					//cout << "0 - No\n";
					//string ans;
					//cin.ignore();
					//cin >> ans;
					if (ans == 1) {
						Tutorial old_tutorial = tutorials[j];
						string presenter = old_tutorial.get_presenter();
						string title = old_tutorial.get_title();
						int likes = old_tutorial.get_likes();
						string link = old_tutorial.get_link();
						int minutes = old_tutorial.get_minutes();
						int seconds = old_tutorial.get_seconds();
						Tutorial new_tutorial{ title, presenter, { minutes, seconds },likes + 1, link };
						this->repository.update(tutorials[j], new_tutorial);
						
						this->watchLater.erase(this->watchLater.begin() + i);
						break;
					}
					else if (ans == 0) {
						//cout << "Video not liked!\n";
						this->watchLater.erase(this->watchLater.begin() + i);
						break;
					}
					else {
						//cout << "Invalid command!\n";
						break;
					}
				}
			}
			
		}
	}
}

vector<Tutorial>& UserService::getWatchLater_nc()
{
	return this->watchLater;
}

vector<Tutorial>& UserService::getWatchLater_c() const
{
	return const_cast<vector<Tutorial>&>(this->watchLater); 
}

std::vector<Tutorial> UserService::getAllTutorials() {
    return repository.getTutorials();
}

void UserService::display_single_tutorial_decision(const Tutorial& t, int command) {
	string link = t.get_link_c();
    
    if (command == 1) {
        this->watchLater.push_back(t);
    }
}
