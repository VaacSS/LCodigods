#include <iostream>
using namespace std;

int main() {
    int n,d;
    cin>>n;
    int d1[n];
    d=n;
    for(int i=0;i<n;i++){
        d=d*(n-(i+1));
        d1[i]=d;
    }
    d=0;
    for(int i=0;i<n-1;i++){
        d+=d1[i];
    }
    d+=n;
    d+=1;
    cout<<d;
}