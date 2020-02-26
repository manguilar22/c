#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// Development
char** tokenizeME(char* str);
void print_ME(char **tokens);

int string_length(char *string);

int is_valid_character(char c);

// Helper Function: character validity
int is_valid_character(char c)
{
    if (0x61 >= c && c <= 0x7a)
        return 1; //True
    else
        return 0; //False
}

// Helper Function: string length
int string_length(char *string)
{
    int index = 0;
    int result = 0;
    while (string[index])
    {
        result++;
        index++;
    }
    return result - 1; // Minus one, because of strings ending with \0
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
    char *newStorage = (char*) malloc(len+1 * sizeof(char*));

    int i = 0;
    while (len > i)
    {
        newStorage[i] = inStr[i];
        i++;
    }
    newStorage[len] = '\0';
    return newStorage;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
/* Prints all tokens. */
void print_tokens(char **tokens)
{
    int index = 0;
    while (tokens[index])
    {
        printf("[*] token[%d] => %s\n", index, tokens[index]);
        index++;
    }
    printf("[*] token[%d] => %s\n",index,"0"); //?

}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
    int index = 0;
    while (tokens[index])
    {
        free(tokens[index]); // Part of stdlib.h
        index++;
    }
    free(tokens); // Part of stdlib.h

}


/* Tokenize String */
char** tokenize(char* str)
{
    int index = 0;
    int distance = 0;

    int get_total_number_of_tokens = count_words(str); // GET TOKEN COUNT, SO YOU KNOW HOW MANY THERE ARE !!!

    // ALLOCATE MEMORY BASED ON LENGTH OF THE WHOLE STRING
    char **new_storage = (char **)malloc(sizeof(char*) * (string_length(str)));

    while(get_total_number_of_tokens > index)
    {

        str = word_start(str);

        // find the distance between words separated by characters
        distance = word_end(str) - str;

        new_storage[index] = copy_str(str, distance);

        // POINT TO NEXT WORD
        str = word_end(str);

        // UPDATE INDEX
        index++;
    }

    new_storage[index] = '\0';

    return new_storage;

}




/* Counts the number of words in the string argument. */
int count_words(char *str)
{
    int words = 0;
    if (str == 0)
        return 0;
    while (*str)
    {
        if (*str == ' ')
            words++;
        ++str;
    }
    return words+1;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str)
{
    if (str == NULL) {
        return 0;
    }

    // ignore breaks in string
    while (space_char(*str)) {
        str++;
    }

    return str;
}

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if
   str does not contain any space characters. */
char *word_end(char *str)
{
    int i = 0;
    if (*str == '\0')
    {
        return 0;
    }

    while (str[i] != '\0') {
        if(space_char(str[i]) == 1)
        {
            return &str[i];
        }
        i++;
    }
}

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
    if (c == ' '|| c == '\t' || c == '\0')
        return 1;
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
    if (space_char(c) || c == '\0')
        return 0;
    return 1;
}
