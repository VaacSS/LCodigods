#include <iostream>
using namespace std;

int main()
{
    int num;     // Se crea una variable llamada num con el valor 5

    cout<<"Ingrese un numero: ";cin>>num;


    int *ptr = &num; // Se crea un puntero llamado ptr que apunta a la dirección de memoria de num

    cout << "El valor de num es: " << num << endl;                 // Imprime el valor de num
    cout << "La dirección de memoria de num es: " << &num << endl; // Imprime la dirección de memoria de num
    cout << "El valor de ptr es: " << ptr << endl;                 // Imprime el valor de ptr (la dirección de memoria de num)
    cout << "El valor al que apunta ptr es: " << *ptr << endl;     // Imprime el valor al que apunta ptr (el valor de num)

    *ptr = 10; // Se cambia el valor de num a través del puntero ptr

    cout << "El valor de num es ahora: " << num << endl; // Imprime el nuevo valor de num

    return 0;
}
