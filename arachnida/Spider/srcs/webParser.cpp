#include "spider.hpp"
#include <regex>
#include <set>

std::set<std::string> extract_hreflinks(std::string &buffer)
{
	static const std::regex hl_regex( "<a href=\"(.*?)\">", std::regex_constants::icase  ) ;

	return { std::sregex_token_iterator(buffer.begin(), buffer.end(), hl_regex, 1 ),
		std::sregex_token_iterator{} } ;
}

std::set<std::string> extract_imglinks(std::string &buffer)
{
	static const std::regex hl_regex(
		R"REGEX(<img[^>]*\bsrc\s*=\s*"([^"]*)")REGEX",
		std::regex_constants::icase
	);

	return { std::sregex_token_iterator(buffer.begin(), buffer.end(), hl_regex, 1 ),
		std::sregex_token_iterator{} } ;
}

void parseWebHref(std::string &buffer, std::deque<std::pair<uint8_t, std::string>> &links, uint8_t depth, std::string url) {
	std::set<std::string> href = extract_hreflinks(buffer);
	
	std::set<std::string>::iterator it;
	for (it = href.begin(); it != href.end(); ++it) {
		std::cout << "href : " << url + *it << std::endl;
		links.push_back(std::pair<uint8_t, std::string>(depth, url + *it));
	}
	std::cout << links.size() << ":";
}

void parseWebImg(std::string &path, std::string &buffer, std::string url) {
	std::set<std::string> img = extract_imglinks(buffer);
	
	std::set<std::string>::iterator it;
	for (it = img.begin(); it != img.end(); ++it) {
		downloadImg(path, url + *it);
	}
}
