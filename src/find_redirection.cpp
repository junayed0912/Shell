#include "../pch.h"
std::pair<int, std::string> find_redirection(const std::vector<std::string> &tokens)
{
    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == ">" || tokens[i] == ">>" || tokens[i] == "1>" || tokens[i] == "2>" || tokens[i] == "1>>" || tokens[i] == "2>>")
        {
            return {i, tokens[i]};
        }
    }
    return {-1, ""};
}