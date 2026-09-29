//-----------------------------------------------------------------
// File name: component.hh
// Purpose: Defines the component class and the interfaces it uses
// Autor: Alvaro Zurinaga
// DigiPen id: alvaro.zurinaga
//-----------------------------------------------------------------

#include <iostream>

//Forward declaration
class Entity;

// ICloneable Inteface
class ICloneable
{
    public:

    //Returns a new copy that the caller is responsible for deleting
    virtual ICloneable* clone() const = 0;
    //Allows objects to be safely deleted through this interface
    virtual ~ICloneable() = default;
};

// IPrintable Interface
class IPrintable
{
    public:
    
    //Prints a readable description of the object
    virtual void print() const = 0;
    //Allows object to be safely deleted through this interface
    virtual ~IPrintable() = default;
};

// IComparable Inteface
class IComparable
{
    public:

    // Returns true if this object is considered equal to the other one
    virtual bool compare_to(const IComparable& other) const = 0;
    //Allows objects to be safely deleted though this interface
    virtual ~IComparable() = default;
};


// Component class publicly inherits methods from the already defined interfaces
class Component : public ICloneable, public IPrintable, public IComparable
{
    protected:
    int id;
    Entity* owner = nullptr;


    public:
    // Returns the ID of this component
    int get_id() const;

    // Makes a new Component with the same ID and owner pointer
    // The caller is responsible for deleting the copy
    Component* clone() const override;
    // Prints a short message showing the component's ID
    void print() const override;
    // Checks wether both components have the same ID
    // Throws a std::bad_cast if the other object is not a Component
    bool compare_to(const IComparable& other) const override;
    // Stores the pointer to the entity that owns this component
    void set_owner(Entity* entity);
    // Returns the owner pointer, or nullptr if no owner is set
    Entity* get_owner() const;
};

class ConcreteComponent : public Component {};