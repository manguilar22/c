#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "tokenizer.c" // REMOVE ME

// Linked List (github.com/robustUTEP)
#include "history.h"
#include "history.c" // REMOVE ME

// MAX_SIZE for INPUT BUFFER
#define MAX_SIZE 100

int main()
{

	char scanner[MAX_SIZE];

	List *history = init_history();

    /*
     * PROMPT
     */
    printf("[+] Tokenizer Project, press \'q\' to quit\n");
    do
        {
        printf("(Prompt)>\t");
        fgets(scanner,MAX_SIZE,stdin);

        if (*scanner != 'q' && *scanner != '!')         // QUIT button and HISTORY button
        {
            printf("\n[!] Your word is: %s\n", scanner);

            char *copy = copy_str(scanner, sizeof(scanner));

            char *pa = word_start(copy);
            char *pe = word_end(copy);
            int count = count_words(copy);
            int len = string_length(copy);

            // Functions Start Here
            printf("[-] Word Start: %s\n", pa);
            printf("[-] Word End: %s\n", pe);
            printf("[-] Word Count: %d\n", count);
            printf("[-] Length of string: %d\n", len);

            printf("\n[+] Printing Tokens [+]\n");
            // Milestone
            char **tokens = tokenize(copy);
            print_tokens(tokens);
            free_tokens(tokens);
        }
    } while (*scanner != 'q');

    return 0;

}
