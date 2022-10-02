#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;*/

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void cargarVector(int v[], int tam); ///asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam); /// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam); /// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[],int tam, int numero); /// devuelve la posición que ocupa un número que se //envía como parámetro. Devuelve la primera posición que encuentra el número. Si no lo encuentra devuelve -1

int contarNumerosRepetidos(int v[], int tam , int numero); /// cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam); /// devuelve  la posición (primera) que ocupa el máximo en el vector

int minimoVector(int v[], int tam); /// devuelve  la posición (primera) que ocupa el mínimo en el vector

void cargarAleatorio(int v[], int tam, int limite); /// asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

void ordenarVectorDescendente(int v[],int tam); /// ordena de mayor a menor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[],int tam ); /// copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam ); /// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

/// anexo delaraciones propias

int contarPar(int v[],int tam); /// cuenta pares y devuelve cuantos hay

int contarImpar(int v[],int tam); /// cuenta impares y devuelve cuantos hay

bool comprobarExistencia(int v[], int tam, int aBuscar); /// comprueba si un numero esta en vector y devulve verdadero o falso

void compararVectorVectores(); /// ver que hace clase viernes 3-06-2022

void cargarCadena(char *pal, int tam); /// carga cadena de caracteres char de tamaño 30

void cargarNombres(); /// carga 2 nombres en matriz 2x30

void mostrarNombres(); /// muestra 2 nombres en matriz 2x30

void mostrarCaracter(char cadena[30]); /// muestra cadena de caracteres char de tamaño 30

void ponerMenos1(int v[], int tam); /// pone al vector en -1

void cargarDados(int v[], int tam); /// cargar dados manualmente

void dibujarTablaPuntos (int v[]); /// Dibuja tabla de puntos

void resaltarMenuLanzarTest(const char* texto, int posX, int posY, bool seleccion); /// RESALTA VALIDACION DE PRIMER TIRADA VALOR LANZANDO TEST

int selectValorDadoTest(int x0, int y0); /// Valida valor de dado 1 a 6 PRIMER TIRADA TEST

/// Desarrollo de funciones / Definiciones

int posicionNumeroEnVector(int v[],int tam, int numero) {
    int i;

    for (i = 0; i < tam; i++) {
        if (v[i] == numero) return i;
        }
    return -1;
}

int minimoVector(int v[], int tam) {
    int i, posMin = 0;

    for (i = 1; i < tam; i++) {
        if (v[i] < v[posMin]) {
            posMin=i;
        }
    }
    return posMin;
}

void ordenarVector(int v[], int tam ) {
    int i, j, posmin, aux;

    for (i = 0; i < tam - 1; i++) {
        posmin = i;
        for (j = i + 1; j < tam; j++) {
            if (v[j] < v[posmin]) posmin = j;
        }
        aux = v[i];
        v[i] = v[posmin];
        v[posmin] = aux;
    }
}

void ordenarVectorDescendente(int v[], int tam ) {
    int i,j, posmax, aux;

    for (i = 0; i < tam - 1; i++) {
        posmax = i;
        for (j = i + 1; j < tam; j++) {
            if (v[j] > v[posmax]) posmax = j;
        }
        aux = v[i];
        v[i] = v[posmax];
        v[posmax] = aux;
    }
}

int maximoVector(int v[], int tam) {
    int i, posMax = 0;

    for (i = 1; i < tam; i++) {
        if (v[i] > v[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite) {
    int i;

    srand(time(NULL));
    for (i = 0; i < tam; i++) {
        v[i] = (rand()%limite) + 1;
    }
}

void mostrarVector(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        cout << v[i] << "\t";
    }
}


int contarNumerosRepetidos(int v[], int tam, int numero) {
    int i, cant = 0;

    for (i = 0; i < tam; i++) {
        if (v[i] == numero) cant++;
        }
    return cant;
}

void ponerCero(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        v[i]=0;
    }
}

int sumarVector(int v[], int tam ) {
    int i, suma = 0;

    for (i = 0; i < tam; i++) {
        suma+= v[i];
    }
    return suma;
}


void copiarVector(int v[], int v2[],int tam ) {
    int i;

    for (i = 0; i < tam; i++) {
        v2[i] = v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam ) {
    int i;

    for (i = 0; i < tam; i++) {
        if (v2[i] != v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        cout << "INGRESE NUMERO: ";
        cin >> v[i];
    }
}

/// anexo definiciones propias

int contarPar(int v[], int tam) {
    int i, contPar = 0;

    for (i = 0; i < tam; i++){
        if (v[i] % 2 == 0) {
            contPar++;
        }
    }
    return contPar;
}

int contarImpar(int v[], int tam) {
    int i, contImpar = 0;

    for (i = 0; i < tam; i++) {
        if (v[i] % 2 != 0) {
            contImpar++;
        }
    }
    return contImpar;
}

bool comprobarExistencia(int v[], int tam, int aBuscar) {
    int i;

    for (i = 0; i < tam; i++) {
        if (v[i] == aBuscar) {
            return true;
        }
    }
    return false;
}

void compararVectorVectores() {
    int v1[5], v2[5], i, iguales = 0;
    bool existe;

    cout << "CARGAR LOS VALORES DEL PRIMER VECTOR" << endl;
    cargarVector(v1, 5);
    cout << "CARGAR LOS VALORES DEL SEGUNDO VECTOR" << endl;
    cargarVector(v2, 5);
    for (i = 0; i < 5; i++) {
        existe = comprobarExistencia(v2, 5, v1[i]);
        if (existe == true) {
            iguales++;
        }
    }
    cout << "EN LOS DOS VECTORES HAY: " << iguales << " NUMEROS IGUALES" << endl;
}

void cargarCadena(char *pal, int tam) {
  int i;

  fflush(stdin);
  for (i = 0; i < tam; i++) {
      pal[i] = cin.get();
	  if (pal[i] == '\n') break;
	  }
  pal[i] = '\0';
  fflush(stdin);
}

void cargarNombres(char nombres[2][30]) {
    cargarCadena(nombres[0], 29);
    cargarCadena(nombres[1], 29);
}

void mostrarNombres(char nombres[2][30]) {
    cout << nombres[0] << endl;
    cout << nombres[1] << endl;
}

void mostrarCaracter(char cadena[30]) {
    cout << cadena;
}

void ponerMenos1(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        v[i] = -1;
    }
}

void cargarDados(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        gotoxy(85, 3 + i);
        cout << "INGRESE NUMERO: ";
        v[i] = selectValorDadoTest(101, 3 + i);
    }
}

void dibujarTablaPuntos (int v[]) {
    int j;
    char juegos[][30] = {"Juego de 1", "Juego de 2", "Juego de 3", "Juego de 4", "Juego de 5", "Juego de 6", "Escalera", "Full", "Poker", "Generala"};

    recuadro(2, 27, 108, 3, 15, 4); /// Tabla de puntos
    for (j = 0; j < 10; j++) {
        rlutil::locate (4 + j * 11, 29);
        cout << juegos[j];
    }
    for (j = 0; j < 10; j++) {
        rlutil::locate (7 + j * 11, 30);
        if (v[j] == -1) {
            cout << " ";
        }
        else {
            cout << v[j];
        }
    }
}

void resaltarMenuLanzarTest(const char* texto, int posX, int posY, bool seleccion) {
    if (seleccion) {
        rlutil::setBackgroundColor(rlutil::RED);
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    rlutil::locate(posX, posY);
    cout << texto;
    rlutil::setBackgroundColor(rlutil::BLUE);
}

int selectValorDadoTest(int x0, int y0) {
    int x = 0, opc = -1;
    char valorDadoChar[6][5] = {"1", "2", "3", "4", "5", "6"};
    x = 0;
    do { /// VALIDAR ELECCION DADOS 1 - 6
        resaltarMenuLanzarTest(valorDadoChar[x], x0 , y0, true);

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

#endif // FUNCIONES_H_INCLUDED
