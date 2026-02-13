#include "../pch.h"
void reDirection(std::vector<std::string> &tokens, int redirection_ind, std::string redirection_symbol){
    std::string filename = tokens[redirection_ind + 1];
    int flags = O_WRONLY | O_CREAT;
    if(redirection_symbol.find(">>") != std::string::npos){
        flags |= O_APPEND;
    }else{
        flags |= O_TRUNC;
    }

    int target_fd = (redirection_symbol[0] == '2') ? STDERR_FILENO : STDOUT_FILENO;
    int fd = open(filename.c_str(), flags, 0644);
    if(fd == -1){
        perror("fd");
        return;
    }
    if(dup2(fd, target_fd) == -1){
        perror("dup2");
        return;
    }
    close(fd);

    tokens.erase(tokens.begin() + redirection_ind, tokens.begin() + redirection_ind + 2);
}