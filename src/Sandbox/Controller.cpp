#include "pch.h"
#include "Controller.h"

#include "ControlKeyboard.h"

Controller::Controller()
{
    Start();
}

void Controller::Start()
{
    SetAllControl(nullptr);
}

void Controller::Update(float deltaTime)
{
    int lenghtAllControl = mAllControl->size() - 1;
    for (int i = lenghtAllControl; i > -1; i--)
    {
        (*mAllControl)[i]->Update(deltaTime);
    }
}

void Controller::DeleteAll(std::vector<Control*>* all)
{
    int lenghtAll = all->size() - 1;
    for (int i = lenghtAll; i > -1; i--)
    {
        delete (*all)[i];
    }
    delete all;
}

void Controller::SetKeyboardKey(std::string string, Keyboard::Key key)
{
    Control* control = AddControl<ControlKeyboard>();
    ControlKeyboard* controlKeyboard = dynamic_cast<ControlKeyboard*>(control);
    controlKeyboard->SetString(string);
    controlKeyboard->SetKeyTarget(key);
}

Control* Controller::GetControl(std::string stringId)
{
    int lenghtAllControl = mAllControl->size();
    for (int i = 0; i < lenghtAllControl; i++)
    {
        if ((*mAllControl)[i]->GetString() == stringId)
        {
            return (*mAllControl)[i];
        }
    }
    return nullptr;
}

bool Controller::GetIsBeginPressed(std::string stringId)
{
    Control* control = GetControl(stringId);
    if (control != nullptr)
    {
        return control->GetIsBeginPressed();
    }
    std::cout << stringId << "n'est pas une vrai stringId existante : GetIsBeginPressed() = echec" << std::endl;
    return false;
}

bool Controller::GetIsPressed(std::string stringId)
{
    Control* control = GetControl(stringId);
    if (control != nullptr)
    {
        return control->GetIsPressed();
    }
    std::cout << stringId << "n'est pas une vrai stringId existante : GetIsPressed() = echec" << std::endl;
    return false;
}

bool Controller::GetIsEndPressed(std::string stringId)
{
    Control* control = GetControl(stringId);
    if (control != nullptr)
    {
        return control->GetIsEndPressed();
    }
    std::cout << stringId << "n'est pas une vrai stringId existante : GetIsEndPressed() = echec" << std::endl;
    return false;
}

void Controller::SetAllControl(std::vector<Control*>* allControl)
{
    mAllControl = allControl;
}

std::vector<Control*>* Controller::GetAllControl()
{
    return mAllControl;
}

std::string Controller::GetString(int index)
{
    if (index > -1 && index < mAllString.size())
    {
        return mAllString[index];
    }
    return "";
}

Controller::~Controller()
{
    DeleteAll(mAllControl);
}

