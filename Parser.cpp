#include "Parser.h"
#include <sstream>

// Initialize the opcode_map
std::map<std::string, OPCODE> opcode_map = {
    {"print", PRINT}
};

Instruction::Instruction(OPCODE opcode, OPERATOR function, ARGS args)
{
    this->opcode = opcode;
    this->function = function;
    this->args = args;
}

Instruction::~Instruction()
{
    // pass
}

Instruction::ARGS print_args(std::stringstream& stream)
{
    Instruction::ARGS args;
    std::string temp = "";
    int i = 1;

    while (std::getline(stream, temp, ' '))
    {
        args.push_back(Integer(i++));
    }

    return args;
}

std::vector<Instruction*> parse(std::string line)
{
    std::vector<Instruction*> instructions;
    std::deque<std::string> token_stream;
    std::stringstream stream(line);
    std::vector<Token> passed_args;

    std::string head_instruction = "";
    std::getline(stream, head_instruction, ' ');

    switch (opcode_map[head_instruction])
    {
        case PRINT:
            instructions.push_back(new Instruction(OPCODE::PRINT, print, print_args(stream)));
        break;
    }

    return instructions;
}

