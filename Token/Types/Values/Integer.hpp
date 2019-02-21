#ifndef INTEGER_H_
#define INTEGER_H_

#include "../Value.hpp"

class Integer : public Value
{
public:
    Integer(long long value);

    bool operator <(const Value&) const;
    bool operator >(const Value&) const;
    bool operator ==(const Value&) const;

    virtual std::string value() const;

protected:
    virtual void _print(std::ostream&) const;

    long long _val;
};

#endif // INTEGER_H_
