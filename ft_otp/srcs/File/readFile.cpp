#include "file.hpp"

std::string getKey(std::string path) {
	std::string myKey;
	std::ifstream file;

	file.open(path.c_str());
	if (!file)
		throw std::runtime_error("Unable to create file");
	char ch;
	while(file.get(ch))
		myKey.push_back(ch);
	file.close();
	return (myKey);
}
