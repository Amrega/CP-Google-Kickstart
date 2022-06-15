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

//Consecutive Prime
int is_prime(unsigned long long int a){
	for(int aa=2; aa<=sqrt(a); aa++){
		if(a%aa == 0) return 0;
	}return 1;
}

void olah(unsigned long long int b){
	unsigned long long int a = ceil(sqrt(b)), kecil, besar;
	unsigned long long int aa, ab, cek = 0;
	if(cek == 0){
		while(true){
			if(is_prime(a)){
				aa = a;
				break;
			}a++;
		}
		a = ceil(sqrt(b));
		while(true){
			a--;
			if(is_prime(a)){
				ab = a;
				break;
			}
		}	
	}
	if(ab*aa <= b) printf("%llu\n", ab*aa);
	else cek = 1;
	a = ceil(sqrt(b));
	if(cek == 1){
		while(true){
			if(is_prime(a)){
				aa = a;
				break;
			}a--;
		}
		while(true){
			a--;
			if(is_prime(a)){
				ab = a;
				break;
			}
		}	
	}
	if(cek == 1 && ab*aa <= b) printf("%llu\n", ab*aa);
}

int main(){
	unsigned long long int a, b;
	scanf("%llu", &a);
	for(int c=0; c<a;c++){
		scanf("%llu", &b);
		printf("case #%d: ", c+1);
		olah(b);
	}
}