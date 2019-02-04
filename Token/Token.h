#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>

class Token
{
public:
    Token();
    ~Token();

    friend std::ostream& operator <<(std::ostream& s, const Token& t);

protected:
    void _print(std::ostream&) const;

    std::string _str_val;
};

#endif // TOKEN_H_