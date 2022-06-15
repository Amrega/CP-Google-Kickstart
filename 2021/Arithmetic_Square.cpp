#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Arithmetic Square
int arr[3][3];
int ar[4][2];

void olah(int a){
	int poin = 0;
	if(arr[0][1] - arr[0][0] == arr[0][2] - arr[0][1]) poin++;
	if(arr[2][1] - arr[2][0] == arr[2][2] - arr[2][1]) poin++;
	if(arr[1][0] - arr[0][0] == arr[2][0] - arr[1][0]) poin++;
	if(arr[1][2] - arr[0][2] == arr[2][2] - arr[1][2]) poin++;
	
	
	ar[0][0] = arr[0][0] + arr[2][2];
	ar[0][1] = 1;
	
	ar[1][0] = arr[0][1] + arr[2][1];
	ar[1][1] = 1;
	for(int z = 0; z<1; z++){
		if(ar[1][0] == ar[z][0]) {
			ar[z][1]++;
			break;	
		}
	}
	
	ar[2][0] = arr[0][2] + arr[2][0];
	ar[2][1] = 1;
	for(int z = 0; z<2; z++){
		if(ar[2][0] == ar[z][0]){
			ar[z][1]++;
			break;
		} 
	}
	
	ar[3][0] = arr[1][0] + arr[1][2];
	ar[3][1] = 1;
	for(int z = 0; z<3; z++){
		if(ar[3][0] == ar[z][0]){
			ar[z][1]++;
			break;
		}
	}
	/*printf("\n");
	for(int z = 0 ;z<4; z++){
		printf("%d ", ar[z][0]);
	}printf("\n");*/
	int min = 0;
	for(int z = 0; z<4; z++){
		if(min < ar[z][1] && ar[z][0]%2 == 0){
			min = ar[z][1];
		}
	}
	//printf("min = %d\n", min);
	printf("Case #%d: %d\n", a, poin+min);
}

int main(){
	int n; scanf("%d", &n);
	for(int z=0; z<n; z++){
		scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
		scanf("%d %d", &arr[1][0], &arr[1][2]);
		scanf("%d %d %d", &arr[2][0], &arr[2][1], &arr[2][2]);
		
		olah(z+1);
	}
}
