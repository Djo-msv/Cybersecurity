#include <exception>
#include "parser.hpp"

int	Parser::handleOption(StringArray &array, StringArray::iterator pnt) {
	std::string	arg = (*pnt);
	if (arg[0] != '-')
		return (1);
	for (std::string::iterator it = arg.begin() + 1; it != arg.end(); it++) {
		StringArray::iterator tmp = pnt;
		tmp++;
		if (*it == 'g')
			setKey(array, tmp);
		else if (*it == 'k')
			setPath(array, tmp);
		else
			throw std::invalid_argument(std::string("Unknow arguments : ") + *it);
	}
	return (0);
}


void	Parser::setKey(StringArray &array, StringArray::iterator &pnt) {
	for (; pnt != array.end() && (*pnt)[0] == '-'; pnt++) {}
	if (pnt == array.end())
		throw std::invalid_argument(std::string("Missing arguments for -g option"));
	std::string	arg = (*pnt);
	_key = std::string(arg);
	pnt = array.erase(pnt);
	_hasKey = true;
}

void	Parser::setPath(StringArray &array, StringArray::iterator &pnt) {
	for (; pnt != array.end() && (*pnt)[0] == '-'; pnt++) {}
	if (pnt == array.end())
		throw std::invalid_argument(std::string("Missing arguments for -k option"));
	std::string	arg = (*pnt);
	_path = std::string(arg);
	pnt = array.erase(pnt);
	_hasPath = true;
}
