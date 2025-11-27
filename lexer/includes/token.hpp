#pragma once

namespace ovoid::lexer {

/**
 * @brief A type of lexer token.
 */
enum token_type {

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

}