#include "Parser.hpp"
#include "Thread.hpp"

void	startProgram(Parser &setting) {
	std::deque<Task> tasks = {{setting.getUrl(), setting.getDepth(), false}};

	ThreadPool ThreadPool(setting.getNbThread(), tasks);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
