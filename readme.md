Description: 
============
jsmn is a world fastest JSON parser/tokenizer. Easily integrated with any embedded application which has less memory

By making use of jsmn, in this repo I separated the function declarations and function definition into a separate jsmn.c and jsmn.h

Problem Statement:
==================
Most JSON parsers offer you a bunch of functions to load JSON data, parse it and extract any value by its name. jsmn proves that checking the correctness of every JSON packet or allocating temporary objects to store parsed JSON fields often is an overkill.

JSON format itself is extremely simple, so why should we complicate it?

jsmn is designed to be robust (it should work fine even with erroneous data), fast (it should parse data on the fly), portable (no superfluous dependencies or non-standard C extensions). And of course, simplicity is a key feature - simple code style, simple algorithm, simple integration into other projects.

Explanation:
============
jsmn_init() function --> initializes the parser to default value

jsmn_parse() function --> this function looks loops into the input string and creates multiple tokens of different types (OBJECT, ARRAY, STRING, PRIMITIVE). This operation is done dynamically by looking into the double quotes, braces present in the input as well as looping through chanracters one by one

jsmn_parse_string() function --> this fills the token with next string from the available input

jsmn_alloc_token() function --> this allocates a fresh unused token from the token pool.

jsmn_fill_token() function --> this function fills token type and boundaries

jsmn_parse_primitive() function --> looks for primitives like true, false and assigns them into token 

Credits:
========
Source project details: jsmn
Source Link: https://github.com/zserge/jsmn
