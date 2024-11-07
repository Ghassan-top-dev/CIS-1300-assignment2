#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "givenA2.h"



int main(){
   


    char ipAddress[16]; 
    int numDigits = 0;
    int lengthIPAddr = 300; 

    printf("Testing Task 1 in main\n\n"); 

    readIPAddress (ipAddress);
    printf("IP Addr: %s", ipAddress); //task 1
    printf("\n\nTask 1 ends"); 


    long decimal = convertIPToLongNumber(ipAddress, lengthIPAddr, &numDigits); 
    
    printf("\n\nTesting Task 2 in main"); 
    printf("\n\nipDecimal = %ld", decimal); //task 2
    printf("\nNumber of digits  = %d", numDigits); //task 2
    printf("\nTask 2 ends"); 

    printf("\n\nTesting Task 3 in main"); 
    printf("\n\nClass for %s = %c", ipAddress, classifyIPAddress(ipAddress)); //task 3
    printf("\nTask 3 ends\n\n"); 



    
    return 0; 
}
