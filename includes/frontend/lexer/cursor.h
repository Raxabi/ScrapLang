#ifndef CURSOR_H
#define CURSOR_H

#include <fstream>

namespace Scrap {
namespace Scan {

class Cursor {
private:
    std::ifstream source;

public:
    long pos;
    char current_tok;

public:
    Cursor(const char* filename);
    void advance();

    // Advance forwarding `n` characters from the current position
    void advance_n(long n);
    bool check(char c);
    bool has_end();
};

} // namespace Scan
} // namespace Scrap

#endif // CURSOR_H