#include "Repo.h"

#include <fstream>
#include <sstream>
#include "Exception.h"

Repo::Repo(const std::string& file) : filename(file) {
	load_from_file();
}

Repo::~Repo() {
	save_to_file();
}

void Repo::load_from_file() {
	std::ifstream in(this->filename);
	if (!in.is_open()) return;

	Tutorial t;
	while (in >> t) {
		this->elements.push_back(t);
	}
	in.close();
}

void Repo::save_to_file() {
	std::ofstream out(this->filename);
	for (const auto& t : this->elements) {
		out << t;
	}
	out.close();
}


void Repo::add(const Tutorial& t) {
	int pos;
	pos = this->find(t);
	if (pos == -1) {
		this->elements.push_back(t);
		save_to_file();
	}
	else
		throw RepositoryException("The tutorial already exists in the repository!");
}


const vector<Tutorial>& Repo::getTutorials() {
	return this->elements;
}

int Repo::find(const Tutorial& t) {
	for (int i = 0; i < this->elements.size(); i++)
	{
		if (this->elements[i].get_link() == t.get_link_const())
		{
			return i;
		}
	}
	return -1;
}

vector<Tutorial>& Repo::getTutorials_nc()
{
	return this->elements;
}

void Repo::remove(const Tutorial& t) {
	int pos;
	pos = this->find(t);
	if (pos != -1)
	{
		this->elements.erase(this->elements.begin() + pos);
	}
	else
		throw RepositoryException("The tutorial does not exist in the repository!");
	save_to_file();

}

int Repo::find_by_link(string link)
{
	for (int i = 0; i < this->elements.size(); i++)
	{
		if (this->elements[i].get_link() == link)
		{
			return i;
		}
	}
	return -1;
}

void Repo::update(const Tutorial& t_old, const Tutorial& t_new) {
	int pos;
	pos = this->find(t_old);
	if (pos != -1)
	{
		this->elements[pos] = t_new;
	}
	else
		throw RepositoryException("The tutorial does not exist in the repository!");
	save_to_file();

}