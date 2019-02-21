#ifndef VALUE_H_
#define VALUE_H_

#include "../Token.hpp"

// This enum represents all the types of values
enum class VALUE_TYPE : uint_least8_t
{
    STRING,
    INTEGER,
    FLOAT,
    BOOLEAN,
    NONE,
};

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