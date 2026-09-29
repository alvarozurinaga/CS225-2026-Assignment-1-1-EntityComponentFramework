//-----------------------------------------------------------------
// File name: entity.hh
// Purpose: Defines the entity class that stores components and 
//          takes care of deleting them.
// Autor: Alvaro Zurinaga
// DigiPen id: alvaro.zurinaga
//-----------------------------------------------------------------

#include <cstddef>
#include <vector>

// Forward declaration
class Component;

// Entity class
class Entity
{
    public:
    // Returns how many components are stored in this entity
    std::size_t component_count() const;
    // Stores the component and sets this entity as its owner
    // The emtity will delete the component when it is destroyed
    void attach(Component* component);
    // Clones the component and stores the copy
    // The original component is left unchanged
    void attach(const Component& component);
    // Returns the component at the given position without copying it
    // The index must be within the vector's bounds
    Component& operator[](std::size_t index);

    // Deletes all the components stored in this entity
    ~Entity();

    private:
    std::vector<Component*> components;
};