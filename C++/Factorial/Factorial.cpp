#include <iostream>
using namespace std;

int Factorial(int n);

int main(){

    int result;
    int n;
    cin>>n;

    result = Factorial(n);
    cout  << result << endl;

    return 0;
}

int Factorial(int n){

    if (n <= 1) return 1;
    else return n*Factorial(n - 1);

}