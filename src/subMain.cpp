#include "../pch.h"

void subMain()
{
    while (true)
    {
        std::cout << "$ ";

        std::string line;
        std::getline(std::cin, line);
        spaceRemove(line);
        if (line == "exit")
        {
            break;
        }
        else if (line.substr(0, 4) == "echo")
        {
            std::string text = line.substr(5);
            spaceRemove(text);
            std::cout << text << std::endl;
        }
        else if (line.substr(0, 4) == "type")
        {
            std::string text = line.substr(5);
            spaceRemove(text);
            auto it = builtins.find(text);
            if (it != builtins.end())
            {
                std::cout << text << " is a shell builtin" << std::endl;
            }
            else
            {
                std::cout<<typeChecker(text)<<std::endl;
            }
        }
        else if(line.substr(0, 3) == "pwd"){
            std::cout<<currentDir()<<std::endl;
        }
        else
        {
            fileExecution(line);
        }
    }
}