#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char ip[] = "198.240.1.0";  // IP address to process
    int octets[4];


    int result = sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    printf("%d", octets[1]); 

    printf("\n\n\n"); 


    //Here I will have the check for octet 2

    if (octets[1] >= 240 && octets[1] <= 255) {
   
        printf("This IP address belongs to class E"); 

    } 
    else if (octets[1] >= 224 && octets[1] <= 239) {
        
        printf("This IP address belongs to class D"); 

    } 
    else if (octets[1] >= 192 && octets[1] <= 223) {
        
        printf("This IP address belongs to class C"); 

    } 
    else if (octets[1] >= 127 && octets[1] <= 191) {
        
        printf("This IP address belongs to class B"); 

    } 
    else if (octets[1] >= 0 && octets[1] <= 126) {
    
        printf("This IP address belongs to class A"); 

    }
        









    return 0; 
}
