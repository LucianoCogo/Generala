#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

/// DECLARACION

void recuadroMenu(); /// RECUADROS MENU PRINCIPAL

void recuadroBorrar();

void resaltarMenu(const char* texto, int posX, int posY, bool seleccion); /// RESALTA PALABRA MENU

void resaltarMenuLanzar(const char* texto, int posX, int posY, bool seleccion); /// RESALTA VALIDACION DE SEGUIR LANZANDO

void resaltarMenuRondas(const char* texto, int posX, int posY, bool seleccion); /// RESALTA OPCIONES DE CANTIDAD DE RONDAS

int elegirRondas(); /// VALIDA LA CANTIDAD DE RONDAS DE 0 A 10

char elegirLanzar(); /// VALIDA LANZAR

int elegirDados(); /// VALIDA CANTIDAD DE DADOS A VOLVER A TIRAR

int selectDado(int dadoAux[5],int x0, int y0); /// Valida dado elegido para no repetir dado

int selectValorDado(int x0, int y0); /// Valida valor de dado 1 a 6

/// DEFINICION

void recuadroMenu() {
    rlutil::hidecursor(); /// IMAGENES Y RECUADROS DE FONDO DE MENU///
    recuadro(2, 1, 75, 25, 15, 0);
    recuadro(4, 4, 8, 4, 15, 0);
    cara6(6, 5);
    recuadro(9, 13, 8, 4, 15, 0);
    cara2(11, 14);
    recuadro(21, 21, 8, 4, 15, 0);
    cara5(23, 22);
    recuadro(47, 17, 8, 4, 15, 0);
    cara1(49, 18);
    recuadro(67, 21, 8, 4, 15, 0);
    cara3(69, 22);
    recuadro(58, 12, 8, 4, 15, 0);
    cara4(60, 13);
    recuadro(67, 3, 8, 4, 15, 0);
    cara2(69, 4);
    recuadro(21, 5, 35, 11, 15, 0); /// RECUADRO MAS PEQUEÑO ENCIERRA LAS OPCIONES
}

void recuadroBorrar() {
    recuadro(3, 11, 50, 8, 4, 4);
}


void resaltarMenu(const char* texto, int posX, int posY, bool seleccion) {
    if (seleccion) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
    rlutil::locate(posX, posY);
    cout << texto;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void resaltarMenuLanzar(const char* texto, int posX, int posY, bool seleccion) {
    if (seleccion) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else {
        rlutil::setBackgroundColor(rlutil::RED);
    }
    rlutil::locate(posX, posY);
    cout << texto;
    rlutil::setBackgroundColor(rlutil::RED);
}

void resaltarMenuRondas(const char* texto, int posX, int posY, bool seleccion) {
    if (seleccion) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else {
        rlutil::setBackgroundColor(rlutil::GREEN);
    }
    rlutil::locate(posX, posY);
    cout << texto;
    rlutil::setBackgroundColor(rlutil::GREEN);
}

int elegirRondas(){
    int  x = 0, opc = -1;
    do { /// VALIDAR RONDAS 0 - 10
        resaltarMenuRondas("0", 27, 12, x == 0);
        resaltarMenuRondas("1", 30, 12, x == 1);
        resaltarMenuRondas("2", 33, 12, x == 2);
        resaltarMenuRondas("3", 36, 12, x == 3);
        resaltarMenuRondas("4", 39, 12, x == 4);
        resaltarMenuRondas("5", 42, 12, x == 5);
        resaltarMenuRondas("6", 45, 12, x == 6);
        resaltarMenuRondas("7", 48, 12, x == 7);
        resaltarMenuRondas("8", 51, 12, x == 8);
        resaltarMenuRondas("9", 54, 12, x == 9);
        resaltarMenuRondas("10", 57, 12, x == 10);
        rlutil::locate(25 + 3 * x, 12); /// Muestra selector de menu
        cout << char(175);

        int key = rlutil::getkey();

        switch (key) {
            case 16: /// izquierda
                rlutil::locate(25 + 3 * x, 12);
                cout << " ";
                x--;
                if(x < 0){
                    x = 0;
                    cout << "\a";
                }
                break;
            case 17: /// derecha
                rlutil::locate(25 + 3 * x, 12);
                cout << " ";
                x++;
                if(x > 10) {
                    x = 10;
                    cout << "\a";
                }
                break;
            case 1: /// ENTER
                switch (x) {
                    case 0:
                        return 0;
                        opc = 0;
                        break;
                    case 1:
                        return 1;
                        opc = 0;
                        break;
                    case 2:
                        return 2;
                        opc = 0;
                        break;
                    case 3:
                        return 3;
                        opc = 0;
                        break;
                    case 4:
                        return 4;
                        opc = 0;
                        break;
                    case 5:
                        return 5;
                        opc = 0;
                        break;
                    case 6:
                        return 6;
                        opc = 0;
                        break;
                    case 7:
                        return 7;
                        opc = 0;
                        break;
                    case 8:
                        return 8;
                        opc = 0;
                        break;
                    case 9:
                        return 9;
                        opc = 0;
                        break;
                    case 10:
                        return 10;
                        opc = 0;
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

char elegirLanzar() {
    int opc = -1, x = 0;
    do { /// VOLVER LANZAR SI O NO
            resaltarMenuLanzar("S", 30, 12, x == 0);
            resaltarMenuLanzar("N", 33, 12, x == 1);
            rlutil::locate(28 + 3*x, 12); /// Muestra selector de menu
            cout << char(175);

            int key = rlutil::getkey();

            switch (key) {
                case 16: /// izquierda
                    rlutil::locate(28 + 3 * x, 12);
                    cout << " ";
                    x--;
                    if(x < 0){
                        x = 0;
                        cout << "\a";
                    }
                    break;
                case 17: /// derecha
                    rlutil::locate(28 + 3 * x, 12);
                    cout << " ";
                    x++;
                    if(x > 1) {
                        x = 1;
                        cout << "\a";
                    }
                    break;
                case 1: /// ENTER
                    switch (x) {
                    case 0:
                        return 's';
                        opc = 0;
                        break;
                    case 1:
                        return 'n';
                        opc = 0;
                        break;
                    default:
                        break;
                    }
                default:
                    break;
            }
        } while (opc != 0);
    return '0';
}

int elegirDados() {
    int  x = 0, opc = -1;
    do { /// VALIDAR CANTIDAD DADOS 1 - 5
        resaltarMenuLanzar("1", 35, 13, x == 0);
        resaltarMenuLanzar("2", 38, 13, x == 1);
        resaltarMenuLanzar("3", 41, 13, x == 2);
        resaltarMenuLanzar("4", 44, 13, x == 3);
        resaltarMenuLanzar("5", 47, 13, x == 4);

        rlutil::locate(33 + 3 * x, 13); /// Muestra selector de menu
        cout << char(175);

        int key = rlutil::getkey();

        switch (key) {
            case 16: /// izquierda
                rlutil::locate(33 + 3 * x, 13);
                cout << " ";
                x--;
                if(x < 0){
                    x = 0;
                    cout << "\a";
                }
                break;
            case 17: /// derecha
                rlutil::locate(33 + 3 * x, 13);
                cout << " ";
                x++;
                if(x > 4) {
                    x = 4;
                    cout << "\a";
                }
                break;
            case 1: /// ENTER
                switch (x) {
                    case 0:
                        return 1;
                        opc = 0;
                        break;
                    case 1:
                        return 2;
                        opc = 0;
                        break;
                    case 2:
                        return 3;
                        opc = 0;
                        break;
                    case 3:
                        return 4;
                        opc = 0;
                        break;
                    case 4:
                        return 5;
                        opc = 0;
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

int selectDado(int dadoAux[5], int x0, int y0){
    int i, p = 0, x = 0, opc = -1, dadoOpcXpos[5];
    char dadoOpcXposChar[5][5];
    for (i = 0; i < 5; i++) { /// muestra las opciones posibles a elegir
        gotoxy (x0 + 3 * p, y0);
        switch (i) {
            case 0:
                if (dadoAux[i] == 0) {
                    p++;
                    dadoOpcXpos[p - 1] = i;
                    dadoOpcXposChar[p - 1][0] = '1';
                }
                break;
            case 1:
                if (dadoAux[i] == 0) {
                    p++;
                    dadoOpcXpos[p - 1] = i;
                    dadoOpcXposChar[p - 1][0] = '2';
                }
                break;
            case 2:
                if (dadoAux[i] == 0) {
                    p++;
                    dadoOpcXpos[p - 1] = i;
                    dadoOpcXposChar[p - 1][0] = '3';
                }
                break;
            case 3:
                if (dadoAux[i] == 0) {
                    p++;
                    dadoOpcXpos[p - 1] = i;
                    dadoOpcXposChar[p - 1][0] = '4';
                }
                break;
            case 4:
                if (dadoAux[i] == 0) {
                    p++;
                    dadoOpcXpos[p - 1] = i;
                    dadoOpcXposChar[p - 1][0] = '5';
                }
                break;
            default:
                break;
        }
    }
    x = 0;
    do { /// VALIDAR ELECCION DADOS 1 - 5
        for(i = 0; i < p ; i++){
            resaltarMenuLanzar(dadoOpcXposChar[i], x0 + 3 * i, y0, x == i);
        }

        rlutil::locate(x0 - 2 + 3 * x, y0); /// Muestra selector de menu
        cout << char(175);

        int key = rlutil::getkey();

        switch (key) {
            case 16: /// izquierda
                rlutil::locate(x0 - 2 + 3 * x, y0);
                cout << " ";
                x--;
                if(x < 0){
                    x = 0;
                    cout << "\a";
                }
                break;
            case 17: /// derecha
                rlutil::locate(x0 - 2 + 3 * x, y0);
                cout << " ";
                x++;
                if(x > p - 1) {
                    x = p - 1;
                    cout << "\a";
                }
                break;
            case 1: /// ENTER
                switch (x) {
                    case 0:
                        dadoAux[dadoOpcXpos[x]] = dadoOpcXpos[x] + 1;
                        return dadoAux[dadoOpcXpos[x]];
                        opc = 0;
                        break;
                    case 1:
                        dadoAux[dadoOpcXpos[x]] = dadoOpcXpos[x] + 1;
                        return dadoAux[dadoOpcXpos[x]];
                        opc = 0;
                        break;
                    case 2:
                        dadoAux[dadoOpcXpos[x]] = dadoOpcXpos[x] + 1;
                        return dadoAux[dadoOpcXpos[x]];
                        opc = 0;
                        break;
                    case 3:
                        dadoAux[dadoOpcXpos[x]] = dadoOpcXpos[x] + 1;
                        return dadoAux[dadoOpcXpos[x]];
                        opc = 0;
                        break;
                    case 4:
                        dadoAux[dadoOpcXpos[x]] = dadoOpcXpos[x] + 1;
                        return dadoAux[dadoOpcXpos[x]];
                        opc = 0;
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

int selectValorDado(int x0, int y0) {
    int x = 0, opc = -1;
    char valorDadoChar[6][5] = {"1", "2", "3", "4", "5", "6"};
    x = 0;
    do { /// VALIDAR ELECCION DADOS 1 - 6
        resaltarMenuLanzar(valorDadoChar[x], x0 , y0, true);

        rlutil::locate(x0 - 2, y0); /// Muestra selector de menu
        cout << char(175);

        int key = rlutil::getkey();

        switch (key) {
            case 16: /// izquierda
                rlutil::locate(x0 - 2, y0);
                cout << " ";
                x--;
                if(x < 0){
                    x = 0;
                    cout << "\a";
                }
                break;
            case 17: /// derecha
                rlutil::locate(x0 - 2, y0);
                cout << " ";
                x++;
                if(x > 5) {
                    x = 5;
                    cout << "\a";
                }
                break;
            case 1: /// ENTER
                switch (x) {
                    case 0:
                        return 1;
                        opc = 0;
                        break;
                    case 1:
                        return 2;
                        opc = 0;
                        break;
                    case 2:
                        return 3;
                        opc = 0;
                        break;
                    case 3:
                        return 4;
                        opc = 0;
                        break;
                    case 4:
                        return 5;
                        opc = 0;
                        break;
                    case 5:
                        return 6;
                        opc = 0;
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

#endif // INTERFACES_H_INCLUDED
