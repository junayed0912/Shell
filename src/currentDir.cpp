#include "../pch.h"
std::string currentDir(){
    char pwd[4096];
    std::string result;
    if(getcwd(pwd, sizeof(pwd)) != nullptr){
        result = pwd;
    }
    else{
        result = "pwd";
    }
    return result;
}