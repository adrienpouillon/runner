#include "pch.h"
#include "ControlKeyboard.h"

ControlKeyboard::ControlKeyboard()
{
	Start();
}

void ControlKeyboard::Start()
{
	SetKeyTarget(Keyboard::ENTER);
	mIsPressed = false;
}

void ControlKeyboard::Update(float deltaTime)
{
	Control::Update(deltaTime);

	mIsBeginPressed = false;
	mIsEndPressed = false;

	mIsPressed = GetKey(mKeyTarget);
	if (mIsPressed)
	{
		if (mIsPressed != mIsPressedFormer)
		{
			mIsBeginPressed = true;
		}
	}
	else
	{
		if (mIsPressed != mIsPressedFormer)
		{
			mIsEndPressed = true;
		}
	}

	mIsPressedFormer = mIsPressed;
}

bool ControlKeyboard::GetIsBeginPressed()
{
	return mIsBeginPressed;
}

bool ControlKeyboard::GetIsPressed()
{
	return mIsPressed;
}

bool ControlKeyboard::GetIsEndPressed()
{
	return mIsEndPressed;
}

void ControlKeyboard::SetKeyTarget(Keyboard::Key keyTarget)
{
	mKeyTarget = keyTarget;
}

Keyboard::Key ControlKeyboard::GetKeyTarget()
{
	return mKeyTarget;
}


