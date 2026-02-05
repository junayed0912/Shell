#include "../pch.h"
std::pair<std::string, std::string> pathChecker(std::string command)
{
    char *raw_path = getenv("PATH");
    if (raw_path == nullptr)
    {
        return {"PATH", " isn't found"};
    }
    std::string pathStr = raw_path;
    std::vector<std::string> dirs;
    std::string tmp;
    for (char c : pathStr)
    {
        if (c == ':')
        {
            if (!tmp.empty())
            {
                dirs.push_back(tmp);
                tmp.clear();
            }
        }
        else
        {
            tmp.push_back(c);
        }
    }
    if(!tmp.empty()){
        dirs.push_back(tmp);
        tmp.clear();
    }
    for(auto &dir : dirs){
        std::filesystem::path fullPath = dir;
        fullPath /= command;
        auto exists = std::filesystem::exists(fullPath);
        if(!exists) continue;
        auto isRegular = std::filesystem::is_regular_file(fullPath);
        if(!isRegular) continue;

        auto perms = std::filesystem::status(fullPath).permissions();
        if((perms & std::filesystem::perms::owner_exec) != std::filesystem::perms::none){
            return {command, fullPath.string()};
        }
    }
    return {command, ": not found"};
}