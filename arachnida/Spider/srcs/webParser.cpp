#include "Spider.hpp"

int parseWebHref(std::string &buffer, std::deque<std::pair<uint8_t, std::string> links, uint8_t depth) {
	std::set<std::string> href = extract_hreflinks(buffer);
	
	std::set<std::string>::iterator it;
	for (it = href.begin(); it != href.end(); ++it) {
		links.push_back(std::pair<uint8_t, std::string>(depth, *it));
	}
}

parseWebImg(std::string &path, std::string &buffer) {
	std::set<std::string> img = extract_hreflinks(buffer);
	
	std::set<std::string>::iterator it;
	for (it = href.begin(); it != href.end(); ++it) {
		downloadImg(path, *it);
	}
}

std::set<std::string> extract_hyperlinks(std::string &buffer)
{
    static const std::regex hl_regex( "<a href=\"(.*?)\">", std::regex_constants::icase  ) ;

    return { std::sregex_token_iterator(buffer.begin(), buffer.end(), hl_regex, 1 ),
             std::sregex_token_iterator{} } ;
}

std::set<std::string> extract_imglinks(std::string &buffer)
{
    static const std::regex hl_regex( "<img src=\"(.*?)\">", std::regex_constants::icase  ) ;

    return { std::sregex_token_iterator(buffer.begin(), buffer.end(), hl_regex, 1 ),
             std::sregex_token_iterator{} } ;
}
