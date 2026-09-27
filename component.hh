class ICloneable
{

};

class Component : public ICloneable
{
    public:
    int id;
    int get_id() const
    {
        return id;
    }
};

class ConcreteComponent : public Component
{

};