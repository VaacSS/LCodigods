#include <iostream>
#include <string>
#include <fstream>
#include "santis.h"
using namespace std;
int a,m=100,ma=100;
void prom(float promedio[],int e){
    if(promedio[e]<=59){
        cout<<" (REPROBADO)"<<endl;
    }else if(promedio[e]>59 && promedio[e]<=79){
        cout<<" (REGULAR)"<<endl;
    }else if(promedio[e]>80 && promedio[e]<=89){
        cout<<" (MUY BIEN)"<<endl;
    }else if(promedio[e]>90 && promedio[e]<=100){
        cout<<" (EXCELENTE)"<<endl;
    }
}
void mostrar(int a,string nombre[],string carrera[],float promedio[]){
    fflush(stdin);
    int e;
    system("cls");
    cout<<"LISTA DE ALUMNOS ["<<a<<"] (SI EL ALUMNO TIENE DATOS SE MOSTRARAN, DE LO CONTRARIO NO APARECERA NADA)"<<endl;
    for(int i=0;i<a;i++){
        if(nombre[i]!=" "){
            cout<<i+1<<"- "<<nombre[i]<<endl;
            cout<<carrera[i]<<endl;
            cout<<"PROMEDIO: "<<promedio[i];
            e=i;
            prom(promedio,e);
        }
    }
}
void datos(int a,int m,int ma,int e,string nombre[],string carrera[],string maestrosma[],int califm[],string materiasm[],float promedio[]){
    cout<<"NOMBRE: "<<nombre[e]<<endl;
    cout<<"CARRERA: "<<carrera[e]<<endl;
    cout<<"MAESTROS: "<<endl;
    for(int i=0;i<ma;i++){
            fflush(stdin);
            if(maestrosma[i]!=" "){
                cout<<maestrosma[i]<<endl;
            }
        }
        cout<<"MATERIAS: "<<endl;
        for(int i=0;i<a;i++){
            fflush(stdin);
            if(materiasm[i]!=" "){
                cout<<materiasm[i]<<endl;
            cout<<"calificacion: "<<califm[i]<<endl;
            }
        }
}
void addeditar(int a,int m,int ma,int e,string nombre[],string carrera[],string maestrosma[],int califm[],string materiasm[],float promedio[],int d1[],int d2mt[],int d3cf[]){
    int pp,d=0;
    float ppp=0;
    fflush(stdin);
    if(nombre[e]!=" "){
        cout<<"ANTES: "<<endl;
         datos(a,m,ma,e,nombre,carrera,maestrosma,califm,materiasm,promedio);
        cout<<"\nCAMBIOS QUE DESEES HACER: "<<endl;
    }
    fflush(stdin);
        cout<<"NOMBRE: ";
        getline(cin, nombre[e]);
        cout<<"CARRERA: ";
        getline(cin, carrera[e]);
        cout<<"MAESTROS: "<<endl;
        for(int i=0;i<ma;i++){
            fflush(stdin);
            cout<<"MAESTRO "<<i+1<<" : ";
            getline(cin, maestrosma[i]);
            d1[e]++;
            if(i!=(ma-1)){
            cout<<"TIENE MAS MAESTROS? (0-no / 1-si)";
            cin>>pp;
            if(pp==0){
                i+=ma;
            }
            }
        }
        cout<<"MATERIAS: "<<endl;
        for(int i=0;i<ma;i++){
            fflush(stdin);
            cout<<"MATERIA "<<i+1<<" : ";
            getline(cin, materiasm[i]);
            d2mt[e]++;
            cout<<"\nCALIFICACION: ";
            califm[i]=v();
            d3cf[e]++;
            d++;
            if(i!=(ma-1)){
            cout<<"TIENE MAS MATERIAS? (0-no / 1-si)";
            cin>>pp;
            if(pp==0){
                i+=ma;
            }
            }
        }
        promedio[e]=0;
        for(int i=0;i<d;i++){
            ppp+=califm[i];
        }
        promedio[e]=ppp/d;
}
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
    archivo.close();
}
void archivo(float promedio[],string nombre[],string carrera[]){
    ifstream archivo("nombre.txt");
    if (archivo.peek() == ifstream::traits_type::eof()) {
        ofstream archivo("nombre.txt");
        ofstream archivo1("carrera.txt");
        ofstream archivo5("prom.txt");
    }else {
        getline(archivo,nombre[0]);
        for(int i=0;i<a;i++){
            getline(archivo,nombre[i]);
        }
        archivo.close();
        ifstream archivo1("carrera.txt");
        for(int i=0;i<a;i++){
            getline(archivo1,carrera[i]);
        }
        archivo1.close();
        ifstream archivo5("promedio.txt");
        string promedio1[a];
       for(int i=0;i<a;i++){
            getline(archivo5, promedio1[i]);
            promedio[i] = stof(promedio1[i]);
        }
        archivo5.close();
    }
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
void gmm(string materiasm[],int d2mt[],int i){
    string p[a*100];
    int d,d3d=0;
    d=i;
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
        archivomm<<materiasm[i]<<endl;
    }
}
void gcf(int califm[],int d3cf[],int i){
    string p[a*100];
    int d,d3d=0;
    d=i;
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
int main() {
    int d[5],e;
    A();
    int d1[a],d2mt[a],d3cf[a];
    string nombre[a],carrera[a],maestros[a][ma],materias[a][m];
    string materiasm[m],maestrosma[ma];
    int califm[m],calif[a][m];
    float promedio[a];
    for(int i=0;i<a;i++){
        nombre[i]=" ";
        d1[i]=0;
        d2mt[i]=0;
        d3cf[i]=0;
        for(int j=0;j<m;j++){
            calif[i][j]=0;
            maestros[i][j]=" ";
            materias[i][j]=" ";
        }
    }
    for(int i=0;i<100;i++){
        maestrosma[i]=" ";
        materiasm[i]=" ";
    }
    archivo(promedio,nombre,carrera);
    do{
        mostrar(a,nombre,carrera,promedio);
        cout<<"\nQUE DESEAS HACER: "<<endl;
        cout<<"0 - SALIR Y GUARDAR CAMBIOS"<<endl;
        cout<<"1 - AGREGAR/EDITAR ALUMNOS"<<endl;
        cout<<"2 - MOSTRAR INFO ALUMNOS"<<endl;
        cout<<"3 - BORRAR DATOS DE ALGUN ALUMNO"<<endl;
        cout<<"4 - SALIR SIN GUARDAR"<<endl;
        d[0]=v();
        if(d[0]==1){
            cout<<"QUE NUMERO DE ALUMNO DESEAS AGREGAR/EDITAR: ";
            e=v();
            if(e<=a){
            e--;
            if(nombre[e]!=" "){
                for(int i=0;i<a;i++){
                maestrosma[i]=maestros[e][i];
                materiasm[i]=materias[e][i];
                califm[i]=calif[e][i];
                }
            }
            addeditar(a,m,ma,e,nombre,carrera,maestrosma,califm,materiasm,promedio,d1,d2mt,d3cf);
            for(int i=0;i<a;i++){
                maestros[e][i]=maestrosma[i];
                materias[e][i]=materiasm[i];
                calif[e][i]=califm[i];
                }
                for(int i=0;i<a;i++){
                maestrosma[i]=" ";
                materiasm[i]=" ";
                califm[i]=0;
                }
            }else{
                cout<<"ESE ALUMNO NO EXISTE..."<<endl;
            }
        }else if(d[0]==2){
            if(e<=a){
            cout<<"INGRESA EL NUMERO DEL ALUMNNO QUE DESEAS VER TODOS LOS DATOS: ";
            e=v();
            e--;
            if(nombre[e]!=" "){
            datos(a,m,ma,e,nombre,carrera,maestrosma,califm,materiasm,promedio);
            system("pause");
            }else{
                cout<<"NO HAY DATOS QUE MOSTRAR";
                system("pause");
            }
            }else{
                cout<<"ESE ALUMNO NO EXISTE..."<<endl;
            }
        }else if(d[0]==3){
            cout<<"INGRESA EL NUMERO DEL ALUMNO EL CUAL DESEAS ELIMINAR TODOS SUS DATOS: ";
            e=v();
            e--;
            nombre[e]=" ";
        }else if(d[0]==4){
            exit(EXIT_SUCCESS);
        }else{
            cout<<"INGRESA ALGO VALIDO"<<endl;
        }
    }while(d[0]!=0);
    garchivo(promedio,nombre,carrera);
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
    pls=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<d2mt[i];j++){
            materiasm[pls]=materias[i][j];
            pls++;
            if(j+1==d2mt[i]){
                gmm(materiasm,d2mt,i);
            }
        }
    }
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
}
// FALTA QUE GUARDE CALIF, MAESTROS Y MATERIAS