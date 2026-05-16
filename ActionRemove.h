#pragma once

#include "Action.h"

#include <string>
#include <functionalities/Tutorial.h>
#include <functionalities/Repo.h>

class ActionRemove : public Action {

private:
	Tutorial addedTutorial;
	Repo& repo;

public:
	ActionRemove(Tutorial s, Repo& r) : addedTutorial{ s }, repo{ r } {}
	virtual void executeUndo() override {
		repo.add(addedTutorial);

	}
	virtual void executeRedo() override {
		repo.remove(addedTutorial);
	}
};