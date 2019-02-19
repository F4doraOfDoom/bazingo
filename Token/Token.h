#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>

// This enum represents all types of tokens
enum class TOKEN_TYPE : uint_least8_t
{
    TOKEN,
    KEYWORD,
    VALUE,
};

/*
    This is the master class for all the tokens in the program.
    Every token shall inherit it
*/
class Token
{
public:
    // Constructor
    Token();
    // Destructor
    ~Token();

    /*
        This function prints the value of a Token
        Input:
            std::ostream& s - a reference to some stream to channel the output to
            const Token& t - a refernce to a Token that is to be printed
        Output:
            std::ostream&
    */
    friend std::ostream& operator <<(std::ostream& s, const Token& t);

    /*
        Getter function for _token_type.
        Input:
            None
        Output:
            TOKEN_TYPE - the type of the token as defined in the enum class TOKEN_TYPE
    */
    TOKEN_TYPE type();

protected:
    /*
        Const function
        This function moves the value of the Token to a stream
        Input:
            std::ostream& - refernce to some stream
        Output:
            None
    */
    void _print(std::ostream&) const;

    // This attribute holds a string representation of the Token's value.
    // It is used to print the value of a Token.
    std::string _str_val;

    // This attributes holds the type of the Token, as defined in TOKEN_TYPE
    TOKEN_TYPE _token_type;
};

#endif // TOKEN_H_