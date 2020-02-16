#include <stdio.h>

// Proto-typing
void printCharacters(char *myArray);

int main(void)
{

    char myArray[100] = {"This is a really long string of characters"};

    printCharacters(myArray);

    // https://www.tutorialspoint.com/cprogramming/c_pointers.htm

    int  var = 20;   /* actual variable declaration */
    int  *ip;        /* pointer variable declaration */

    ip = &var;  /* store address of var in pointer variable*/

    printf("Address of var variable: %p\n", &var  );

    /* address stored in pointer variable */
    printf("Address stored in ip variable: %p\n", ip );

    /* access the value using the pointer */
    printf("Value of *ip variable: %d\n", *ip );

    // NULL Pointers
    int  *ptr = NULL;
    printf("The value of ptr is : %p\n", ptr );

    int a = 10;
    int *p = &a;



    printf("This is the magic character number:\t%d",*p);


    return 0;

}


void printCharacters(char *myArray)
{
    while (*myArray != '\0')
    {
        printf("%c",*myArray);
        ++myArray;
    }


}

