#include <iostream>

#include "core/CommandParser.h"

namespace {

int failures = 0;

void expect(bool condition, const char* description) {
    if (!condition) {
        std::cerr << "FAILED: " << description << '\n';
        ++failures;
    }
}

}  // namespace

int main() {
    const core::CommandParser parser;

    expect(!parser.parse("").has_value(), "empty line returns nothing");
    expect(!parser.parse("   ").has_value(), "blank line returns nothing");

    const auto command = parser.parse("commit -m message");
    expect(command.has_value(), "valid line is parsed");
    if (command) {
        expect(command->name == "commit", "command name is the first word");
        expect(command->arguments.size() == 2, "remaining words are arguments");
        expect(command->arguments[0] == "-m", "arguments keep their order");
    }

    return failures == 0 ? 0 : 1;
}
