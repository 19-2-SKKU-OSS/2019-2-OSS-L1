#include <stdio.h>

void selection_sort(int list[], int n){
    int i, j, l, tmp;
    
    for(i=0; i<n-1; i++){
        l = i;
        for(j=i+1; j<n; j++){
            if(list[j]<list[l]){
                l = j;
            }
        }
        if(i != l){
            tmp = list[i];
            list[i] = list[l];
            list[l] = tmp;
        }
    }
}
int main(){
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d",&count);

    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
       scanf("%d",&number[i]);

    selection_sort(number, count);

    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
       printf(" %d",number[i]);

    return 0;
}
