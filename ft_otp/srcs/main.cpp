#include "Parser.hpp"
#include "Totp.hpp"

void	trunkKey(std::string &key) {

	if (key.size() > 64)
		key = sha1(key);

	key.resize(64, 0);
	return ();
}

void	startProgram(Parser &setting) {
	if (setting.getHasKey()) {
		try {
			setKeyEncryption(setting.getKey());
		}
	}
	if (setting.getHasPath()) {
		try {
			std::string key = getKey(setting.getPath());
			trunkKey(key);
			std::cout << Totp((uint8_t *)key.c_str()) << std::endl;
		} catch (const std::exeption& e) {
			std::cout << e.what() << std::endl;
			return ;
		}
	}
}

int	main(int argc, char **argv) {
	try {
		// pars argc and argv, Setup curl for each thread, lunch TreadPool
		Parser setting(argc, argv);
		startProgram(setting);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
