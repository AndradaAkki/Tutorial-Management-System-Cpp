#pragma once
#pragma once
#include "Action.h"

#include <string>
#include <functionalities/Tutorial.h>
#include <functionalities/Repo.h>

class ActionUpdate : public Action {

private:
	Tutorial addedTutorial;
	Tutorial deletedTutorial;
	Repo& repo;

public:
	ActionUpdate(Tutorial s1, Tutorial s2, Repo& r) : addedTutorial{ s1 }, deletedTutorial{ s2 }, repo{ r } {}
	virtual void executeUndo() override {
		repo.remove(addedTutorial);
		repo.add(deletedTutorial);

	}
	virtual void executeRedo() override {
		repo.remove(deletedTutorial);
		repo.add(addedTutorial);
	}
};