#include "../pch.h"
std::vector<std::string> handleLine(std::string line)
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
        if (c == '\\')
        {
            if (i + 1 >= line.size())
            {
                continue;
            }
            char next = line[i + 1];

            if (isSingleQuote)
            {
                token += '\\';
            }
            else if (isDoubleQuote)
            {
                if (next == '"' || next == '\\')
                {
                    token += next;
                    i++;
                }
                else
                {
                    token += '\\';
                }
            }
            else
            {
                token += next;
                i++;
            }
            continue;
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
    return tokens;
}