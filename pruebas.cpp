#include <iostream>
#include <string>
#include <fstream>
#include "santis.h"
using namespace std;
int a=0,m=100, ma=100;
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
void archivo(float promedio[],string nombre[],string carrera[]){
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
int main(){
    A(); 
    float promedio[a];
    string nombre[a],carrera[a];
    archivo(promedio,nombre,carrera);
    cout<<nombre[0]<<" "<<nombre[1]<<endl;
    cout<<carrera[0]<<" "<<carrera[1]<<endl;
    cout<<promedio[0]<<" "<<promedio[1]<<endl;

}