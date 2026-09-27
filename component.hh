#include <iostream>

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

class Component : public ICloneable, public IPrintable
{
    public:
    int id;
    int get_id() const
    {
        return id;
    }

    ICloneable* clone() const override
    {
        return new Component(*this);
    }

    void print() const override
    {      
        std::cout<<"This is a Component with id = "<< id <<std::endl;
    }
};

class ConcreteComponent : public Component
{

};