#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 7;
    int sum = a + b;
    cout << "La suma de " << a << " y " << b << " es " << sum << endl;
    return 0;
}
/*
Copy code
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
    int a = 5, b = 7;
    Suma s(a, b);
    int sum = s.calcular();
    cout << "La suma de " << a << " y " << b << " es " << sum << endl;
    return 0;
}*/