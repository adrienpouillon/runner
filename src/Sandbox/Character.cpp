#include "pch.h"
#include "Character.h"
#include "Scene.h"
#include "DefineTile.h"

Character::Character()
{
	
}

Character::~Character()
{

}

void Character::Start()
{
    Entity::Start();

    //character set
    SetVelocity(gce::Vector3f32(0.f, 0.f, 0.f));
    SetMaxVelocity(gce::Vector3f32(1.f, 1.f, 1.f));
    SetGravity(0.5f);
    SetBoost(false);

    //entity re set
    SetTag(Tag::CHARACTER);
}

void Character::Update(float deltaTime)
{
    if (deltaTime == 0.f)
    {
        //si pause
        return;
    }

    gce::Vector3f32 velocity = GetVelocity();
    gce::Vector3f32 position = GetPosition();
    gce::Vector3f32 maxVelocity = GetMaxVelocity();

    float maxVelocityX = maxVelocity.x;
    float maxVelocityY = maxVelocity.y;
    float maxVelocityZ = maxVelocity.z + MaxSpeedIsBoost(deltaTime);

    float velocityX = velocity.x;
    float velocityY = velocity.y - GetGravity();
    float velocityZ = velocity.z + SpeedIsBoost(velocity.z, maxVelocityZ);


    if (velocityX != 0.f)
    {
        float xMax = MAX_X;
        float posX = position.x + velocityX;
        if (-xMax > posX || posX > xMax)
        {
            velocityX = 0.f;
        }
    }
    
    if (velocityY > maxVelocityY)
    {
        velocityY = maxVelocityY;
    }

    if (mBoost && velocityZ > maxVelocity.z)
    {
        mBoost = false;
        velocityZ = maxVelocity.z;
    }
    else if (velocityZ < 0.f)
    {
        velocityZ = 0.f;
    }

    SetVelocity(gce::Vector3f32(velocityX, velocityY, velocityZ));
    SetMove(gce::Vector3f32(velocityX, velocityY * deltaTime, velocityZ * deltaTime));
    SetMaxVelocity(gce::Vector3f32(maxVelocityX, maxVelocityY, maxVelocityZ));

    SetPosition(position + GetMove());
}

void Character::OnCollision(Entity* other, gce::Vector3f32 penetration)
{
    switch (other->GetTag())
    {
    case Entity::GROUND:
    {
        float px = penetration.x;
        float px_ = std::abs(penetration.x);
        float py = penetration.y;
        float py_ = std::abs(penetration.y);
        float pz = penetration.z;
        float pz_ = std::abs(penetration.z);

        if (px < py_ && px > py_)
        {
            //collision x
            gce::Vector3f32 currentvelocity = GetMove();
            gce::Vector3f32 velocity = GetVelocity();
            gce::Vector3f32 position = GetPosition();
            SetPosition(gce::Vector3f32(position.x - currentvelocity.x, position.y, position.z));
            SetVelocity(gce::Vector3f32(velocity.x, velocity.y, 0.f));
        }
        if (py_ != 0.f)
        {
            //collision y
            gce::Vector3f32 currentvelocity = GetMove();
            gce::Vector3f32 velocity = GetVelocity();
            gce::Vector3f32 position = GetPosition();
            SetPosition(gce::Vector3f32(position.x, position.y - currentvelocity.y, position.z));
            SetVelocity(gce::Vector3f32(0.f, 0.f, velocity.z));
        }
        if (pz_ < py_ && pz_ > 0.1f)
        {
            //collision z
            gce::Vector3f32 currentvelocity = GetMove();
            gce::Vector3f32 velocity = GetVelocity();
            gce::Vector3f32 position = GetPosition();
            SetPosition(gce::Vector3f32(position.x, position.y, position.z - currentvelocity.z));
            SetVelocity(gce::Vector3f32(0.f, velocity.y, velocity.z));
        }
        
        break;
    }
    case Entity::SPEED_BONUS:
    {
        SetBoost(true);
        break;
    }
    case Entity::SPEED_MALUS:
    {
        gce::Vector3f32 velocity = GetVelocity();
        SetVelocity(gce::Vector3f32(velocity.x, velocity.y, velocity.z * 0.5f));
        break;
    }
    case Entity::SPEED_JUMP:
    {
        gce::Vector3f32 velocity = GetVelocity();
        SetVelocity(gce::Vector3f32(velocity.x, velocity.y + JUMP * 2.f, velocity.z));
        break;
    }

    }
}

void Character::MoveLeft()
{
    gce::Vector3f32 velocity = GetVelocity();
    velocity.x += -LATERAL_VELOCITY;
    SetVelocity(velocity);
}

void Character::MoveRight()
{
    gce::Vector3f32 velocity = GetVelocity();
    velocity.x += LATERAL_VELOCITY;
    SetVelocity(velocity);
}

void Character::Jump()
{
    gce::Vector3f32 velocity = GetVelocity();
    if (velocity.y == 0.f)
    {
        velocity.y += JUMP;
    }
    SetVelocity(velocity);
}

float Character::SpeedIsBoost(float velocity, float maxVelocity)
{
    if (mBoost)
    {
        return REDUCE_VELOCITY_PLAYER * 1000.f * maxVelocity;
    }
    else
    {
        return -(INCREASE_VELOCITY_PLAYER + (velocity * 0.001f));
    }
}

float Character::MaxSpeedIsBoost(float deltaTime)
{
    if (mBoost)
    {
        return 0.f;
    }
    else
    {
        return deltaTime * MULTIPLICATOR_MAX_VELOCITY_PLAYER;
    }
}

void Character::SetGravity(float gravity)
{
    mGravity = gravity;
}

float Character::GetGravity()
{
    return mGravity;
}

void Character::SetBoost(bool boost)
{
    mBoost = boost;
}

bool Character::GetBoost()
{
    return mBoost;
}

void Character::SetVelocity(gce::Vector3f32 velocity)
{
    mVelocity = velocity;
}

gce::Vector3f32 Character::GetVelocity()
{
    return mVelocity;
}

void Character::SetMove(gce::Vector3f32 move)
{
    mMove = move;
}

gce::Vector3f32 Character::GetMove()
{
    return mMove;
}

void Character::SetMaxVelocity(gce::Vector3f32 maxVelocity)
{
    mMaxVelocity = maxVelocity;
}

gce::Vector3f32 Character::GetMaxVelocity()
{
    return mMaxVelocity;
}
