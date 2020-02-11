#include <stdio.h> 
#include <stdbool.h>
int main(){



	char scanner [50];
	bool flag = false; 
	// Milestone 1: Echo  
	do { 
	printf(">\t");
	fgets(scanner,50,stdin); 
	printf("%s",scanner); 
	} while (scanner != '\0'); 
	return 0; 

}
