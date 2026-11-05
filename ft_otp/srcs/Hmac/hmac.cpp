
// result = 20
// key = 64

void	hmac(uint8_t *key, uint64_t count, uint8_t *result) {
	uint8_t k_ipad[65];
    uint8_t k_opad[65];

	size_t	i;
	memset(result, 0, sizeof(20));

	bzero(k_ipad, sizeof(k_ipad));
	bzero(k_opad, sizeof(k_opad);
	bcopy(key, k_ipad, strlen(key));
	bcopy(key, k_opad, strlen(key));

	for (i=0; i<64; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	uint8_t text[9] = {(uint8_t)count >> 56, (uint8_t)count >> 48, (uint8_t)count >> 40, (uint8_t)count >> 32, (uint8_t)count >> 24, (uint8_t)count >> 16, (uint8_t)count >> 8, (uint8_t)count, 0};
	
	std::string sum = std::string(k_oped) + sha1(std::string(k_ipad) + text);
	std::string resstring = sha1();
	uint8_t *res = resstring.c_str();
	
	memcpy(result, res, 20);
}
