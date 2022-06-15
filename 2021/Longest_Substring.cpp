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

//Longest Substring
void hitung(int aa, char *ok){
	int angka[aa], hitung;
	for(int zz = aa-1; zz>-1; zz--){
		hitung = 1;
		for(int zzz = zz-1; zzz>-2; zzz--){
			//printf("bisa %d %d\n",(int)ok[zz], (int)ok[zzz]);
				
			if((int)ok[zz] <= (int)ok[zzz] || (int)ok[zzz] >= (int)ok[zzz+1] || zzz == -1) {
				angka[zz] = hitung;
				//printf("angka[%d]=%d\n", zz, hitung);
				break;	
			}
			else hitung++;
			
			//printf("hitung=%d\n", hitung);
		}
	}
	for(int zz = 0; zz<aa; zz++){
		printf("%d ", angka[zz]);
	}
}


int main(){
	int a, aa;
	scanf("%d", &a);
	for(int z =0; z<a; z++){
		scanf("%d ", &aa);
		char ok[aa];
		scanf("%[^\n]%*c", ok);
		
		printf("case #%d: ", z+1);
		hitung(aa, ok);
		printf("\n");
	}
}