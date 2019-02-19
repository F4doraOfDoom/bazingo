#ifndef BOOLEAN_H_
#define BOOLEAN_H_

#include "../Value.h"

class Boolean : public Value
{
public:
    Boolean(bool value);

    bool operator <(const Value&) const;
    bool operator >(const Value&) const;
    bool operator ==(const Value&) const;

    virtual std::string value() const;

protected:
    virtual void _print(std::ostream&) const;

    bool _val;
};

#endif // BOOLEAN_H_