#ifndef PARSER_H
#define PARSER_H

#include "frontend/token.h"
#include "frontend/lexer/lexer.h"
#include "frontend/ast/ast.h"

namespace Scrap {
namespace Scan {

class Parser {
private:
    Lexer* lexer;
    const Token* current_tok;

public:
    inline bool has_end();
    [[noreturn]] void abort(std::string fmt);
    const Token* eat(Tokens type);
    Node*  parse_expr();
    Node*  parse_function_expr();
    Node*  parse_function();
    Node*  parse_variable();
    Node*  parse_class();
    Node*  parse_module();
};

} // namespace Scan
} // namespace Scrap


#endif // PARSER_H