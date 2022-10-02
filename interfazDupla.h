#ifndef INTERFAZDUPLA_H_INCLUDED
#define INTERFAZDUPLA_H_INCLUDED

/// DECLARACION INTERFAZ DUPLA

void dupla(char *maxNombre, int tam, int *maxSumaTiro, int *maxPuntos); /// VENTANA CARGAR NOMBRES DE DOS JUGADORES

int interfazDupla(char nombre[2][30], int totalRondas, int resultado[2]); /// INTERFAZ DOS JUGADORES

/// DEFINICION

void dupla(char *maxNombre, int tam, int *maxSumaTiro, int *maxPuntos) {
    char nombre[2][30];
    int totalRondas, i, resultado[2], j;

    rlutil::hidecursor();
    rlutil::cls();
    recuadro(2, 1, 75, 25, 15, 2);

    rlutil::locate(23, 11);
    cout << "INGRESE LA CANTIDAD DE RONDAS A JUGAR: "; /// CANTIDAD DE RONDAS
    totalRondas = elegirRondas(); /// LLAMA A FUNCION QUE VALIDA EL NUMERO DE RONDAS

    for (i = 0; i <= 1; i++) {   /// CARGA NOMBRE DE JUGADORES
        rlutil::locate(23, 13 + i);
        cout << "INGRESE NOMBRE: ";
        rlutil::locate(40, 13 + i);
        cargarCadena(nombre[i], 29);
    }

    system("cls");
    j = interfazDupla(nombre, totalRondas, resultado);
    if (resultado[0] > *maxPuntos) { /// COMPARA VALORES EN RANKING
        strcpy(maxNombre,nombre[j]);
        *maxPuntos = resultado[0];
        *maxSumaTiro = resultado[1];
    }
}

int interfazDupla(char nombre[2][30], int totalRondas, int resultado[2]){
    int ronda, lanzamiento, puntos[2] = {0}, vecDado[2][5], sumaTiro[2] = {0}, i, j;
    int salir;
    bool TestMode[2] = {false}, generala[2];
    char TestName[2][30] = {"Test", "Test2"};
    char lanzar;
    int vecTabla[2][10]; /// Vector de la tabla de puntuaciones;

    ponerMenos1(vecTabla[0], 10);
    ponerMenos1(vecTabla[1], 10);
    if (strcmp(nombre[0], TestName[0]) == 0) TestMode[0] = true;
    if (strcmp(nombre[1], TestName[1]) == 0) TestMode[1] = true;
    for (ronda = 1; ronda <= totalRondas; ronda++) {
        for (i = 0; i <= 1; i++) {
            generala[i] = false;
            lanzamiento = 1;
            sumaTiro[i]++;
            rlutil::cls();

            rlutil::cls();
            recuadro(2, 1, 75, 25, 15, 4);
            rlutil::locate(4, 3);
            cout << "TURNO DE: ";
            rlutil::locate(14, 3);
            mostrarCaracter(nombre[i]);
            rlutil::locate(30, 3);
            cout << "RONDA N: " << ronda;
            rlutil::locate(53, 3);
            cout << "PUNTAJE TOTAL: " <<  puntos[i] << " PUNTOS";
            rlutil::locate(4, 4);
            cout << "--------------------------------------------------------------------------";
            rlutil::locate(4, 5);
            cout << "LANZAMIENTO: " << lanzamiento << " - TIRADAS TOTALES: " << sumaTiro[i];
            rlutil::locate(4, 6);
            cout << "--------------------------------------------------------------------------";
            dibujarTablaPuntos(vecTabla[i]); /// Muestra jugadas echas, por hacer o tachadas
            if (TestMode[i] == false) {
                tirarDados(vecDado[i], 5, 6, 10, 7); /// Mostrar dados cargados
            }
            else {
                recuadro(80, 1, 30, 25, 7, 1);
                testDados(vecDado[i], 5, 10, 7); /// Mostrar dados elegidos en modo test
            }
            rlutil::setColor(rlutil::WHITE);
            reRoll(vecDado[i], 5, &lanzar, &lanzamiento, &generala[i], &sumaTiro[i], vecTabla[i], TestMode[i]); /// Que dados volver a tirar y que guardar

            if (generala[i] == false) { /// Si tiene generala servida no solicitar tirar dados
                analizarPuntos(vecDado[i], 5, ronda, lanzamiento, vecTabla[i]); /// Evaluar las combinaciones posibles y elegir la que de mas puntos
                puntos[i] = sumarPuntos(vecTabla[i]);///suma total de los puntos
            }
            else{
                puntos[i] += 50;
            }

            rlutil::cls();
            recuadro(30, 7, 50, 10, 15, 4);

            if (!(((ronda == totalRondas) && (i == 1)) || ((generala[0] == true) && (i == 1)))) { /// Si sale generala servida que no muetre recuadro entre turnos, solo resultado
                switch (i) {
                    case 0:
                        rlutil::locate(50, 10);
                        cout << "RONDA N: " << ronda;
                        rlutil::locate(44, 11);
                        cout << "PROXIMO TURNO: " << nombre[i + 1];
                        rlutil::locate(45, 12);
                        cout << "LANZAMIENTOS: " << sumaTiro[i];
                        rlutil::locate(45, 14);
                        cout << "PUNTAJE DE " << nombre[i + 1] << ": " << puntos[i + 1];
                        rlutil::locate(45, 15);
                        cout << "PUNTAJE DE " << nombre[i] << ": " << puntos[i];
                        rlutil::locate(38, 16);
                        system("pause");
                        break;
                    case 1:
                        if (!(generala[1] == true)) { /// Si sale generala servida al ultimo jugador no muestra recuadro entre turnos, solo resultado final
                            rlutil::locate(50, 10);
                            cout << "RONDA N: " << ronda;
                            rlutil::locate(44, 11);
                            cout << "PROXIMO TURNO: " << nombre[i - 1];
                            rlutil::locate(45, 12);
                            cout << "LANZAMIENTOS: " << sumaTiro[i];
                            rlutil::locate(45, 14);
                            cout << "PUNTAJE DE " << nombre[i - 1] << ": " << puntos[i - 1];
                            rlutil::locate(45, 15);
                            cout << "PUNTAJE DE " << nombre[i] << ": " << puntos[i];
                            rlutil::locate(38, 16);
                            system("pause");
                        }
                            break;
                    default :
                        break;
                }
            }
        }
        if (generala[0] == 1 || generala[1] == 1) {
            if ((generala[0] == true) && (generala[1] == true)) {
                salir = 0;
            }
            if ((generala[0] == true) && (generala[1] == false)) {
                salir = 1;
            }
            if ((generala[0] == false) && (generala[1] == true)) {
                salir = 2;
            }
            switch(salir) {
                case 0:
                    rlutil::cls();
                    recuadro(30, 7, 50, 10, 15, 4);
                    rlutil::locate(48, 10);
                    cout << "GANADORES: " << nombre[0] << " y " << nombre[1];
                    rlutil::locate(45, 11);
                    cout << "LANZAMIENTOS: " << sumaTiro[0] << " y " << sumaTiro[1];
                    rlutil::locate(45, 13);
                    cout << "PUNTAJE TOTAL ACUMULADO " << puntos[0] << " y " << puntos[1];
                    getch();
                    rlutil::cls(); /// REDIBUJA RECUADRO MENU
                    recuadroMenu();
                    resultado[0] = puntos[0];
                    resultado[1] = sumaTiro[0];
                    return 0;
                    break;
                case 1:
                    rlutil::cls();
                    recuadro(30, 7, 50, 10, 15, 4);
                    rlutil::locate(35, 10);
                    cout << "GANADOR: " << nombre[0] << " POR GENERALA SERVIDA";
                    rlutil::locate(45, 11);
                    cout << "LANZAMIENTOS: " << sumaTiro[0];
                    rlutil::locate(40, 13);
                    cout << "PUNTAJE TOTAL ACUMULADO " << puntos[0];
                    getch();
                    rlutil::cls(); /// REDIBUJA RECUADRO MENU
                    recuadroMenu();
                    resultado[0] = puntos[0];
                    resultado[1] = sumaTiro[0];
                    return 0;
                    break;
                case 2:
                    rlutil::cls();
                    recuadro(30, 7, 50, 10, 15, 4);
                    rlutil::locate(40, 10);
                    cout << "GANADOR: " << nombre[1] << " POR GENERALA SERVIDA";
                    rlutil::locate(45, 11);
                    cout << "LANZAMIENTOS: " << sumaTiro[1];
                    rlutil::locate(45, 13);
                    cout << "PUNTAJE TOTAL ACUMULADO " << puntos[1];
                    getch();
                    rlutil::cls(); /// REDIBUJA RECUADRO MENU
                    recuadroMenu();
                    resultado[0] = puntos[1];
                    resultado[1] = sumaTiro[1];
                    return 1;
                    break;
            }
            break;
        }
        }
        if(puntos[0] != puntos[1]) {
            rlutil::cls();
            recuadro(30, 7, 50, 10, 15, 4);
            j = maximoVector(puntos, 2);
            rlutil::locate(50, 10);
            cout << "GANADOR: " << nombre[j];
            rlutil::locate(45, 11);
            cout << "LANZAMIENTOS: " << sumaTiro[j];
            rlutil::locate(45, 13);
            cout << "PUNTAJE TOTAL ACUMULADO " << puntos[j];
            getch();
            rlutil::cls(); /// REDIBUJA RECUADRO MENU
            recuadroMenu();
            resultado[0] = puntos[j];
            resultado[1] = sumaTiro[j];
            return j;
        }
        else {
            rlutil::cls();
            recuadro(30, 7, 50, 10, 15, 4);
            rlutil::locate(48, 10);
            cout << "EMPATARON: " << nombre[0] << " y " << nombre[1];
            rlutil::locate(45, 11);
            cout << "LANZAMIENTOS: " << sumaTiro[0] << " y " << sumaTiro[1];
            rlutil::locate(45, 13);
            cout << "PUNTAJE TOTAL ACUMULADO " << puntos[0] << " y " << puntos[1];
            getch();
            rlutil::cls(); /// REDIBUJA RECUADRO MENU
            recuadroMenu();
            resultado[0] = puntos[0];
            resultado[1] = sumaTiro[0];
            return 0;
        }
}

#endif // INTERFAZDUPLA_H_INCLUDED
