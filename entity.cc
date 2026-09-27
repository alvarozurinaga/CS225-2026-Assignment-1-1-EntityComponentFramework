#include "entity.hh"
#include "component.hh"

Entity::~Entity()
{
    for(std::size_t i = 0; i < components.size(); i++ )
    {
        delete components[i];
    }
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