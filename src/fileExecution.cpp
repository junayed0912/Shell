#include "../pch.h"
void fileExecution(std::string line)
{
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word)
    {
        tokens.push_back(word);
    }
    if (tokens.empty())
        return;
    std::vector<char *> argv;
    auto path = pathChecker(tokens[0]);
    if (path.second == ": not found")
    {
        std::cout << path.first << ": command not found" << std::endl;
        return;
    }
    for (auto &token : tokens)
    {
        argv.push_back(token.data());
    }
    argv.push_back(nullptr);
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(argv[0], argv.data());
        perror("exec failed");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        if(waitpid(pid, &status, 0) == -1){
            perror("waitpid failed");
        };
    }
    else
    {
        std::cout << "Fork failed" << std::endl;
    }
}