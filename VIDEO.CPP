#include <iostream>
using namespace std;

class Suma {
public:
    Suma(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int calcular() {
        return a + b;
    }
private:
    int a, b;
};

int main() {
    int a , b ;
    cin>>a;
    cin>>b;
    Suma s(a, b);
    int sum = s.calcular();
    cout << "La suma de " << a << " y " << b << " es " << sum << endl;
    return 0;
}