#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "givenA2.h"


int main(){

    char ipAddress[16]; //is this legal? is this what I am suppoused to do? - YES

    int *ptr = 0; 
    printf("Testing Task 1 in main\n\n"); //do I have these here?

    readIPAddress (ipAddress);
    printf("IP Addr: %s", ipAddress); //task 1
    printf("\n\nTask 1 ends"); //do I have these here?


    long decimal = convertIPToLongNumber(ipAddress, 0, ptr); 
    
    printf("\n\nTesting Task 2 in main"); //do I have these here?
    printf("\n\nipDecimal = %ld", decimal); //task 2
    printf("\nNumber of digits  = %d", countDig(decimal)); //task 2
    printf("\nTask 2 ends"); //do I have these here?

    printf("\n\nTesting Task 3 in main"); //do I have these here?
    printf("\n\nClass for %s = %c", ipAddress, classifyIPAddress(ipAddress)); //task 3
    printf("\nTask 3 ends\n\n"); //do I have these here?
    return 0; 
}
