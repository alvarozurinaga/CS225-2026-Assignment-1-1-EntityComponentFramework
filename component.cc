//-----------------------------------------------------------------
// File name: component.cc
// Purpose: Implements the component's ID, cloning, printing, 
//          comparison and owner functions
// Autor: Alvaro Zurinaga
// DigiPen id: alvaro.zurinaga
//-----------------------------------------------------------------
    
    #include "component.hh"
    
    int Component::get_id() const
    {
        return id;
    }

    Component* Component::clone() const 
    {
        return new Component(*this);
    }

    void Component::print() const 
    {      
        std::cout<<"This is a Component with id = "<< id <<std::endl;
    }

    bool Component::compare_to(const IComparable& other) const 
    {
        const Component& other_component = dynamic_cast<const Component&>(other);

        return id==other_component.get_id();
    }

    void Component::set_owner(Entity* entity)
    {
        owner = entity;
    }

    Entity* Component::get_owner() const
    {
        return owner;
    }