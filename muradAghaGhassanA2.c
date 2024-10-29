#include <stdio.h>
#include "givenA2.h"

//gcc -Wall -std=c99 muradAghaGhassanA2Main.c muradAghaGhassanA2.c


// Task 1
//is this how the function should be or do I need to have scanf in main? 
void readIPAddress (char ipAddress []){

    int octetInput1 = -1, octetInput2 = -1, octetInput3 = -1, octetInput4 = -1; 
    ipAddress[0] = '\0';
    char string1[10], string2[10], string3[10], string4[10];

    //octet#1
    while (octetInput1 < 0 || octetInput1 > 127){
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%d", &octetInput1); 
    }
    sprintf(string1, "%d.", octetInput1); 
    strcat(ipAddress,string1);

    //octet#2
    while (octetInput2 < 0 || octetInput2 > 255){
        printf("Octet#2 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput2); 
    }
    sprintf(string2, "%d.", octetInput2); 
    strcat(ipAddress, string2);

    //octet#3
    while (octetInput3 < 0 || octetInput3 > 255){
        printf("Octet#3 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput3); 
    }
    sprintf(string3, "%d.", octetInput3); 
    strcat(ipAddress, string3);

    //octet#4
    while (octetInput4 < 0 || octetInput4 > 255){
        printf("Octet#4 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput4); 
    }
    sprintf(string4, "%d", octetInput4); 
    strcat(ipAddress, string4);

    printf("IP Addr: %s", ipAddress); //is this how I am suppoused to print the function?
    //it says not to print it 

}


//task 2

long int convertIPToLongNumber ( char ipAddress [], int lengthIPAddr, int * numDigits);
