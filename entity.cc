//-----------------------------------------------------------------
// File name: entity.cc
// Purpose: Implements how entities add, access and delete their
//          components
// Autor: Alvaro Zurinaga
// DigiPen id: alvaro.zurinaga
//-----------------------------------------------------------------

#include "entity.hh"
#include "component.hh"

Entity::~Entity()
{
    for(std::size_t i = 0; i < components.size(); i++ )
    {
        delete components[i];
    }
}

std::size_t Entity::component_count() const
{
    return components.size();
}

void Entity::attach(Component* component)
{
    components.push_back(component);
    component->set_owner(this);
}

void Entity::attach(const Component& component)
{
    Component* copy = component.clone();
    attach(copy);
}

Component& Entity::operator[](std::size_t index)
{
    return *(components[index]);
}