#include "../pch.h"

std::map<std::string, std::string> builtins = {
    {"exit", "Exit the shell"},
    {"cd", "It changes the current working directory"},
    {"echo", "Print text to the terminal"},
    {"type", "Show if command is builtin or external"},
    {"pwd", "Print current working directory"},
    {"clear", "Clear the terminal screen"},
    {"help", "Shows all built-ins with a short description"}};