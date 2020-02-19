#include <stdio.h> 
#include "tokenizer.h"

#define MAX_SIZE 100

void simple_ui(); // TODO:

// READ Chapter 6

int main()
{

	char scanner[MAX_SIZE];

	// Milestone 1: Echo  
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

	 char *pa = word_start(arr);
	 char *pe = word_end(arr);
	 int count = count_words(arr);

	 printf("\n[+]Word Start:%s\n[+]Word End:%s\n[+]Word Count:%d\n",pa,pe,count);


     return 0;

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
