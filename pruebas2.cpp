#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int pele=0;
int Ccalf(int califm[]){
        ifstream archivo("calif.txt");
        string temp,temp1[100];
        int stoil=0;
        for(int i=0;i<pele;i++){
            getline(archivo,temp);
        }
        if(archivo.eof()){
        }else{
            for(int i=0;i<100;i++){
            getline(archivo,temp1[i]);
            pele++;
            stoil++;
            if(temp1[i].empty()){
                for(int i=0;i<(stoil-1);i++){
                    califm[i] = stoi(temp1[i]);
                }
                break;
            }
        }
        }
        return 0;
    }
int main(){
    int a=10;
    int califm[100],calif[a][100];
    for(int i=0;i<a;i++){
        for(int j=0;j<100;j++){
            calif[i][j]=0;
        }
    }
    //
    int nmbre=3;
    for(int i=0;i<nmbre;i++){
        Ccalf(califm);
        for(int j=0;j<100;j++){
            calif[i][j]=califm[j];
        }
    }
    //mostrar
    cout<<calif[0][0]<<endl;
    cout<<calif[0][1]<<endl;
    cout<<calif[1][0]<<endl;
    cout<<calif[2][0]<<endl;

    /*for(int i=0;i<a;i++){
        for(int j=0;j<100;j++){
            if(calif[i][j]==0){
            
            }else{
                cout<<calif[i][j]<<endl;
            }  
        }
    }*/
}