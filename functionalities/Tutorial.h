#pragma once
#include <string>

using namespace std;

struct Duration {
public:
	int minutes;
	int seconds;
	Duration(int minutes = 0, int seconds = 0) : minutes{ minutes }, seconds{ seconds } {};
};

class Tutorial {
private:
	string title;
	string presenter;
	Duration duration;
	int likes;
	string link;
public:
	friend std::ostream& operator<<(std::ostream& out, const Tutorial& t);
	friend std::istream& operator>>(std::istream& in, Tutorial& t);
	
	Tutorial(string title, string presenter, const Duration& duration, int likes, string link);
	Tutorial();
	std::string get_link_const() const;
	std::string get_link();
	std::string get_title_c() const { return this->title; }
	std::string get_link_c() const { return this->link; }
	std::string get_duration_c() const {
		int a = this->duration.minutes;
		std::string str = std::to_string(a);
		int b = this->duration.seconds;
		std::string str2 = std::to_string(b);
		std::string str3 = str + ":" + str2;
		return str3;
	}
	std::string get_presenter_c() const { return this->presenter; }
	int get_minutes_c() const { return this->duration.minutes; }
	int get_seconds_c() const { return this->duration.seconds; }
	int get_likes_c() const { return this->likes; }

	std::string getString();
	std::string get_presenter() { return this->presenter; }
	std::string get_title() { return this->title; }
	int get_likes() { return this->likes; }
	int get_minutes() { return this->duration.minutes; }
	int get_seconds() { return this->duration.seconds; }
	std::string getTitle() const { return this->title; }
	std::string getPresenter() const { return this->presenter; }
	std::string getLink() const { return this->link; }
	std::string getDuration() const {
		return std::to_string(duration.minutes) + ":" + std::to_string(duration.seconds);
	}
	int getLikes() const { return this->likes; }
	int getMinutes() const { return this->duration.minutes; }
	int getSeconds() const { return this->duration.seconds; }
};