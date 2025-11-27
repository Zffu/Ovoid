#pragma once

namespace ovoid::lexer {

enum token_type {

};

class token {
public:
	token_type type;

	token(token_type type) {
		this->type = type;
	}
};

}