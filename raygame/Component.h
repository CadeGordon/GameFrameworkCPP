#pragma once
#include "Actor.h"
class Component :
	public Actor
{
public:
	Component();
	virtual ~Component();
	Component(Actor*, const char*);

	void getName(const char*);
	void getOwner(Actor*);
	virtual void start();
	virtual void update(float);
	virtual void draw();
	virtual void end();
	virtual void onCollision(Actor*);




private:

	Actor* m_owner;
	const char* m_name;





};

