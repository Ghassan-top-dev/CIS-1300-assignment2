#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "givenA2.h"

// gcc -std=c99 -Wall muradAghaGhassanA2.c muradAghaGhassanA2Main.c
void readIPAddress (char ipAddress []){ // Task 1

    int octetInput1 = -1, octetInput2 = -1, octetInput3 = -1, octetInput4 = -1; 
    ipAddress[0] = '\0';
    char string1[10], string2[10], string3[10], string4[10];

    while (octetInput1 < 0 || octetInput1 > 127){     //octet#1
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%d", &octetInput1); 
    }
    sprintf(string1, "%d.", octetInput1); 
    strcat(ipAddress,string1);

    while (octetInput2 < 0 || octetInput2 > 255){     //octet#2
        printf("Octet#2 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput2); 
    }
    sprintf(string2, "%d.", octetInput2); 
    strcat(ipAddress, string2);

    while (octetInput3 < 0 || octetInput3 > 255){    //octet#3
        printf("Octet#3 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput3); 
    }
    sprintf(string3, "%d.", octetInput3); 
    strcat(ipAddress, string3);

    while (octetInput4 < 0 || octetInput4 > 255){     //octet#4
        printf("Octet#4 - Enter a number - must be between 0 and 255: ");
        scanf("%d", &octetInput4); 
    }
    sprintf(string4, "%d", octetInput4); 
    strcat(ipAddress, string4);
}

long int convertIPToLongNumber ( char ipAddress [], int lengthIPAddr, int * numDigits){
    int octet0, octet1, octet2, octet3;
    int octetOfBinary0[8], octetOfBinary1[8], octetOfBinary2[8], octetOfBinary3[8];
    int allOctets[36]; 
    long decimal; 
    

    // Attempt to parse IP address into four integers
    sscanf(ipAddress, "%d.%d.%d.%d", &octet0, &octet1, &octet2, &octet3);

    
    convertToBinary(octet0, octetOfBinary0); 
    convertToBinary(octet1, octetOfBinary1);
    convertToBinary(octet2, octetOfBinary2); 
    convertToBinary(octet3, octetOfBinary3); 

    combineAllOctets(octetOfBinary0, 0, allOctets); 
    combineAllOctets(octetOfBinary1, 8, allOctets); 
    combineAllOctets(octetOfBinary2, 16, allOctets); 
    combineAllOctets(octetOfBinary3, 24, allOctets); 

    decimal = convertBinaryToDecimal(allOctets); 

    *numDigits = countDig(decimal); 

    return decimal;
}

void convertToBinary (int octet, int octetBinary [8]){ 

    int div = octet;
    for (int i = 7; i >= 0; i--) {
        octetBinary[i] = div % 2;
        div = div / 2;
    }
}


void combineAllOctets (int octetBinary[8], int pos, int binaryAllOctets [32]){

    int j = 0; 

    for (int i = pos; i < pos + 8; i++)
    {
        binaryAllOctets[i] = octetBinary[j]; 
        j++; 
    }
}


long int convertBinaryToDecimal (int binaryAllOctets [32]){
    char placeHolderTemp[36] = ""; //this will temperorially hold each binary block
    char binaryStr[36] = ""; //this will hold the full binary string
    int i; 
    long decimal; 
    for(i = 0; i < 32; i++){
        sprintf(placeHolderTemp, "%d", binaryAllOctets[i]);
        strcat(binaryStr,placeHolderTemp); 
    }
    decimal = strtol(binaryStr, NULL, 2);
    return decimal; 
}

int countDig (int finalLong){ //digit counter

    int counter = 0; 
    do {
    finalLong /= 10;
    ++counter;
    } while (finalLong != 0);

    return counter; 
}


char classifyIPAddress (char ipAddress []){ //task 3

    int octets[4];

    sscanf(ipAddress, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    if (octets[1] >= 240 && octets[1] <= 255) {
        return 'E'; 
    } 
    else if (octets[1] >= 224 && octets[1] <= 239) {
        return 'D'; 
    } 
    else if (octets[1] >= 192 && octets[1] <= 223) {
        return 'C'; 
    } 
    else if (octets[1] >= 128 && octets[1] <= 191) {
        return 'B'; 
    } 
    else if (octets[1] >= 0 && octets[1] <= 127) {
        return 'A'; 
    }else{
        return 0; 
    }
}
