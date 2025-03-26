// utils.cc -- Defines lexer methods which executes simple statements

#include <string>

#include "frontend/tokens.h"
#include "frontend/lexer/lexer.h"

namespace Scrap {
namespace Scan {

bool Lexer::has_end() const {
    return this->cursor.has_end();
}

bool Lexer::check(char c) {
    return this->cursor.check(c);
}


void Lexer::advance() {
    this->cursor.advance();
}


void Lexer::advance_n(int n) {
    this->pos_line += n;
    this->cursor.advance_n(n);
}


const Position Lexer::create_position() const {
    return Position(this->pos, this->line, this->pos_line);
}

const Token* Lexer::create_token(Tokens type, std::string content) {
    return new Token(this->create_position(), type, content);
}

const Token* Lexer::create_token(Tokens type) {
    std::string content(1, this->current_tok);
    const Token* tok = this->create_token(type, content);

    this->advance();
    return tok;
}

const Token* Lexer::create_token(char c) {
    std::string content(1, c);
    Tokens type = r_tokens.find(content)->second;
    const Token* tok = this->create_token(type, content);

    this->advance();
    return tok;
}

} // namespace Scan
} // namespace Scrap
