#include<iostream>
using namespace std;

int factorial(int value){
    if(value == 0){
        return 1; // base case because computer can directly solve this.
    }
    return value * factorial(value - 1); // recursive case because it call itself to solve this problem untill reaching on the base case (0!).
};

int main(){
    int facNum;
    cout<<"Enter value to find factorial: ";
    cin>>facNum;
    cout<< factorial(facNum);
}