#include "Parser.hpp"

Parser::Parser(int argc, char **argv) {
	if (argc == 1)
		throw std::invalid_argument(HELP_MSG);

	StringArray arguments(argv + 1, argv + argc);
	for (StringArray::iterator it = arguments.begin(); it != arguments.end(); it++) {
		if (handleOption(arguments, it))
			setUrl(*it);
	}
	if (_url.empty())
			throw std::invalid_argument(std::string("Url is missing"));
}

bool Parser::isRecursive() {
	return (_recursive);
}

uint8_t Parser::getDepth() {
	return (_depth);
}

std::string Parser::getPath() {
	return (_path);
}

uint8_t Parser::getNbThread() {
	return (_nbThread);
}

std::string Parser::getUrl() {
	return (_url);
}
