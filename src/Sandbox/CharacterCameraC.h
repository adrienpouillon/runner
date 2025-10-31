#pragma once
#include "CameraC.h"

class Character;

class CharacterCameraC :public CameraC
{
protected:
    Character* mTarget;
    gce::Vector3f32 mOffset;
public:
    CharacterCameraC();

    virtual void Start();

    virtual void Update(float deltaTime);
    virtual void Update(float deltaTime, bool endGame);

    virtual void FollowTarget(float deltaTime);

    void SetTarget(Character* target);
    void ReplaceTarget(Character* target);
    Character* GetTarget();

    void SetOffset(const gce::Vector3f32& offset);

    gce::Vector3f32 GetOffset();


};

