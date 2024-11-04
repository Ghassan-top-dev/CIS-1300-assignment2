//how can I turn the smaller binary values into a long binary value - calm down baby

//This will turn string with dots into smaller blocks of binary integers (4 of them)
//convert each block into a string, concatanate, then turn into long int using atol
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char ip[] = "198.78.1.0";  // IP address to process
    int octets[4];
    int newOctet[16]; 
    int i, j, div;
    int bits = 0; //how many iterations? 8 of course
    long finalLong;
    char placeHolderTemp[36] = ""; //this will temperorially hold each binary block
    char binaryStr[36] = ""; //this will hold the full binary string

    // Attempt to parse IP address into four integers
    int result = sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);


    // Check if all four octets were parsed successfully
    if (result == 4) {

        for (i = 0; i < 4; i++)
        {
            printf("%d", octets[i]);
        }
        
    } else {
        printf("Error: Invalid IP address format.\n");
    }

    printf("\n\n\n"); 

    for (i = 0; i < 4; i++) //run for all 4 octets
    {
        bits = 0;
        div = octets[i]; 
        do{
            
            newOctet[bits] = div % 2;
            div = div / 2;
            bits++;
            

        }while(bits != 8);


        for(j = bits -1; j>=0;j--){

            sprintf(placeHolderTemp, "%d", newOctet[j]);
            strcat(binaryStr,placeHolderTemp); 

 
        }
        

        
    }

    printf("\n%s", binaryStr);
    
    finalLong = strtol(binaryStr, NULL, 2);

    printf("\n%ld", finalLong);



    


    return 0;
}



