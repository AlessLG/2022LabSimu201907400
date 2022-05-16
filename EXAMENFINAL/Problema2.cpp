/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/16
Compilador:     g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      g++ -o Problema2.out Problema2.cpp && ./Problema2.out
Librerias:      iostream
Resumen:        Este programa 
*/

// Librerías.
#include <iostream>

// Para usar impresión de texto más simple.
using namespace std;

class Cohetes
{
    public:
        // Atributos públicos de la clase.
        double emp, tsfc, cd, secc, masac, masaf;
    public:
        // Definimos el constructor, le pasamos 6 variables de tipo double.
        Cohetes(double a, double b, double c, double d, double e, double f)
        {
            
            emp=a;
            tsfc=b;
            cd=c;
            secc=d;
            masac=e;
            masaf=f;
        }
        // Definimos el método que imprime la información de los objetos.
        void mosInfo()
        {
            // Mostramos la información de los cohetes
            cout << emp <<"\n"<< tsfc <<"\n"<< cd <<"\n"<< secc <<"\n"<< masac <<"\n"<< masaf <<"\n";
        }
};

int main() {
    // Definimos los objetos con sus atributos.
    Cohetes mun(30000000.0, 0.0003248, 61.27, 201.06, 110000.0, 1500000.0);
    Cohetes kin(27000000.0, 0.0002248, 61.27, 201.06, 110000.0, 1500000.0);
    Cohetes chac(25000000.0, 0.0002248, 70.25, 215.06, 180000.0, 2100000.0);
    // Mostramos la información.
    cout << "Los datos del cohete Mun son: \n";
    mun.mosInfo();
    cout << "Los datos del cohete Kin son: \n";
    kin.mosInfo();
    cout << "Los datos del cohete Chac son: \n";
    chac.mosInfo();
    cout << endl;
    return 0;
}
