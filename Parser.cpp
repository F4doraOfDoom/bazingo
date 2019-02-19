#include "Parser.h"

// Initialize the opcode_map
std::map<std::string, FUNCTION> opcode_map = {
    {"print", FUNCTION::PRINT},
    {"set", FUNCTION::SET}
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

Instruction::ARGS tokenize(std::stringstream& stream)
{
    Instruction::ARGS args;
    std::string line = "";
    std::string first_char = "";

    /*
        The user can do something like this: print "hello world
        without closing the brackets. I think that we should treat that as a valid string,
        and just close the entire sentence
        so even if there is a variable called 'hello' or 'world', the command
        print "hello world
        will result in a string "hello world"
    */
    while (std::getline(stream, line, ' '))
    {
        if (line[0] == '"' && line.back() != '"')
        {
            std::string temp = "";

            std::getline(stream, temp, '"');
            line += ' ' + temp + '"';

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
    Instruction::OPERATOR function;
    OPCODE opcode;

    std::string head_instruction = "";
    std::getline(stream, head_instruction, ' ');

    passed_args = tokenize(stream);
    switch (opcode_map[head_instruction])
    {
        case FUNCTION::PRINT:
            function = print;
            opcode = OPCODE::PRINT;
        break;

        case FUNCTION::SET:
            function = set;
            opcode = OPCODE::NSET_VAR;
        break;
    }

    instructions.push_back(new Instruction(opcode, function, passed_args));
    return instructions;
}

Token infer_type(std::string& obj)
{
    // A map of regex and the referring type
    static const std::array<std::pair<std::regex, VALUE_TYPE>, 4> regex_type_map = {{
        {std::regex("^\"([^\"]*)\"$"), VALUE_TYPE::STRING},
        {std::regex("^[0-9]+$"), VALUE_TYPE::INTEGER},
        {std::regex("^[0-9]+\\.[0-9]+$"), VALUE_TYPE::FLOAT},
        {std::regex("^True$|^False$"), VALUE_TYPE::BOOLEAN}
    }};
    // A map of strings and keyword definitions
    static std::unordered_map<std::string, KEYWORD> keyword_map = {
        {"const", KEYWORD::CONST}
    };
    static const std::regex var_name("^[a-zA-Z]([_a-zA-Z\\d]+)?$");
    VALUE_TYPE obj_type = VALUE_TYPE::NONE;
    std::smatch regex_match;

    Trim::trim_all(obj);
    
    // First of all, is the string a keyword?
    if (keyword_map.find(obj) != keyword_map.end())
    {
        std::cout << "Keyword: " << obj << std::endl;
        return SyntaxToken(keyword_map[obj]);
    }

    // If not a keyword, try finding corresponding regex
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
        case VALUE_TYPE::STRING:
            //std::cout << "String" << std::endl;
            return String(regex_match[0]);

        case VALUE_TYPE::INTEGER:
            //std::cout << "Integer" << std::endl;
            return Integer(std::stoi(regex_match[0]));

        case VALUE_TYPE::FLOAT:
            //std::cout << "Float " << std::endl;
            return Float(std::stoi(regex_match[0]));

        case VALUE_TYPE::BOOLEAN:
            //std::cout << "Boolean" << std::endl;
            return (obj == "True" ? Boolean(true) : Boolean(false));

        default:
            if (std::regex_match(obj, var_name))
            {
                return String(obj);
            }
            //std::cout << "None" << std::endl;
            return String("None");
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
