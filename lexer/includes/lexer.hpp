#include <token.hpp>

namespace ovoid::lexer {

class lexer {
private:
	void append_token(token* t);

public:
	token* root;
	token* head;

	lexer(char* data, size_t sz);
	~lexer();
};

}