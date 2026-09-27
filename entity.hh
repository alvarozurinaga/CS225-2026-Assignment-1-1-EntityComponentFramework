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

    private:
    std::vector<Component*> components;
};