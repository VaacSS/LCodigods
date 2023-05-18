#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int pele=0;
void Cma(string maestrosma[]){
        ifstream archivo("maestros.txt");
        string temp;
        for(int i=0;i<pele;i++){
            getline(archivo,temp);
        }
        if(archivo.eof()){
        }else{
            for(int i=0;i<100;i++){
            getline(archivo,maestrosma[i]);
            pele++;
            if(maestrosma[i].empty()){
                break;
            }
        }
        }
    }
int main(){
    int a=10;
    string maestrosma[100],maestros[a][100],nombre[a];
    nombre[0]="aa";
    nombre[1]="aa";
    nombre[2]="aa";
    //
    int nmbre=0;
    for(int i=0;i<a;i++){
        if(nombre[i]!=" "){
            nmbre++;
        }
    }
    for(int i=0;i<nmbre;i++){
        Cma(maestrosma);
        for(int j=0;j<100;j++){
            maestros[i][j]=maestrosma[j];
        }
    }
    //mostrar
    for(int i=0;i<a;i++){
        for(int j=0;j<100;j++){
            if(maestros[i][j].empty()){
            
            }else{
                cout<<maestros[i][j]<<endl;
            }  
        }
    }
}