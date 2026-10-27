#include "spider.hpp"

//
// libcurl write callback function
//
static size_t writer(char *data, size_t size, size_t nmemb,
                     std::string *writerData)
{
  if(!writerData)
	  return 0;
 
  writerData->append(data, size * nmemb);
 
  return size * nmemb;
}
 
//
// libcurl connection initialization
//
static bool init(CURL *&curl, const char *url)
{
  CURLcode result;
 
  curl = curl_easy_init();
 
  if(!curl) {
    fprintf(stderr, "Failed to create CURL handle\n");
    return false;
  }
 
  result = curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
  if(result != CURLE_OK) {
    fprintf(stderr, "Failed to set error buffer [%d]\n", result);
    return false;
  }
 
  result = curl_easy_setopt(curl, CURLOPT_URL, url);
  if(result != CURLE_OK) {
    fprintf(stderr, "Failed to set URL [%s]\n", errorBuffer);
    return false;
  }
 
  result = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  if(result != CURLE_OK) {
    fprintf(stderr, "Failed to set redirect option [%s]\n", errorBuffer);
    return false;
  }
 
  result = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
  if(result != CURLE_OK) {
    fprintf(stderr, "Failed to set writer [%s]\n", errorBuffer);
    return false;
  }
 
  result = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
  if(result != CURLE_OK) {
    fprintf(stderr, "Failed to set write data [%s]\n", errorBuffer);
    return false;
  }
  return true;
}

int readWebPages(std::string url, std::string &_buffer) {
	CURL *curl = NULL;
	CURLcode result;
	std::string title;

	// Ensure one argument is given

	result = curl_global_init(CURL_GLOBAL_ALL);
	if(result != CURLE_OK)
		return (int)result;

	// Initialize CURL handle

	if(!init(curl, url.c_str())) {
		fprintf(stderr, "Handle initialization failed\n");
		curl_global_cleanup();
		return EXIT_FAILURE;
	}

	// Retrieve content for the URL

	result = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	if(result != CURLE_OK) {
		fprintf(stderr, "Failed to get '%s' [%s]\n", url.c_str(), errorBuffer);
		return EXIT_FAILURE;
	}

	_buffer = buffer;
	return (0);
}
