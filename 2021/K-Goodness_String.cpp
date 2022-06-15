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


//K-Goodness String
void olah(char *ok, int l, int k){
	int nilai = 0;
	for(int a = 0; a<strlen(ok)/2; a++){
		//printf("\n%c %c", ok[a], ok[strlen(ok) - (a+1)]);
		if(ok[a] != ok[strlen(ok) - (a+1)]) nilai++;
	}
	//printf("\n%d\n", strlen(ok));
	printf("%d\n", abs(k-nilai));
}

int main(){
	int n, l, k;
	scanf("%d", &n);
	for(int a = 0; a<n; a++){
		scanf("%d %d ", &l, &k);
		char ok[l];
		scanf("%[^\n]%*c", ok);
		
		printf("Case #%d: ",a+1);
		olah(ok, l, k);
	}
}