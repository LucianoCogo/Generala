#ifndef ANALIZARPUNTOS_H_INCLUDED
#define ANALIZARPUNTOS_H_INCLUDED

/// DECLARACIONES
int combinacion1 (int vecDado[], int tam); /// Evalua el juego de unos

int combinacion2 (int vecDado[], int tam); /// Evalua el juego de dos

int combinacion3 (int vecDado[], int tam); /// Evalua el juego de tres

int combinacion4 (int vecDado[], int tam); /// Evalua el juego de cuatros

int combinacion5 (int vecDado[], int tam); /// Evalua el juego de cincos

int combinacion6 (int vecDado[], int tam); /// Evalua el juego de seises

int combinacionEscalera (int vecDado[], int tam); /// Evalua el juego de Escalera

int combinacionFull (int vecDado[], int tam); /// Evalua el juego de Full

int combinacionPoker (int vecDado[], int tam); /// Evalua el juego de Poker

int combinacionGenerala (int vecDado[], int tam); /// Evalua el juego de Generala

void analizarPuntos(int vecDado[], int tam, int ronda, int lanzamiento, int vecTabla[]); /// Evaluar las combinaciones posibles y elegir la que de mas puntos

int sumarPuntos(int vecTabla[]);

///DEFINICION

void analizarPuntos(int vecDado[], int tam, int ronda, int lanzamiento, int vecTabla[]) {
    int s = -1;
    int vecAux[10]; /// Vector donde se guardan los posibles puntajes de la ronda
    int vecOpcXpos[10];/// Vector que guarda la posicion de la opcion elegida
    int p = 0, opc = -1, y, yA;

    recuadro(80, 1, 30, 25, 7, 1);
    ponerMenos1(vecOpcXpos,10);
    vecAux[0] = combinacion1(vecDado, 5);///carga los resultados posibles de la tirada en el vector auxiliar
    vecAux[1] = combinacion2(vecDado, 5);
    vecAux[2] = combinacion3(vecDado, 5);
    vecAux[3] = combinacion4(vecDado, 5);
    vecAux[4] = combinacion5(vecDado, 5);
    vecAux[5] = combinacion6(vecDado, 5);
    vecAux[6] = combinacionEscalera(vecDado, 5);
    vecAux[7] = combinacionFull(vecDado, 5);
    vecAux[8] = combinacionPoker(vecDado, 5);
    vecAux[9] = combinacionGenerala(vecDado, 5);

    gotoxy (85, 5);
    cout << "OPCIONES A ANOTAR";
    for (int i = 0; i < 10; i++) { /// muestra las opciones posibles a elegir
        gotoxy (85, 8 + p);
        switch (i) {
            case 0:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar " << vecAux[i] << " al 1";
                }
                break;
            case 1:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar " << vecAux[i] << " al 2";
                }
                break;
            case 2:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p <<" Anotar "<< vecAux[i] << " al 3";
                }
                break;
            case 3:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar " << vecAux[i] << " al 4";
                }
                break;
            case 4:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar " << vecAux[i] << " al 5";
                }
                break;
            case 5:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar " << vecAux[i] << " al 6";
                }
                break;
            case 6:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar Escalera";
                }
                break;
            case 7:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar Full";
                }
                break;
            case 8:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar Poker";
                }
                break;
            case 9:
                if (vecTabla[i] == -1 && vecAux[i] != 0) {
                    p++;
                    vecOpcXpos[p - 1] = i;
                    cout << "Opcion " << p << " Anotar Generala";
                }
                break;
            default:
                break;
        }
    }
    if(p != 0) { /// si no hay jugadas anulo anotar
        y = 0;
    }
    else {
        y = 1;
    }
    do{
        gotoxy(85, 22);
        cout << "ANOTAR";
        gotoxy(85, 23);
        cout << "TACHAR";
        rlutil::locate(82, 22 + y);
        cout << char(175);
        int key = rlutil::getkey();
        switch (key) {
            case 14: /// UP
                if(p != 0) {
                    rlutil::locate(82, 22 + y);
                    cout << " ";
                    y--;
                    if (y < 0) {
                        y = 0;
                        cout << "\a";
                    }
                }
                else {
                    cout << "\a";
                }
                break;
            case 15: /// DOWN
                rlutil::locate(82, 22 + y);
                cout << " ";
                y++;
                if (y > 1) {
                    y = 1;
                    cout << "\a";
                }
                break;
            case 1: /// ENTER
                gotoxy(85, 22); /// BORRA ANOTAR
                cout << "      ";
                gotoxy(85, 23); /// BORRA TACHAR
                cout<<"      ";
                rlutil::locate(82, 22 + y); /// BORRA >>
                cout << " ";
                switch (y) {
                    case 0:
                        gotoxy(85, 24);
                        cout << "Elija una opcion: ";
                    //////////////////////////////////////////////////////////////////
                        yA = 0;
                        do { /// VALIDAR ELECCION juego

                            rlutil::locate(83, 8 + yA); /// Muestra selector de menu
                            cout << char(175);

                            int key = rlutil::getkey();

                            switch (key) {
                                case 14: /// arriba
                                    rlutil::locate(83, 8 + yA);
                                    cout << " ";
                                    yA--;
                                    if(yA < 0){
                                        yA = 0;
                                        cout << "\a";
                                    }
                                    break;
                                case 15: /// abajo
                                    rlutil::locate(83, 8 + yA);
                                    cout << " ";
                                    yA++;
                                    if(yA > p - 1) {
                                        yA = p - 1;
                                        cout << "\a";
                                    }
                                    break;
                                case 1: /// ENTER
                                    switch (yA) {
                                        case 0:
                                            opc = yA + 1;
                                            break;
                                        case 1:
                                            opc = yA + 1;
                                            break;
                                        case 2:
                                            opc = yA + 1;
                                            break;
                                        case 3:
                                            opc = yA + 1;
                                            break;
                                        case 4:
                                            opc = yA + 1;
                                            break;
                                        case 5:
                                            opc = yA + 1;
                                            break;
                                        case 6:
                                            opc = yA + 1;
                                            break;
                                        case 7:
                                            opc = yA + 1;
                                            break;
                                        case 8:
                                            opc = yA + 1;
                                            break;
                                        case 9:
                                            opc = yA + 1;
                                            break;
                                        default:
                                            break;
                                    }
                                default:
                                    break;
                            }
                        } while (opc == -1);

                        if (vecOpcXpos[opc - 1] != -1) {
                            vecTabla[vecOpcXpos[opc - 1]] = vecAux[vecOpcXpos[opc - 1]];
                            }
                        s = 0;
                        break;
                    case 1:
                        /// TACHAR
                        int x = 0;
                        do {
                            dibujarTablaPuntos(vecTabla);
                            rlutil::locate(7 + x * 11, 30);
                            cout << char(88);
                            int axial = rlutil::getkey();
                            switch (axial) {
                                case 16: /// IZQUIERDA
                                    rlutil::locate(7 + x * 11, 30);
                                    cout << " ";
                                    x--;
                                    if (x < 0) {
                                        x = 0;
                                        cout << "\a";
                                    }
                                    break;
                                case 17: /// DERECHA
                                    rlutil::locate(7 + x * 11, 30);
                                    cout << " ";
                                    x++;
                                    if (x > 9) {
                                        x = 9;
                                        cout << "\a";
                                    }
                                    break;
                                case 1: /// ENTER
                                    switch (x) {
                                    case 0:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 1:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 2:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 3:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 4:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 5:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 6:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 7:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 8:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    case 9:
                                        if (vecTabla[x] == -1) {
                                        vecTabla[x] = 0;
                                        s = 0;
                                        }
                                        else {
                                            cout << "\a";
                                        }
                                        break;
                                    default:
                                        break;
                                    }
                                default:
                                    break;
                            }
                        } while(s != 0);
                        s = 0;
                        break;
                    ///default:
                        ///break;
                }
            default:
                break;
        }
    } while(s != 0);
}


int sumarPuntos(int vecTabla[]) {
    int i;
    int puntos = 0;

    for (i = 0; i <= 9; i++) {
        if (vecTabla[i] > 0) {
            puntos = puntos + vecTabla[i];
        }
    }
    return puntos;
}

///DEFINICIONES

int combinacion1(int vecDado[], int tam) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (vecDado[i] == 1) cant++;
    }
    return cant * 1;
}

int combinacion2(int vecDado[], int tam) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (vecDado[i] == 2) cant++;
    }
    return cant * 2;
}

int combinacion3(int vecDado[], int tam) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (vecDado[i] == 3) cant++;
    }
    return cant * 3;
}

int combinacion4(int vecDado[], int tam) {
    int i, cant = 0;

    for(i = 0; i < tam; i++) {
        if (vecDado[i] == 4) cant++;
    }
    return cant * 4;
}

int combinacion5(int vecDado[], int tam) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (vecDado[i] == 5) cant++;
    }
    return cant * 5;
}

int combinacion6(int vecDado[], int tam) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (vecDado[i] == 6) cant++;
    }
    return cant * 6;
}

int combinacionEscalera(int vecDado[], int tam) {
    int i, j, posmin, aux;
    bool escalera = false;
    for (i = 0; i < tam - 1; i++) {
        posmin = i;
        for (j = i + 1; j < tam; j++) {
            if(vecDado[j] < vecDado[posmin]) posmin = j;
        }
        aux = vecDado[i];
        vecDado[i] = vecDado[posmin];
        vecDado[posmin] = aux;
    }
    if(vecDado[0] == 1 && vecDado[1] == 2 && vecDado[2] == 3 && vecDado[3] == 4 && vecDado[4] == 5) {
        escalera = true;
    }
    else if (vecDado[0] == 2 && vecDado[1] == 3 && vecDado[2] == 4 && vecDado[3] == 5 && vecDado[4] == 6) {
        escalera = true;
    }
    if (escalera == true) {
        return 25;
    }
    else {
        return 0;
    }
}

int combinacionFull(int vecDado[], int tam) {
    bool rep3 = false;
    bool rep2 = false;
    int cant = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (vecDado[j] == i) {
                cant++;
            }
        }
        if (cant == 3) {
            rep3 = true;
        }
        else if (cant == 2) {
            rep2 = true;
        }
        cant = 0;
    }
    if (rep3 == true && rep2 == true) {
        return 30;
    }
    else {
        return 0;
    }
}

int combinacionPoker(int vecDado[], int tam) {
    bool rep4 = false;
    int cant = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (vecDado[j] == i) {
                cant++;
            }
        }
        if (cant == 4) {
            rep4 = true;
        }
        cant = 0;
    }
    if (rep4 == true) {
        return 40;
    }
    else {
        return 0;
    }
}

int combinacionGenerala(int vecDado[], int tam) {
    bool rep5 = false;
    int cant = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (vecDado[j] == i) {
                cant++;
            }
        }
        if (cant == 5) {
            rep5 = true;
        }
        cant = 0;
    }
    if (rep5 == true) {
        return 50;
    }
    else {
        return 0;
    }
}

#endif // ANALIZARPUNTOS_H_INCLUDED
