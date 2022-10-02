#ifndef REROLL_H_INCLUDED
#define REROLL_H_INCLUDED

/// DElcaracion
void reRoll(int vDado[], int tam, char *lanzar, int *lanzamiento, bool *generala, int *sumaTiro, int vecTabla[], bool TestMode); /// Que dados volver a tirar y que guardar

/// Definicion
void reRoll(int vDado[], int tam, char *lanzar, int *lanzamiento, bool *generala, int *sumaTiro, int vecTabla[], bool TestMode){
    int i, cantDado, dado, dadoAux[5];

    rlutil::setColor(rlutil::WHITE);
    if (combinacionGenerala(vDado, tam) == 50) { /// VEO SI SALIO GENERALA AL PRIMER TIRO
        *generala = true;
    }
    else {
        dibujarTablaPuntos(vecTabla);

        rlutil::locate(4, 12);
        cout << "CONTINUAR LANZANDO (S/N)? ";
        *lanzar = elegirLanzar(); /// VALIDA LANZAR
    }
     while ((*lanzar == 's') && (*lanzamiento < 3) && (*generala == false)) {
        *lanzamiento = *lanzamiento + 1;
        *sumaTiro = *sumaTiro + 1;
        rlutil::locate(4, 13);
        cout << "CUANTOS DADOS VOLVES A TIRAR? "; /// SE PIEDE CUANTOS DADOS VUELVE A TIRAR
        cantDado = elegirDados(); /// Valida la cantidad de dados
        ponerCero(dadoAux, 5); /// VER SI REINICIA BIEN BANDERAS
        switch(cantDado){
            case 5: /// SI PIDE 5 DADOS TIRA SIN PEDIR INGRESO DE DADOS
                if (TestMode) {
                    for (i = 1; i <= cantDado; i++) { /// ELIJE CUALES DADOS TIRAR
                        rlutil::locate(4, 13 + i);
                        cout << "CUAL/ES?: ";
                        dado = selectDado(dadoAux, 15, 13 + i); /// Valida dado elegido

                        rlutil::locate(36, 13 + i);
                        cout << "Ingrese valor: ";
                        vDado[dado - 1] = selectValorDado(51, 13 + i); /// valida valor de dado entre 1 y 6
                    }
                }
                else {
                    cargarAleatorio(vDado, 5, 6);
                }
                break;
            default:
                for (i = 1; i <= cantDado; i++) { /// ELIJE CUALES DADOS TIRAR
                    rlutil::locate(4, 13 + i);
                    cout << "CUAL/ES?: ";
                    dado = selectDado(dadoAux, 15, 13 + i); /// Valida dado elegido

                    if (TestMode) {
                        rlutil::locate(36, 13 + i);
                        cout << "Ingrese valor: ";
                        vDado[dado - 1] = selectValorDado(51, 13 + i);
                    }
                    else {
                        vDado[dado - 1] = (rand() % 6) + 1;
                    }
                }
                break;
     }
        rlutil::locate(4, 5);
        cout << "LANZAMIENTO: " << *lanzamiento << " - TIRADAS TOTALES: " << *sumaTiro;
        if(*lanzamiento < 3){
            recuadroBorrar(); /// BORRA LANZAR, CUANTOS Y CUALES

            dibujarDado(vDado, 5, 10, 7);

            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(4, 12);
            cout << "CONTINUAR LANZANDO (S/N)? ";
            *lanzar = elegirLanzar(); /// VALIDA LANZAR
        }
        else {
        rlutil::locate(4, 5);
        cout << "LANZAMIENTO: " << *lanzamiento - 1 << " - TIRADAS TOTALES: " << *sumaTiro - 1;
        }
    }
    rlutil::locate(4, 14 + i);
    cout << "LANZAMIENTO: " << *lanzamiento << " - TIRADAS TOTALES: " << *sumaTiro;
    rlutil::locate(4, 15 + i);
    cout << "--------------------------------------------------------------------------" ;

    dibujarDado(vDado, 5, 10, 16 + i);
    rlutil::setColor(rlutil::WHITE);
}

#endif // REROLL_H_INCLUDED
