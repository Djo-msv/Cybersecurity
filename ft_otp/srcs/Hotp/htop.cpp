
uint64_t	truncate(uint8_t *key) {
	uint8_t OffsetBits = (key[19] & 0xf);

	uint32_t p = (uint32_t)key[OffsetBits] << 24 | (uint32_t)key[OffsetBits + 1] << 16 | (uint32_t)key[OffsetBits + 2] << 8 | (uint32_t)key[OffsetBits + 3];
	p &= 0x7FFFFFFF;
	return ((uint64_t)p % pow(10, DIGIT));
}

uint32_t	hotp(uint8_t *key, uint64_t count) {
	uint8_t result[20];
	hmac(sh1, key, count, result);
	return (truncate(result));
}
