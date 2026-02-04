#include <string>
#include <vector>
#include <utility>

#ifndef UTILITIES_H
#define UTILITIES_H

std::string currentDir(); //it will print the current directory
void changeDirectory(); // it will change the current directory
std::pair<std::string, std::string> pathChecker(std::string command); // it will check the path whether it's valid or not
std::string typeChecker(std::string command); //it will check if something is shell builtin or not
void fileExecution(std::vector<std::string> &tokens); // it will execute a file;
void spaceRemove(); // it will remove unnecessary spaces.
void subMain(); 

#endif