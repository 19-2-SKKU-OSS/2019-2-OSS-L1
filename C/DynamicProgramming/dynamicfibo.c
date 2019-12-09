//
//  dynamicfibo.c
//  opensource
//
//  Created by 성주용 on 2019/12/09.
//  Copyright © 2019 성주용. All rights reserved.
//

#include <stdio.h>

int fibo(int n){
    int i = 0;
    int result = 0;
    int * fibo = 0;
    
    if (n == 0 || n == 1){
        return n;
    }
    
    fibo = (int*)malloc((n+1)*sizeof(int));
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(i = 2; i <= n; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    result = fibo[n];
    return result;
}

int main(){
    int i;
    i = fibo(15);
    printf("%d\n", i);
}
