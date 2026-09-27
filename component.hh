#include <iostream>

//Forward declaration
class Entity;

class ICloneable
{
    public:
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() = default;
};

class IPrintable
{
    public:
    virtual void print() const = 0;
    virtual ~IPrintable() = default;
};

class IComparable
{
    public:
    virtual bool compare_to(const IComparable& other) const = 0;
    virtual ~IComparable() = default;
};

class Component : public ICloneable, public IPrintable, public IComparable
{
    protected:
    int id;
    Entity* owner = nullptr;

    public:
    int get_id() const
    {
        return id;
    }

    Component* clone() const override
    {
        return new Component(*this);
    }

    void print() const override
    {      
        std::cout<<"This is a Component with id = "<< id <<std::endl;
    }

    bool compare_to(const IComparable& other) const override
    {
        const Component& other_component = dynamic_cast<const Component&>(other);

        return id==other_component.get_id();
    }

    void set_owner(Entity* entity)
    {
        owner = entity;
    }

    Entity* get_owner() const
    {
        return owner;
    }
};

class ConcreteComponent : public Component
{

};