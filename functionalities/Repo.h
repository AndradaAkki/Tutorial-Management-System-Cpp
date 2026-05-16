#pragma once
#include <vector>
#include "Tutorial.h"

class Repo {
private:
	std::vector<Tutorial> elements;
	std::string filename;

public:
	Repo(const std::string& file);
	~Repo();

	void load_from_file();
	void save_to_file();
	void add(const Tutorial& t);
	//Add a tutorial to the repository
	//Input: t - Tutorial

	const vector<Tutorial>& getTutorials();
	//Get all the tutorials from the repository
	//Output: a dynamic array of tutorials
	vector<Tutorial>& getTutorials_nc();
	
	void remove(const Tutorial& t);
	//Remove a tutorial from the repository
	//Input: t - Tutorial
	

	int find(const Tutorial& t);
	//Find a tutorial in the repository
	//Input: t - Tutorial
	//Output: the position of the tutorial in the repository, -1 if the tutorial is not in the repository
	int find_by_link(string link);
	void update(const Tutorial& t_old, const Tutorial& t_new);
	//Update a tutorial from the repository
	//Input: t_old - Tutorial, t_new - Tutorial
};