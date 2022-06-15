#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(){
	int n;scanf("%d",&n);
	int a, d, c, cc; 
	for(int z = 0 ; z < n; z++){
		scanf("%d %d %d %d", &a, &d, &c, &cc);
		char arr[a]; scanf("%s", arr);
		int y = 1, yy = 1;
		printf("Case #%d: ", z+1);
		for(int zz = 0 ; zz<a; zz++){
			if(arr[zz] == 'D'){
				if(!d || !yy){
					y = 0;
					printf("NO\n");
					break;
				}
				d--;
				c += cc;
			}else if(arr[zz] == 'C'){
				if(!c){
					yy = 0;
					continue;	
				}
				c--;
			}
		}
		if(y) printf("YES\n");
	}
}
