#include "Parser.hpp"

int main()
{
    std::string user_input = "";

    std::cout << "Bazingo Interpeter version 0.01 (Mor Gal and Jonathan pUklisty)" << std::endl;

    while (user_input != "Quit")
    {
        std::cout << ">>> ";
        std::getline(std::cin, user_input);
        std::vector<Instruction*> instructions = parse(user_input);

        for (auto instruction : instructions)
        {
            if (!instruction->function(instruction->args))
            {
                std::cout << "Instruction failed." << std::endl;
            }
            
            delete instruction;
        }
    }

    return 0;
}