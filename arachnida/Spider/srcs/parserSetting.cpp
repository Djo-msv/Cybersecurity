#include "parserSetting.hpp"


parserSetting::parserSetting(int ac, char **av) {
	if (ac == 1)
		throw std::invalid_argument(HELP_MSG);

	StringArray arguments(av + 1, av + ac);
	for (StringArray::iterator it = arguments.begin(); it != arguments.end(); it++) {
		if (handleOption(arguments, it))
			setUrl(*it);
	}
	if (_url.empty())
			throw std::invalid_argument(std::string("Url is missing"));
}

int	parserSetting::handleOption(StringArray &array, StringArray::iterator pnt) {
	std::string	arg = (*pnt);
	if (arg[0] != '-')
		return (1);
	for (std::string::iterator it = arg.begin() + 1; it != arg.end(); it++) {
		StringArray::iterator tmp = pnt;
		tmp++;
		if (*it == 'r')
			setRecursive();
		else if (*it == 'l')
			setDepth(array, tmp);
		else if (*it == 'p')
			setPath(array, tmp);
		else
			throw std::invalid_argument(std::string("Unknow arguments : ") + *it);
	}
	return (0);
}

void	parserSetting::setRecursive(void) {
	_recursive = true;
}

void	parserSetting::setDepth(StringArray &array, StringArray::iterator &pnt) {
	for (; pnt != array.end() && (*pnt)[0] == '-'; pnt++) {}
	if (pnt == array.end())
		throw std::invalid_argument(std::string("Missing arguments for -l option"));
	std::string	arg = (*pnt);
	if (!std::all_of(arg.begin(), arg.end(), ::isdigit) || arg.size() > 3 || std::atoi(arg.c_str()) > 255)
			throw std::invalid_argument(std::string("-l option only tooks number between 0 - 255"));
	_depth = std::atoi(arg.c_str());
	pnt = array.erase(pnt);
}

void	parserSetting::setPath(StringArray &array, StringArray::iterator &pnt) {
	for (; pnt != array.end() && (*pnt)[0] == '-'; pnt++) {}
	if (pnt == array.end())
		throw std::invalid_argument(std::string("Missing arguments for -p option"));
	std::string	arg = (*pnt);
	_path = std::string(arg);
	pnt = array.erase(pnt);
}

void	parserSetting::setUrl(std::string argument) {
	if (_url.empty()) {
		_url = std::string(argument);
	} else {
		throw std::invalid_argument(std::string("Unknow arguments : ") + argument);
	}
}

bool parserSetting::isRecursive() {
	return (_recursive);
}

uint8_t parserSetting::getDepth() {
	return (_depth);
}

std::string parserSetting::getPath() {
	return (_path);
}

std::string parserSetting::getUrl() {
	return (_url);
}
