///principal
#include <iostream>
#include <stdio.h>
#include <cstdlib> //rand
#include <ctime> //tiempo de rand
#include <string> //string
#include <locale.h> //acentos y ñ
#include <windows.h> //acentos y ñ
#include <unistd.h> //sleep
using namespace std;
#include "func.h"
#include "rlutil.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);


    int trufasJ1 = 0, trufasJ2 = 0, oinkJ1 = 0, oinkJ2 = 0, lanzamientosMax1 = 0, lanzamientosMax2 = 0, pdv1 = 0, pdv2 = 0, pdvmax = 0, seleccion = 4;
    string primerJugador, segundoJugador, campeon;

    while (seleccion != 0){

        system("cls");
        generarMenu(seleccion);


        cout << endl;
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:

            system("cls");
            jugar(primerJugador, segundoJugador, trufasJ1, trufasJ2, oinkJ1, oinkJ2, lanzamientosMax1, lanzamientosMax2, pdv1, pdv2);

            if (pdv1 > pdv2) {

                if (pdv1 > pdvmax) {

                    pdvmax = pdv1;
                    campeon = primerJugador;

                }

             } else {

                if (pdv2 > pdvmax) {

                    pdvmax = pdv2;
                    campeon = segundoJugador;

                }
             }
             break;
        case 2:
            system("cls");
            cout << "------------------------------" << endl;
            cout << "Campeón actual: " << campeon << "." << endl;
            cout << "Con un acumulado de " << pdvmax << " puntos de victoria." << endl;
            cout << "------------------------------";
            rlutil::anykey();
            break;
        case 3:
            system("cls");
            cout << "------------------------------" << endl;
            cout << "Integrantes: " << endl;
            cout << "27234, Lenzi Gaspar" << endl;
            cout << "26852, Giardini Uriel Damián" << endl;
            cout << "23616, Montes de Oca Jorge" << endl;
            cout << "27258, Quiros Pedro" << endl;
            cout << "------------------------------";
            rlutil::anykey();
            break;

        case 0:
            return 0;

        }

    }



}
