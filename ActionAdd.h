#pragma once

#include "Action.h"

#include <string>
#include <functionalities/Tutorial.h>
#include <functionalities/Repo.h>

class ActionAdd : public Action {

private:
	Tutorial addedTutorial;
	Repo& repo;

public:
	ActionAdd(Tutorial s, Repo& r) : addedTutorial{ s }, repo{ r } {}
	virtual void executeUndo() override {
		repo.remove(addedTutorial);
	}
	virtual void executeRedo() override {
		repo.add(addedTutorial);
	}
};