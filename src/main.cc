#include <iostream>

#include "frontend/token.h"
#include "frontend/lexer/lexer.h"

int main(int argc, char** argv) {
    Scrap::Scan::Lexer l(argv[1]);
    const Scrap::Scan::Token* tok = nullptr;

    while (!l.has_end()) {
        tok = l.scan();
        std::cout << tok->content << std::endl;
        delete tok;
    }

    return 0;
}

/* #include "frontend/lexer/cursor.h"

int main() {
    Scrap::Scan::Cursor c("../tests/tiny.scrap");

    std::cout << c.current_tok << std::endl;
    c.advance_n(4);
    std::cout << c.current_tok << std::endl;

    // check test
    std::cout << (c.check('i') ? "The next letter is 'i'!" : "Wrong letter") << std::endl;
    return 0;
} */