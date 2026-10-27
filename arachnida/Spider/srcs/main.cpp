#include "spider.hpp"
#include "parserSetting.hpp"

int	main(int argc, char **argv) {

	try {
		uint8_t			_depth;
		std::string		_path;
		std::string		_buffer;
		parserSetting	_setting(argc, argv);

		if (DEBUG == 1) {
			std::cout << "Url : " << _setting.getUrl() << std::endl;
			std::cout << "Recursive : " << _setting.isRecursive() << std::endl;
			std::cout << "Depth : " << (int)_setting.getDepth() << std::endl;
			std::cout << "Path : " << _setting.getPath() << std::endl;
		}
		_depth = _setting.getDepth();
		_path = _setting.getPath();

		if (access(chemin, F_OK) == -1)
			throw std::invalid_argument(std::string("wrong path"));

		std::unordered_set<std::string>	_alredyPassHere;
		std::deque<std::pair<uint8_t, std::string>> _links{{0, _setting.getUrl()}};   
		
		if (readWebPages(_setting.getUrl(), _buffer) != 0)
			return (1);

		while (!_links.empty()) {
			auto search = _alredyPassHere.find(_links.front().second);
			if (search != _alredyPassHere.end()) {
				_links.pop_front();
				continue ;
			}
			if (readWebPages(_links.front().second, _buffer) != 0) {
				// TODO print url inacsessible
				_links.pop_front();
				continue ;
			}
			if (_links.front().first < _depth) {}
				parseWebHref(_buffer, _links, _links.front().first() + 1); // add each href to _links TODO normaliz url before
			parseWebImg(path, _buffer);
			_alredyPassHere.insert(_links.front().second);
			_links.pop_front();
		}
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
