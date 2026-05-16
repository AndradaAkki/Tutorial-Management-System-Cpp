#pragma once
#include "Repo.h"
#include <stack>
#include "Action.h"
#include <memory>

class Service {
private:
	Repo& repository;
	std::stack<std::unique_ptr<Action>> undoStack;
	std::stack<std::unique_ptr<Action>> redoStack;

public:
	Service(Repo& repository) : repository(repository) {}
	//Constructor
	//Input: repository

	void add(string title, string presenter, int minutes, int seconds, int likes, string link);
	//Add a tutorial to the repository
	//Input: title, presenter, minutes, seconds

//	std::vector<Tutorial> getElements();
	//Get all the tutorials from the repository
	//Output: a vector of tutorials

	const vector<Tutorial>& getTutorials();
	//Get all the tutorials from the repository
	//Output: a dynamic array of tutorials
	vector<Tutorial>& getTutorials_nc();

	void remove(string link);
	//Remove a tutorial from the repository
	//Input: link

	Tutorial find_by_link(string link);
	//Find a tutorial in the repository by link
	//Input: link
	//Output: the Tutorial element with the given link

	void update(string old_link, string title, string presenter, int minutes, int seconds, int likes, string link);
	//Update a tutorial from the repository
	//Input: old_link, title, presenter, minutes, seconds, likes, link

	void validate_duration(int minutes, int seconds);
	//Validate the duration of a tutorial

	void undo();
	void redo();
};
