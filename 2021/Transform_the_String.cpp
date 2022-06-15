#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


char a[100000];
char b[26];
int c[26];
char d[26];

void reset(){
    for(int z = 0 ; z<26; z++){
        c[z] = -1;
        //d[z] = 0;
    }
}

int main(){
	int n; scanf("%d", &n);
	for(int z = 0 ; z<n; z++){
		scanf("%s", a);
		scanf("%s", d);
		
		printf("Case #%d: ", z+1);
		if(strlen(d) == 1){
			int poin = 0;
			for(int zz = 0; zz<strlen(a); zz++){
				if(a[zz] > d[0]){
					if(a[zz] - d[0] < (d[0]-97) + (26 - (a[zz]-97))) poin += a[zz] - d[0];
					else poin += (d[0]-97) + (26 - (a[zz]-97));
				}else if(a[zz] < d[0]){
					if(d[0] - a[zz] < (26 - (d[0]-97)) + (a[zz]-97)) poin += d[0] - a[zz];
					else poin += (26 - (d[0]-97)) + (a[zz]-97);
				}
				
			}
			printf("%d\n", poin);
		}else if(strlen(d) == 26){
			printf("0\n");
		}else{		
			reset();
			int poin = 0;
			for(int zz = 0 ; zz<strlen(a); zz++){
				if(c[a[zz]-97] == -1){
					int terkecil = 9999;
					for(int zzz = 0; zzz<strlen(d); zzz++){
					  //printf("%c %c\n", a[zz], d[zzz]);
					  //if(a[zz] == 's' && d[zzz] =='d'){
					    /*printf("%d %d\n", zz, zzz);
					    if(a[zz] - d[zzz] >= (d[zzz]-97) + (26 - (a[zz]-97)) && (d[zzz]-97) + (26 - (a[zz]-97)) >= terkecil){
					      printf("ya");
					      printf(" %d %d\n", (d[zzz]-97) + (26 - (a[zz]-97)), terkecil);
					    }*/
					  //}
						if(a[zz] > d[zzz]){
							if(a[zz] - d[zzz] < (d[zzz]-97) + (26 - (a[zz]-97))){
								//if(a[zz] - d[zzz] >= terkecil) break;
								//else terkecil = a[zz] - d[zzz];
								int nilai = a[zz] - d[zzz];
								if(nilai < terkecil) terkecil = nilai;
							} 
							else {
								//if(((d[zzz]-97) + (26 - (a[zz]-97))) >= terkecil) break;
								//else terkecil = (d[zzz]-97) + (26 - (a[zz]-97));
								int nilai = (d[zzz]-97) + (26 - (a[zz]-97));
								if (terkecil > nilai) terkecil = nilai;
							}
						}else if(a[zz] < d[zzz]){
							if(d[zzz] - a[zz] < (26 - (d[zzz]-97)) + (a[zz]-97)) {
								//if(d[zzz] - a[zz] >= terkecil) break;
								//else terkecil = d[zzz] - a[zz];
								int nilai = d[zzz] - a[zz];
								if (terkecil > nilai) terkecil = nilai;
							}else{
							 
								//if((26 - (d[zzz]-97)) + (a[zz]-97) >= terkecil) break;
							  //else terkecil = (26 - (d[zzz]-97)) + (a[zz]-97);
								int nilai = (26 - (d[zzz]-97)) + (a[zz]-97);
								if(terkecil > nilai)terkecil = nilai;
							} 
						}else{
							terkecil = 0;
							break;
						}
					}
					c[a[zz]-97] = terkecil;
					//poin += terkecil;
				}
				poin += c[a[zz]-97];
				

				/*c[a[zz]-97] += 1;
				//if(zz < strlen(b) ) d[b[zz] - 97] = 1;
			}int poin = 0;
			printf("\ncontoh b: ");
			for(int zz = 0 ; zz<26; zz++){
				printf("%d ", d[zz]);
			}printf("\n");*/
			/*printf("contoh a: ");
			for(int zz = 0 ; zz<26; zz++){
				printf("%d ", c[zz]);
			}printf("\n");
			for(int zz = 0; zz<26; zz++){
				
				if(c[zz]){
					int terbesar = 9999;
					for(int zzz = 0; zzz < strlen(d); zzz++){
						int banding = zz - (d[zzz] - 97);
						if(banding <0) banding *= -1;
						if(terbesar > banding){
							terbesar = banding;
							//
						}else {
							
							break;
						}
					}poin += terbesar * c[zz];
					
				}*/
			}printf("%d\n", poin);
			
		}
		
	}
}
