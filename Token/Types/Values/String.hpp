#ifndef STRING_H_
#define STRING_H_

#include "../Value.hpp"

class String : public Value
{
public:
    String(std::string);

    bool operator <(const Value&) const;
    bool operator >(const Value&) const;
    bool operator ==(const Value&) const;

    virtual std::string value() const;

protected:
    virtual void _print(std::ostream&) const;

    std::string _val;
};

#endif // STRING_H_
