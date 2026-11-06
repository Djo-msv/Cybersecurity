#include <cstring>
#include <string>
#include "otp.hpp"


# define RESULT_SIZE 20
# define KEY_SIZE 64

void	hmac(std::string (*hash)(const std::string &), uint8_t *key, uint64_t count, uint8_t *result) {
	uint8_t k_ipad[65];
    uint8_t k_opad[65];

	size_t	i;
	memset(result, 0, RESULT_SIZE);

	memset(k_ipad, 0, sizeof(k_ipad));
	memset(k_opad, 0, sizeof(k_opad));
	memcpy(k_ipad, key, KEY_SIZE);
	memcpy(k_opad, key, KEY_SIZE);

	for (i=0; i<64; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	uint8_t text[9] = {(uint8_t)(count >> 56), (uint8_t)(count >> 48), (uint8_t)(count >> 40), (uint8_t)(count >> 32), (uint8_t)(count >> 24), (uint8_t)(count >> 16), (uint8_t)(count >> 8), (uint8_t)count, 0};
	
	std::string sum = std::string((char *)k_opad, KEY_SIZE) + hash(std::string((char *)k_ipad, KEY_SIZE) + std::string((char *)text, 8));
	std::string resstring = hash(sum);
	uint8_t *res = (uint8_t *)resstring.c_str();
	
	memcpy(result, res, 20);
}
