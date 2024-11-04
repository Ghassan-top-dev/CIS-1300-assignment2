#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char binary[60] = "11000110010011100000000100000000";
    
    long num;
    
    num  = strtol(binary, NULL, 2);
    
    printf("%ld", num); 

    return 0;
}
