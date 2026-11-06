#include "file.hpp"
#include "sha.hpp"

void setKeyEncryption(std::string key) {
	std::ofstream	file("ft_otp.key");

	if (!file)
		throw std::runtime_error("Unable to create file");

	file << sha1(key);

	file.close();
}
