#pragma once

#include <stdio.h>
#include <unistd.h>
#include <cstdint>
#include <curl/curl.h>
#include <unordered_set>
#include <deque>

#include <sys/stat.h>
#include <sys/types.h>

#include "parserSetting.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

static char errorBuffer[CURL_ERROR_SIZE];
static std::string buffer;

std::string generate_random_string(size_t length);

int downloadImg(std::string &path, std::string url);

void parseWebHref(std::string &buffer, std::deque<std::pair<uint8_t, std::string>> &links, uint8_t depth, std::string url);
void parseWebImg(std::string &path, std::string &buffer, std::string url);

int readWebPages(std::string _setting, std::string &_buffer);
