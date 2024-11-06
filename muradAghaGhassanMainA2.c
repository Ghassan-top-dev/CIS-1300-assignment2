#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "givenA2.h"


int main(){

    char ipAddress[36]; //is this legal? is this what I am suppoused to do? - YES

    int *ptr = 0; 

    readIPAddress (ipAddress);
    printf("IP Addr: %s", ipAddress); 

    // countDig(ipAddress); I don't understand how I am suppoused to get the length of ipAddress
    //when it is a string and countDig takes an int
    // printf("Length of ip address: %d", ipAddress); 

    // convertIPToLongNumber(ipAddress, 0, ptr);

    printf("\n\n%ld", convertIPToLongNumber(ipAddress, 0, ptr));

    




    return 0; 
}
