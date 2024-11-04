#include <stdio.h>

int main() {
    char ip[] = "198.78.1.0";  // IP address to process
    int octets[4];
    int i, div;
    int bits = 0; //how many iterations? 8 of course

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
        div = octets[i]; 
        do{
            
            octets[bits] = div % 2;
            div = div / 2;
            bits++;
            

        }while(bits != 8);


        for(i = bits -1; i>=0;i--){


            printf("%d", octets[i]);
        }
    }
    


    


    return 0;
}
