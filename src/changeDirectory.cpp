#include "../pch.h"
void changeDirectory(std::string path)
{
    if (path == "~")
    {
        char *home = getenv("HOME");
        if (home != nullptr)
        {
            chdir(home);
            return;
        }
    }
    else if ((!std::filesystem::exists(path) || !std::filesystem::is_directory(path)))
    {
        std::cout << "cd: " << path << ": No such file or directory" << std::endl;
        return;
    }
    chdir(path.c_str());
    return;
}
