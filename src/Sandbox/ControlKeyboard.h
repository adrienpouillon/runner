#pragma once
#include "Control.h"
class ControlKeyboard :public Control
{
protected:
	Keyboard::Key mKeyTarget;
	bool mIsBeginPressed;
	bool mIsPressed;
	bool mIsPressedFormer;
	bool mIsEndPressed;
public:

	ControlKeyboard();

	virtual void Start();

	virtual void Update(float deltaTime);

	virtual bool GetIsBeginPressed();
	virtual bool GetIsPressed();
	virtual bool GetIsEndPressed();

	void SetKeyTarget(Keyboard::Key keyTarget);

	Keyboard::Key GetKeyTarget();

};

