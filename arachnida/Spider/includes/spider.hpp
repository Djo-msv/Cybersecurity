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

int readWebPages(std::string _setting, std::string &_buffer);
