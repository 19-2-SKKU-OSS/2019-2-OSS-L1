#include <stdio.h>
#include <string.h>


const char* input1,input2;
int dist[1001][1001];

int min(int a, int b)
{
	if (a<=b)
 		 return a;
	else return b;
}

int levenshtein(char* input1, char* input2){
        for(int i =1;i<=strlen(input1);i++){
                dist[i][0] = i;
        }
        for(int j =1;j<=strlen(input2);j++){
                dist[0][j] = j;
        }
        for(int j =1;j<=strlen(input2);j++){
                for(int i =1; i<=strlen(input1);i++){
                        if(input1[i-1] == input2[j-1])  dist[i][j] = dist[i-1][j-1];
                        else
                                dist[i][j] = min(dist[i-1][j-1] + 1,min(dist[i][j-1]+1,dist[i-1][j]+1));
                }
        }
        for(int j=0;j<=strlen(input2);j++){
                for(int i=0;i<=strlen(input1);i++)
                        printf("%d\t",dist[i][j]);
                        printf("\n");
        }
        return dist[strlen(input1)][input2.length()];
}
int main(){
        scanf("%s",input1);
	scanf("%s",input2);

        int result = levenshtein(input1,input2);
       
	printf("편집 거리 : %d\n",result);
}


