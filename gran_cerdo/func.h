///declaración de funciones
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

void tirarDosDados (int &dado1, int &dado2);
void tirarTresDados (int &dado1, int &dado2, int &dado3);
void mostrarDosDados (int dado1, int dado2);
void mostrarTresDados (int dado1, int dado2, int dado3);
int valorMax (int vec[], int cantidad);
void generarMenu(int &seleccion);
int lanzamientoInicial(int dado1, int dado2, int vec []);
bool lanzamiento2 (int &trufasRonda, int &trufasTotales, int &oink, bool &barro);
bool lanzamiento3 (int &trufasRonda, int &trufasTotales, int &trufasTotales2, int &oink);
void inicio (string jugador1, string jugador2, string &primero, string &segundo);
void turno (string jugadorActivo, string jugadorRival, int &trufasRonda, int &trufasTotales, int &trufasTotales2, int &oink, int &ronda, bool &barro, int &lanzamientosMax);
void jugar (string &primero, string &segundo, int &trufasTotales, int &trufasTotales2, int &oinks1, int &oinks2, int &lanzamientosMax, int &lanzamientosMax2, int &pdv1, int &pdv2);


#endif // FUNC_H_INCLUDED
