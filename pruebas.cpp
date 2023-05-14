#include <iostream>
#include <string>
#include <fstream>
#include "santis.h"
using namespace std;
int a=2,m=100, ma=100;
string maestros[100],materias[100];
void A(){
    string a1;
    ifstream archivo("nombre.txt");
    if (archivo.peek() == ifstream::traits_type::eof()) {
        cout<<"\nCUANTOS ALUMNOS HAY EN LA INSTITUCION: ";
        a=v();
        if(a<=0){
            cout<<"ingresa mas de uno no sea menso";
            exit(EXIT_SUCCESS);
        }
    }else{
        getline(archivo,a1);
        a = atoi(a1.c_str());
    }
}
void archivol(float promedio[],string nombre[],string carrera[]){
    ifstream archivo("nombre.txt");
    if (archivo.peek() == ifstream::traits_type::eof()) {
        ofstream archivo("nombre.txt");
        ofstream archivo1("carrera.txt");;
        ofstream archivo5("prom.txt");
    }else {
        for(int i=0;i<a;i++){
            getline(archivo,nombre[i]);
        }
        ifstream archivo1("carrera.txt");
        for(int i=0;i<a;i++){
            getline(archivo1,carrera[i]);
        }
        ifstream archivo5("prom.txt");
        string promedio1[a];
       for(int i=0;i<a;i++){
            getline(archivo5,promedio1[i]);
            promedio[i] = stof(promedio1[i].c_str());
        }
    }
    archivo.close();
}
void garchivo(float promedio[],string nombre[],string carrera[]){
    ofstream archivo1("nombre.txt");
    archivo1<<a<<endl;
    for (int i = 0; i < a; i++) {
           archivo1 << nombre[i] << endl;
       }
    archivo1.close();
    ofstream archivo2("carrera.txt");
    for (int i = 0; i < a; i++) {
           archivo2 << carrera[i] << endl;
       }
       archivo2.close();
    ofstream archivo3("promedio.txt");
    for (int i = 0; i < a; i++) {
           archivo3 << promedio[i] << endl;
       }
    archivo3.close();
}
void gm(string maestrosma[],int d1[],int i){
    string p[a*100];
    int d,d3d=0;
    d=i;
    ofstream archivomi("maestros.txt");
    archivomi.close();
    ifstream archivom("maestros.txt");
    if (archivom.peek() == ifstream::traits_type::eof()) {
    }else {
        for(int i=0;i<(a*100);i++){
            getline(archivom,p[i]);
            d3d++;
            if(p[i].empty()){
                break;
            }
        }
    }
    archivom.close();
    ofstream archivomm("maestros.txt");
    for(int i=0;i<d3d;i++){
        archivomm<<p[i]<<endl;
    }
    for(int i=0;i<d1[d];i++){
        archivomm<<maestrosma[i]<<endl;
    }
    archivomm.close();
}
void gmm(string materiasma[],int d2mt[],int i){
    string p[a*100];
    int d,d3d=0;
    d=i;
    ofstream archivomi("materias.txt");
    archivomi.close();
    ifstream archivom("materias.txt");
    if (archivom.peek() == ifstream::traits_type::eof()) {
    }else {
        for(int i=0;i<(a*100);i++){
            getline(archivom,p[i]);
            d3d++;
            if(p[i].empty()){
                break;
            }
        }
    }
    archivom.close();
    ofstream archivomm("materias.txt");
    for(int i=0;i<d3d;i++){
        archivomm<<p[i]<<endl;
    }
    for(int i=0;i<d2mt[d];i++){
        archivomm<<materiasma[i]<<endl;
    }
}
void gcf(int califm[],int d3cf[],int i){
    string p[a*100];
    int d,d3d=0;
    d=i;
    ofstream archivomi("calif.txt");
    archivomi.close();
    ifstream archivom("calif.txt");
    if (archivom.peek() == ifstream::traits_type::eof()) {
    }else {
        for(int i=0;i<(a*100);i++){
            getline(archivom,p[i]);
            d3d++;
            if(p[i].empty()){
                break;
            }
        }
    }
    archivom.close();
    ofstream archivomm("calif.txt");
    for(int i=0;i<d3d;i++){
        archivomm<<p[i]<<endl;
    }
    for(int i=0;i<d3cf[d];i++){
        archivomm<<califm[i]<<endl;
    }
}
int main(){
    //A();
    float promedio[a];
    string nombre[a],carrera[a],maestros[a][m],materias[a][ma];
    string maestrosma[m],materiasma[m];
    int d1[a],d2mt[a],d3cf[a],calif[a][m],califm[m];
    for(int i=0;i<a;i++){
        for(int j=0;j<m;j++){
            maestros[i][j]=" ";
        }
    }
    maestros[0][0]="pepe";
    maestros[0][1]="pepe1";
    d1[0]=2;
    maestros[1][0]="pepe2";
    d1[1]=1;
    int pls=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<d1[i];j++){
            maestrosma[pls]=maestros[i][j];
            pls++;
            if(j+1==d1[i]){
                gm(maestrosma,d1,i);
            }
        }
    }
    /*materias[0][0]="mate";
    materias[0][1]="geo";
    d2mt[0]=2;
    materias[1][0]="gta";
    d2mt[1]=1;*/
    pls=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<d2mt[i];j++){
            materiasma[pls]=materias[i][j];
            pls++;
            if(j+1==d2mt[i]){
                gmm(materiasma,d2mt,i);
            }
        }
    }
    /*calif[0][0]=100;
    calif[0][1]=99;
    d3cf[0]=2;
    calif[1][0]=98;
    d3cf[1]=1;*/
    pls=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<d3cf[i];j++){
            califm[pls]=calif[i][j];
            pls++;
            if(j+1==d3cf[i]){
                gcf(califm,d3cf,i);
            }
        }
    }
    //archivol(promedio,nombre,carrera );
    //cout<<nombre[0]<<" "<<nombre[1]<<endl;
    //cout<<carrera[0]<<" "<<carrera[1]<<endl;
    //cout<<promedio[0]<<" "<<promedio[1]<<endl; 
}
//guardar si no tienen "  "