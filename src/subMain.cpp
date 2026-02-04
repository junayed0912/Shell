#include <iostream>
#include <string>
void subMain(){
    while(true)
    {
        std::cout<<"$ ";

        std::string command;
        std::cin>> command;
        std::cout<<command<<": command not found"<<std::endl;
    }
}