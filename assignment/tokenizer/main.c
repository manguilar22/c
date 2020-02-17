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
	//printf("Space_Char:\t%d",space_char(' ')); 
	//printf("Non-Space-Char:\t%d",non_space_char('\t')); 


	char a = 'a';
    printf("Do something:\t%p\n",word_start(&a));
	char *p = word_start(&a);
	printf("Do Something Cooler:\t%c\n",*p);

	 char arr[MAX_SIZE] = "ab bb cc";
	 char test[MAX_SIZE];
	 char *pa = word_start(arr);
	 printf("%c\n",*pa);
	 printf("%c\n",*word_start(test));


     return 0;

}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{

}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str)
{
    if ( str == NULL) {
        return 0;
    }
    for (int i = 0; i < sizeof(str); i++)
    {
        if ( ! (str[i] != ' '))
        {
            return str;
        }
    }
    return str;
}

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if
   str does not contain any space characters. */
char *word_end(char *s)
{

}

int space_char(char c)
{

	if ((c == ' ' || c == '\t' )&& c != '\0') 
	{
		return 1; //true 
	}

	return 0; //false  

}

int non_space_char(char c) 
{
	if ((c != '\t' || c !=' ') && c != '\0')
	{
		return 1; 
	}
	return 0; 
	
}
