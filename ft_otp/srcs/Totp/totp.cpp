#include "otp.hpp"

#include <ctime>

uint32_t	totp(uint8_t *key) {
	size_t	x = 30;
	size_t t = static_cast<size_t> (time(NULL));

	return (hotp(key, t / x));
}
