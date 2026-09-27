#include "entity.hh"
#include "component.hh"

Entity::~Entity()
{
    for(std::size_t i = 0; i < components.size(); i++ )
    {
        delete components[i];
    }
}