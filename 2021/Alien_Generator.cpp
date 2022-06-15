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

//alien generator
unsigned long long rekursif(unsigned long long a, unsigned long long b, unsigned long long x){
	if( b== x) return 1;
	else if (b > x) return 0;
	else return rekursif(a+1, b+a, x);
}

void sn(unsigned long long a, unsigned long long z){
	unsigned long long nilai = 1;
	for(unsigned long long z = 1; z<=a/2; z++){
		nilai += rekursif(z,0, a);
	}
	printf("Case #%d: %llu\n", z+1,nilai);
}

unsigned long long batas(unsigned long long a){
	unsigned long long b = 0, bb = 1;
	while(1){
		b+=bb;
		bb++;
		if(b >= a) return bb;
	}
}

void olah(unsigned long long a, unsigned long long batas, unsigned long long zz){
	unsigned long long nilai = 1;
	for(unsigned long long z = 2; z<= batas; z++){
		
		if(z%2 == 0 && a == (((a/z)*2) + 1) *(z/2)) {
			//printf("%llu %llu %llu\n",z, a ,(((a/z)*2) + 1) *(z/2) );
			nilai++;	
		}
		else if(z%2 != 0 && a == (a/z)*z){
			//printf("%llu %llu %llu\n",z, a ,(a/z)*z );
			nilai++;	
		} 
	}
	printf("Case #%llu: %llu\n", zz+1,nilai);
}

int main(){
	unsigned long long n, a;
	scanf("%llu", &n);
	
	for(unsigned long long z = 0; z<n; z++){
		scanf("%llu", &a);
		//printf("%llu\n", batas(a));
		if(a <= 10){
			sn(a, z);
		}else olah(a, batas(a), z);
	}
}