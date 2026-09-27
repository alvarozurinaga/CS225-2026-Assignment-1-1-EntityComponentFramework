class ICloneable
{
    public:
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() = default;
};

class Component : public ICloneable
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
};

class ConcreteComponent : public Component
{

};