//This will convert a string in binary to base 10 int, then it will count how many digits it has 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    long n;
    int counter = 0; 
    char binary[36] = "11000110010011100000000100000000";
    
    long num;
    
    num  = strtol(binary, NULL, 2);
    
    printf("%ld", num); 


    n = num; 


    while (n!=0)
    {
        n = n/10; 
        counter++;
    }
    
    printf("\n%d", counter); 


    return 0;
}
