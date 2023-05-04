#include <iostream>
using namespace std;
int main(){
    int n,d=0;
    cin>>n;
    int n1[n],n2[n];
    for(int i=1;i<=n;i++){
        cin>>n1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>n2[i];
    }
    for(int i=1;i<=n;i++){
        d+= n1[i]*n2[i];
    }
    cout<<d;
    
}