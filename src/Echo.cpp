#include "../pch.h"
void Echo(std::string &line)
{
    std::vector<std::string> tokens;
    std::string token;
    bool isSingleQuote = false;
    bool isDoubleQuote = false;
    for (size_t i = 0; i < line.size(); i++)
    {
        char c = line[i];
            if (c == '\'')
        {
          if (!isDoubleQuote)
          {
            isSingleQuote = !isSingleQuote;
            continue;
          }
        }
        if (c == '"')
        {
          if (!isSingleQuote)
          {
            isDoubleQuote = !isDoubleQuote;
            continue;
          }
        }
        if (!isSingleQuote && !isDoubleQuote && isspace(c))
        {
          if (!token.empty())
          {
            tokens.push_back(token);
            token.clear();
          }
        }
        else
        {
            token += c;
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
        token.clear();
    }
    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i];
        if (i != tokens.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}