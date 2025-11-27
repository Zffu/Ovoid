#include <lexer.hpp>

#include <stdlib.h>
#include <string.h>

using namespace ovoid::lexer;

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

			
		}


	}
}