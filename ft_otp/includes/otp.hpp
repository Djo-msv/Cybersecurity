#pragma once

#include "sha.hpp"

// nombre de digit return
# define DIGIT 6

uint32_t	totp(uint8_t *key);
uint32_t	hotp(uint8_t *key, uint64_t count);
void		hmac(std::string (*hash)(const std::string &), uint8_t *key, uint64_t count, uint8_t *result);
