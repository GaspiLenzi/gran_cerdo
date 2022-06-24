///definicion de funcionees
#include<iostream>
#include <stdio.h>
#include <cstdlib> //rand
#include <ctime> //tiempo de rand
#include <string> //string
#include <locale.h> //acentos y ñ
#include <windows.h> //acentos y ñ
#include <unistd.h> //
using namespace std;
#include "func.h"
#include "rlutil.h"


/*--------------------------------------------------------------------------------------------------------------------------------*/
///le asigna valor random a los 2 primeros dados
void tirarDosDados (int &dado1, int &dado2){

    srand (time(NULL));
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///le asigna valor random a los 3 dados
void tirarTresDados (int &dado1, int &dado2, int &dado3){


    srand (time(NULL));
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    dado3 = (rand() % 6) + 1;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///muestra los dos primeros dados
void mostrarDosDados (int dado1, int dado2){

    cout << endl << endl << dado1 << " | " << dado2 << endl << endl;

}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///muestra los tres dados
void mostrarTresDados (int dado1, int dado2, int dado3){

    cout << endl << endl << dado1 << " | " << dado2 << " | " << dado3 << endl << endl;

}


/*--------------------------------------------------------------------------------------------------------------------------------*/

///ejecuta el lanzamiento de 2 dados
bool lanzamiento2 (int &trufasRonda, int &trufasTotales, int &oink, bool &barro){

    int dado1, dado2;

    char seleccion;

    tirarDosDados(dado1, dado2);
    mostrarDosDados(dado1, dado2);

    if (dado1 != dado2 && (dado1 != 1 && dado2 != 1)){


        trufasRonda += dado1 + dado2;
        trufasTotales += dado1 + dado2;

        cout << "¡Sumaste " << dado1 + dado2 << " trufas!" << endl;
        cout << "¿Continuar? S/N" << endl;
        cin >> seleccion;


        while (seleccion != 'S' && seleccion != 'N'){
            cout << endl << "Ingreso no válido, favor de escribir S o N" << endl;
            cin >> seleccion;
        }

        if (seleccion == 'S'){

            return true;

        }

        return false;
    }

    else{

            if (dado1 == dado2 && (dado1 != 1 && dado2 != 1)){

            trufasRonda += (dado1 + dado2) * 2;
            trufasTotales += (dado1 + dado2) * 2;
            oink ++;

            rlutil::setColor(rlutil::GREEN);

            cout << "¡Oink!" << endl;
            cout << "    _____  " << endl << "^..^     \9" << endl << "(oo)_____/ " << endl << "   WW  WW" << endl;
            cout << "¡Sumaste " << (dado1 + dado2) * 2 << " trufas!" << endl;
            cout << endl << "Debes lanzar nuevamente";

            rlutil::setColor(rlutil::BLACK);

            rlutil::anykey();

            return true;


        }
        else {

                if (dado1 != dado2 && (dado1 == 1 || dado2 == 1)){

                        rlutil::setColor(rlutil::RED);


                        cout << "¡Sacaste un as!" << endl;
                        cout << "Perdiste todas las trufas que fuiste ganando en la ronda";
                        cout << endl << endl << "Le cedes tu turno al rival";

                        trufasTotales = trufasTotales - trufasRonda;
                        trufasRonda = 0;

                        rlutil::setColor(rlutil::BLACK);

                        rlutil::anykey();

                        return false;
                    }
                    else {

                            if (dado1 == 1 && dado2 == 1) {

                                rlutil::setColor(rlutil::RED);


                                cout << "¡Te hundiste en el barro!" << endl << "Perdes todas tus trufas";
                                cout << endl << endl << "            (\____/)" << endl << "            / @__@ \." << endl << "           (  (oo)  )" << endl << "            `-.~~.-'" << endl << "             /    \.";
                                cout << endl << "           @/      \_" << endl << "          (/ /    \ \)" << endl << "           WW`----'WW";

                                trufasTotales = 0;
                                trufasRonda = 0;

                                barro = true;

                                rlutil::setColor(rlutil::BLACK);


                                rlutil::anykey();


                                return false;

                            }

                    }

        }
    }


}

/*--------------------------------------------------------------------------------------------------------------------------------*/


///ejecuta el lanzamiento de 3 dados

bool lanzamiento3 (int &trufasRonda, int &trufasTotales, int &trufasTotales2, int &oink){

    int dado1, dado2, dado3;

    char seleccion;

    tirarTresDados(dado1, dado2, dado3);
    mostrarTresDados(dado1, dado2, dado3);

    if ((dado1 != dado2 || dado1 != dado3 || dado2 != dado3) && ((dado1 != 1) && (dado2 != 1) && (dado3 != 1))){ /// decidí que se sumen todos los dados


        trufasRonda += dado1 + dado2 + dado3;
        trufasTotales += dado1 + dado2 + dado3;

        cout << "¡Sumaste " << dado1 + dado2 + dado3 << " trufas!" << endl;
        cout << "¿Continuar? S/N" << endl;
        cin >> seleccion;


        while (seleccion != 'S' && seleccion != 'N'){
            cout << endl << "Ingreso no válido, favor de escribir S o N" << endl;
            cin >> seleccion;
        }

        if (seleccion == 'S'){

            return true;

        }

        return false;
    }

    else{

            if ((dado1 == dado2 && dado1 == dado3) && ((dado1 != 1) && (dado2 != 1) && (dado3 !=1))){

            trufasRonda += (dado1 + dado2 + dado3) * 2;
            trufasTotales += (dado1 + dado2 + dado3) * 2;
            oink ++;

            rlutil::setColor(rlutil::GREEN);

            cout << "¡Oink!" << endl;
            cout << "    _____  " << endl << "^..^     \9" << endl << "(oo)_____/ " << endl << "   WW  WW" << endl;
            cout << "¡Sumaste " << (dado1 + dado2 + dado3) * 2 << " trufas!" << endl;
            cout << endl << "Debes lanzar nuevamente";

            rlutil::setColor(rlutil::BLACK);


            rlutil::anykey();

            return true;


        }
        else {

                if ((dado1 == 1 && ((dado2 != dado1) && (dado3 != dado1))) || (dado2 == 1 && ((dado1 != dado2) && (dado3 != dado2))) || (dado3 == 1 && ((dado1 != dado3) && (dado2 != dado3)))){

                        rlutil::setColor(rlutil::RED);


                        cout << "¡Sacaste un as!" << endl;
                        cout << "Perdiste todas las trufas que fuiste ganando en la ronda";
                        cout << endl << endl << "Le cedes tu turno al rival";


                        trufasTotales = trufasTotales - trufasRonda;
                        trufasRonda = 0;


                        rlutil::setColor(rlutil::BLACK);


                        rlutil::anykey();

                        return false;
                    }
                    else {

                            if ((dado1 == 1) && (dado2 == 1) && (dado3 == 1)) {


                                rlutil::setColor(rlutil::RED);


                                cout << "¡Te ahogaste en el barro!" << endl << "Le cedes todas las trufas a tu rival";
                                cout << endl << endl << "                ,-,------," << endl << "              _ \(\(_,--'" << endl << "         <`--'\>/(/(__" << endl << "         /. .  `'` '  \." << endl << "        (`')  ,        @";
                                cout << endl << "         `-._,        /" << endl << "            )-)_/--( >    " << endl << "           ''''  ''''";

                                trufasTotales2 += trufasTotales;
                                trufasTotales = 0;
                                trufasRonda = 0;

                                rlutil::setColor(rlutil::BLACK);


                                rlutil::anykey();

                                return false;

                            }
                            else {

                                    rlutil::setColor(rlutil::RED);


                                    cout << "¡Te hundiste en el barro!" << endl << "Perdes todas tus trufas";
                                    cout << endl << endl << "            (\____/)" << endl << "            / @__@ \." << endl << "           (  (oo)  )" << endl << "            `-.~~.-'" << endl << "             /    \.";
                                    cout << endl << "           @/      \_" << endl << "          (/ /    \ \)" << endl << "           WW`----'WW";

                                    trufasTotales = 0;
                                    trufasRonda = 0;

                                    rlutil::setColor(rlutil::BLACK);


                                    rlutil::anykey();

                                    return false;


                            }

                    }

        }
    }


}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///maneja el cambio de turno

void turno (string jugadorActivo, string jugadorRival, int &trufasRonda, int &trufasTotales, int &trufasTotales2, int &oink, int &ronda, bool &barro, int &lanzamientosMax){

bool continuar = true;
int lanzamientos = 0;

while (continuar){


    system("cls");

    cout << endl << "Trufas totales de " << jugadorActivo << ": " << trufasTotales << "                           Trufas totales de " << jugadorRival << ": " << trufasTotales2;
    cout << endl << endl << endl << "Turno de: " << jugadorActivo << endl << "Ronda: " << ronda;

    lanzamientos ++;


    cout << endl <<"Lanzamiento #" << lanzamientos;
    cout << endl << "Trufas de la ronda " << trufasRonda;

    if (lanzamientos > lanzamientosMax){

        lanzamientosMax = lanzamientos;
    }

    if (trufasTotales >= 50 && trufasTotales2 >= 50){
        barro = true;
    }

    if (barro == true) {

    continuar = lanzamiento3(trufasRonda, trufasTotales, trufasTotales2, oink);

    } else {

    continuar = lanzamiento2(trufasRonda, trufasTotales, oink, barro);

    }
}

}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///ejecuta el lanzamiento inicial (solo para decidir quien juega primero)
int lanzamientoInicial(int dado1, int dado2, int vec []) {

    tirarDosDados(dado1, dado2);
    mostrarDosDados(dado1, dado2);
    vec [0]= dado1;
    vec [1]= dado2;
    return vec [0] + vec [1];

}

///busca el valor maximo del vector
int valorMax (int vec[], int cantidad){

    int maxi = 0;

    for (int i = 0; i < cantidad; i++) {

        if (i == 0){

            maxi = vec [i];

        }
        else {

            if (vec [i] > maxi){

                maxi = vec [i];

            }
        }

    }

     return maxi;

}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///muestra menu
void generarMenu (int &selecccion) {

    cout << "------------------------------\n1 - Jugar \n2 - Estadísticas \n3 - Cerditos \n------------------------------\n0 - Salir";


}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///funcion para ver quien juega primero, si empatan en puntaje y dado maximo se llama a si misma otra vez
void inicio (string jugador1, string jugador2, string &primero, string &segundo){

    int dado1 = 0, dado2 = 0, puntajeInicial1 [2] = {}, puntajeInicial2 [2] = {}, primerTirada1 = 0, primerTirada2 = 0, max1, max2;

    cout << endl << endl << "Lanzamiento de " << jugador1;

    rlutil::anykey();

    primerTirada1 = lanzamientoInicial(dado1, dado2, puntajeInicial1);
    cout << endl << "Puntos de " << jugador1 << ": " << primerTirada1 << endl;
    rlutil::anykey();


    cout << endl << endl << "Lanzamiento de " << jugador2;

    rlutil::anykey();

    primerTirada2 = lanzamientoInicial(dado1, dado2, puntajeInicial2);
    cout << endl << "Puntos de " << jugador2 << ": " << primerTirada2 << endl;


    if (primerTirada1 > primerTirada2){


       primero = jugador1;
       segundo = jugador2;

    }
    else {

        if (primerTirada1 < primerTirada2) {

                primero = jugador2;
                segundo = jugador1;

        } else {

            rlutil::anykey();
            cout << "Tienen la misma puntuación, el ganador se da por el dado mas alto" << endl;
            if (valorMax(puntajeInicial1, 2) > valorMax(puntajeInicial2, 2)){

                primero = jugador1;
                segundo = jugador2;

            } else{

                if (valorMax(puntajeInicial1, 2) < valorMax(puntajeInicial2, 2)){

                        primero = jugador2;
                        segundo = jugador1;

                    } else {
                        rlutil::anykey();
                        cout << endl << "...";
                        rlutil::anykey();
                        cout << endl << "¡Hubo empate de puntuación y dado mayor! Hay que tener mala suerte... ¿O buena? \nTiremos de nuevo";
                        rlutil::anykey();
                        system("cls");
                        inicio (jugador1, jugador2, primero, segundo);

                    }

            }

        }


    }




}

/*--------------------------------------------------------------------------------------------------------------------------------*/

///inicia una partida
void jugar (string &primerJugador, string &segundoJugador, int &trufasJ1, int &trufasJ2, int &oinkJ1, int &oinkJ2, int &lanzamientosMax1, int &lanzamientosMax2, int &pdv1, int &pdv2){

    rlutil::setBackgroundColor(rlutil::YELLOW);
    setlocale(LC_ALL, "spanish"); // acentos y ñ
    srand (time(NULL)); // inicializo motor de numeros random

    int trufasRondaJ1 = 0, trufasRondaJ2 = 0;
    string jugador1, jugador2;
    char seguir;
    bool barro = false;


    trufasJ1 = 0;
    trufasJ2 = 0;
    oinkJ1 = 0;
    oinkJ2 = 0;
    lanzamientosMax1 = 0;
    lanzamientosMax2 = 0;


    cout << "Ingresar nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingresar nombre del jugador 2: ";
    cin >> jugador2;

    system("cls");

    inicio(jugador1, jugador2, primerJugador, segundoJugador);

    rlutil::anykey();

    cout << endl << "Quien juega primero es " << primerJugador;

    rlutil::anykey();

    system("cls");

    for (int i = 1; i <= 5; i++){


        turno (primerJugador, segundoJugador, trufasRondaJ1, trufasJ1, trufasJ2,  oinkJ1, i, barro, lanzamientosMax1);
        trufasRondaJ1 = 0;

        turno (segundoJugador, primerJugador, trufasRondaJ2, trufasJ2, trufasJ1, oinkJ2, i, barro, lanzamientosMax2);
        trufasRondaJ2 = 0;


    }


    system("cls");

    pdv1 = trufasJ1 / 50 + oinkJ1 * 2;
    pdv2 = trufasJ2 / 50 + oinkJ2 * 2;

    if (trufasJ1 > trufasJ2) {

        pdv1 += 5;
    } else {

        if (trufasJ1 < trufasJ2){

            pdv2 += 5;
        } else {

            if (trufasJ1 == trufasJ2){
            pdv1 += 5;
            pdv2 += 5;}
        }
    }

    if (lanzamientosMax1 > lanzamientosMax2){

        pdv1 += 3;
    } else {

        if (lanzamientosMax1 < lanzamientosMax2) {
            pdv2 += 3;
        } else {

            if (lanzamientosMax1 == lanzamientosMax2){
            pdv1 += 3;
            pdv2 += 3;}
        }
    }


    rlutil::locate(55,1);
    cout << "GRAN CERDO" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    rlutil::locate(1,4);
    cout << "HITO";
    rlutil::locate(40,4);
    cout << primerJugador;
    rlutil::locate(80,4);
    cout << segundoJugador << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";


    rlutil::locate(1,6);
    cout << "Mas trufas en total";

    if (trufasJ1 > trufasJ2){
        rlutil::locate(40,6);
        cout << "5 PDV (" << trufasJ1 << " trufas)";

        rlutil::locate(80,6);
        cout << "0 PDV (" << trufasJ2 << " trufas)";

    } else {

        if (trufasJ1 < trufasJ2){
        rlutil::locate(40,6);
        cout << "0 PDV (" << trufasJ1 << " trufas)";

        rlutil::locate(80,6);
        cout << "5 PDV (" << trufasJ2 << " trufas)";

        } else {

            if (trufasJ1 == trufasJ2) {
            rlutil::locate(40,6);
            cout << "5 PDV (" << trufasJ1 << " trufas)";

            rlutil::locate(80,6);
            cout << "5 PDV (" << trufasJ2 << " trufas)";}

        }

    }


    rlutil::locate(1,7);
    cout << "Cada 50 trufas";

    rlutil::locate(40,7);
    cout << trufasJ1 / 50 << " PDV (" << trufasJ1 - (trufasJ1 % 50) << " trufas)";

    rlutil::locate(80,7);
    cout << trufasJ2 / 50 << " PDV (" << trufasJ2 - (trufasJ2 % 50) << " trufas)";


    rlutil::locate(1,8);
    cout << "Oinks";

    rlutil::locate(40,8);
    cout << oinkJ1 * 2 << " PDV (" << oinkJ1 << " oinks)";

    rlutil::locate(80,8);
    cout << oinkJ2 * 2 << " PDV (" << oinkJ2 << " oinks)";


    rlutil::locate(1,9);
    cout << "Cerdo codicioso";

    if (lanzamientosMax1 > lanzamientosMax2){
        rlutil::locate(40,9);
        cout << "3 PDV (" << lanzamientosMax1 << " lanzamientos)";

        rlutil::locate(80,9);
        cout << "0 PDV (" << lanzamientosMax2 << " lanzamientos)";

    } else {

        if (lanzamientosMax1 < lanzamientosMax2){
            rlutil::locate(40,9);
            cout << "0 PDV (" << lanzamientosMax1 << " lanzamientos)";

            rlutil::locate(80,9);
            cout << "3 PDV (" << lanzamientosMax2 << " lanzamientos)";
        } else {

            rlutil::locate(40,9);
            cout << "3 PDV (" << lanzamientosMax1 << " lanzamientos)";

            rlutil::locate(80,9);
            cout << "3 PDV (" << lanzamientosMax2 << " lanzamientos)";

        }
    }

    cout << endl << "------------------------------------------------------------------------------------------------------------------------";

    rlutil::locate(1,11);
    cout << "TOTAL";

    rlutil::locate(40,11);
    cout << pdv1 << " PDV";

    rlutil::locate(80,11);
    cout << pdv2 << " PDV";

    if (pdv1 > pdv2) {

        cout << endl << endl << "Ganador: " << primerJugador << " con " << pdv1 << " puntos de victoria.";

    } else {

        cout << endl << endl << "Ganador: " << segundoJugador << " con " << pdv2 << " puntos de victoria.";

    }

    rlutil::anykey();

}















