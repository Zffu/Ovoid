#pragma once

#include <string_view>
#include <stdint.h>

namespace ovoid::utils {

/**
 * @brief Hashes the string.
 * @details Uses the TNV-1a hash (64-bit variant) algorithm.
 * 
 * @param str the string.
 * 
 * @return the hash.
 */
consteval uint64_t static_hash_str(std::string_view str) {
	uint64_t hash = 1469598103934665603ull; 
	for (char c : str) {
		hash = (hash ^ c) * 1099511628211ull;
	} 
	
	return hash;
}

/**
 * @brief Hashes the string.
 * @details Uses the TNV-1a hash (64-bit variant) algorithm.
 * 
 * @param str the string.
 * 
 * @return the hash.
 */
uint64_t hash_str(std::string_view str) {
	uint64_t hash = 1469598103934665603ull; 
	for (char c : str) {
		hash = (hash ^ c) * 1099511628211ull;
	} 
	
	return hash;
}

}