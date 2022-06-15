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
using namespace std; 


int main(){
    int n; scanf("%d", &n);

    for(int zz = 00; zz < n; zz++){
        char i[100001]; scanf("%s", i);
        char p[100001]; scanf("%s", p);
        
        
        int len = strlen(i);
        
        if(len > strlen(p)){
            printf("Case #%d: IMPOSSIBLE\n", zz+1);
            continue;
        }
        
        
        
        int poin = 0;
        int sama = 0;
        for(int z = 0 ; z<strlen(p); z++){
            
            if(p[z] != i[sama]){
                poin++;
            }else{
                sama++;
                if(sama == len) break;
            }

            
        }
        if(sama == len)
            printf("Case #%d: %d\n", zz+1, strlen(p)-sama);
        else
            printf("Case #%d: IMPOSSIBLE\n", zz+1);

    }
}


/* TEST SET 1
int main(){
    int n; scanf("%d", &n);

    for(int zz = 00; zz < n; zz++){
        char i[100001]; scanf("%s", i);
        char p[100001]; scanf("%s", p);

        int len = strlen(i);
        int poin = 0;
        for(int z = 0 ; z<strlen(p); z++){
            if(i[0] == p[z]){
                poin++;
                if(poin == len) break;
            }
        }
        if(poin == len)
            printf("Case #%d: %d\n", zz+1, strlen(p)-poin);
        else
            printf("Case #%d: IMPOSSIBLE\n", zz+1);
    }
}

*/