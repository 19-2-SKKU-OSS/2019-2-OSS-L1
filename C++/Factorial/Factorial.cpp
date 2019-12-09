#include <iostream>
using namespace std;

int Factorial(int n);

int main(){

    long result;
    int n;
    cout<<"Enter an integer to find its factorial"<<endl;
    cin>>n;

    if(n<0)
    	cout<<"Factorial of negative integers isn't defined."<<endl;
    else{
	    result = Factorial(n);
   		cout  <<n<<"! = " <<result << endl;
    }

    return 0;
}

int Factorial(int n){

    if (n <= 1) return 1;
    else return n*Factorial(n - 1);

}