#include "../pch.h"

void spaceRemove(std::string &line){
    while(!line.empty() && line[0] == ' '){
        line.erase(0, 1);
    }
}