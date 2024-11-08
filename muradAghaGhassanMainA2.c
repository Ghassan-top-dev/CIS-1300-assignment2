/************************muradAghaGhassanA2Main.c**************
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
#include "givenA2.h" //include needed libraries 



int main(){
   


    char ipAddress[16]; //set a variable for the ipaddress
    int numDigits = 0; //numdigits variables
    int lengthIPAddr = 0; //set the length to 0 for the sake of initalizing the variable

    printf("Testing Task 1 in main\n\n"); 

    readIPAddress (ipAddress); //input ipAddress, this is where the user inputted ipaddress wil be 
    printf("IP Addr: %s", ipAddress); //task 1 
    printf("\n\nTask 1 ends"); 


    long decimal = convertIPToLongNumber(ipAddress, lengthIPAddr, &numDigits); //task 2, enter the ipaddress the user
    //created, the length of the ipaddress, and the number of digits variable
    
    printf("\n\nTesting Task 2 in main"); 
    printf("\n\nipDecimal = %ld", decimal); //task 2
    printf("\nNumber of digits  = %d", numDigits); //task 2
    printf("\nTask 2 ends"); 

    printf("\n\nTesting Task 3 in main"); 
    printf("\n\nClass for %s = %c", ipAddress, classifyIPAddress(ipAddress)); //task 3 
    //print the class of the ipaddress 
    printf("\nTask 3 ends\n\n"); 



    
    return 0; 
}
