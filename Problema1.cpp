#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cin>>k;
    for(int i=0;i<n;i++){
        if(s[i]%k!=0){
            cout<<'X'<<" ";
        }
        else{
            cout<<s[i]<<" ";
        }
    }

}