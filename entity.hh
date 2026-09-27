#include <cstddef>
#include <vector>

//Forward declaration
class Component;
class Entity
{
    public:
    std::size_t component_count() const
    {
        return components.size();
    }

    void attach(Component* component)
    {
        components.push_back(component);
    }

    private:
    std::vector<Component*> components;
};