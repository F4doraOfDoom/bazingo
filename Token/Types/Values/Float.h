#ifndef FLAOT_H_
#define FLAOT_H_

#include "../Value.h"

class Float : public Value
{
public:
    Float(double value);

    bool operator <(const Value&) const;
    bool operator >(const Value&) const;
    bool operator ==(const Value&) const;

    virtual std::string value() const;

protected:
    virtual void _print(std::ostream&) const;

    double _val;
};

#endif // FLAOT_H_
