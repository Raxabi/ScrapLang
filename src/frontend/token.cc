#include <exception>
#include <string>
#include <map>

#include "frontend/tokens.h"
#include "frontend/position.h"
#include "frontend/token.h"

namespace Scrap {
namespace Scan {

Token::Token(Position pos, Tokens type, std::string content):
    pos(pos), type(type), content(content) {}


bool Token::operator==(const Token& rhs) {
    return this->type == rhs.type;
}


inline bool Token::is_keyword() {
    return this->type > Tokens::keywords_open and this->type < Tokens::keywords_close;
}


inline bool Token::is_operator() {
    return this->type > Tokens::operators_open and this->type < Tokens::operators_close;
}


inline bool Token::is_literal() {
    return this->type > Tokens::literals_open and this->type < Tokens::literals_close;
}

} // namespace Scan
} // namespace Scrap
