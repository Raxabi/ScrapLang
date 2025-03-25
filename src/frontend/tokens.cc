// tokens.cc -- Defines map constants for `Tokens` enumeration

#include <map>
#include <string>

#include "frontend/tokens.h"

namespace Scrap {
namespace Scan {

extern const std::map<Tokens, std::string> tokens = {
    {Tokens::FN,         "fn"},
    {Tokens::VAR,        "var"},
    {Tokens::CONST,      "const"},
    {Tokens::RETURN,     "return"},
    {Tokens::IMPORT,     "import"},
    {Tokens::FROM,       "from"},
    {Tokens::EXPORT,     "export"},
    {Tokens::CLASS,      "class"},
    {Tokens::TYPE,       "type"},
    {Tokens::INTERFACE,  "interface"},
    {Tokens::ENUM,       "enum"},
    {Tokens::MODULE,     "module"},
    {Tokens::FOR,        "for"},
    {Tokens::WHILE,      "while"},
    {Tokens::DO,         "do"},
    {Tokens::BREAK,      "break"},
    {Tokens::SKIP,       "skip"},
    {Tokens::IF,         "if"},
    {Tokens::ELSE,       "else"},
    {Tokens::ELIF,       "elif"},
    {Tokens::MATCH,      "match"},
    {Tokens::SWITCH,     "switch"},
    {Tokens::EXTENDS,    "extends"},
    {Tokens::IMPLEMENTS, "implements"},
    {Tokens::CASE,       "case"},
    {Tokens::DEFAULT,    "default"},
    {Tokens::OF,         "of"},
    {Tokens::TRY,        "try"},
    {Tokens::CATCH,      "catch"},
    {Tokens::PUBLIC,     "public"},
    {Tokens::PRIVATE,    "private"},
    {Tokens::PROTECTED,  "protected"},
    {Tokens::STATIC,     "static"},
    {Tokens::OVERRIDE,   "override"},
    {Tokens::SETTER,     "setter"},
    {Tokens::GETTER,     "getter"},
    {Tokens::ASYNC,      "async"},
    {Tokens::AWAIT,      "await"},

    // OPERATORS OPEN
    // 1º OPERATORS WHICH ARE WORDS
    {Tokens::IN,         "in"},
    {Tokens::AND,        "and"},
    {Tokens::OR,         "or"},
    {Tokens::NOT,        "not"},
    {Tokens::INSTANCEOF, "instanceof"},
    {Tokens::AS,         "as"},
    {Tokens::NEW,        "new"},
    {Tokens::DROP,       "drop"},

    // 2º OPERATORS WHICH ARE TOKENS
    {Tokens::PLUS,    "+"},
    {Tokens::MINUS,   "-"},
    {Tokens::STAR,    "*"},
    {Tokens::SLASH,   "/"},
    {Tokens::PERCEN,  "%"},
    {Tokens::LESS,    "<"},
    {Tokens::GREATER, ">"},
    {Tokens::DOT,     "."},
    {Tokens::LSQRBR,  "["},
    {Tokens::BANG,    "!"},
    {Tokens::LPAREN,  "("},
    {Tokens::AMPER,   "&"},
    {Tokens::EQUAL,   "="},

    // 3º OPERATORS WHICH ARE COMPOUNDED TOKENS
    {Tokens::MOD_ACCESSOR, "::"},
    {Tokens::INCREMENT,    "++"},
    {Tokens::DECREMENT,    "--"},

    {Tokens::LESS_EQUAL,  "<="},
    {Tokens::GREAT_EQUAL, ">="},

    {Tokens::SLICE,       ".."},
    {Tokens::SPREAD,      "..."},
    {Tokens::EQUALS,      "=="},
    {Tokens::NOT_EQUALS,  "!="},

    {Tokens::ADD_ASSIGN,   "+="},
    {Tokens::MINUS_ASSIGN, "-="},
    {Tokens::MULT_ASSIGN,  "*="},
    {Tokens::DIV_ASSIGN,   "/="},
    {Tokens::MOD_ASSIGN,   "%="},
    // OPERATORS END

    // LITERALS ARE DOESNT NEEDED HERE, BECAUSE DOESNT NEED TO BE COMPARED AGAINST NOTHING

    // DELIMITERS
    {Tokens::LBRACE,     "{"},
    {Tokens::RBRACE,     "}"},

    // CLOSING
    {Tokens::RSQRBR,     "]"},
    {Tokens::RPAREN,     ")"},


    // SIMPLE TOKENS
    {Tokens::COLON,      ":"},
    {Tokens::SEMICOLON,  ";"},
    {Tokens::UNDERSCORE, "_"},
    {Tokens::QUESTION,   "?"},
    {Tokens::COMMA,      ","},
};

extern const std::map<std::string, Tokens> r_tokens = {
    {"fn",         Tokens::FN},
    {"var",        Tokens::VAR},
    {"const",      Tokens::CONST},
    {"return",     Tokens::RETURN},
    {"import",     Tokens::IMPORT},
    {"from",       Tokens::FROM},
    {"export",     Tokens::EXPORT},
    {"class",      Tokens::CLASS},
    {"type",       Tokens::TYPE},
    {"interface",  Tokens::INTERFACE},
    {"enum",       Tokens::ENUM},
    {"module",     Tokens::MODULE},
    {"for",        Tokens::FOR},
    {"while",      Tokens::WHILE},
    {"do",         Tokens::DO},
    {"break",      Tokens::BREAK},
    {"skip",       Tokens::SKIP},
    {"if",         Tokens::IF},
    {"else",       Tokens::ELSE},
    {"elif",       Tokens::ELIF},
    {"match",      Tokens::MATCH},
    {"switch",     Tokens::SWITCH},
    {"extends",    Tokens::EXTENDS},
    {"implements", Tokens::IMPLEMENTS},
    {"case",       Tokens::CASE},
    {"default",    Tokens::DEFAULT},
    {"of",         Tokens::OF},
    {"try",        Tokens::TRY},
    {"catch",      Tokens::CATCH},
    {"public",     Tokens::PUBLIC},
    {"private",    Tokens::PRIVATE},
    {"protected",  Tokens::PROTECTED},
    {"static",     Tokens::STATIC},
    {"override",   Tokens::OVERRIDE},
    {"setter",     Tokens::SETTER},
    {"getter",     Tokens::GETTER},
    {"async",      Tokens::ASYNC},
    {"await",      Tokens::AWAIT},

    // OPERATORS OPEN
    // 1º OPERATORS WHICH ARE WORDS
    {"in",         Tokens::IN},
    {"and",        Tokens::AND},
    {"or",         Tokens::OR},
    {"not",        Tokens::NOT},
    {"instanceof", Tokens::INSTANCEOF},
    {"as",         Tokens::AS},
    {"new",        Tokens::NEW},
    {"drop",       Tokens::DROP},

    // 2º OPERATORS WHICH ARE TOKENS
    {"+", Tokens::PLUS},
    {"-", Tokens::MINUS},
    {"*", Tokens::STAR},
    {"/", Tokens::SLASH},
    {"%", Tokens::PERCEN},
    {"<", Tokens::LESS},
    {">", Tokens::GREATER},
    {".", Tokens::DOT},
    {"[", Tokens::LSQRBR},
    {"!", Tokens::BANG},
    {"(", Tokens::LPAREN},
    {"&", Tokens::AMPER},
    {"=", Tokens::EQUAL},

    // 3º OPERATORS WHICH ARE COMPOUNDED TOKENS
    {"::" , Tokens::MOD_ACCESSOR},
    {"++" , Tokens::INCREMENT},
    {"--" , Tokens::DECREMENT},

    {"<=" , Tokens::LESS_EQUAL},
    {">=" , Tokens::GREAT_EQUAL},

    {".." , Tokens::SLICE},
    {"...", Tokens::SPREAD},
    {"==" , Tokens::EQUALS},
    {"!=" , Tokens::NOT_EQUALS},

    {"+=" , Tokens::ADD_ASSIGN},
    {"-=" , Tokens::MINUS_ASSIGN},
    {"*=" , Tokens::MULT_ASSIGN},
    {"/=" , Tokens::DIV_ASSIGN},
    {"%=" , Tokens::MOD_ASSIGN},
    // OPERATORS END

    // LITERALS ARE DOESNT NEEDED HERE, BECAUSE DOESNT NEED TO BE COMPARED AGAINST NOTHING

    // DELIMITERS
    {"{", Tokens::LBRACE},
    {"}", Tokens::RBRACE},

    // CLOSING
    {"]", Tokens::RSQRBR},
    {")", Tokens::RPAREN},

    // SIMPLE TOKENS
    {":", Tokens::COLON},
    {";", Tokens::SEMICOLON},
    {"_", Tokens::UNDERSCORE},
    {"?", Tokens::QUESTION},
    {",", Tokens::COMMA},
};  

} // namespace Scan
} // namespace Scrap
