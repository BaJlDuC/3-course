package com.lexer;

public enum TokenType {
    End_of_input, Multiply,  Divide, StartComment, EndComment, Mod, Plus, Minus, Not, Less, LessEqual, Greater, GreaterEqual,
    Equal, NotEqual, Assign, And, Or, Keyword_if,
    Keyword_else, Keyword_while, Keyword_print, Keyword_read, Keyword_integer, Keyword_string, Keyword_hex, Keyword_return, Keyword_binary, Keyword_void, Keyword_main,
    Keyword_import, Keyword_class, Keyword_public, Keyword_static, Keyword_package, Keyword_private, Keyword_bool, Keyword_true, Keyword_false, LeftParentheses, RightParentheses,
    Begin, End, Semicolon, Comma, Dot, Identifier, Integer, String, Binary, Hexadecimal, FloatPointNumber, Error
}
