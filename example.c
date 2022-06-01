/* This file is a clone of example.c */

#include "jsmn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A small example of jsmn parsing when JSON structure is known and number of 
 * tokens is predictable.
 */

static const char * JSON_STRING = 
    "{\"user\": \"johndoe\", \"admin\": false, \"uid\": 1000, \n "
    "\"groups\": [\"users\", \"wheel\", \"audio\", \"video\"]}";

/* json will have starting address of the string/input we're passing
 * Comparing keys which is of STRING type and we already know the JSON structure
 * Making a compare operation on the expected key and actual key and deciding
 * whether the input key is as expected or not
 */
static int jsoneq(const char *json, jsmntok_t *tok, const char *s){
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
        strncmp(json + tok->start, s, tok->end - tok->start) == 0){
        return 0;
        }
    return -1;
}

int main() {
    int i;
    int r; // stores count of total number of tokens present in the input string
    jsmn_parser p;
    jsmntok_t t[128]; // Maximum 128 tokens can be saved
    
    jsmn_init(&p);
    r = jsmn_parse(&p, JSMN_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));

    /*
     * r stores the count of total number of tokens present in the input JSON_STRING
     */
    if (r < 0) {
        printf("Failed to parse JSON input: %d\n", r);
    }

    /*
     * Assume the top-level element is an object
     * First token should be always object type. 
     * In order words, complete input is considered as an one object. 
     */
    if (r < 1 || t[0].type != JSMN_OBJECT){
        printf("Object expected\n");
    }

    for (i = 1; i < r; i++){
        if (jsoneq(JSON_STRING, &t[i], "user") == 0){
            printf("- User: %.*s\n", t[i + 1].end - t[i + 1].start, 
                    JSON_STRING + t[i + 1].start);
        }
        else if (jsoneq(JSON_STRING, &t[i], "admin") == 0){
            /* Condition to check if the value is either true or false */
            printf("- Admin: %.*s\n", t[i + 1].end - t[i + 1].start, 
                    JSON_STRING + t[i + 1].start);
        }
        else if (jsoneq(JSON_STRING, &t[i], "uid") == 0){
            printf("- Admin: %.*s\n", t[i + 1].end - t[i + 1].start, 
                    JSON_STRING + t[i + 1].start);
        }
        else if (jsoneq(JSON_STRING, &t[i], "group") == 0){
            int j;
            printf("- Groups: \n");
            if (t[i + 1].type != JSMN_ARRAY){
                printf("Array is expected in groups\n");
                continue;
            }
            for (j = 0; j < t[i + 1].size; j++){
                jsmntok_t *g = &t[i + j + 2];
                printf(" * %.*s\n", g->end - g->start, JSON_STRING + g->start);
            }
            i += t[i + 1].size + 1;
        }
        else {
            printf("Unexpected key: %.*s\n", t[i].end - t[i].start, 
                    JSON_STRING + t[i].start);
        }
    }
    return EXIT_SUCCESS;
}

