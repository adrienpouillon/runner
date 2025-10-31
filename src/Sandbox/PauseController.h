#pragma once
#include "Controller.h"

class Pause;

class PauseController : public Controller
{
protected:
	Pause* mPause;
	enum IndexString
	{
		PAUSE,
		RESTART,
		QUIT,

		COUNT
	};
public:
	PauseController();

	virtual void Start();

	virtual void Update(float deltaTime);

	void SetPauseKey(std::string string1, Keyboard::Key key1, std::string string2, Keyboard::Key key2, std::string string3, Keyboard::Key key3);
	
	void SetPause(Pause* pause);
	Pause* GetPause();

};

