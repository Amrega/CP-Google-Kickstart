#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int ok[1002][1002], left[1002][1002], right[1002][1002], up[1002][1002], down[1002][1002];

void set(int x, int y){
	for(int a = 1; a <x+1; a++){
		for(int aa = 1 ; aa<y+1;aa++){
			if(ok[a][aa] == 1) left[a][aa] += left[a][aa-1] + 1;
			if(ok[x+1-a][y+1-aa] == 1) right[x+1-a][y+1-aa] +=right[x+1-a][y+1-aa + 1] + 1;
			//if(ok[aa][a] == 1) up[aa][a] += up[aa-1][a] + 1;
			//if(ok[y+1-aa][x+1-a] == 1) down[y+1-aa][x+1-a] += up[y+1-aa+1][x+1-a] + 1;
			//if(ok[a][aa] != 1)printf("%d\t", left[a][aa]);
		}//printf("\n");
	}
	for(int aa = 1; aa <x+1; aa++){
		for(int a = 1 ; a<y+1;a++){
			if(ok[aa][a] == 1) up[aa][a] += up[aa-1][a] + 1;
			if(ok[x+1-aa][y+1-a] == 1) down[x+1-aa][y+1-a] += down[x+1-aa+1][y+1-a] + 1;
			//if(ok[a][aa] != 1)printf("%d\t", left[a][aa]);
		}//printf("\n");
	}
}

int cari(int x, int y){
	int nilai =0;
	//printf("\n");
	for(int a = 1; a <x+1; a++){
		for(int aa = 1 ; aa<y+1;aa++){
			if(left[a][aa] >= 4 && up[a][aa] >= left[a][aa]/2) nilai += (left[a][aa]/2) - 1;
			if(left[a][aa] >= 4 && down[a][aa] >= left[a][aa]/2) nilai+= (left[a][aa]/2) - 1;
			if(right[a][aa] >= 4 && up[a][aa] >= right[a][aa]/2) nilai+= (right[a][aa]/2) - 1;
			if(right[a][aa] >= 4 && down[a][aa] >= right[a][aa]/2) nilai+= (right[a][aa]/2) - 1;
			if(up[a][aa] >= 4 && left[a][aa] >= up[a][aa]/2) nilai+= (up[a][aa]/2) - 1;
			if(up[a][aa] >= 4 && right[a][aa] >= up[a][aa]/2) nilai+= (up[a][aa]/2) - 1;
			if(down[a][aa] >= 4 && left[a][aa] >= down[a][aa]/2) nilai+= (down[a][aa]/2) - 1;
			if(down[a][aa] >= 4 && right[a][aa] >= down[a][aa]/2) nilai+= (down[a][aa]/2) - 1;
			
			if(left[a][aa] >= 2 && up[a][aa] > left[a][aa]*2 + 1) nilai += (left[a][aa]) - 1;
			if(left[a][aa] >= 2 && down[a][aa] > left[a][aa]*2 + 1) nilai+= (left[a][aa]) - 1;
			if(right[a][aa] >= 2 && up[a][aa] > right[a][aa]*2 + 1) nilai+= (right[a][aa]) - 1;
			if(right[a][aa] >= 2 && down[a][aa] > right[a][aa]*2 + 1) nilai+= (right[a][aa]) - 1;
			if(up[a][aa] >= 2 && left[a][aa] > up[a][aa]*2 + 1) nilai+= (up[a][aa]) - 1;
			if(up[a][aa] >= 2 && right[a][aa] > up[a][aa]*2 + 1) nilai+= (up[a][aa]) - 1;
			if(down[a][aa] >= 2 && left[a][aa] > down[a][aa]*2 + 1) nilai+= (down[a][aa]) - 1;
			if(down[a][aa] >= 2 && right[a][aa] > down[a][aa]*2 + 1) nilai+= (down[a][aa]) - 1;
			//printf("%d\t", down[a][aa]);
		}//printf("\n");
	}return nilai;
}

void printset(int x, int y){
	printf("\nUP:\n");
	for(int a = 1; a<x+1;a++){
		for(int aa = 1; aa<y+1;aa++){
			printf("%d ", up[a][aa]);
		}printf("\n");
	}
	printf("\nDOWN:\n");
	for(int a = 1; a<x+1;a++){
		for(int aa = 1; aa<y+1;aa++){
			printf("%d ", down[a][aa]);
		}printf("\n");
	}
	printf("\nLEFT:\n");
	for(int a = 1; a<x+1;a++){
		for(int aa = 1; aa<y+1;aa++){
			printf("%d ", left[a][aa]);
		}printf("\n");
	}
	printf("\nright:\n");
	for(int a = 1; a<x+1;a++){
		for(int aa = 1; aa<y+1;aa++){
			printf("%d ", right[a][aa]);
		}printf("\n");
	}
}

int main(){
	int n, x, y;
	scanf("%d", &n);
	for(int a = 0; a<n; a++){
		memset(ok,0,sizeof ok);
		memset(left,0,sizeof left);
		memset(right,0,sizeof right);
		memset(up,0,sizeof up);
		memset(down,0,sizeof down);
		scanf("%d %d", &x, &y);
		int nilai = 0;
		for(int aa = 1; aa<x+1; aa++){
			for(int aaa = 1; aaa<y+1; aaa++){
				scanf("%d", &ok[aa][aaa]);
			}
		}
		set(x,y);
		//printset(x,y);
		nilai = cari(x,y);
		printf("Case #%d: %d\n", a+1,nilai);
	}	
}