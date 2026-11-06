#pragma once

#include <cstdint>
#include <string>
#include <exception>
#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>

#define HELP_MSG \
	"\033[1mft_otp\033[0m\n" \
	"======\n" \
	"\n" \
	"The ft_otp program allows you to store an initial password in file, and that is capable of generating a new one time password every time it is requested.\n" \
	"\n" \
	"\033[1mUSAGE\033[0m\n" \
	"-----\n" \
	"  \033[1m./ft_otp [-gk] URL\033[0m\n" \
	"\n" \
	"\033[1mOPTIONS\033[0m\n" \
	"-------\n" \
	"  \033[1m-g [Key]\033[0m : The program receives as argument a hexadecimal key of at least 64 characters. The program stores this key safely in a file called ft_otp.key, which is encrypted.\n" \
	"  \033[1m-r [PATh]\033[0m: The program generates a new temporary password based on the key given as argument and prints it on the standard output.\n" \

typedef std::list<std::string> StringArray;

class Parser {
	public :
		Parser(int ac, char **av);

		bool getHasKey();
		bool getHasPath();
		std::string getKey();
		std::string getPath();

	private :
		int		handleOption(StringArray &array, StringArray::iterator pnt);

		void	setHasKey();
		void	setHasPath();
		void	setKey(StringArray &argument, StringArray::iterator &pnt);
		void	setPath(StringArray &argument, StringArray::iterator &pnt);

		bool		_hasKey = false;
		bool		_hasPath = false;

		std::string	_key = "";
		std::string	_path = "";
};
