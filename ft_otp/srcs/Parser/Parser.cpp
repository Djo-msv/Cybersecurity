#include "Parser.hpp"

Parser::Parser(int argc, char **argv) {
	if (argc == 1)
		throw std::invalid_argument(HELP_MSG);

	StringArray arguments(argv + 1, argv + argc);
	for (StringArray::iterator it = arguments.begin(); it != arguments.end(); it++) {
		handleOption(arguments, it);
	}
}


bool Parser::getHasKey() {
	return (_hasKey);
}

bool Parser::getHasPath() {
	return (_hasPath);
}

std::string Parser::getKey() {
	return (_path);
}

std::string Parser::getPath() {
	return (_path);
}
