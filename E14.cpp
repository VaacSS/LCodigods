/*
---------------------------------------------------------------
NOMBRE: SANTIAGO VARGAS ACEVES
FECHA:20/04/2023
PROGRAMA:EJERCICIO 14
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION/2DO SEMESTRE
PROFESOR:CRUZ FRANCO CARLOS JAVIER
---------------------------------------------------------------
*/
#include <iostream>
#include <stdlib.h>
#include "conio.h"
#include "santis.h"
using namespace std;
const int MAX_DISCS = 10;
void mostrartorres(int A[], int B[], int C[], int n) {
    for (int i = n-1; i >= 0; i--) {
        if (i < n - A[0]) {
            cout << A[i+1];
        } else {
            cout << " ";
        }
        cout << "  ";
        if (i < n - B[0]) {
            cout << B[i+1];
        } else {
            cout << " ";
        }
        cout << "  ";
        if (i < n - C[0]) {
            cout << C[i+1];
        } else {
            cout << " ";
        }
        cout << endl;
    }
    cout << "--------------------------\n";
    cout << "  A     B     C\n\n";
}
void mover(int A[], int B[], int C[], int& from, int& to) {
    if (from == 0) {
        cout << "Movimiento inválido" << endl;
        return;
    }
    if (to != 0 && C[to] < A[from]) {
        cout << "Movimiento inválido" << endl;
        return;
    }
    int disk = A[from];
    A[from] = 0;
    to++;
    C[to] = disk;
}

void TH(int n,int o,int d,int temp){
	if(n>0){
		TH(n-1,o,temp,d);
		cout<<"SE MUEVE DESDE: "<<o<<endl;
		cout<<"HASTA: "<<d<<endl;
		cout<<endl;
		TH(n-1,temp,d,o);
	}
}
int main(){
	int d,n1;
	cout<<"INGRESA CUANTOS DISCOS QUIERES QUE HAYA c:"<<endl;
	n1=v();
	system("cls");
	cout<<"COMO DESEAS HACERLO: "<<endl<<"1- AUTOMATICO"<<endl<<"2- MANUAL"<<endl;
	d=v();
	if(d==1){
		cout<<"SE ACOMODARAN "<<n1<<" DISCOS DE HANOI"<<endl;
		TH(n1,1,3,2);
	}else if(d==2){
		int A[MAX_DISCS+1] = {n1};
    int B[MAX_DISCS+1] = {0};
    int C[MAX_DISCS+1] = {0};

    for (int i = 1; i <= n1; i++) {
        A[i] = n1 - i + 1;
    }

    mostrartorres(A, B, C, n1);

    int from, to;
    while (C[n1] == 0) {
        cout << "Ingrese la torre de origen (1 para A, 2 para B, 3 para C): ";
        cin >> from;
        cout << "Ingrese la torre de destino (1 para A, 2 para B, 3 para C): ";
        cin >> to;
        mover(A, B, C, from, to);
        mostrartorres(A, B, C, n1);
    }

    cout << "¡Juego completado!" << endl;

	}
}

