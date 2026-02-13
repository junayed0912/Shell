#include "../pch.h"
void Echo(std::string &line)
{
  auto tokens = handleLine(line);
  auto re_direction = find_redirection(tokens);
  if (re_direction.first != -1)
  {
    pid_t pid = fork();
    if (pid == 0)
    {
      reDirection(tokens, re_direction.first, re_direction.second);
      for (size_t i = 0; i < tokens.size(); i++)
      {
        std::cout << tokens[i];
        if (i != tokens.size() - 1)
          std::cout << " ";
      }
      std::cout << std::endl;
      _exit(0);
    }
    else if (pid > 0)
    {
      waitpid(pid, nullptr, 0);
    }
    else
    {
      perror("echo redirection failed");
    }
    return;
  }
  for (size_t i = 0; i < tokens.size(); i++)
  {
    std::cout << tokens[i];
    if (i != tokens.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
}