#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{
    if (component->getOwner() != nullptr)
    return nullptr;

    Component** tempArray = new Component * [m_componentCount + 1];

    int j = 0;
    for (int i = 0; i < m_componentCount; i++)
    {
        tempArray[i] = m_comp[i];
        j++;
    }

    tempArray[j] = component;
    m_componentCount + 1;
    m_comp = tempArray;

    return component;
}

bool Actor::removeComponent(Component* component)
{
    if(component->getOwner() != nullptr)
    return false;

    bool componentRemoved = false;

    Component** newArray = new Component * [m_componentCount - 1];

    int j = 0;

    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_comp[i])
        {
            newArray[j] = m_comp[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        m_comp = newArray;
        m_componentCount--;
    }

    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_comp[i]->getName() == name)
            return m_comp[i];
    }
    return false;
}

Component* Actor::getComponent(const char* name)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_comp[i]->getName() == name)
            return m_comp[i];
    }
    return nullptr;
}

void Actor::update(float deltaTime)
{
}

void Actor::draw()
{
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}