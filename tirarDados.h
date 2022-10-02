#ifndef TIRARDADOS_H_INCLUDED
#define TIRARDADOS_H_INCLUDED

/// DECLARACION

void tirarDados(int vecDado[], int tam, int limite, int x0, int y0); /// RECIVE UNA TIRADA AL AZAR

void testDados (int vecDado[], int tam, int x0, int y0);

void dibujarDado(int vecDado[],int tam, int x0, int y0); /// MUESTRA LA CARA DEL DADO QUE CORRESPONDE A LA TIRADA

void cara1 (int x, int y); /// IMAGEN CARA 1 DEL DADO

void cara2 (int x, int y); /// IMAGEN CARA 2 DEL DADO

void cara3 (int x, int y); /// IMAGEN CARA 3 DEL DADO

void cara4 (int x, int y); /// IMAGEN CARA 4 DEL DADO

void cara5 (int x, int y); /// IMAGEN CARA 5 DEL DADO

void cara6 (int x, int y); /// IMAGEN CARA 6 DEL DADO

void esquemaDados(int x0, int y0);

/// DEFINICION

void tirarDados(int vecDado[], int tam, int limite, int x0, int y0) {
    cargarAleatorio(vecDado, tam, limite);
    dibujarDado(vecDado, 5, x0, y0);
}

void testDados(int vecDado[], int tam, int x0, int y0) {
    cargarDados(vecDado, tam);
    dibujarDado(vecDado, 5, x0, y0);
}

void cara1(int x, int y) {
    gotoxy(x, y + 1);
    cout << "       ";
    gotoxy(x, y + 2);
    cout << "   0   ";
    gotoxy(x, y + 3);
    cout << "       ";
}

void cara2(int x, int y) {
    gotoxy(x, y + 1);
    cout << " 0     ";
    gotoxy(x, y + 2);
    cout << "       ";
    gotoxy(x, y + 3);
    cout << "     0 ";
}

void cara3 (int x, int y) {
    gotoxy(x, y + 1);
    cout << " 0     ";
    gotoxy(x, y + 2);
    cout << "   0   ";
    gotoxy(x, y + 3);
    cout << "     0 ";
}

void cara4(int x, int y) {
    gotoxy(x, y + 1);
    cout << " 0   0 ";
    gotoxy(x, y + 2);
    cout << "       ";
    gotoxy(x, y + 3);
    cout << " 0   0 ";
}

void cara5(int x, int y) {
    gotoxy(x, y + 1);
    cout << " 0   0 ";
    gotoxy(x, y + 2);
    cout << "   0   ";
    gotoxy(x, y + 3);
    cout << " 0   0 ";
}

void cara6(int x, int y) {
    gotoxy(x, y + 1);
    cout << " 0   0 ";
    gotoxy(x, y + 2);
    cout << " 0   0 ";
    gotoxy(x, y + 3);
    cout << " 0   0 ";
}

void dibujarDado(int vecDado[], int tam, int x0, int y0) {
    int vectX[5], vectY[5];

    vectX[0] = x0;
    vectX[1] = x0 + 12;
    vectX[2] = x0 + 24;
    vectX[3] = x0 + 36;
    vectX[4] = x0 + 48;
    vectY[0] = y0;
    vectY[1] = y0 ;
    vectY[2] = y0;
    vectY[3] = y0;
    vectY[4] = y0;

    esquemaDados(x0, y0);
    for (int i = 0; i < tam; i++) {
    rlutil::setBackgroundColor(15);
        switch (vecDado[i]) {
        case 1:
            cara1(vectX[i], vectY[i]);
            break;
        case 2:
            cara2(vectX[i], vectY[i]);
            break;
        case 3:
            cara3(vectX[i], vectY[i]);
            break;
        case 4:
            cara4(vectX[i], vectY[i]);
            break;
        case 5:
            cara5(vectX[i], vectY[i]);
            break;
        case 6:
            cara6(vectX[i], vectY[i]);
            break;
        default:
            break;
        }
        rlutil::setBackgroundColor(4);
    }
}

void esquemaDados(int x0, int y0) {
    int x = x0 - 2;
    float y = y0 - 1;

    recuadro(x, y, 8, 4, cNEGRO, cBLANCO);
    recuadro(x + 12, y, 8, 4, cNEGRO, cBLANCO);
    recuadro(x + 24, y, 8, 4, cNEGRO, cBLANCO);
    recuadro(x + 36, y, 8, 4, cNEGRO, cBLANCO);
    recuadro(x + 48, y, 8, 4, cNEGRO, cBLANCO);
    rlutil::setBackgroundColor(2);
}

#endif // TIRARDADOS_H_INCLUDED
