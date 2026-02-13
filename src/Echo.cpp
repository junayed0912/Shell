#include "../pch.h"
void Echo(std::string &line)
{
  auto tokens = handleLine(line);
    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i];
        if (i != tokens.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}