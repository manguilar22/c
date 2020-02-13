#include <stdio.h> 

// Working with Strings 
int space_char(char c); 

int non_space_char(char c); 

//char *word_start(char *c); 

//char *word_end(char *s); 

//int count_words(char *s); 

// READ Chapter 6

int main(){



	char scanner [50];

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
	printf("%d",space_char(' ')); 
	return 0; 

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
	if ((c != '\t' || c !=' ') && c != '\0') 	{
		return 1; 
	}
	return 0; 
	
}
