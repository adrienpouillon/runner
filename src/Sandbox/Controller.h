#pragma once
#include "pch.h"
#include "Control.h"

class Controller
{
protected:
	std::vector<Control*>* mAllControl;
	std::vector<std::string> mAllString;
public:

	Controller();

	virtual void Start();

	virtual void Update(float deltaTime);

	template<typename T>
	Control* AddControl();

	void DeleteAll(std::vector<Control*>* all);

	void SetKeyboardKey(std::string string, Keyboard::Key key);

	Control* GetControl(std::string stringId);

	bool GetIsBeginPressed(std::string stringId);
	bool GetIsPressed(std::string stringId);
	bool GetIsEndPressed(std::string stringId);

	void SetAllControl(std::vector<Control*>* allControl);
	std::vector<Control*>* GetAllControl();

	std::string GetString(int index);

	~Controller();
};

template<typename T>
inline Control* Controller::AddControl()
{
	T* newT = new T();
	if (Control* c = dynamic_cast<Control*>(newT))
	{
		mAllControl->push_back(c);
		return c;
	}
	std::cout << " !!! AddControl de Controller n'a pas eu un type enfant de Control !!! " << std::endl;
	return nullptr;
}


