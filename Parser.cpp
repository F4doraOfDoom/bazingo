#include "Parser.h"

// Initialize the opcode_map
std::map<std::string, OPCODE> opcode_map = {
    {"print", PRINT}
};

std::vector<Instruction*> parse(std::string line)
{
    std::vector<Instruction*> instructions;
    std::deque<std::string> token_stream;
    std::stringstream stream(line);

    std::string head_instruction = "";
    std::getline(stream, head_instruction, ' ');

    switch (opcode_map[head_instruction])
    {
        case PRINT:
            instructions.push_back(new Instruction{OPCODE::PRINT, print, nullptr, nullptr});
        break;
    }

    return instructions;
}