#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>

// This enum represents all types of tokens
enum class TYPE : uint_least8_t
{
    STRING,
    INTEGER,
    FLOAT,
    BOOLEAN,
    NONE
};

class Token
{
public:
    Token();
    ~Token();

    friend std::ostream& operator <<(std::ostream& s, const Token& t);
    TYPE type();

protected:
    void _print(std::ostream&) const;

    std::string _str_val;
    TYPE _token_type;
};

#endif // TOKEN_H_