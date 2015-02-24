#include "PhysicSystem.h"


PhysicSystem::PhysicSystem()
{
}


PhysicSystem::~PhysicSystem()
{
}

auto PhysicSystem::subscribe(Collider* subscriber) -> void
{
	subscribers.push_back(subscriber);
}

auto PhysicSystem::update() -> void
{

}
