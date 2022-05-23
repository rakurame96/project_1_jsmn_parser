Description: 
============
jsmn is a world fastest JSON parser/tokenizer. Easily integrated with any embedded application which has less memory

By making use of jsmn, in this repo I separated the function declarations and function definition into a separate jsmn.c and jsmn.h

Problem Statement:
==================
Most JSON parsers offer you a bunch of functions to load JSON data, parse it and extract any value by its name. jsmn proves that checking the correctness of every JSON packet or allocating temporary objects to store parsed JSON fields often is an overkill.

JSON format itself is extremely simple, so why should we complicate it?

jsmn is designed to be robust (it should work fine even with erroneous data), fast (it should parse data on the fly), portable (no superfluous dependencies or non-standard C extensions). And of course, simplicity is a key feature - simple code style, simple algorithm, simple integration into other projects.

Credits:
========
Source project details: jsmn
Source Link: https://github.com/zserge/jsmn
