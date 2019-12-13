// C program to demonstrate 
// working of Alpha-Beta Pruning 
#include <stdio.h> 
  
// Initial values of 
// Aplha and Beta 
const int MAX = 1000; 
const int MIN = -1000; 
  
  int max( int a, int b){
    if(a>=b)    return a;
    else    return b;
  }

int min (int a, int b){
    if(a<=b)     return a;
    else    return b;
}
// Returns optimal value for 
// current player(Initially called 
// for root and maximizer) 
int minimax(int depth, int nodeIndex, 
            int maximizingPlayer, 
            int values[], int alpha,  
            int beta) 
{ 
      
    // Terminating condition. i.e  
    // leaf node is reached 
    if (depth == 3) 
        return values[nodeIndex]; 
  
    if (maximizingPlayer==1) 
    { 
        int best = MIN; 
  
        // Recur for left and  
        // right children 
        for (int i = 0; i < 2; i++) 
        { 
              
            int val = minimax(depth + 1, nodeIndex * 2 + i,  
                              0, values, alpha, beta); 
            best = max(best, val); 
            alpha = max(alpha, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    } 
    else
    { 
        int best = MAX; 
  
        // Recur for left and 
        // right children 
        for (int i = 0; i < 2; i++) 
        { 
            int val = minimax(depth + 1, nodeIndex * 2 + i, 
                              1, values, alpha, beta); 
            best = min(best, val); 
            beta = min(beta, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 }; 
    int result =  minimax(0, 0, 1, values, MIN, MAX);
    printf("The optial value is : %d \n ", result);
    return 0; 
} 

