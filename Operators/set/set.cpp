#include "set.hpp"

bool set(Instruction::ARGS args)
{
    bool set_const = false;
    std::string new_name = "";
    Name* given_name = nullptr;
    Value* given_value = nullptr;

    try
    {  
        if (args.at(0).type() == TOKEN_TYPE::KEYWORD)
        {
            // We already checked that args[0] is indeed a SyntaxToken, so a downward cast is safe
            SyntaxToken* syntax_token = (SyntaxToken*)&args[0];
            set_const = (syntax_token->keyword() == KEYWORD::CONST);
            args.erase(args.begin());
        }

        if (args.at(0).type() == TOKEN_TYPE::NAME)
        {
            new_name = ((Name*)&args.at(0))->name();
        }

        switch (args.at(1).type())
        {
            case TOKEN_TYPE::NAME:
                given_name = (Name*)&args.at(1);
                std::cout << set_const << new_name << given_name->name() << std::endl;
                break;

            case TOKEN_TYPE::VALUE:
                given_value = (Value*)&args.at(1);
                std::cout << set_const << new_name << given_value->value() << std::endl;
                break;

            default:
                std::cout << "Syntax Error" << std::endl;
                return false;
        }
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Invalid number of arguments. (" << e.what()  << ")" << std::endl;
        return false;
    } 
    catch (const std::bad_alloc& e)
    {
        std::cout << "Bad Alloc: " << e.what() << std::endl;
        return false;
    }

    return true;
}