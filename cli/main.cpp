#include <iostream>
#include <string>

#include "core/CommandParser.h"

int main() {
    const core::CommandParser parser;
    std::string line;

    std::cout << "AP shell. Type 'exit' to quit.\n";
    while (std::cout << "> " && std::getline(std::cin, line)) {
        const auto command = parser.parse(line);
        if (!command) {
            continue;
        }
        if (command->name == "exit") {
            break;
        }
        if (command->name == "help") {
            std::cout << "Available commands: help, exit\n";
            continue;
        }
        std::cout << "command: " << command->name
                  << ", arguments: " << command->arguments.size() << '\n';
    }
    return 0;
}
