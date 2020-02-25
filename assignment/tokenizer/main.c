#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "tokenizer.c"

// Linked List (github.com/robustUTEP)
#include "llist.h"

#define MAX_SIZE 100

int main()
{

	char scanner[MAX_SIZE];

    /*
     * PROMPT
     *
     */

    printf("[+] Tokenizer Project, press \'q\' to quit\n");
    do {
        printf("(Prompt)>\t");
        fgets(scanner,50,stdin);
        printf("%s",scanner);

    char *copy = copy_str(scanner, sizeof(scanner));

    char *pa = word_start(copy);
    char *pe = word_end(copy);
    int count = count_words(copy);
    int len = string_length(copy);

    printf("[-] Word Start: %s\n",pa);
    printf("[-] Word End: %s\n",pe);
    printf("[-] Word Count: %d\n",count);
    printf("[-] Length of string: %d\n",len);

    printf("\n[+] Printing Tokens [+]\n");
    // Milestone
    char **tokens = tokenize(copy);
    print_tokens(tokens);
    free_tokens(tokens);
    } while (scanner != '\0');

    return 0;

}
