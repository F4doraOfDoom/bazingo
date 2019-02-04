#ifndef VALUE_H_
#define VALUE_H_

#include "../Token.h"

class Value : public Token
{
public:
    virtual bool operator <(const Value&) const = 0;
    virtual bool operator >(const Value&) const = 0;
    virtual bool operator ==(const Value&) const = 0;

    virtual std::string value() const = 0;
    virtual void _print(std::ostream&) const = 0;
};

#endif // VALUE_H_