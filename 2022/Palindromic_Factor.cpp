#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <list>
#include <iostream> 
#include <list> 
#include <string.h>
#include <vector>
#include <queue>
#include <deque>

unsigned long long is_palindrome(unsigned long long angka){
    char c[1000]; 
    sprintf(c, "%llu", angka);
    // printf("Converted character is %s",c);
    // printf("%s\n", c);
    for(unsigned long long z = 0; z < strlen(c)/2; z++){
        // printf("%c %c\n", c[z], c[strlen(c) - (z + 1)]);
        if(c[z] != c[strlen(c) - (z + 1)])
            return 0;
    }
    return 1;
}

unsigned long long is_prime_sekalian_olah(unsigned long long angka){
    if(angka == 1)
        return 1;
    if(angka < 4)
        return 2;
    
    unsigned long long jumlah=0;
    for(unsigned long long z = 1; z <= sqrt(angka); z++){
        if(angka%z == 0){
            // printf("%d %d\n", z, angka/z);
            if(z < 10){
                jumlah++;
            }else{
                if(is_palindrome(z)){
                    jumlah++;
                }
            }
            
            if(z != angka/z){
                if(angka/z < 10){
                    jumlah++;
                }else{
                    if(is_palindrome(angka/z)){
                        jumlah++;
                    }
                }
            }
        }
    }
    return jumlah;
    
}

int main(){
    // printf("%d\n", is_palindrome(2));
    int n; scanf("%d", &n);
    for(unsigned long long z = 1; z <= n; z++){
        unsigned long long angka; scanf("%llu", &angka);
        printf("Case #%llu: %llu\n", z, is_prime_sekalian_olah(angka));
    }
}