#include <iostream>
#include <string>
#include <random>

std::string generate_random_string(size_t length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 generator(rd());
    
    // Define the range of indices for the character set
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string random_string;
    random_string.reserve(length); // Optimization: reserve memory to avoid reallocations
    
    for (size_t i = 0; i < length; ++i) {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}
