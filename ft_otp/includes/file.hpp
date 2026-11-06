#pragma once

#include <fstream>
#include <string>
#include <exception>

std::string getKey(std::string path);
void setKeyEncryption(std::string key);

