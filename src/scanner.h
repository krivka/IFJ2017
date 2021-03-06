/**
 * @file scanner.h
 * @author Jan Bartosek (xbarto92)
 * @brief Defines the values for every posible lexem that can come from an input file.
 */

#ifndef IFJ_SCANNER_H
#define IFJ_SCANNER_H

typedef enum {
	ID, // _ or ABC_abc95
	NUMBER, // int value 123456
	DECIMAL_NUMBER, // float value 123.456 or 123e456 or 123.456E-789
	STRING_EXPRESSION, // Has to start: !"my string" .. returns only my string.

	PLUS, // +
	MINUS, // -
	MULTIPLY, // *
	DIVISION, // /
	BACKSLASH, // \.
	ASSIGNMENT, // =

	PLUS_ASSIGNMENT, // +=
	MINUS_ASSIGNMENT, // -=
	MULTIPLY_ASSIGNMENT, // *=
	DIVISION_ASSIGNMENT, // /=
	BACKSLASH_ASSIGNMENT, // \=

	LESS, // <
	LESS_EQUAL, // <=
	GREATER, // >
	GREATER_EQUAL, // >=
	NOT_EQUAL,// <>

	BRACKET_LEFT, // (
	BRACKET_RIGHT, // )
	COMMA, // ,
	SEMICOLON, // ;

	//Keywords
	AS = 30,
	ASC = 31,
	DECLARE = 32,
	DIM = 33,
	DO = 34,
	DOUBLE = 35,
	ELSE = 36,
	END = 37,
	CHR = 38,
	FUNCTION = 39,
	IF = 40,
	INPUT = 41,
	INTEGER = 42,
	LENGTH = 43,
	LOOP = 44,
	PRINT = 45,
	RETURN = 46,
	SCOPE = 47,
	STRING = 48,
	SUBSTR = 49,
	THEN = 50,
	WHILE = 51,
	AND = 52,
	BOOLEAN = 53,
	CONTINUE = 54,
	ELSEIF = 55,
	EXIT = 56,
	FALSE = 57,
	FOR = 58,
	NEXT = 59,
	NOT = 60,
	OR = 61,
	SHARED = 62,
	STATIC = 63,
	TRUE = 64,
} lexems;

#define EOL '\n'

// Keywords
/*
 * The value of keywords increments depending on position in array.
 * The value of the keyword "As" is 30, then "Asc" is equal to 1 ...
 * The last value "True" is set to 64.
 * All the values can be found above
 */
extern char *keyWords[];

// Error codes
#define LEX_ERROR -1

/**
 * @param f - this is an input file in IFJ2017 language.
 *
 * Gets input file from main and initialise global variable.
 */
void setSourceFile(FILE *f);

/**
 * @return lexems - value of the last lexem
 *
 * Function is called in parser.h to get value of every single word or char from the input file.
 * It reads char by char from the input file until it can decide what kind of word it is.
 * Then it sends back a "token" of lexems datatype that represents what was read in the input file.
 *
 * If an ID or a Number came in, the function saves the name in a symbol table represented by a binary tree.
 */
lexems getNextToken();

#endif