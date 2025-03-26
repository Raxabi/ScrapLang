#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <string>

#include "frontend/tokens.h"
#include "frontend/position.h"
#include "frontend/token.h"
#include "frontend/lexer/cursor.h"
#include "frontend/lexer/lexer.h"

namespace Scrap {
namespace Scan {

/**
 * Lexer struct
 */
class Lexer {
private:
    Cursor cursor;   // Manages the position during lexical analysis.
    
public:
    char& current_tok; // Reference to the current character being processed.
    long& pos;  // Reference to the current position in the file.
    int line;  // Tracks the current line number.
    int pos_line; // Position within the current line.


private:

    /* ---- UTILITY FUNCTIONS ---- */

    // Creates a Position object based on the current cursor position.
    const Position create_position() const;

    const Token* create_token(Tokens type, std::string content);

    // Creates a new token of the specified type.
    const Token* create_token(Tokens type);
    
    // Creates a new token from the passed char
    const Token* create_token(char c);

    // Checks if the current character matches the specified one.
    bool check(char maybe);

    // Checks if the end of the file has been reached.
    bool has_end() const;

    // Moves the cursor to the next character in the source code.
    void advance();

    // Moves the cursor forward by 'n' characters.
    void advance_n(int n);

    /* ---- SCANNER FUNCTIONS ---- */

    const Token* scan_colon();

    // Scans a string enclosed by quotation marks.
    const Token* scan_text(char quote_type);

    // Scans a single-character token.
    const Token* scan_single();

    // Scans a token that starts with a slash ('/'), useful for division or comments.
    const Token* scan_slash();

    // Scans identifiers and keywords.
    const Token* scan_identifier();

    // Scans integer or floating-point numbers.
    const Token* scan_number();

public:
    // Constructor that initializes the lexer with a given file.
    Lexer(const char* filename);

    // Scans and returns the next token in the source code.
    const Token* scan();
};

} // namespace Scan
} // namespace Scrap

#endif // LEXER_H
