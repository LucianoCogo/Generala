#ifndef INTERFAZSOLO_H_INCLUDED
#define INTERFAZSOLO_H_INCLUDED

/// DECLARACION INTERFAZ SOLO

void solitario(char *maxNombre, int tam, int *maxSumaTiro, int *maxPuntos); /// VENTANA CARGAR NOMBRE DE UN JUGADOR

int interfazSolo(char nombre[30], int totalRondas, int resultado[2]); /// INTERFAZ MODO UN JUGADOR

/// DEFINICION

void solitario(char *maxNombre, int tam, int *maxSumaTiro, int *maxPuntos) {
    char nombre[30];
    int totalRondas = 0, resultado[2];

    rlutil::hidecursor();
    rlutil::cls();
    recuadro(2, 1, 75, 25, 15, 2);
    rlutil::locate(23, 11);
    cout << "INGRESE LA CANTIDAD DE RONDAS A JUGAR: "; /// CANTIDAD DE RONDAS
    totalRondas = elegirRondas(); /// LLAMA A FUNCION QUE VALIDA EL NUMERO DE RONDAS

    rlutil::locate(23, 13);
    cout << "INGRESE NOMBRE: "; /// CARGA NOMBRE DE JUGADOR
    rlutil::locate(40, 13);
    cargarCadena(nombre, 29);
    system("cls");
    if (interfazSolo(nombre, totalRondas, resultado) > *maxPuntos) {
        strcpy(maxNombre, nombre);
        *maxPuntos = resultado[0];
        *maxSumaTiro = resultado[1];
    }
}

int interfazSolo(char nombre[30], int totalRondas, int resultado[2]) {
    int ronda, lanzamiento, puntos = 0, vecDado[5], sumaTiro = 0;
    bool TestMode = false;
    char TestName[30] = "Test";
    char lanzar;
    int vecTabla[10]; /// Vector de la tabla de puntuaciones;

    ponerMenos1(vecTabla, 10);
    if (strcmp(nombre, TestName) == 0) TestMode = true;
    for (ronda = 1; ronda <= totalRondas; ronda++) {
        bool generala = false;

        lanzamiento = 1;
        sumaTiro++;
        rlutil::cls();
        if (ronda == 1) {
            puntos = 0;
        }
        rlutil::cls();
        recuadro(2, 1, 75, 25, 15, 4);
        rlutil::locate(4, 3);
        cout << "TURNO DE: ";
        rlutil::locate(14, 3);
        mostrarCaracter(nombre);
        rlutil::locate(30, 3);
        cout << "RONDA N: " << ronda;
        rlutil::locate(53, 3);
        cout << "PUNTAJE TOTAL: " <<  puntos << " PUNTOS";
        rlutil::locate(4, 4);
        cout << "--------------------------------------------------------------------------";
        rlutil::locate(4, 5);
        cout << "LANZAMIENTO: " << lanzamiento << " - TIRADAS TOTALES: " << sumaTiro;
        rlutil::locate(4, 6);
        cout << "--------------------------------------------------------------------------";
        dibujarTablaPuntos(vecTabla); /// Muestra jugadas echas, por hacer o tachadas
        if (TestMode == false) {
            tirarDados(vecDado, 5, 6, 10, 7); /// Mostrar dados cargados
        }
        else {
            recuadro(80, 1, 30, 25, 7, 1);
            testDados(vecDado, 5, 10, 7); /// Mostrar dados elegidos en modo test
        }
        rlutil::setColor(rlutil::WHITE);
        reRoll(vecDado, 5, &lanzar, &lanzamiento, &generala, &sumaTiro, vecTabla, TestMode); /// Que dados volver a tirar y que guardar

        if(generala == false) {
            analizarPuntos(vecDado, 5, ronda, lanzamiento, vecTabla); /// Evaluar las combinaciones posibles y elegir la que de mas puntos
            puntos = sumarPuntos(vecTabla); ///suma total de los puntos
        }
        else {
            puntos += 50;
        }

        if (ronda < totalRondas && generala == false) {
            rlutil::cls();
            recuadro(30, 7, 50, 10, 15, 4);
            rlutil::locate(50, 10);
            cout << "RONDA N: " << ronda;
            rlutil::locate(45, 11);
            cout << "LANZAMIENTOS: " << sumaTiro;
            rlutil::locate(45, 13);
            cout << "PUNTAJE DE " << nombre << ": " << puntos;
            rlutil::locate(38, 14);
            system("pause");
        }
        else {
            break;
        }
    }
    rlutil::cls();
    recuadro(30, 7, 50, 10, 15, 4);
    rlutil::locate(50, 10);
    cout << "GANADOR: " << nombre;
    rlutil::locate(45, 11);
    cout << "LANZAMIENTOS: " << sumaTiro;
    rlutil::locate(45, 13);
    cout << "PUNTAJE TOTAL ACUMULADO " << puntos;
    getch();
    rlutil::cls(); /// REDIBUJA RECUADRO MENU
    recuadroMenu();
    resultado[0] = puntos;
    resultado[1] = sumaTiro;
    return resultado[0];
}

#endif // INTERFAZSOLO_H_INCLUDED
