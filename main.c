#include <stdio.h>

// Proto-typing
void printCharacters(char *myArray);

int main(void)
{

    char myArray[100] = {"This is a really long string of characters"};

    printCharacters(myArray);

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

