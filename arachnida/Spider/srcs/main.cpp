#include "Parser.hpp"

int	main(int argc, char **argv) {
	try {
		// pars argc and argv, Setup curl for each thread, lunch TreadPool
		Parser setting(argc, argv);
//		run_thread(setting);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// TODO handle display

	return (0);
}
