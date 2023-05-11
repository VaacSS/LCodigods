#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void a_alumno(string *&alumnos, int &d1) {
    int d;
    cout << "CUANTOS ALUMNOS DESEAS AGREGAR? (" << d1 << " GUARDADOS): ";
    cin >> d;
    cin.ignore();
    if (d > 0) {
        string *nalumnos = new string[d1 + d]; //d1 son los ya guardados y se suma d para que guarde los nuevos
        for (int i = 0; i < d; i++) {
            cout << "NOMBRE DEL ALUMNO [" << d1 + i + 1 << "]: ";
            getline(cin, nalumnos[d1 + i]);
        }
        if (d1 > 0) {
            for (int i = 0; i < d1; i++) {
                nalumnos[i] = alumnos[i];
            }
            delete[] alumnos; // Libera la memoria de alumnos para vaciarla e igualarla
        } 
        alumnos = nalumnos;
        d1 += d;
    }
}
int main() {
    string *alumnos = nullptr;
    int d1 = 0;
    a_alumno(alumnos, d1);
    cout << "ALUMNOS GUARDADOS: " << endl;
    for (int i = 0; i < d1; i++) {
        cout << i + 1 << ". " << alumnos[i] << endl;
    }
    delete[] alumnos; // Liberar memoria al final
}
