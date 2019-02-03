#include "Parser.h"

std::vector<Instruction*> parse(std::string line)
{
    std::vector<Instruction*> instructions;
    std::deque<std::string> token_stream;
    std::stringstream stream(line);

    std::string head_instruction = "";
    std::getline(stream, head_instruction, ' ');

    std::cout << head_instruction << std::endl;

    return instructions;
}