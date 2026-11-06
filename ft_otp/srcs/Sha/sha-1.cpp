#include "sha.hpp"

std::string sha1(const std::string& input)
{
	unsigned char hash[SHA_DIGEST_LENGTH];

	SHA1(
			reinterpret_cast<const unsigned char*>(input.c_str()),
			input.size(),
			hash
		);

	std::string ss;

	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
		ss.push_back(hash[i]);

	return ss;
}
