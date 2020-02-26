#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
}



/* gets the total length of the string */
int str_length(char *str)
{

    int count;
    for (count = 0; str[count] != '\0'; count++)
    {
        return;
    }
    return count;
}



/* Add a history item to the end of the list.
       List* list - the linked list
       char* str - the string to store
*/
void add_history(List *list, char *str)
{
    // NODE POINTS TO NEXT NODE
    Item *node = (Item *)malloc(sizeof(Item));

    // add char array str to new_item
    node->str  = copy_str(str, str_length(str));
    node->next = NULL;

    // if empty then head = tail = new_item
    if (list->head == NULL)
    {
        list->head   = node;
        list->tail   = node;
        node->id = 1;
    }

    else {
        int prev_id = list->tail->id;
        list->tail->next = node;
        list->tail = node;
        node->id = prev_id + 1;
    }

}



/* Retrieve the string stored in the node where Item->id == id.
       List* list - the linked list
       int id - the id of the Item to find */
char *get_history(List *list, int id)
{
    // Check for Exception
    if (list->tail->id < id)
    {
        printf("Index out of bounds, number should be less than %d\n", list->tail->id);
        return NULL;
    }

    Item *current = list->head;

    // LOOP UNTIL FOUND
    while(current->id != id)
    {
        current = current->next;
    }

    return current->str;
}

/* Print the entire contents of the list. */
void print_history(List *list)
{

    Item *current = list->head;

    while (current != NULL)
    {
        printf(" %s ", current->str);
        current = current->next;
    }
    printf("\n");

}



/* Free the history list and the strings it references. */
void free_history(List *list)
{

    Item *current = list->head;
    Item *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

}

// HELPER FUNCTION: PRINT CHARACTER ARRAY
void print(char *str)
{
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}