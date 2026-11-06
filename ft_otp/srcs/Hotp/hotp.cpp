#include "otp.hpp"
#include "sha.hpp"
#include <cmath>

#include <iostream>

uint64_t	truncate(uint8_t *key) {
	uint8_t OffsetBits = (key[19] & 0xf);

//	std::cout << std::hex;
	for (int i = 0; i != 20; i++) {
		std::cout << (int)key[i] << ' ';
	}
	std::cout << std::dec << std::endl;
	uint32_t p = (uint32_t)key[OffsetBits] << 24 | (uint32_t)key[OffsetBits + 1] << 16 | (uint32_t)key[OffsetBits + 2] << 8 | (uint32_t)key[OffsetBits + 3];
	p &= 0x7FFFFFFF;
	return ((uint64_t)p % (uint64_t)pow(10, DIGIT));
}

#include <openssl/hmac.h>

uint32_t	hotp(uint8_t *key, uint64_t count) {
	uint8_t result[20];
	uint8_t text[8] = {0};
//	uint8_t	tmp[] = "12345678901234567890";

	unsigned int len = 0;
	HMAC(EVP_sha1(), key, 64, text, 8, result, &len);
	return (truncate(result));
}
