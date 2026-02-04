#include <iostream>
#include <utilities.h>

int main(){
    std::cout<< std::unitbuf;
    std::cerr<< std::unitbuf;
    subMain();
    return 0;
}