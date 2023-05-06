/*#include <iostream>
using namespace std;
int main() {
    float h,t,d;
    cin>>h;
    cin>>t;
    if(h>40){
        h-=40;
        if(h<=10){
            d=(40*t)+(h*(1.5*t));
        }else{
            h-=10;
            d=(40*t)+(10*(1.5*t)+(h*(2*t)));
        }
    }else{
        d=h*t;
    }
    cout<<d;
}*/
#include <stdio.h>
int main(){
    int n, l=1;
    scanf("%u", &n);
    int m=1;
    for(int i=1; i<=n; i++){
		m+=(n-i)*m;
		l+=m;
    }
    printf("%u ", l);
    return 0;
}