/************************muradAghaGhassanA2.c**************
Student Name: Ghassan Murad Agha  Email Id: gmuradag
Due Date: Novemeber 8 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall muradAghaGhassanA2.c muradAghaGhassanA2Main.c
Running: ./a.out
OR
gcc -std=c99 -Wall muradAghaGhassanA2.c muradAghaGhassanA2Main.c -o assn2
Running the Program: ./assn2
*********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "givenA2.h" //include the needed libraries

void readIPAddress (char ipAddress []){ // Task 1

    int octetInput1 = -1, octetInput2 = -1, octetInput3 = -1, octetInput4 = -1; //these will hold the integer user input
    ipAddress[0] = '\0'; //initalize it to 0 at the begining
    char string1[10], string2[10], string3[10], string4[10]; //create 4 string arrays that will be used to concatenate the strings
    // with the dots


    //ask for each octet below
    while (octetInput1 < 0 || octetInput1 > 127){     //octet#1 
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%d", &octetInput1); 
    }
    //turn each integer input into a string with a dot at the end
    sprintf(string1, "%d.", octetInput1); 
    //concatenate
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
    int octet0, octet1, octet2, octet3; //these are variables for the value of each octet as an integer without the dot
    int octetOfBinary0[8], octetOfBinary1[8], octetOfBinary2[8], octetOfBinary3[8]; //these are arrays of 8 bits for each octet
    //in binary
    int allOctets[36]; //this is the array of the whole ipaddress in 1 and 0
    long decimal; //this is where the final decimal of the ip will be held 
    

    // Attempt to parse IP address into four integers
    sscanf(ipAddress, "%d.%d.%d.%d", &octet0, &octet1, &octet2, &octet3); //remove the dots

    
    convertToBinary(octet0, octetOfBinary0); //turn octet0 into binary array octetofbinary0
    convertToBinary(octet1, octetOfBinary1);
    convertToBinary(octet2, octetOfBinary2); 
    convertToBinary(octet3, octetOfBinary3); 

    combineAllOctets(octetOfBinary0, 0, allOctets);  //concatenate each array of binary into the final array at each position
    //spot 
    combineAllOctets(octetOfBinary1, 8, allOctets); 
    combineAllOctets(octetOfBinary2, 16, allOctets); 
    combineAllOctets(octetOfBinary3, 24, allOctets); 

    decimal = convertBinaryToDecimal(allOctets); //this function converts the string of binary into a decimal

    *numDigits = countDig(decimal); //this will update the value of numDigits, it is the total digits of the decimal value 
    //of the ip 

    return decimal;//return the decimal of the ipaddress
}

void convertToBinary (int octet, int octetBinary [8]){  //this function turns each octet int into a binary array

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
    decimal = strtol(binaryStr, NULL, 2); //turn the string of binary into a decimal
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

    sscanf(ipAddress, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]); //remove the dots

    if (octets[1] >= 240 && octets[1] <= 255) { //see which class octet 2 belongs to
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

