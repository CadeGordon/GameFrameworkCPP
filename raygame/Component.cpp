#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
	m_name = "Null";
	m_started = false;
}

Component::~Component()
{
}

Component::Component(Actor* actor, const char* name)
{
	m_owner = actor;
	m_name = name;
	m_started = false;
}

const char* Component::getName()
{
	return m_name;
}

Actor* Component::getOwner()
{
	return m_owner;
}

void Component::start()
{
}

void Component::update(float deltaTime)
{
}

void Component::draw()
{
}

void Component::end()
{
}

void Component::onCollision(Actor*)
{
}
