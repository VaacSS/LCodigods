#include <iostream>
#include <string>
#include <fstream>
#include "santis.h"
using namespace std;
void mostrar(int a,string nombre[],string carrera[],float promedio[]){
    fflush(stdin);
    system("cls");
    cout<<"LISTA DE ALUMNOS"<<endl;
    for(int i=0;i<a;i++){
        if(nombre[i]!=" "){
            cout<<i+1<<"- "<<nombre[i]<<endl;
            cout<<carrera[i]<<endl;
            cout<<"PROMEDIO: "<<promedio[i]<<endl;
            cout<<i;
        }else{
            cout<<i+1<<"- "<<endl;
        }
    }
}
void datos(int a,int m,int ma,int e,string nombre[],string carrera[],string maestrosma[],int califm[],string materiasm[],float promedio[]){
    cout<<"NOMBRE: "<<nombre[e-1]<<endl;
    cout<<"CARRERA: "<<carrera[e-1]<<endl;
    cout<<"MAESTROS: "<<endl;
    for(int i=0;i<ma;i++){
            fflush(stdin);
            cout<<maestrosma[i]<<endl;
        }
        cout<<"MATERIAS: "<<endl;
        for(int i=0;i<a;i++){
            fflush(stdin);
            cout<<materiasm[i]<<endl;
            cout<<"calificacion: "<<califm[i]<<endl;
        }
}
void addeditar(int a,int m,int ma,int e,string nombre[],string carrera[],string maestrosma[],int califm[],string materiasm[],float promedio[]){
    int pp,ppp=0;
    fflush(stdin);
    if(nombre[e]!=" "){
         datos(a,m,ma,e,nombre,carrera,maestrosma,califm,materiasm,promedio);
        cout<<"\nCAMBIO: "<<endl;
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
            cout<<"\ncalificacion: ";
            califm[i]=v();
            if(i!=(ma-1)){
            cout<<"TIENE MAS MATERIAS? (0-no / 1-si)";
            cin>>pp;
            if(pp==0){
                i+=ma;
            }
            }
        }
        promedio[e]=0;
        for(int i=0;i<m;i++){
            ppp+=califm[i];
        }
        promedio[e]=ppp/=m;
}
int main() {
    int d[5],a,m,ma,e;
    cout<<"\nCUANTOS ALUMNOS HAY EN LA INSTITUCION: ";
    a=v();
    cout<<"\nCUANTAS MATERIAS HAY EN LA INSTITUCION: ";
    m=v();
    cout<<"\nCUANTOS MAESTROS HAY EN LA INSTITUCION: ";
    ma=v();
    string nombre[a],carrera[a],maestros[a][ma],materias[a][m];
    string materiasm[m],maestrosma[ma];
    int califm[m],calif[a][m];
    float promedio[a];
    for(int i=0;i<a;i++){
        nombre[i]=" ";
        for(int j=0;j<m;j++){
            calif[i][j]=0;
        }
    }
    system("cls");
    do{
        mostrar(a,nombre,carrera,promedio);
        cout<<"\nQUE DESEAS HACER: "<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"1 - AGREGAR/EDITAR ALUMNOS"<<endl;
        cout<<"2 - MOSTRAR INFO ALUMNOS"<<endl;
        d[0]=v();
        if(d[0]==1){
            cout<<"QUE NUMERO DE ALUMNO DESEAS AGREGAR/EDITAR: ";
            e=v();
            e--;
            if(nombre[e]!=" "){
                for(int i=0;i<a;i++){
                maestrosma[i]=maestros[e][i];
                materiasm[i]=materias[e][i];
                califm[i]=calif[e][i];
                }
            }
            addeditar(a,m,ma,e,nombre,carrera,maestrosma,califm,materiasm,promedio);
            for(int i=0;i<a;i++){
                maestros[e][i]=maestrosma[i];
                materias[e][i]=materiasm[i];
                calif[e][i]=califm[i];
                }
        }
    }while(d[0]!=0);
}
/*FALTA GUARDAR EN LAS MATRICES LOS DATOS M Y MA EESOS PEUS
SACAR PROMEDIOS
GUARDAR EN UN BLOC DE NOTAS
NO PONER MAS MAESTROS SI YA ES MAS DE LOS YA DUICHOS
QUE QUEDE BIEN EL EDITAR QUE NO EDITA*/