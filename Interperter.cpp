#include "Parser.h"

int main()
{
    std::string user_input = "";

    std::cout << "Bazingo Interpeter version 0.01 (Mor Gal and Jonathan Uklisty)" << std::endl;

    while (true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, user_input);
        std::vector<Instruction*> instructions = parse(user_input);

        for (auto instruction : instructions)
        {
            instruction->function(instruction->args);
            delete instruction;
        }
    }

    return 0;
}