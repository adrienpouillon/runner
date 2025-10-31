#include "pch.h"
#include "Character.h"
#include "GameManager.h"
#include "Scene.h"

Entity::Entity()
{
}

void Entity::Start()
{
    SetGeometry(new Cube);
    SetColor({ 1.f, 0.f, 0.f });
    SetPosition({ 0.0f, 0.f, 0.0f });
    SetScale({1.f, 1.f, 1.f});
    SetRotation({ 0.f, 0.f, 0.f });
    SetIsDead(false);
    SetTag(Tag::ENTITY);
}

void Entity::Update(float deltaTime)
{

}

void Entity::OnCollision(Entity* other, gce::Vector3f32 penetration)
{
    if (mTag == Tag::SPEED_BONUS)
    {
        //delete mGeometry;
        mGeometry = nullptr;
    }
    if (mTag == Tag::SPEED_MALUS)
    {
        //delete mGeometry;
        mGeometry = nullptr;
    }
}

void Entity::Draw(Window* renderTarget)
{
    if(mGeometry != nullptr)
    {
        renderTarget->Draw(*mGeometry);
    }
}

gce::Vector3f32 Entity::Collide(Entity* other)
{
    gce::Vector3f32 me_pos = GetPosition();
    gce::Vector3f32 me_scale = GetScale();

    gce::Vector3f32 o_pos = other->GetPosition();
    gce::Vector3f32 o_scale = other->GetScale();

    gce::Vector3f32 penetration = { 0.f, 0.f, 0.f };  
    penetration.x = IsCollide(me_pos.x, me_scale.x, o_pos.x, o_scale.x); 
    if (penetration.x != 0.f)
    {
        penetration.y = IsCollide(me_pos.y, me_scale.y, o_pos.y, o_scale.y);
        if (penetration.y != 0.f)
        {
            penetration.z = IsCollide(me_pos.z, me_scale.z, o_pos.z, o_scale.z);
            if (penetration.z != 0.f)
            {
                return penetration;
            }
        }
    }
    return gce::Vector3f32(0.f, 0.f, 0.f);
}

float Entity::IsCollide(float me_pos, float me_scale, float o_pos, float o_scale)
{
    float me_half = me_scale * 0.5f;
    float o_half = o_scale * 0.5f;

    float dis = o_pos - me_pos;
    float pen = (me_half + o_half) - std::abs(dis);
    if (pen >= 0.f)
    {
        if (dis < 0.f)
        {
            return -pen;
        }
        return pen;
    }
    return 0.f;
}



void Entity::SetTexture(Texture& texture)
{
    if (mGeometry)
    {
        mGeometry->SetTexture(texture);
    }
}

void Entity::SetColor(const gce::Vector3f32& color)
{
    if (mGeometry)
    {
        mGeometry->SetColor(color);
    }
}

void Entity::SetGeometry(Geometry* geometry)
{
    mGeometry = geometry;
}

void Entity::ReplaceGeometry(Geometry* geometry)
{
    if (mGeometry != nullptr)
    {
        //delete mGeometry;
    }
    mGeometry = geometry;
}

Geometry* Entity::GetGeometry()
{
    return mGeometry;
}

void Entity::SetPosition(const gce::Vector3f32& xyz)
{
    if(mGeometry)
    {
        mGeometry->SetPosition(xyz);
    }
}

gce::Vector3f32 Entity::GetPosition()
{
    if(mGeometry)
    {
        return mGeometry->GetPosition();
    }
}

void Entity::SetScale(const gce::Vector3f32& scale)
{
    if(mGeometry)
    {
        mGeometry->SetScale(scale);
    }
}

gce::Vector3f32 Entity::GetScale()
{
    if(mGeometry)
    {
        return mGeometry->GetScale();
    }
}

void Entity::SetRotation(const gce::Vector3f32& rotation)
{
    if (mGeometry)
    {
        mGeometry->SetRotation(rotation);
    }
}

gce::Vector3f32 Entity::GetRotation()
{
    if (mGeometry)
    {
        return mGeometry->GetRotation();
    }
}

void Entity::SetIsDead(bool isDead)
{
    mIsDead = isDead;
}

bool Entity::GetIsDead()
{
    return mIsDead;
}

Entity::~Entity()
{
    if (mGeometry)
    {
        //delete mGeometry;
    }
}
