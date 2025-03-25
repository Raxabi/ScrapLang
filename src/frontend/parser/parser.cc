#include <format>
#include <iostream>
#include <exception>

#include "frontend/token.h"
#include "frontend/lexer/lexer.h"
#include "frontend/ast/ast.h"
#include "frontend/parser/parser.h"

namespace Scrap {
namespace Scan {

inline bool Parser::has_end() {
    return this->lexer->has_end();
}

[[noreturn]] void Parser::abort(std::string fmt) {
    std::cerr << fmt << std::endl;
    throw std::exception();
}

const Token* Parser::eat(Tokens type) {
    const Token* next = this->lexer->scan();
    if (next->type != type) {
        std::string expected = tokens.find(type)->second;
        std::string encountered = tokens.find(next->type)->second;
        std::string fmt = std::format("Expected token of type '{}', but an '{}' was encountered", expected, encountered);
        this->abort(fmt);
    }

    return (this->current_tok = next);
}

Node* Parser::parse_expr() {
    return nullptr;
}

Node* Parser::parse_function_expr() {
    return nullptr;
}

Node* Parser::parse_function() {
    return nullptr;
}

Node* Parser::parse_class() {
    return nullptr;
}

Node* Parser::parse_variable() {
    return nullptr;
}

Node* Parser::parse_module() {
    return nullptr;
}

} // namespace Scan
} // namespace Scrap

