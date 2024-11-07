//how can I turn the smaller binary values into a long binary value - calm down baby

//This will turn string with dots into smaller blocks of binary integers (4 of them)
//convert each block into a string, concatanate, then turn into long int using atol
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "givenA2.h"

int main() {
    char ip[] = "1.1.1.1";  // IP address to process
    int octet0, octet1, octet2, octet3;
    int newOctet[16]; 
    int i, j, div;
    int bits = 0; //how many iterations? 8 of course
    long finalLong;
    char placeHolderTemp[36] = ""; //this will temperorially hold each binary block
    char binaryStr[36] = ""; //this will hold the full binary string
    int octetOfBinary0[8], octetOfBinary1[8], octetOfBinary2[8], octetOfBinary3[8];
    int test;
    int allOctets[36]; 
    long decimal; 
    

    // Attempt to parse IP address into four integers
    int result = sscanf(ip, "%d.%d.%d.%d", &octet0, &octet1, &octet2, &octet3);

    
    convertToBinary(octet0, octetOfBinary0); 
    convertToBinary(octet1, octetOfBinary1);
    convertToBinary(octet2, octetOfBinary2); 
    convertToBinary(octet3, octetOfBinary3); 

    combineAllOctets(octetOfBinary0, 0, allOctets); 
    combineAllOctets(octetOfBinary1, 8, allOctets); 
    combineAllOctets(octetOfBinary2, 16, allOctets); 
    combineAllOctets(octetOfBinary3, 24, allOctets); 

    for (i = 0; i < 32; i++)
    {
        printf("%d", allOctets[i]); 
    }
    printf("\n\n\n"); 

    decimal = convertBinaryToDecimal(allOctets); 

    printf("%ld", decimal); 
    *numDigits = countDig(decimal); 

    return 0;
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


