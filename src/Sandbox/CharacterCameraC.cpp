#include "pch.h"
#include "CharacterCameraC.h"
#include "Character.h"


CharacterCameraC::CharacterCameraC()
{
    CameraC::CameraC();
}

void CharacterCameraC::Start()
{
    CameraC::Start();
    SetTarget(nullptr);
    SetOffset(gce::Vector3f32(0.0f, 0.0f, 0.0f));
}

void CharacterCameraC::Update(float deltaTime)
{
    FollowTarget(deltaTime);
    //DebugMove();
}

void CharacterCameraC::Update(float deltaTime, bool endGame)
{
    if (!endGame)
    {
        FollowTarget(deltaTime);
    }
    //DebugMove();
}

void CharacterCameraC::FollowTarget(float deltaTime)
{
    SetPosition(GetTarget()->GetPosition() + GetOffset());
}

void CharacterCameraC::SetTarget(Character* target)
{
    mTarget = target;
}

void CharacterCameraC::ReplaceTarget(Character* target)
{
    if (mTarget != nullptr)
    {
        delete mTarget;
    }
    mTarget = target;
}

Character* CharacterCameraC::GetTarget()
{
    return mTarget;
}

void CharacterCameraC::SetOffset(const gce::Vector3f32& offset)
{
    mOffset = offset;
}

gce::Vector3f32 CharacterCameraC::GetOffset()
{
    return mOffset;
}





