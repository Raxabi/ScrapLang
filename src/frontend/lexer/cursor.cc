// cursor.cc -- Defines `Cursor` methods which allows advance in the source

#include <fstream>
#include "frontend/lexer/cursor.h"

namespace Scrap {
namespace Scan {

Cursor::Cursor(const char* filename):
    source(std::ifstream(filename)), pos(0)
{
    this->source.get(this->current_tok);
    this->pos = this->source.tellg();
}

void Cursor::advance() {
    return this->advance_n(1);
}

void Cursor::advance_n(long n) {
    // we make an 'offset fix'
    // because later, in the 'get' method call the within stream position will increase again
    this->source.seekg(n - 1, source.cur);
    this->current_tok = this->source.get();
    this->pos = this->source.tellg();
}

bool Cursor::check(char c) {
    return this->source.peek() == c;
}

bool Cursor::has_end() const {
    return this->source.eof();
}

} // namespace Scan
} // namespace Scrap
