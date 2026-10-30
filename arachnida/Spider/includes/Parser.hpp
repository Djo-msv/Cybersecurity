#pragma once

#include <cstdint>
#include <string>
#include <exception>
#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>

#define HELP_MSG \
	"\033[1mSPIDER\033[0m\n" \
	"======\n" \
	"\n" \
	"The spider program allow you to extract all the images from a website, recursively, by providing a url as a parameter.\n" \
	"\n" \
	"\033[1mUSAGE\033[0m\n" \
	"-----\n" \
	"  \033[1m./spider [-rlp] URL\033[0m\n" \
	"\n" \
	"\033[1mOPTIONS\033[0m\n" \
	"-------\n" \
	"  \033[1m-r\033[0m       : recursively downloads the images in a URL received as a parameter.\n" \
	"  \033[1m-r -l [N]\033[0m: indicates the maximum depth level of the recursive download. If not indicated, it will be 5.\n" \
	"  \033[1m-p [PATH]\033[0m: indicates the path where the downloaded files will be saved. If not specified, ./data/ will be used.\n"

typedef std::list<std::string> StringArray;

class Parser {
	public :
		Parser(int ac, char **av);

		bool isRecursive();
		uint8_t getDepth();
		std::string getPath();
		uint8_t getNbThread();
		std::string getUrl();
		
	private :
		int		handleOption(StringArray &array, StringArray::iterator pnt);

		void	setRecursive();
		void	setDepth(StringArray &array, StringArray::iterator &pnt);
		void	setPath(StringArray &array, StringArray::iterator &pnt);
		void	setNbThread(StringArray &array, StringArray::iterator &pnt);
		void	setUrl(std::string argument);

		bool		_recursive = false;
		uint8_t		_depth = 5;
		std::string _path = "./data/";
		uint8_t		_nbThread = 6;
		std::string	_url = "";
};
