#include "../pch.h"
std::string typeChecker(std::string command){
   auto path = pathChecker(command);
   if(path.second != ": not found"){
        return path.first + " is " + path.second;
   }
   return path.first + path.second;
} 