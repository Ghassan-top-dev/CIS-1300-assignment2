//Conversion not working...

#include <stdio.h>    // Includes the standard input-output library for functions like printf
#include <string.h>   // Includes the string library for functions like strtok
#include <stdlib.h>


int main() {
    // Declare and initialize an IP address as a string
    char ip[] = "198.78.1.0";  // This is the IP address we want to process
    int i = 0, j; 
    int arr[4]; //stores how many elements each octet has
    int octets[4]; //stores the actual elements of each octet
    int div;
    int counter = 0;
    int runner = 1; //not sure why but got it from lab


    // Declare character arrays to store different parts of the IP address as needed
    char ipStr[16] = "";   // Array to store the final concatenated IP address if needed (not used in this code)

    // Use strtok to split the IP address by the period (.) character
    char *token = strtok(ip, ".");  // strtok modifies the original string, replacing each '.' with '\0'
                                     // and returns a pointer to the first token (i.e., "129")

    // Loop through all tokens (segments of the IP address) until there are none left
    while (token != NULL) {   // strtok returns NULL when there are no more tokens
    
        strcat(ipStr,token);

        arr[i] = strlen(token); //this gets the length of each octet
        octets[i] = atoi(token);



        i++; 

        // Move to the next token (i.e., the next segment of the IP address)
        token = strtok(NULL, ".");  // strtok continues from where it left off, returning the next token

    }

    

     for (i = 0; i < 4; i++) { //prints the length of each octet
        printf("%d\n", arr[i]);
    }

    
    
    printf("\n\n\n"); 
    // Print the content of newIp1, which holds the last segment processed in the loop
    printf("newIp1: %s\n", ipStr);  // This prints the last value of newIp1 after the loop completes


    //int ipNumber = atoi(ipStr);

    long ipNumber = strtoull(ipStr, NULL, 10);


    printf("\n%ld", ipNumber);


    printf("\n\n\n"); 


    div = octets[counter]; 
    do{
		
		octets[counter] = div % 2;
		div = div / 2;
		counter++;
		
		if(div == 0){
			runner = 0;
		}

	}while(runner == 1);

	
	
	for(i = counter -1; i>=0;i--){


		printf("%d", octets[i]);
	}

      




    return 0;  // End of the main function, returns 0 to indicate successful execution
}
