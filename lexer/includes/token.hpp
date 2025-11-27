#pragma once

#include <string>

namespace ovoid::lexer {

/**
 * @brief A type of lexer token.
 */
enum token_type {
	KEYWORD = 0x00,
	STRING = 0x01,

	BOOLEAN = 0x02,
	INTEGER = 0x03
};

/**
 * @brief A lexer token
 */
class token {
public:
	token_type type;

	token(token_type type) {
		this->type = type;
	}
};

/**
 * @brief A token containing data.
 */
template <typename T> 
class data_token: public token {
public:
	T data;

	data_token(token_type type, T data): token(type) {
		this->data = data;
	}
};

/**
 * Sample token types
 */

/**
* @brief A keyword token
*/
class keyword_token: public data_token<std::string> {
public:
	keyword_token(std::string tok): data_token(token_type::KEYWORD, tok) {}
};

/**
 * @brief A string token.
 */
class string_token: public data_token<std::string> {
public:
	string_token(std::string str): data_token(token_type::STRING, str) {}
};

class bool_token: public data_token<bool> {
public:
	bool_token(bool val): data_token(token_type::BOOLEAN, val) {}
};

class int_token: public data_token<int> {
public:
	int_token(int val): data_token(token_type::INTEGER, val) {}
};

}