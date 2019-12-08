#include <stdio.h>
#include <string.h>
#include <algorithm>

const char* input1,input2;
int dist[1001][1001];

int levenshtein(char* input1, char* input2){
        for(int i =1;i<=input1.length();i++){
                dist[i][0] = i;
        }
        for(int j =1;j<=input2.length();j++){
                dist[0][j] = j;
        }
        for(int j =1;j<=input2.length();j++){
                for(int i =1; i<=input1.length();i++){
                        if(input1[i-1] == input2[j-1])  dist[i][j] = dist[i-1][j-1];
                        else
                                dist[i][j] = min(dist[i-1][j-1] + 1,min(dist[i][j-1]+1,dist[i-1][j]+1));
                }
        }
        for(int j=0;j<=input2.length();j++){
                for(int i=0;i<=input1.length();i++)
                        printf("%d\t",dist[i][j]);
                        printf("\n");
        }
        return dist[input1.length()][input2.length()];
}
int main(){
        scanf("%s",input1);
	scanf("%s",input2);
`
        int result = levenshtein(input1,input2);
        cout<<"편집 거리 :"<<result<<endl;
}


