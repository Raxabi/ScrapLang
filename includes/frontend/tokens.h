// tokens.h -- Definitions for valid tokens in a ScrapLang source file

#ifndef TOKENS_H
#define TOKENS_H

#include <map>
#include <string>

// macro representing a white space
#define WHITE_SPACE 0x20

// macro representing a new line character (\n)
#define NEW_LINE    0x0a

namespace Scrap {
namespace Scan {

enum class Tokens {
    // KEYWORDS
    keywords_open,
        FN,         // fn
        VAR,        // var
        CONST,      // const
        RETURN,     // return
        IMPORT,     // import
        FROM,       // from
        EXPORT,     // export
        CLASS,      // class
        TYPE,       // type
        INTERFACE,  // interface
        ENUM,       // enum
        MODULE,     // module
        FOR,        // for
        WHILE,      // while
        DO,         // do
        BREAK,      // break
        SKIP,       // skip
        IF,         // if
        ELSE,       // else
        ELIF,       // elif
        MATCH,      // match
        SWITCH,     // switch
        EXTENDS,    // extends
        IMPLEMENTS, // implements
        CASE,       // case
        DEFAULT,    // default
        OF,         // of
        TRY,        // try
        CATCH,      // catch
        PUBLIC,     // public
        PRIVATE,    // private
        PROTECTED,  // protected
        STATIC,     // static
        OVERRIDE,   // override
        SETTER,     // setter
        GETTER,     // getter
        ASYNC,      // async
        AWAIT,      // await
    keywords_close,

    // OPERATORS OPEN
    // 1º OPERATORS WHICH ARE WORDS
    operators_open,
        IN,         // in
        AND,        // and
        OR,         // or
        NOT,        // not
        INSTANCEOF, // instanceof
        AS,         // as
        NEW,        // new
        DROP,       // drop

        // 2º OPERATORS WHICH ARE TOKENS
        PLUS,    // +
        MINUS,   // -
        STAR,    // *
        SLASH,   // /
        PERCEN,  // %
        LESS,    // <
        GREATER, // >
        DOT,     // .
        LSQRBR,  // [
        BANG,    // !
        LPAREN,  // (
        AMPER,   // &
        EQUAL,   // =

        // 3º OPERATORS WHICH ARE COMPOUNDED TOKENS
        MOD_ACCESSOR, // ::
        INCREMENT,    // ++
        DECREMENT,    // --
        POWER,        // **

        LESS_EQUAL,  // <=
        GREAT_EQUAL, // >=

        SLICE,      // ..
        EQUALS,     // ==
        NOT_EQUALS, // !=

        ADD_ASSIGN,   // +=
        MINUS_ASSIGN, // -=
        MULT_ASSIGN,  // *=
        DIV_ASSIGN,   // /=
        MOD_ASSIGN,   // %=
    operators_close,
    // OPERATORS END

    // SIMPLE TOKENS
    literals_open,
        STRING, // "hola"
        CHAR,   // 'b'
        NUMBER, // 777
        FLOAT,  // 3.14
    literals_close,

    IDENTIFIER, // bruh

    // DELIMITERS
    LBRACE,     // {
    RBRACE,     // }

    // CLOSING
    RSQRBR,     // ]
    RPAREN,     // )

    // SIMPLE TOKENS
    COLON,      // :
    SEMICOLON,  // ;
    UNDERSCORE, // _
    QUESTION,   // ?
    COMMA,      // ,
    SPREAD,     // ...

    EO_FILE,
    UNKNOWN
};

extern const std::map<Tokens, std::string> tokens;
extern const std::map<std::string, Tokens> r_tokens;

} // namespace Scan
} // namespace Scrap

#endif // TOKENS_H