#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
	m_name = nullptr;
	m_started = false;
}

Component::~Component()
{
}

void Component::assignOwner(Actor* owner)
{
	if (!getOwner())
		return;

	m_owner = owner;
}

Component::Component(const char* name)
{
	m_name = name;
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
