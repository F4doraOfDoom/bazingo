#include "Parser.h"

// Initialize the opcode_map
std::map<std::string, OPCODE> opcode_map = {
    {"print", OPCODE::PRINT}
};

// Declare program_variables locally
std::unordered_map<std::string, Value*> program_variables;

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
    std::string line = "";
    std::string first_char = "";

    /*
        Update: This doc is useless coz I fixed the bug
        Docs:
        To parse the tokens, we read them line by line, and then use the infer_type 
        function to get a Token that corresponds to the type inferred in the token.
        Since strings start with a quote, it is problematic to read tokens this way,
        because if the string contains a space in it, we will get an error. Because 
        of that, every time we read a token, we check its first character. If it is 
        a quote, then we read from the stream until the next quote, and add it to the 
        token. But, because the getline function doesn't include the delimiter, we read
        another character, and check if its a quote. If not, it is not a valid string,
        and an error should be thrown.
    */
    while (std::getline(stream, line, ' '))
    {
        if (line[0] == '"' && line.back() != '"')
        {
            std::string temp = "";

            std::getline(stream, temp, '"');
            line += ' ' + temp + '"';

            /*
                The user can do something like this: print "hello world
                without closing the brackets. I think that we should treat that as a valid string,
                and just close the entire sentence
                so even if there is a variable called 'hello' or 'world', the command
                print "hello world
                will result in a string "hello world"
            */
            // if (temp.back() != '"')
            // {
            //     // Invalid quotes
            //     std::cout << "Throw exception" << std::endl;
            // }
        }

        if (line.size() > 0)
        {
            //std::cout << line;
            args.push_back(infer_type(line));
        }
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

Token infer_type(std::string& obj)
{
    // A map of regex and the referring type
    static const std::array<std::pair<std::regex, Type>, 4> regex_type_map = {{
        {std::regex("^\"([^\"]*)\"$"), T_STRING},
        {std::regex("^[0-9]+$"), T_INTEGER},
        {std::regex("^[0-9]+\\.[0-9]+$"), T_FLOAT},
        {std::regex("^True$|^False$"), T_BOOLEAN}
    }};
    Type obj_type = T_NULL;
    std::smatch regex_match;

    Trim::trim_all(obj);
    
    // Pass each regex to find a type
    for (auto regex_pair : regex_type_map)
    {
        if (std::regex_search(obj, regex_match, regex_pair.first))
        {
            obj_type = regex_pair.second;
            break;
        }
    }

    switch (obj_type)
    {
        case T_STRING:
            std::cout << "String" << std::endl;
            return String(regex_match[0]);

        case T_INTEGER:
            std::cout << "Integer" << std::endl;
            return Integer(std::stoi(regex_match[0]));

        case T_FLOAT:
            std::cout << "Float " << std::endl;
            return Float(std::stoi(regex_match[0]));

        case T_BOOLEAN:
            std::cout << "Boolean" << std::endl;
            return (obj == "True" ? Boolean(true) : Boolean(false));

        default:
            std::cout << "Null" << std::endl;
            return String("NULL");
    }
}


void Trim::trim_left(std::string &s) 
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void Trim::trim_right(std::string &s) 
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

void Trim::trim_all(std::string &s) 
{
    trim_left(s);
    trim_left(s);
}
