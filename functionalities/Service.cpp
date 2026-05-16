#include "Service.h"
#include "Exception.h"
#include <ActionAdd.h>
#include <ActionRemove.h>
#include <ActionUpdate.h>

//std::vector<Tutorial> Service::getElements() {
	
//}
const vector<Tutorial>& Service::getTutorials() {
	return this->repository.getTutorials();
}
void Service::add(string title, string presenter, int minutes, int seconds, int likes, string link) {
	this->validate_duration(minutes, seconds);
	Tutorial t{ title, presenter, Duration{minutes, seconds}, likes, link };
	this->repository.add(t);
	unique_ptr<Action> a = make_unique<ActionAdd>(t, repository);
	undoStack.push(move(a));
}


Tutorial Service::find_by_link(string link) {
	vector<Tutorial> tutorials = this->getTutorials();
	for (int i = 0; i < tutorials.size(); i++) {
		if (tutorials[i].get_link() == link) {
			return tutorials[i];
		}
	}
	return Tutorial();
}

vector<Tutorial>& Service::getTutorials_nc()
{
	return this->repository.getTutorials_nc();
}

void Service::remove(string link) {
	
	Tutorial t = this->find_by_link(link);
	this->repository.remove(t);
	unique_ptr<Action> a = make_unique<ActionRemove>(t, repository);
	undoStack.push(move(a));
}

void Service::update(string old_link, string title, string presenter, int minutes, int seconds, int likes, string link) {
	this->validate_duration(minutes, seconds);

	Tutorial t_new = { title, presenter, Duration{minutes, seconds}, likes, link };
	Tutorial t_old = this->find_by_link(old_link);
	this->repository.update(t_old, t_new);
	unique_ptr<Action> a = make_unique<ActionUpdate>(t_new, t_old, repository);
	undoStack.push(move(a));
}

void Service::validate_duration(int minutes, int seconds)
{
	if (minutes < 0 || seconds < 0 || seconds > 59)
	{
		throw RepositoryException("Invalid duration!");
	}
}

void Service::undo()
{
	if (undoStack.empty())
		throw RepositoryException("Cannot perform undo. ");
	this->undoStack.top()->executeUndo();
	unique_ptr<Action> a = move(undoStack.top());
	undoStack.pop();
	redoStack.push(move(a));
}
void Service::redo()
{
	if (redoStack.empty())
		throw RepositoryException("Cannot perform undo. ");
	this->redoStack.top()->executeRedo();
	unique_ptr<Action> a = move(redoStack.top());
	this->redoStack.pop();
	
	undoStack.push(move(a));

}