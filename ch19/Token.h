// Exercise 19.21: Write your own version of the Token class.

#ifndef _Token_h
#define _Token_h

#include <string>

class Token {
public:
	Token(): tok(INT), ival{0} {}
	Token(const Token &t): tok(t.tok) { copyUnion(t); }
	Token(Token &&t) noexcept;
	Token &operator=(const Token&);
	Token &operator=(Token&&) noexcept;
	~Token() { if(tok == STR) sval.~basic_string(); }	// clang bug

	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
	enum {INT, CHAR, DBL, STR} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const Token&);
	void moveUnion(Token&&);
}; // Token

#endif
