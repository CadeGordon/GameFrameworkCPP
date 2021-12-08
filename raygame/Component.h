#pragma once
#include "Actor.h"

class Actor;

class Component :
	public Actor
{
public:
	Component();
	virtual ~Component();
	Component(Actor*, const char*);

	const char* getName();
	Actor* getOwner();
	virtual void start();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();
	virtual void onCollision(Actor*);




private:

	Actor* m_owner;
	const char* m_name;
	bool m_started;




};

