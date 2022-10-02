#ifndef MOSTRARMAXIMOPUNTAJE_H_INCLUDED
#define MOSTRARMAXIMOPUNTAJE_H_INCLUDED

/// Delcaracion funcion mostrarMaximoPuntaje

void mostrarMaximoPuntaje(char maxNombre[30], int maxSumaTiro, int maxPuntos); /// muestra el nombre, lanzamientos y puntaje durante la ejecucion del juego

/// Definicion

void mostrarMaximoPuntaje(char maxNombre[30], int maxSumaTiro, int maxPuntos) {
    rlutil::cls();
    recuadro(30, 7, 50, 10, 15, 4);
    if (maxPuntos == -1) {
        rlutil::locate(41, 10);
        cout << "RANKING NUMERO 1: " << "Null";
        rlutil::locate(45, 11);
        cout << "LANZAMIENTOS: " << "Null";
        rlutil::locate(44, 13);
        cout << "PUNTAJE MAYOR: " << "Null";
    }
    else {
        rlutil::locate(41, 10);
        cout << "RANKING NUMERO 1: " << maxNombre;
        rlutil::locate(45, 11);
        cout << "LANZAMIENTOS: " << maxSumaTiro;
        rlutil::locate(44, 13);
        cout << "PUNTAJE MAYOR: " << maxPuntos;
    }
    getch();
    rlutil::cls(); /// REDIBUJA RECUADRO MENU
    recuadroMenu();
}

#endif // MOSTRARMAXIMOPUNTAJE_H_INCLUDED
