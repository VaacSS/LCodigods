#include <iostream>
using namespace std;
int main(){
    int n1,d=0;
    cin>>n1;
    int n[n1],n2[n1];
    for(int i=1;i<=n1;i++){
        cin>>n[i];
    }
    for(int i=1;i<=n1;i++){
        cin>>n2[i];
    }
    for(int i=1;i<=n1;i++){
        if(n[i]>n2[i]){
            d++;
        }
    }
    if(d==n1){
        cout<<'1';
    }else{
        cout<<'0';
    }
}