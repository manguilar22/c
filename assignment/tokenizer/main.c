#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"

#define MAX_SIZE 100

void simple_ui(); // TODO:

int string_length(char *string);

// READ Chapter 6

int main()
{

	char scanner[MAX_SIZE];

	/*
	do { 
	printf("(Prompt)>\t");
	fgets(scanner,50,stdin); 
	printf("%s",scanner); 
	} while (scanner != '\0'); 
	*/

	 //char arr[MAX_SIZE] = "  ba bb cc";
	 //char arr[MAX_SIZE] = "test1 test2";
	 char arr[MAX_SIZE] = "a b c";

	 //char test[15] = "Hello World";
     char *newTest = copy_str(arr,2);
	 printf("[+] Print Test:%s\n\n",newTest);

    char *pa = word_start(arr);
    char *pe = word_end(arr);
    int count = count_words(arr);
    int len = string_length(arr);
    printf("\n[+]Word Start:%s\n[+]Word End:%s\n[+]Word Count:%d\nLength of string:%d\n",pa,pe,count,len);



    return 0;

}

// Helper Function: string length
int string_length(char *string)
{
    int length = 0;
    while (*string)
    {
        *string++;
        length++;
    }
        return length - 1; // Minus one, because of strings ending with \0
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
    char *newStorage = malloc(len * sizeof(char*));
    for (int i = 0; i< len; i++)
    {
        newStorage[i] = inStr[i];
    }
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

}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{

}

char** tokenize(char* str)
{


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
    return words;
}

/**
 * https://stackoverflow.com/questions/1726302/removing-spaces-from-a-string-in-c
 */
/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str)
{
    int i;

    if ( str == NULL) {
        return 0;
    }
    while (str[i] != '\0')
    {
        if (non_space_char(str[i]) != 0)
        {
            return &str[i];
        }
        i++;
    }
}

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if
   str does not contain any space characters. */
char *word_end(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if(space_char(str[i]) == 1)
        {
            return &str[i];
        }
        i++;
    }
    return 0;
}


/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
    if (c == ' '|| c == '\t')
        return 1;
    return 0;
}


/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) 
{
    if ( c == ' ' || c == '\t' ||  c == '\0')
        return 0;
    return 1;
}
