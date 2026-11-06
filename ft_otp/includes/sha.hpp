#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string sha1(const std::string& input);
std::string sha256(const std::string& input);
std::string sha512(const std::string& input);
