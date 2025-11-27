#include <lexer.hpp>

#include <stdlib.h>
#include <string.h>

#include <str.hpp>

using namespace ovoid::lexer;
using namespace ovoid::utils;

void lexer::append_token(token* t) {
	if(this->root == nullptr) {
		this->root = t;
		this->head = t;
		return;
	}

	t->prev = this->head;
	this->head->next = t;
	
	this->head = t;
}


lexer::lexer(char* data, size_t sz) {
	char c;

	char* temp_buff = (char*) malloc(32);
	int temp_ind = 0;

	for(int i = 0; i < sz; ++i) {
		c = data[i];

		temp_buff[0] = '\0';
		temp_ind = 0;

		if(c == ' ' || c == '\t' || c == '\n') continue;
		else if(c == '\0') break;

		if(isdigit(c)) {
			while(isdigit(c)) {
				temp_buff[temp_ind++] = c;

				++i;
				c = data[i];
			}

			temp_buff[temp_ind] = '\0';
			this->append_token(new int_token(atoi(temp_buff)));

		} else if(c == '\"') {
			while(c != '\"') {
				temp_buff[temp_ind++] = c;

				++i;
				c = data[i];
			}

			temp_buff[temp_ind] = '\0';
			this->append_token(new string_token(std::string(temp_buff)));

		} else if(isalpha(c)) {
			while(isalpha(c)) {
				temp_buff[temp_ind++] = c;

				++i;
				c = data[i];
			}

			std::string str(temp_buff);

			switch(hash_str(str)) {
				case static_hash_str("fun"): {
					this->append_token(new token(token_type::FUNCTION));
					break;
				}
				
				case static_hash_str("true"): {
					this->append_token(new bool_token(true));
					break;
				}

				case static_hash_str("false"): {
					this->append_token(new bool_token(false));
					break;
				}

				default: {
					this->append_token(new keyword_token(str));
					break;
				}
			}
		} else {
			switch(c) {
				case '{': {
					this->append_token(new token(token_type::BRACKET_OPEN));
					break;
				}

				case '}': {
					this->append_token(new token(token_type::BRACKET_CLOSE));
					break;
				}

				case '(': {
					this->append_token(new token(token_type::PAREN_OPEN));
					break;
				}

				case ')': {
					this->append_token(new token(token_type::PAREN_CLOSE));
					break;
				}

				case ';': {
					this->append_token(new token(token_type::SEMICOLON));
					break;
				}

				case ',': {
					this->append_token(new token(token_type::COMMA));
				}

			}
		}


	}
}