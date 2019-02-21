#ifndef NAME_H_
#define NAME_H_

#include "../Token.hpp"

/*
    This Token holds variable names.
*/
class Name : public Token
{
public:
    /*
        Constructor.
        Input:
            std::string - the program name that the Name Token represents.
                Example:
                A token that represents the variable 'x1' will be: Name("x1")
        Output:
            None
    */
    Name(std::string);
    // Destructor
    ~Name();

    /*
        Getter for the _var_name attribute.
        Input:
            None
        Output:
            std::string - the name of the varible the Name Token represents
    */
    std::string name();

private:
    // This attribute holds the name of the varibable that the Name Token represents
    std::string _var_name;
};

#endif // NAME_H_