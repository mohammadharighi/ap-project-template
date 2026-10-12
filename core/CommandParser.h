#pragma once

#include <optional>
#include <string>
#include <vector>

namespace core {

struct ParsedCommand {
    std::string name;
    std::vector<std::string> arguments;
};

class CommandParser {
public:
    // Splits an input line into a command name and its arguments.
    // Returns std::nullopt when the line is empty or contains only spaces.
    std::optional<ParsedCommand> parse(const std::string& line) const;
};

}  // namespace core
