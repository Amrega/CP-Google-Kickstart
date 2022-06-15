#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[][2], int low, int high) 
{ 
    int pivot = arr[high][0]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        
        if (arr[j][0] < pivot) 
        { 
            i++;
            swap(&arr[i][0], &arr[j][0]); 
            swap(&arr[i][1], &arr[j][1]);
        } 
    } 
    swap(&arr[i + 1][0], &arr[high][0]); 
    swap(&arr[i + 1][1], &arr[high][1]); 
    return (i + 1); 
} 
  

void quickSort(int arr[][2], int low, int high) 
{ 
    if (low < high) 
    { 
     
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){
	int n; scanf("%d", &n);
	for(int z = 0 ; z<n; z++){
		char s[10000]; scanf("%s", s);
		int a[26][2], p = 1, nn = strlen(s), pp = 0;
		for(int zz = 0 ; zz<26; zz++){
			a[zz][0] = 0;
			a[zz][1] = zz;
		}
		for(int zz = 0; zz<nn; zz++){
			//int c = int(s[zz]);
			a[s[zz] - 97][0]++;
			if(a[s[zz] - 97][0] == 1){
				pp++;
			}
			if(a[s[zz] - 97][0] > nn/2 || nn == 1){
				printf("Case #%d: IMPOSSIBLE\n", z+1);
				p = 0;
				break;
			}else if(nn == 2){
				printf("Case #%d: %c%c\n", z+1, s[1], s[0]);
				p=0;
				break;
			}
		}
		if(p){
			quickSort(a, 0, 26);
			
			int l = 0;
			for(int zz = 0 ; zz<26; zz++){
				if(a[zz][0] != 0){
					l = zz;
					break;
				}
			}	
			int ll = 0, lll = nn - a[l][0], llll=0;
			for(int zz = nn-a[l][0]-1; zz<nn; zz++){
				//printf("%c=%c ", a[l][1]+97,s[zz]);
				if(a[l][1]+97 == s[zz]){
					//printf("bisa");
					ll++;
				}
			}
			//printf("%d", ll);
			
			printf("Case #%d: ", z+1);
			int zzzz = 25, pp = 0;
			int b =0;			
			
			/*for(int zz = 25 ; zz>-1; zz--){
				printf("%c %d ", a[zz][1]+97, b++);
			}*/
			int o = 0;
			for(int zz = 0; zz<nn; zz++){
				//printf("%d ", zz);
				if(llll){
					//printf(" %c%c ", a[24][1]+97,a[25][1]+97);
					
					
					
					
					//printf(" l=%c l=%d ",a[l][1]+97, l+o);
					
					if(s[zz] != a[l][1] + 97 && a[l][0] != 0){
						//printf(" s=%c ", s[zz]);
						a[l][0]--;
						printf("%c", a[l][1] + 97);
				
						
					}else if(s[zz] != a[l+o][1] + 97 && a[l+o][0] != 0){
						a[l+o][0]--;
						printf("%c", a[l+o][1] + 97);
				
						
					}	
						
				}else{
					for(int zzz= zzzz;zzz>-1; zzz--){
						//printf("2=%d ",zzz);
						//printf(" c=%c ", a[zzz][1] + 97);	
						
						/*if(lll == ll && zz != nn-1 && a[l][0] == a[l+1][0]){
							llll=l;
						}else*/ if(lll == ll && zz != nn-1 && p){
							//printf("bias ");
							p=0;
							zzzz = 25;
							zzz = 25;
							zz--;
							l = a[l][1]+97;
							quickSort(a, 0, 26);
							if(a[25][0] == a[24][0]){
								llll=1;
								
								if(a[24][1]+97 == l){
									l = 24;
									o = 1;
								}else if(a[25][1]+97 == l){
									l = 25;
									o = -1;
								}
							}
							break;
						}
						
						if(s[zz] != a[zzz][1] + 97 && a[zzz][0] != 0){
							a[zzz][0]--;
							lll--;
							printf("%c", a[zzz][1] + 97);
							if(a[zzz][0] == 0 && a[zzzz][0] == 0){
								zzzz--;
								break;
							}
							break;
						}
					}	
				}	
			}
			printf("\n");
		}
	}	
}

/* Only solve Test Set 1 */