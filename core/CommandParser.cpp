#include "core/CommandParser.h"

#include <sstream>

namespace core {

std::optional<ParsedCommand> CommandParser::parse(const std::string& line) const {
    std::istringstream stream(line);

    ParsedCommand command;
    if (!(stream >> command.name)) {
        return std::nullopt;
    }

    std::string argument;
    while (stream >> argument) {
        command.arguments.push_back(argument);
    }
    return command;
}

}  // namespace core
