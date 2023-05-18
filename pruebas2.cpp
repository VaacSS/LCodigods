#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int pele=0;
string Cmat(int califm[]){
        ifstream archivo("calif.txt");
        string temp;
        for(int i=0;i<pele;i++){
            getline(archivo,temp);
        }
        if(archivo.eof()){
        }else{
            for(int i=0;i<100;i++){
            getline(archivo,materiasm[i]);
            pele++;
            if(materiasm[i].empty()){
                break;
            }
        }
        }
        return temp;
    }
int main(){
    int a=10;
    string materiasm[100],materias[a][100],nombre[a];
    //
    int nmbre=0;
    for(int i=0;i<a;i++){
        if(nombre[i]!=" "){
            nmbre++;
        }
    }
    nmbre=3;
    for(int i=0;i<nmbre;i++){
        Cmat(materiasm);
        for(int j=0;j<100;j++){
            materias[i][j]=materiasm[j];
        }
    }
    //mostrar
    for(int i=0;i<a;i++){
        for(int j=0;j<100;j++){
            if(materias[i][j].empty()){
            
            }else{
                cout<<materias[i][j]<<endl;
            }  
        }
    }
}