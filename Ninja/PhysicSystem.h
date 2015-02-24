#pragma once
#include <list>

class Collider;

class PhysicSystem
{
	public:
		PhysicSystem();
		~PhysicSystem();
	
		auto subscribe(Collider* subscriber) -> void;
		auto update() -> void;

	private:
		std::list<Collider*> subscribers;
};

