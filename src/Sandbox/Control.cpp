#include "pch.h"
#include "Control.h"

Control::Control()
{
    Start();
}

void Control::Start()
{
    SetString("no id");
}

void Control::Update(float deltaTime)
{
   
}

void Control::SetString(std::string stringId)
{
    mStringId = stringId;
}

std::string Control::GetString()
{
    return mStringId;
}