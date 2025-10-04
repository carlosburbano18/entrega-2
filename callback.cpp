#include <iostream>
#include <cstdlib>   
#include <string>
using namespace std;


double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cerr << "Error: División por cero no permitida." << endl;
        exit(1);
    }
    return a / b;
}


void performOperation(double (*callback)(double, double), double x, double y) {
    cout << "Resultado: " << callback(x, y) << endl;
}

int main(int argc, char* argv[]) {
    // Validación de argumentos
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <operando1> <operador> <operando2>" << endl;
        cerr << "Ejemplo: " << argv[0] << " 5.2 + 3.1" << endl;
        return 1;
    }

    
    double op1 = atof(argv[1]);   
    string oper = argv[2];        
    double op2 = atof(argv[3]);   


    if (oper == "+") {
        performOperation(add, op1, op2);
    } else if (oper == "-") {
        performOperation(subtract, op1, op2);
    } else if (oper == "*" || oper == "x" || oper == "X") {
        performOperation(multiply, op1, op2);
    } else if (oper == "/") {
        performOperation(divide, op1, op2);
    } else {
        cerr << "Error: Operador inválido. Use +, -, *, x o /." << endl;
        return 1;
    }

    return 0;
}
