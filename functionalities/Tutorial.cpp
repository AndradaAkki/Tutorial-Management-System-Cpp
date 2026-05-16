#define _CRT_SECURE_NO_WARNINGS
#include "Tutorial.h"
#include <iostream>   
#include <sstream> 

Tutorial::Tutorial(string title, string presenter, const Duration& duration, int likes, string link) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
	
}

Tutorial::Tutorial() {
	this->title[0] = '\0';
	this->presenter[0] = '\0';
	this->duration = Duration();
	this->likes = 0;
	this->link[0] = '\0';
}
string Tutorial::getString() {
	string myString{ "" };
	myString += this->title;
	myString += " ";
	myString += this->presenter;
	myString += " ";
	myString += to_string(this->duration.minutes);
	myString += ":";
	myString += to_string(this->duration.seconds);
	myString += " ";
	myString += to_string(this->likes);
	myString += " ";
	myString += this->link;

	return myString;
}
string Tutorial::get_link() {
	return this->link;

}
string Tutorial::get_link_const() const {
	return this->link;
}

std::ostream& operator<<(std::ostream& out, const Tutorial& t) {
	out << t.title << "\n"
		<< t.presenter << "\n"
		<< t.duration.minutes << " " << t.duration.seconds << "\n"
		<< t.likes << "\n"
		<< t.link << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Tutorial& t) {
	std::string minutes_seconds_line;

	std::getline(in, t.title);
	std::getline(in, t.presenter);

	// Read "minutes seconds" in one line, then parse
	std::getline(in, minutes_seconds_line);
	std::istringstream timeStream(minutes_seconds_line);
	timeStream >> t.duration.minutes >> t.duration.seconds;

	in >> t.likes;
	in.ignore(); // skip newline after reading likes
	std::getline(in, t.link);

	return in;
}


