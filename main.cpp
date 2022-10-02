#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>

using namespace std;

#include "funcionesUtilesFinal.h"
#include "rlutil.h"
#include "funciones.h"

#include "tirarDados.h"
#include "INTERFACES.h"
#include "analizarPuntos.h"
#include "reRoll.h"
#include "interfazSolo.h"
#include "interfazDupla.h"
#include "mostrarMaximoPuntaje.h"

int main() {
    int opc = 1, y = 0, maxSumaTiro = 0, maxPuntos = -1;
    char maxNombre[30] = "null";

    recuadroMenu();
    do {
        resaltarMenu("Juego nuevo de a 1", 27, 10, y == 0);

        resaltarMenu("Juego nuevo entre 2", 27, 11, y == 1);

        resaltarMenu("Mostrar puntuacion mas alta", 27, 12, y == 2);

        resaltarMenu("Salir", 27, 13, y == 3);

        rlutil::locate(25, 10 + y); /// Muestra selector de menu
        cout << char(175);

        int key = rlutil::getkey();

        switch (key) {
        case 14: /// UP
            rlutil::locate(25, 10 + y);
            cout << " ";
            y--;
            if(y < 0){
                y = 0;
                cout << "\a";
            }
            break;
        case 15: /// DOWN
            rlutil::locate(25, 10 + y);
            cout << " ";
            y++;
            if(y > 3) {
                y = 3;
                cout << "\a";
            }
            break;
        case 1: /// ENTER
            switch (y) {
            case 0:
                solitario(maxNombre, 29, &maxSumaTiro, &maxPuntos);
                break;
            case 1:
                dupla(maxNombre, 29, &maxSumaTiro, &maxPuntos);
                break;
            case 2:
                rlutil::cls();
                mostrarMaximoPuntaje(maxNombre, maxSumaTiro, maxPuntos);
                break;
            case 3:
                rlutil::cls();
                opc = 0;
                cout << "\a";
                rlutil::locate(23, 12);
                cout << "GRACIAS POR JUGAR A NUESTRA GENERALA!";
                rlutil::locate(23, 14);
                cout <<"COGO, LUCIANO - GOMEZ, GRACIELA - ORELLANO, JOSELO";
                rlutil::locate(23, 16);
                system("pause");
                rlutil::cls();
                break;
            default:
                break;
            }
        default:
            break;
        }
    } while (opc != 0);
    return 0;
}




