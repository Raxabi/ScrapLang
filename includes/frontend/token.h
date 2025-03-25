// token.h - Token struct 

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>
#include "tokens.h"
#include "position.h"

namespace Scrap {
namespace Scan {

struct Token {
    Position& pos;
    Tokens type;
    std::string content;

    Token(Position pos, Tokens type, std::string content);

    bool operator==(const Token &rhs);

    // Checks if `this` token is a keyword
    inline bool is_keyword();

    // Checks if `this` token is an operator
    inline bool is_operator();

    // Checks if `this` token is a literal
    inline bool is_literal();
};

} // namespace Scan
} // namespace Scrap

#endif // TOKEN_H