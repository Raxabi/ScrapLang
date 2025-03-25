// lexer.cc -- Defines lexer methods which allows transform the source code into tokens

#include <string>
#include <fstream>
#include <cctype>

#include "frontend/tokens.h"
#include "frontend/token.h"
#include "frontend/lexer/cursor.h"
#include "frontend/lexer/lexer.h"

namespace Scrap {
namespace Scan {

Lexer::Lexer(const char* filename):
    cursor(filename), current_tok(cursor.current_tok),
    pos(cursor.pos), line(1), pos_line(1) {}


void Lexer::advance() {
    this->cursor.advance();
}


void Lexer::advance_n(int n) {
    this->pos_line += n;
    this->cursor.advance_n(n);
}


const Token* Lexer::scan_colon() {
    if (this->check(':')) {
        this->advance_n(2);
        return this->create_token(Tokens::MOD_ACCESSOR, "::");
    }

    return this->create_token(Tokens::COLON);
}


const Token* Lexer::scan_text(char quote_type) {
    this->advance(); // starts the text scan
    std::string content = "";
    while (this->current_tok != quote_type) {
        content += this->current_tok;
        this->advance();
    }

    this->advance(); // ends the text scan
    return new Token(this->create_position(), quote_type == '\'' ? Tokens::CHAR : Tokens::STRING, content);
}


const Token* Lexer::scan_single() {
    switch (this->current_tok) {
        case '>':
        case '<':
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case '.':
        case '{':
        case '}':
        case '(':
        case ')':
        case '[':
        case ']':
        case ',':
        case '&':
        case ';':
        case '?':
        case '!': return this->create_token(this->current_tok);
        case ':': return this->scan_colon();
        case '`': 
        case '"':
        case '\'': return this->scan_text(this->current_tok);
    }

    if (this->current_tok == WHITE_SPACE) {
        return this->scan();
    }

    return this->create_token(Tokens::UNKNOWN);
}


const Token* Lexer::scan_number() {
    std::string content = "";
    while (isdigit(this->current_tok)) {
        content += this->current_tok;
        this->advance();
    }

    return this->create_token(Tokens::NUMBER, content);
}


const Token* Lexer::scan_identifier() {
    std::string content = "";
    while (isalnum(this->current_tok)) {
        content += this->current_tok;
        this->advance();
    }

    auto type_find = r_tokens.find(content);
    Tokens type = type_find != r_tokens.end() ? type_find->second : Tokens::IDENTIFIER;
    return this->create_token(type, content);
}


const Token* Lexer::scan() {
    while (this->current_tok == WHITE_SPACE) { // white space
        this->advance();
    }

    while (this->current_tok == NEW_LINE) { // new line
        this->advance();
        this->pos_line = 1;
        this->line++;
    }

    if (this->has_end()) {
        return this->create_token(Tokens::EO_FILE);
    }
    
    if (std::isalpha(this->current_tok)) {
        return this->scan_identifier();
    }

    if (std::isdigit(this->current_tok)) {
        return this->scan_number();
    }

    const Token* single_tok = this->scan_single();
    return single_tok;
}

} // namespace Scan
} // namespace Scrap
