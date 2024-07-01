#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <time.h>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define WIDTH Console::WindowWidth
#define HEIGHT Console::WindowHeight

// Secuencias de escape ANSI para colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BROWN   "\033[38;5;94m"
#define DARKGRAY "\033[1;30m"
#define ORANGE  "\033[38;2;255;165;0m"
#define DARK_GREEN "\033[38;2;0;100;0m"

using namespace System;
using namespace std;

// Funciones de calculo:
int numeroAleatorio(int inicio, int final) {
    return inicio + rand() % (final - inicio + 1);
}

int calcular_distancia_entreDosPuntos(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Structss
struct Capibara {
    char* nombre = "Capibara";
    int x;
    int y;
    int dx;
    int dy;
    int alto;
    int ancho;
    int vida = 100;
    int mana;
    int estamina;
    bool muerto = false;
    bool atacar = false;
    bool atacarArriba = false;
    bool atacarAbajo = false;
    bool atacarDerecha = false;
    bool atacarIzquierda = false;
    int contadorDeGolpes = 0;
    bool recibeDanio = false;
    bool recibeMejora = false;
    int contadorDeGolpesFuertes = 0;
    int contadorDeGolpesFuertesMax = 2;
    int contadorDeInmunidad = 0;
    int contadorDeInmunidadMax = 4;
    bool cambiarEstamina = false;
    bool cambiarMana = false;
};

struct BolaDeFuego {
    int x;
    int y;
    int dx;
    int dy;
    int ancho;
    int alto;
    bool activo;
    int descanso = 100;
    int id;
    int tiempoDisparo = 0;
    int xInicial = x;
    int yInicial = y;
    bool desaparecer;
    int objetivo_x;
    int objetivo_y;
};

struct Llamarada {
    int x;
    int y;
    int dx;
    int dy;
    int ancho;
    int alto;
    bool activo;
    int descanso = 100;
    int id;
    int tiempoDisparo = 0;
    int xInicial = x;
    int yInicial = y;
    bool desaparecer;
    int objetivo_x;
    int objetivo_y;
};

struct Enemigo {
    char* nombre = new char[20];
    int vida;
    int danioRecibido;
    int xEnemigo;
    int yEnemigo;
    int dxEnemigo;
    int dyEnemigo;
    int anchoEnemigo;
    int altoEnemigo;
    bool enemigoMuerto = false;
    bool ataque = false;
    bool alejandose = false;
    bool descansando = false;
    int tiempoAlejamiento = 0;
    int tiempoDescanso = 0;
    int margen;
    int contadorDePasos = 0;
    int golpesMaximos;
    int contador = 0;
    int dano;
    bool direccionDerecha = true;
    bool direccionIzquierda = false;
    BolaDeFuego bolaDeFuego;
    bool turnoDeAtaque;
    int tiempoDisparo;
    Llamarada* llamaradas = new Llamarada[3];
};

struct Coordenada
{
    int x;
    int y;
    int dx = 0;
    int dy = 0;
    int ancho = 18;
    int alto = 10;
    bool coordenadaEncontrada = false;
    bool activo;
    int xInicial = x;
    int yInicial = y;
};

struct Bellota {
    int x;
    int y;
    int dx;
    int dy;
    int ancho;
    int alto;
    bool desaparecer = false;
    int tiempoDisparo = 0;
};

// Estructura de pociones
struct Potion {
    int id;
    int x;
    int y;
    int alto;
    int ancho;
    bool desaparecer = false;
    int aumentarVida = 0;
    int aumentarMana = 0;
    int aumentarFuerza = 0;
};

struct Bloque {
    int x;
    int y;
    int alto = 3;
    int ancho = 11;
};

Enemigo crearEnemigo1(char* nombre, int x, int y, int dx, int dy, int altoEnemigo, int anchoEnemigo) {
    Enemigo nuevoEnemigo;
    nuevoEnemigo.nombre = nombre;
    nuevoEnemigo.xEnemigo = x;
    nuevoEnemigo.yEnemigo = y;
    nuevoEnemigo.dxEnemigo = dx;
    nuevoEnemigo.dyEnemigo = dy;
    nuevoEnemigo.altoEnemigo = altoEnemigo;
    nuevoEnemigo.anchoEnemigo = anchoEnemigo;
    nuevoEnemigo.ataque = false;
    return nuevoEnemigo;
}

Enemigo crearEnemigo2(char* nombre, int x, int y, int dx, int dy, int altoEnemigo, int anchoEnemigo, int vida) {
    Enemigo nuevoEnemigo;
    nuevoEnemigo.nombre = nombre;
    nuevoEnemigo.xEnemigo = x;
    nuevoEnemigo.yEnemigo = y;
    nuevoEnemigo.dxEnemigo = dx;
    nuevoEnemigo.dyEnemigo = dy;
    nuevoEnemigo.altoEnemigo = altoEnemigo;
    nuevoEnemigo.anchoEnemigo = anchoEnemigo;
    nuevoEnemigo.vida = vida;
    return nuevoEnemigo;
}

void gotoXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void setWindow() {
    Console::CursorVisible = false;
    Console::Clear();
    Console::SetWindowSize(WIDTH, HEIGHT);
}

void dibujarLineaH(int x, int y, int tam) {
    for (int i = 1; i <= tam * 2; i += 2) {
        gotoXY(x + i, y);
        cout << "* ";
    }
}

void borrarLineaH(int x, int y, int tam) {
    for (int i = 1; i <= tam * 2; i += 2) {
        gotoXY(x + i, y);
        cout << "  ";
    }
}

void dibujarLineaIncompleta(int x, int y, int tamanho) {
    for (int i = 1; i <= tamanho * 2; i += 2) {

        gotoXY(x + i, y);
        if (i == 1 || i == ((tamanho * 2) - 1)) {
            cout << "*";
        }
        else {
            cout << " ";
        }


    }
}

void borrarLineaIncompleta(int x, int y, int tamanho) {
    for (int i = 1; i <= tamanho * 2; i += 2) {
        gotoXY(x + i, y);
        cout << " ";
    }
}

void dibujarRectanguloHueco(int x, int y, int largo, int ancho) {
    for (int i = 1; i < ancho; i++) {
        if (i == 1) {
            dibujarLineaH(x, y + i, largo);
        }
        else {
            dibujarLineaIncompleta(x, y + i, largo);
        }
    }
    dibujarLineaH(x, y + ancho, largo);
}

void borrarRectangulo(int x, int y, int largo, int ancho) {
    for (int i = 0; i < ancho; i++) {
        borrarLineaH(x, y + i, largo);
    }
    borrarLineaH(x, y + ancho, largo);
}

void iniciando() {
    setWindow();
    cout << "Cargando Juego..." << endl;
    _getch();
    Console::Clear();
}

//letras
void dibujarletraA(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraB(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@@@@ ";
}

void dibujarletraC(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@    ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraD(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@@@@ ";
}

void dibujarletraE(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void dibujarletraF(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@    ";
}

void dibujarletraG(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@ @@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraH(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraI(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void dibujarletraJ(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "    @";
    gotoXY(x, y + 3); cout << "    @";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << " @  @";
    gotoXY(x, y + 6); cout << " @@@@";
}

void dibujarletraK(int x, int y) {
    gotoXY(x, y + 1); cout << "@  @ ";
    gotoXY(x, y + 2); cout << "@ @  ";
    gotoXY(x, y + 3); cout << "@@   ";
    gotoXY(x, y + 4); cout << "@ @  ";
    gotoXY(x, y + 5); cout << "@  @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraL(int x, int y) {
    gotoXY(x, y + 1); cout << "@    ";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@    ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void dibujarletraM(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@@ @@";
    gotoXY(x, y + 3); cout << "@ @ @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraN(int x, int y) {
    gotoXY(x, y + 1); cout << "@@  @";
    gotoXY(x, y + 2); cout << "@ @ @";
    gotoXY(x, y + 3); cout << "@  @@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraO(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraP(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@@@@ ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@    ";
}

void dibujarletraQ(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@ @ @";
    gotoXY(x, y + 5); cout << "@  @@";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraR(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@@@@ ";
    gotoXY(x, y + 5); cout << "@  @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraS(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << " @@@ ";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraT(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void dibujarletraU(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void dibujarletraV(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << " @ @ ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void dibujarletraW(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@ @ @";
    gotoXY(x, y + 5); cout << "@@ @@";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraX(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << " @ @ ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << " @ @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void dibujarletraY(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << " @ @ ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void dibujarletraZ(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "   @ ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << " @   ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

//letras pequeñas
void a(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "| |";
}

void b(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_)";
    gotoXY(x, y + 3); cout << "|_)";
}

void c(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|  ";
    gotoXY(x, y + 3); cout << "|__";
}

void d(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| \\";
    gotoXY(x, y + 3); cout << "|_/";
}

void e(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|__";
    gotoXY(x, y + 3); cout << "|__";
}

void f(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|__";
    gotoXY(x, y + 3); cout << "|  ";
}

void g(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << " _|";
}

void h(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "| |";
}

void i(int x, int y) {
    gotoXY(x, y + 1); cout << "_ _";
    gotoXY(x, y + 2); cout << " | ";
    gotoXY(x, y + 3); cout << "_|_";
}

void j(int x, int y) {
    gotoXY(x, y + 1); cout << "__ ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "\\_|";
}

void k(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|/ ";
    gotoXY(x, y + 3); cout << "|\\ ";
}

void l(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|  ";
    gotoXY(x, y + 3); cout << "|__";
}

void m(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|\\/|";
    gotoXY(x, y + 3); cout << "|  |";
}

void n(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|\\|";
    gotoXY(x, y + 3); cout << "| |";
}

void o(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

void p(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|  ";
}

void q(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "  |";
}

void r(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|\\ ";
}

void s(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << " _|";
}

void t(int x, int y) {
    gotoXY(x, y + 1); cout << "___";
    gotoXY(x, y + 2); cout << " | ";
    gotoXY(x, y + 3); cout << " | ";
}

void u(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

void v(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|  |";
    gotoXY(x, y + 3); cout << " \\/ ";
}

void w(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|  |";
    gotoXY(x, y + 3); cout << "|/\\|";
}

void xx(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "\\/ ";
    gotoXY(x, y + 3); cout << "/\\";
}

void yy(int x, int y) {
    gotoXY(x, y + 1); cout << "  ";
    gotoXY(x, y + 2); cout << "\\/";
    gotoXY(x, y + 3); cout << "/ ";
}

void z(int x, int y) {
    gotoXY(x, y + 1); cout << "__ ";
    gotoXY(x, y + 2); cout << " / ";
    gotoXY(x, y + 3); cout << "/_ ";
}

//numeros
void dibujarnumero0(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |    |  ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void dibujarnumero1(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "    |     ";
    gotoXY(x, y + 3); cout << "    |     ";
    gotoXY(x, y + 4); cout << "    |     ";
    gotoXY(x, y + 5); cout << "    |     ";
}

void dibujarnumero2(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "   ____|  ";
    gotoXY(x, y + 4); cout << "  |       ";
    gotoXY(x, y + 5); cout << "  |____   ";
}

void dibujarnumero3(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "   ____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "   ____|  ";
}

void dibujarnumero4(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

void dibujarnumero5(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |       ";
    gotoXY(x, y + 3); cout << "  |____   ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "   ____|  ";
}

void dibujarnumero6(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |       ";
    gotoXY(x, y + 3); cout << "  |____   ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void dibujarnumero7(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "       |  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

void dibujarnumero8(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void dibujarnumero9(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

// Numero Pequeño
void number9(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << " _|";
}

void number8(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|_|";
}

void number7(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "  |";
}

void number6(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << "|_|";
}

void number5(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << " _|";
}

void number4(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "  |";
}

void number3(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << " _|";
    gotoXY(x, y + 3); cout << " _|";
}

void number2(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << " _|";
    gotoXY(x, y + 3); cout << "|_ ";
}

void number1(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "  |";
}

void number0(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

//caracteres
void flechitajsjsjs(int x, int y) {
    gotoXY(x, y + 1); cout << "      @    ";
    gotoXY(x, y + 2); cout << "        @  ";
    gotoXY(x, y + 3); cout << "  @@@@@   @";
    gotoXY(x, y + 4); cout << "  @@@@@   @";
    gotoXY(x, y + 5); cout << "        @  ";
    gotoXY(x, y + 6); cout << "      @    ";
}

void dibujarparentesisabierto(int x, int y) {
    gotoXY(x, y + 1); cout << " @";
    gotoXY(x, y + 2); cout << "@ ";
    gotoXY(x, y + 3); cout << "@ ";
    gotoXY(x, y + 4); cout << "@ ";
    gotoXY(x, y + 5); cout << "@ ";
    gotoXY(x, y + 6); cout << " @";
}

void dibujarparentesiscerrado(int x, int y) {
    gotoXY(x, y + 1); cout << "@ ";
    gotoXY(x, y + 2); cout << " @";
    gotoXY(x, y + 3); cout << " @";
    gotoXY(x, y + 4); cout << " @";
    gotoXY(x, y + 5); cout << " @";
    gotoXY(x, y + 6); cout << "@ ";
}

void coma(int x, int y) {
    gotoXY(x, y + 3); cout << "|";
}

void puntoycoma(int x, int y) {
    gotoXY(x, y + 1); cout << "|-|";
    gotoXY(x, y + 2); cout << "   ";
    gotoXY(x, y + 3); cout << "|  ";
}

void dospuntos(int x, int y) {
    gotoXY(x, y + 1); cout << "|-|";
    gotoXY(x, y + 2); cout << "   ";
    gotoXY(x, y + 3); cout << "|-|";
}

void igualxd(int x, int y) {
    gotoXY(x, y + 2); cout << "__";
    gotoXY(x, y + 3); cout << "--";
}

void admiracion(int x, int y) {
    gotoXY(x, y + 2); cout << "|";
    gotoXY(x, y + 3); cout << "-";
}

void punto(int x, int y) {
    gotoXY(x, y + 3); cout << "|-|";
}

void guion(int x, int y) {
    gotoXY(x, y + 2); cout << "--";
}

void flechita(int x, int y) {
    gotoXY(x, y + 1); cout << "      @    ";
    gotoXY(x, y + 2); cout << "        @  ";
    gotoXY(x, y + 3); cout << "  @@@@@   @";
    gotoXY(x, y + 4); cout << "  @@@@@   @";
    gotoXY(x, y + 5); cout << "        @  ";
    gotoXY(x, y + 6); cout << "      @    ";
}

void fleschitajsjaja(int x, int y) {
    gotoXY(x, y + 2); cout << "  @ ";
    gotoXY(x, y + 3); cout << "@@ @";
    gotoXY(x, y + 4); cout << "  @ ";
}

void fleschitajsjajsja(int x, int y) {
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "@@  @";
    gotoXY(x, y + 4); cout << "@@  @";
    gotoXY(x, y + 5); cout << "  @  ";
}

void borrar_fleschitajsjajsja(int x, int y) {
    gotoXY(x, y + 2); cout << "     ";
    gotoXY(x, y + 3); cout << "     ";
    gotoXY(x, y + 4); cout << "     ";
    gotoXY(x, y + 5); cout << "     ";
}

void borrar_flecha_jsjaja(int x, int y) {
    gotoXY(x, y + 2); cout << "    ";
    gotoXY(x, y + 3); cout << "    ";
    gotoXY(x, y + 4); cout << "    ";
}

void parentesis_abierto_3(int x, int y) {
    gotoXY(x, y + 2); cout << "/";
    gotoXY(x, y + 3); cout << "\\";
}

void parentesis_cerrado_3(int x, int y) {
    gotoXY(x, y + 2); cout << "\\";
    gotoXY(x, y + 3); cout << "/";
}

void admiracion_grande_xd(int x, int y) {
    gotoXY(x, y + 1); cout << "@@";
    gotoXY(x, y + 2); cout << "@@";
    gotoXY(x, y + 3); cout << "@@";
    gotoXY(x, y + 4); cout << "@@";
    gotoXY(x, y + 5); cout << "  ";
    gotoXY(x, y + 6); cout << "@@";
}

// Pocion
void pocion_fuerza(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "  @@  " << RESET;
    gotoXY(x, y + 2); cout << CYAN << " @@@@ " << RESET;
    gotoXY(x, y + 3); cout << CYAN << "  @@  " << RESET;
    gotoXY(x, y + 4); cout << CYAN << " @" << RESET << GREEN << "@@" << RESET << CYAN << "@ " << RESET;
    gotoXY(x, y + 5); cout << CYAN << "@" << RESET << GREEN << "@@@@" << RESET << CYAN << "@" << RESET;
    gotoXY(x, y + 6); cout << CYAN << " @@@@ " << RESET;
}

void pocion_mana(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "  @@  " << RESET;
    gotoXY(x, y + 2); cout << CYAN << " @@@@ " << RESET;
    gotoXY(x, y + 3); cout << CYAN << "  @@  " << RESET;
    gotoXY(x, y + 4); cout << CYAN << " @" << RESET << BLUE << "@@" << RESET << CYAN << "@ " << RESET;
    gotoXY(x, y + 5); cout << CYAN << "@" << RESET << BLUE << "@@@@" << RESET << CYAN << "@" << RESET;
    gotoXY(x, y + 6); cout << CYAN << " @@@@ " << RESET;
}

void pocion_vida(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "  @@  " << RESET;
    gotoXY(x, y + 2); cout << CYAN << " @@@@ " << RESET;
    gotoXY(x, y + 3); cout << CYAN << "  @@  " << RESET;
    gotoXY(x, y + 4); cout << CYAN << " @" << RESET << RED << "@@" << RESET << CYAN << "@ " << RESET;
    gotoXY(x, y + 5); cout << CYAN << "@" << RESET << RED << "@@@@" << RESET << CYAN << "@" << RESET;
    gotoXY(x, y + 6); cout << CYAN << " @@@@ " << RESET;
}

void pocion_cheta(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "  @@  " << RESET;
    gotoXY(x, y + 2); cout << CYAN << " @@@@ " << RESET;
    gotoXY(x, y + 3); cout << CYAN << "  @@  " << RESET;
    gotoXY(x, y + 4); cout << CYAN << " @" << RESET << MAGENTA << "@@" << RESET << CYAN << "@ " << RESET;
    gotoXY(x, y + 5); cout << CYAN << "@" << RESET << MAGENTA << "@@@@" << RESET << CYAN << "@" << RESET;
    gotoXY(x, y + 6); cout << CYAN << " @@@@ " << RESET;
}

void borrar_pocion(int x, int y) {
    gotoXY(x, y + 1); cout << "         ";
    gotoXY(x, y + 2); cout << "         ";
    gotoXY(x, y + 3); cout << "         ";
    gotoXY(x, y + 4); cout << "         ";
    gotoXY(x, y + 5); cout << "         ";
    gotoXY(x, y + 6); cout << "         ";
}

// Dibujos:
void dibujarCapibaraBatalla(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "       @@@@@ @@@@@@@         ";
    gotoXY(x, y + 2);  cout << "   @@@@@          @@@        ";
    gotoXY(x, y + 3);  cout << " @@         @@@  @@          ";
    gotoXY(x, y + 4);  cout << "@@                @@@        ";
    gotoXY(x, y + 5);  cout << "@@ @@              @@        ";
    gotoXY(x, y + 6);  cout << "@@ @@              @@        ";
    gotoXY(x, y + 7);  cout << "@@   @@@             @@@     ";
    gotoXY(x, y + 8);  cout << "@@                     @@    ";
    gotoXY(x, y + 9);  cout << "  @@@@@@@@@              @@  ";
    gotoXY(x, y + 10); cout << "          @@               @@";
    gotoXY(x, y + 11); cout << "          @@        @@@    @@";
    gotoXY(x, y + 12); cout << "          @@@@@@@    @@    @@";
    gotoXY(x, y + 13); cout << "            @@@@@@  @@@@   @@";
    gotoXY(x, y + 14); cout << "           @@@@@@@@@@@@@@@@@@";
    cout << RESET;
}

void dibujarCapibaraBatallaSoldier(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "            @@@@@ @@@@@@@              ";
    gotoXY(x, y + 2);  cout << "        @@@@@          @@@             ";
    gotoXY(x, y + 3);  cout << "      @@         @@@  @@     @@@@@@@   ";
    gotoXY(x, y + 4);  cout << "     @@                @@@ @@@@@@@@@@  ";
    gotoXY(x, y + 5);  cout << "     @@ @@              @@ @@@@@@@@@@@ ";
    gotoXY(x, y + 6);  cout << "     @@ @@              @@@@@@@@@@@@@@ ";
    gotoXY(x, y + 7);  cout << "     @@   @@@             @@@@@@@@@@@@ ";
    gotoXY(x, y + 8);  cout << "     @@                     @@@@@@@@@@ ";
    gotoXY(x, y + 9);  cout << "       @@@@@@@@@              @@@@@@@  ";
    gotoXY(x, y + 10); cout << "     @         @@               @@@@   ";
    gotoXY(x, y + 11); cout << "    @@@@@@@@@@ @@@        @@@    @@@   ";
    gotoXY(x, y + 12); cout << "@@@@@@@@@@@@@@@@@@@@@@@@    @@    @@   ";
    gotoXY(x, y + 13); cout << "      @@ @@@@@ @@@@@@@  @@@@   @@@     ";
    gotoXY(x, y + 14); cout << "           @@   @@@@@@@@@@@@@@@@@@     ";
    cout << RESET;
}

void dibujarCapibaraBatallaWarrior(int x, int y) {
    cout << BLUE;
    gotoXY(x, y + 1);  cout << "       @@@@@           @@@@@                   ";
    gotoXY(x, y + 2);  cout << "       @@@@@@@@@@@@@@@@@@@@@                   ";
    gotoXY(x, y + 3);  cout << "        @@   @@@@@@@   @@@@@@                  ";
    gotoXY(x, y + 4);  cout << "          @@@    @@    @@  @                   ";
    gotoXY(x, y + 5);  cout << "          @      @@    @@  @@@                 ";
    gotoXY(x, y + 6);  cout << "  @@ @@  @@@  @@@@      @@@@  @                ";
    gotoXY(x, y + 7);  cout << "  @@ * @@ * @@              @@@                ";
    gotoXY(x, y + 8);  cout << "  @@ * @@ * @@              @@@                ";
    gotoXY(x, y + 9);  cout << "  @@ * @@ *  @          @@@@@  @@              ";
    gotoXY(x, y + 10); cout << "@@   * @@ * @##        @  @  @ @@@             ";
    gotoXY(x, y + 11); cout << "@@   * @@ *  @##############@@@@**@@@@@@@@@@@  ";
    gotoXY(x, y + 12); cout << "@@   * @@ * @**********###**@@@@**@@        @@@";
    gotoXY(x, y + 13); cout << "  @@ * @@ @@################@@@@**@@        @@@";
    gotoXY(x, y + 14); cout << "  @@ * @@@@@***********##@@@   @**@@@@@@@@@@   ";
    gotoXY(x, y + 15); cout << "   @@@@@@@@@@@%#@@@@@@#%@       @@             ";
    gotoXY(x, y + 16); cout << "           @@@@@      @@@@@                    ";
    cout << RESET;
}

void dibujarCapibaraBatallaAssasin(int x, int y) {
    cout << CYAN;
    gotoXY(x, y + 1);    cout << "           @@@@@@@@                 ";
    gotoXY(x, y + 2);    cout << "   @@@@ @@@     @@@@@@              ";
    gotoXY(x, y + 3);    cout << "  @   @@              @             ";
    gotoXY(x, y + 4);    cout << "   @@   @@@@@@    @@@@              ";
    gotoXY(x, y + 5);    cout << "     @@@    @@    @@  @             ";
    gotoXY(x, y + 6);    cout << "     @@     @@    @@   @@           ";
    gotoXY(x, y + 7);    cout << "     @@@    @@    @@   @@           ";
    gotoXY(x, y + 8);    cout << "     @%%@@@@        @@@@@           ";
    gotoXY(x, y + 9);    cout << "   @@@@@       @@@@  @@@@           ";
    gotoXY(x, y + 10);   cout << "   @@   @@@@@         @ @@          ";
    gotoXY(x, y + 11);   cout << "   @@ @@@    @@     @@@@            ";
    gotoXY(x, y + 12);   cout << "   @@   @      @@ @@  @@@ @@        ";
    gotoXY(x, y + 13);   cout << "   @@@@@  @      @    @@@@ @@       ";
    gotoXY(x, y + 14);   cout << "  @      @@         @@@@@   @@@     ";
    gotoXY(x, y + 15);   cout << "@@      @           @@@ @@   @@@@@  ";
    gotoXY(x, y + 17);   cout << " @@@@@@@  @@@@@@@@  @@  @@@       @@";
    gotoXY(x, y + 18);   cout << "     @  @@     @@ @@      @@@@@@@@  ";
    cout << RESET;
}

void dibujarCapibaraBatallaMagician(int x, int y) {
    cout << MAGENTA;
    gotoXY(x, y + 1);    cout << "            @@@@@@@@@  @         ";
    gotoXY(x, y + 2);    cout << "         @@@         @@@@@       ";
    gotoXY(x, y + 3);    cout << "       @@  @              @      ";
    gotoXY(x, y + 4);    cout << "       @@     @@@@      @@@      ";
    gotoXY(x, y + 5);    cout << "   @  @@@@  @    @@   @@  @      ";
    gotoXY(x, y + 6);    cout << " @@ @@ @@   @    @@   @@  @      ";
    gotoXY(x, y + 7);    cout << "@@       @    @@@@@     @@@@@@   ";
    gotoXY(x, y + 8);    cout << " @@     @                  @@    ";
    gotoXY(x, y + 9);    cout << " @@@   @@@          @@@@   @@    ";
    gotoXY(x, y + 10);   cout << " @@     @@  @@@@   @    @ @@@    ";
    gotoXY(x, y + 11);   cout << " @@@   @@@@@    @@@ @@@@ @@@@@   ";
    gotoXY(x, y + 12);   cout << " @@   @   @       @     @  @  @@@";
    gotoXY(x, y + 13);   cout << "   @  @  @@        @    @  @    @";
    gotoXY(x, y + 14);   cout << "   @  @ @         @      @ @    @";
    gotoXY(x, y + 15);   cout << "   @  @@@@@@@@@@@@  @@@@  @     @";
    gotoXY(x, y + 16);   cout << "   @@@@  @@@ @@ @@@@    @@@@@@@@ ";
    cout << RESET;
}

void dibujarCapibaraMujer(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1); cout << "     @@@            ";
    gotoXY(x, y + 2); cout << "   @@  @@@@@@@@@@@@ ";
    gotoXY(x, y + 3); cout << "    @      @@@  @@@@";
    gotoXY(x, y + 4); cout << "  @@@@           @@@";
    gotoXY(x, y + 5); cout << "@                  @";
    gotoXY(x, y + 6); cout << "@              @@@@@";
    gotoXY(x, y + 7); cout << "@    @@@@@@   @     ";
    gotoXY(x, y + 8); cout << " @@@@@    @@@@@     ";
    cout << RESET;
}

void drawCapibaraFace(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "                #######     #####  ";
    gotoXY(x, y + 2);  cout << "                #    ##     #   ###";
    gotoXY(x, y + 3);  cout << "                #   ########     ##";
    gotoXY(x, y + 4);  cout << "         #######       #####     ##";
    gotoXY(x, y + 5);  cout << "     #####                       ##";
    gotoXY(x, y + 6);  cout << "    #                            ##";
    gotoXY(x, y + 7);  cout << "  ##                   ##        ##";
    gotoXY(x, y + 8);  cout << "## ###                 ####      ##";
    gotoXY(x, y + 9);  cout << "##     ###                       ##";
    gotoXY(x, y + 10); cout << "##    ####                       ##";
    gotoXY(x, y + 11); cout << "##   ##                          ##";
    gotoXY(x, y + 12); cout << "##   ##                          ##";
    gotoXY(x, y + 13); cout << "######                           ##";
    gotoXY(x, y + 14); cout << "  ##  ####                      ###";
    gotoXY(x, y + 15); cout << "    ####                       ##  ";
    gotoXY(x, y + 16); cout << "        ###########          ##    ";
    gotoXY(x, y + 17); cout << "              ##         ####      ";
    gotoXY(x, y + 18); cout << "               ############        ";
    cout << RESET;
}

void drawCapibaraFace1(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "     ####  ###########   ###      ";
    gotoXY(x, y + 2);  cout << "     #######           #####      ";
    gotoXY(x, y + 3);  cout << "     ###                 ###      ";
    gotoXY(x, y + 4);  cout << "    ##                     ##     ";
    gotoXY(x, y + 5);  cout << "    ##                     ##     ";
    gotoXY(x, y + 6);  cout << "    ##                     ##     ";
    gotoXY(x, y + 7);  cout << " ###   ####           ####   ###  ";
    gotoXY(x, y + 8);  cout << " ###         ########        ###  ";
    gotoXY(x, y + 9);  cout << " ###       ##        ##      ###  ";
    gotoXY(x, y + 10); cout << " ###       # ######## #      ###  ";
    gotoXY(x, y + 11); cout << "##         #   ####   #         ##";
    gotoXY(x, y + 12); cout << "##        #            #        ##";
    gotoXY(x, y + 13); cout << "##        #            #        ##";
    gotoXY(x, y + 14); cout << "##        #            #        ##";
    gotoXY(x, y + 15); cout << "##        # ##         #        ##";
    gotoXY(x, y + 16); cout << " ###      #  #######   #     ###  ";
    gotoXY(x, y + 17); cout << "    ###    ############   ###     ";
    gotoXY(x, y + 18); cout << "        ##################        ";
    cout << RESET;
}

void borrarCapibaraFace(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "                                   ";
    gotoXY(x, y + 2);  cout << "                                   ";
    gotoXY(x, y + 3);  cout << "                                   ";
    gotoXY(x, y + 4);  cout << "                                   ";
    gotoXY(x, y + 5);  cout << "                                   ";
    gotoXY(x, y + 6);  cout << "                                   ";
    gotoXY(x, y + 7);  cout << "                                   ";
    gotoXY(x, y + 8);  cout << "                                   ";
    gotoXY(x, y + 9);  cout << "                                   ";
    gotoXY(x, y + 10); cout << "                                   ";
    gotoXY(x, y + 11); cout << "                                   ";
    gotoXY(x, y + 12); cout << "                                   ";
    gotoXY(x, y + 13); cout << "                                   ";
    gotoXY(x, y + 14); cout << "                                   ";
    gotoXY(x, y + 15); cout << "                                   ";
    gotoXY(x, y + 16); cout << "                                   ";
    gotoXY(x, y + 17); cout << "                                   ";
    gotoXY(x, y + 18); cout << "                                   ";
    cout << RESET;
}

// Movimiento Assasin 
void dibujarAsesinoIzquierda(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####       " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " ####  " << RED << "#" << DARKGRAY << " #       " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##       ##      " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####      #####  " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << " #####" << RED << "%$ %$%$%" << DARKGRAY << "## " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "    ##" << RED << "%$ %$%$%$" << DARKGRAY << "##" << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "      #" << RED << "%$%$" << DARKGRAY << "###" << RED << "%$" << DARKGRAY << "#" << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "       ####  ####" << RESET;
}

void dibujarAsesinoIzquierdaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " ####  " << RED << "#" << DARKGRAY << " #        " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##       ##       " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####      #####   " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << " #####" << RED << "%$ %$%$%" << DARKGRAY << "##  " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "    ##" << RED << "%$ %$%$%$" << DARKGRAY << "## " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "      #" << RED << "%$%$" << DARKGRAY << "###" << RED << "%$" << DARKGRAY << "# " << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "      #####   ####" << RESET;
}

void dibujarAsesinoDerecha(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << RED << "#" << BROWN << "  #### " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##" << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####      ####" << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << " ##" << RED << "%$%$% $%" << DARKGRAY << "##### " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "##" << RED << "$%$%$% $%$" << DARKGRAY << "##   " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "##" << RED << "$%" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##      " << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "##### #####      " << RESET;

}

void dibujarAsesinoDerechaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << RED << "#" << BROWN << "  #### " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##" << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####      ####" << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << " ##" << RED << "%$%$% $%" << DARKGRAY << "##### " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "##" << RED << "$%$%%$% $%$" << DARKGRAY << "##  " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "##" << RED << "$%$" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##     " << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "#####   #####    " << RESET;

}

// Movimiento Soldier
void dibujarSoldadoIzquierdaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "    #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " #### " << CYAN << "#" << BROWN << " # " << GREEN << "#####  " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##      ##" << GREEN << "###### " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####     #####" << GREEN << "#  " << RESET;
    gotoXY(x, y + 5); cout << BROWN << " #####       ##  " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "     ##       ## " << RESET;
    gotoXY(x, y + 7); cout << GREEN << "      ##  ###  ##" << RESET;
    gotoXY(x, y + 8); cout << GREEN << "     #####   #####" << RESET;
}

void dibujarSoldadoIzquierda(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "    #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " #### " << CYAN << "#" << BROWN << " # " << GREEN << "#####  " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##      ##" << GREEN << "###### " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####     #####" << GREEN << "#  " << RESET;
    gotoXY(x, y + 5); cout << BROWN << " #####       ##  " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "     ##       ## " << RESET;
    gotoXY(x, y + 7); cout << GREEN << "      ##  ###  ##" << RESET;
    gotoXY(x, y + 8); cout << GREEN << "      ##### #####" << RESET;
}

void dibujarSoldadoDerecha(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "        #####    " << RESET;
    gotoXY(x, y + 2); cout << GREEN << "  #####" << BROWN << " # " << CYAN << "#" << BROWN << " #### " << RESET;
    gotoXY(x, y + 3); cout << GREEN << " ######" << BROWN << "##      ##" << RESET;
    gotoXY(x, y + 4); cout << GREEN << "  #" << BROWN << "#####     ####" << RESET;
    gotoXY(x, y + 5); cout << BROWN << "  ##       ##### " << RESET;
    gotoXY(x, y + 6); cout << GREEN << " ##       ##     " << RESET;
    gotoXY(x, y + 7); cout << GREEN << "##  ###  ##      " << RESET;
    gotoXY(x, y + 8); cout << GREEN << "##### #####      " << RESET;
}

void dibujarSoldadoDerechaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "         #####    " << RESET;
    gotoXY(x, y + 2); cout << GREEN << "   #####" << BROWN << " # " << CYAN << "#" << BROWN << " #### " << RESET;
    gotoXY(x, y + 3); cout << GREEN << "  ######" << BROWN << "##      ##" << RESET;
    gotoXY(x, y + 4); cout << GREEN << "   #" << BROWN << "#####     ####" << RESET;
    gotoXY(x, y + 5); cout << BROWN << "   ##       ##### " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "  ##        ##    " << RESET;
    gotoXY(x, y + 7); cout << GREEN << " ##   ###  ##     " << RESET;
    gotoXY(x, y + 8); cout << GREEN << " #####   #####    " << RESET;
}

// Movimiento Magician
void dibujarMagoDerecha(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << WHITE << "#" << BROWN << "  #### " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##" << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####  " << BLUE << "%%" << BROWN << "  ####" << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << " ##" << BLUE << "++ +++++" << MAGENTA << "##### " << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << "##  " << BLUE << "+ +" << MAGENTA << "   ##     " << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << "#   " << BLUE << "+" << MAGENTA << "# " << BLUE << "+" << MAGENTA << " #       " << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << "##### ####       " << RESET;
}

void dibujarMagoDerechaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << WHITE << "#" << BROWN << "  #### " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##" << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####  " << BLUE << "%%" << BROWN << "  ####" << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << " ##" << BLUE << "++ +++++" << BROWN << "##### " << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << "##   " << BLUE "+ +" << MAGENTA << "   ##    " << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << "#    " << BLUE "+" << MAGENTA << "#" << BLUE << "+" << MAGENTA << "   #     " << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << "#####   #####    " << RESET;
}

void dibujarMagoIzquierda(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####      " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " ####  " << WHITE << "#" << BROWN << " #      " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##       ##     " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####  " << BLUE << "%%" << MAGENTA << "  ##### " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << " #####" << BLUE << "+++++ ++" << MAGENTA << "##" << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << "    ##   " << BLUE << "+ +" << MAGENTA << "  ##" << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << "     #   " << BLUE << "+" << MAGENTA << "#" << BLUE << "+" << MAGENTA << "  ##" << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << "      ####  ####" << RESET;
}

void dibujarMagoIzquierdaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####      " << RESET;
    gotoXY(x, y + 2); cout << BROWN << " ####  " << WHITE << "#" << BROWN << " #      " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "##       ##     " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "####  " << BLUE << "%%" << BROWN << "  ##### " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << " #####" << BLUE << "+++++ ++" << MAGENTA << "##" << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << "    ##   " << BLUE << "+ +" << MAGENTA << "  ##" << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << "   ##   " << BLUE << "+" << MAGENTA << "#" << BLUE << "+" << MAGENTA << "   ##" << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << "  ######  #####" << RESET;
}

// Movimiento Warrior
void dibujarWarriorIzquierda(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####       ";
    gotoXY(x, y + 2); cout << " ####" << GREEN << "  #" << BROWN << " #       ";
    gotoXY(x, y + 3); cout << BROWN << "##       ##      ";
    gotoXY(x, y + 4); cout << BROWN << "####    " << CYAN << " .#####  ";
    gotoXY(x, y + 5); cout << BROWN << " #####" << CYAN "...." << BROWN "    ## ";
    gotoXY(x, y + 6); cout << BROWN << "     ##" << CYAN "@@@" << YELLOW "||" << CYAN "@@@" << BROWN "##";
    gotoXY(x, y + 7); cout << BROWN << "      ##" << CYAN "**" << BROWN "###" << CYAN "**" << BROWN "##";
    gotoXY(x, y + 8); cout << BROWN << "      ##### #####" << RESET;
}

void dibujarWarriorIzquierdaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "     #####       ";
    gotoXY(x, y + 2); cout << BROWN << " ####  " << GREEN "# " << BROWN "#       ";
    gotoXY(x, y + 3); cout << BROWN << "##       ##      ";
    gotoXY(x, y + 4); cout << BROWN << "####     " << CYAN "." << BROWN << "#####  ";
    gotoXY(x, y + 5); cout << BROWN << " #####" << CYAN "...." << BROWN << "    ## ";
    gotoXY(x, y + 6); cout << BROWN << "     ##" << CYAN << "@@@" << YELLOW << "||" << CYAN << "@@" << BROWN "## ";
    gotoXY(x, y + 7); cout << BROWN << "    ##" << CYAN "**" << BROWN << "###" << CYAN << "***" << BROWN << "## ";
    gotoXY(x, y + 8); cout << "   #####   ##### " << RESET;
}

void dibujarWarriorDerechaCaminando(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     ";
    gotoXY(x, y + 2); cout << BROWN << "       # " << GREEN "#" << BROWN << " #### ";
    gotoXY(x, y + 3); cout << "      ##       ##";
    gotoXY(x, y + 4); cout << "  #####      ####";
    gotoXY(x, y + 5); cout << " ##     " << CYAN "..." << BROWN "##### ";
    gotoXY(x, y + 6); cout << " ##" << CYAN "@@@" << YELLOW "||" << CYAN << "@@" << BROWN << "##     ";
    gotoXY(x, y + 7); cout << " ##" << CYAN "***" << BROWN "###" << CYAN "**" << BROWN << "##    ";
    gotoXY(x, y + 8); cout << " #####   #####   " << RESET;
}

void dibujarWarriorDerecha(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####     ";
    gotoXY(x, y + 2); cout << "       # " << GREEN << "#" << BROWN "  #### ";
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##";
    gotoXY(x, y + 4); cout << BROWN << "  #####" << CYAN "." << BROWN << "     ####";
    gotoXY(x, y + 5); cout << " ##" << CYAN << "    ...." << BROWN << "##### ";
    gotoXY(x, y + 6); cout << "##" << CYAN << "@@@" << YELLOW "||" << CYAN "@@@" << BROWN "##     ";
    gotoXY(x, y + 7); cout << "##" << CYAN "**" << BROWN "###" << CYAN "**" << BROWN "##      ";
    gotoXY(x, y + 8); cout << "##### #####      " << RESET;
}

// Ataque Warrior
void dibujarWarriorIzquierdaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "             #####       ";
    gotoXY(x, y + 2); cout << "         ####  " << BLUE "#" << BROWN " #       ";
    gotoXY(x, y + 3); cout << "        ##       ##      ";
    gotoXY(x, y + 4); cout << "        ####      #####  ";
    gotoXY(x, y + 5); cout << CYAN << "  @@@@@@@" << BROWN << "#####        ## ";
    gotoXY(x, y + 6); cout << CYAN << "@@       @@@@" << BROWN "##" << CYAN "@@@@@@@@" << BROWN << "##";
    gotoXY(x, y + 7); cout << CYAN << "  @@@@@@@     " << BROWN "##" << CYAN << "" << BROWN << "###" << CYAN << "" << BROWN << "##";
    gotoXY(x, y + 8); cout << "              ##### #####" << RESET;
}

void dibujarWarriorDerechaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "      #####            ";
    gotoXY(x, y + 2); cout << "      # " << BLUE "#" << BROWN << "  ####        ";
    gotoXY(x, y + 3); cout << "     ##       ##       ";
    gotoXY(x, y + 4); cout << " #####      ####       ";
    gotoXY(x, y + 5); cout << "##        #####" << CYAN << "@@@@@@@ ";
    gotoXY(x, y + 6); cout << BROWN << "##" << CYAN << "@@@@@@@" << BROWN << "##" << CYAN << "@@@@      @@";
    gotoXY(x, y + 7); cout << BROWN << "##" << CYAN << "   " << BROWN << "###  " << BROWN << "##" << CYAN << "   @@@@@@@ ";
    gotoXY(x, y + 8); cout << BROWN << "#####   #####          " << RESET;
}

void dibujarWarriorArribaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         ##### " << CYAN << "@@ ";
    gotoXY(x, y + 2); cout << BROWN << "         # " << BLUE << "#" << CYAN << "  @  @";
    gotoXY(x, y + 3); cout << BROWN << "        ##" << CYAN << "    @  @";
    gotoXY(x, y + 4); cout << BROWN << "   ######" << CYAN << ".    @  @";
    gotoXY(x, y + 5); cout << BROWN << "  ##      " << CYAN << ".." << BROWN << "###" << CYAN << "@@ ";
    gotoXY(x, y + 6); cout << BROWN << " ##" << CYAN << "@@@" << YELLOW << "||" << CYAN << "@@@" << BROWN "##  " << CYAN << "@@ ";
    gotoXY(x, y + 7); cout << BROWN << " ##" << CYAN << "" << BROWN << "###" << CYAN << "" << BROWN << "##   " << CYAN << "@@ ";
    gotoXY(x, y + 8); cout << BROWN << " ##### #####      " << RESET;
}

void dibujarWarriorAbajoAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         #####    ";
    gotoXY(x, y + 2); cout << "         # " << BLUE << "#" << CYAN << " @@" << BROWN << "## ";
    gotoXY(x, y + 3); cout << "        ##   " << CYAN << "@@" << BROWN << " ##";
    gotoXY(x, y + 4); cout << "   ######" << CYAN << "." << BROWN << "  #" << CYAN << "@@" << BROWN << "## ";
    gotoXY(x, y + 5); cout << "  ##     " << CYAN << "...@  @  ";
    gotoXY(x, y + 6); cout << BROWN << " ##" << CYAN << "@@@" << YELLOW << "||" << CYAN << "@@@" << BROWN << "#" << CYAN << "@  @  ";
    gotoXY(x, y + 7); cout << BROWN << " ##" << CYAN << "" << BROWN << "###" << CYAN << "" << BROWN << "# " << CYAN << "@  @  ";
    gotoXY(x, y + 8); cout << BROWN << " ##### ####  " << CYAN << "@@   " << RESET;
}

// Ataque Magician
void dibujarMagicianDerechaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << WHITE << "#" << BROWN << "  ####    " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##   " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####  " << BLUE << "%%" << MAGENTA << "  ####   " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << " ##" << BLUE << "++ +++++" << MAGENTA << "#####    " << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << "##  " << BLUE << "+ +" << MAGENTA << "   ##" << YELLOW << "@  @@@  " << RESET;
    gotoXY(x, y + 7); cout << YELLOW << "@@@@@@@@@@@@@@@   @ " << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << "##### ####  " << YELLOW << "@  @@@  " << RESET;
}

void dibujarMagicianIzquierdaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "           #####       " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       ####  " << WHITE << "#" << BROWN << " #       " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##      " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "      ####  " << BLUE << "%%" << BROWN << "  #####  " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << "       #####" << BLUE << "+++++ ++" << MAGENTA << "## " << RESET;
    gotoXY(x, y + 6); cout << YELLOW << "     @@@  @" << MAGENTA << "##   " << BLUE << "+ +" << MAGENTA << "  ##" << RESET;
    gotoXY(x, y + 7); cout << YELLOW << "    @   @@@@@@@@@@@@@@@" << RESET;
    gotoXY(x, y + 8); cout << YELLOW << "     @@@  @" << MAGENTA << "#####  #####" << RESET;
}

void dibujarMagicianAbajoAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         #####     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "         # " << WHITE << "#" << YELLOW << " @" << BROWN << "###  " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "        ##   " << YELLOW << "@" << BROWN << " ### " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "   ######   #" << YELLOW << "@" << BROWN << "###  " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << "  ##        #" << YELLOW << "@     " << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << " ##        # " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << " ##  ###  # " << YELLOW << "@ @    " << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << " ##### #### " << YELLOW << " @     " << RESET;
}

void dibujarMagicianArribaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         ##### " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "         # " << WHITE << "#" << YELLOW << "  @ @    " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "        ##     " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "   ######      " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 5); cout << MAGENTA << "  ##        ###" << YELLOW << "@     " << RESET;
    gotoXY(x, y + 6); cout << MAGENTA << " ##        ##  " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 7); cout << MAGENTA << " ##  ###  ##   " << YELLOW << "@     " << RESET;
    gotoXY(x, y + 8); cout << MAGENTA << " ##### #####         " << RESET;
}

// Ataque Soldier
void dibujarSoldierIzquierdaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "         #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "      #### " << CYAN << "#" << BROWN << " # " << GREEN << "#####  " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "     ##      ##" << GREEN << "###### " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "     ####     #####" << GREEN << "#  " << RESET;
    gotoXY(x, y + 5); cout << BROWN << "      #####       ##  " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "    @  @@ " << RESET << GREEN << "##       ## " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << " @@@@@@@@@@" << RESET << GREEN << "##  ###  ##" << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "       @@  " << RESET << GREEN << "##### #####" << RESET;
}

void dibujarSoldierDerechaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "         #####         " << RESET;
    gotoXY(x, y + 2); cout << GREEN << "   #####" << BROWN << " # " << CYAN << "#" << BROWN << " ####      " << RESET;
    gotoXY(x, y + 3); cout << GREEN << "  ######" << BROWN << "##      ##     " << RESET;
    gotoXY(x, y + 4); cout << GREEN << "   #" << BROWN << "#####     ####     " << RESET;
    gotoXY(x, y + 5); cout << BROWN << "   ##       #####      " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "  ##       ## " << DARKGRAY << "@@  @    " << RESET;
    gotoXY(x, y + 7); cout << GREEN << " ##  ###  ##" << DARKGRAY << "@@@@@@@@@@ " << RESET;
    gotoXY(x, y + 8); cout << GREEN << " ##### #####  " << DARKGRAY << "@@       " << RESET;
}

void dibujarSoldierArribaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "         ##### " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 2); cout << GREEN << "   #####" << BROWN << " # " << CYAN << "#" << BROWN << "  #" << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 3); cout << GREEN << "  ######" << BROWN << "##     " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 4); cout << GREEN << "   #" << BROWN << "#####    #" << DARKGRAY << "@@@      " << RESET;
    gotoXY(x, y + 5); cout << BROWN << "   ##       ###" << DARKGRAY << "@@      " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "  ##       ##  " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 7); cout << GREEN << " ##  ###  ##           " << RESET;
    gotoXY(x, y + 8); cout << GREEN << " ##### #####           " << RESET;
}

void dibujarSoldierAbajoAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << GREEN << "         #####         " << RESET;
    gotoXY(x, y + 2); cout << GREEN << "   #####" << BROWN << " # " << CYAN << "#" << BROWN << " ####      " << RESET;
    gotoXY(x, y + 3); cout << GREEN << "  ######" << BROWN << "##  " << DARKGRAY << " @" << BROWN << "  ##     " << RESET;
    gotoXY(x, y + 4); cout << GREEN << "   #" << BROWN << "#####   " << DARKGRAY << "@@" << BROWN << " ###     " << RESET;
    gotoXY(x, y + 5); cout << BROWN << "   ##      " << DARKGRAY << " @@@        " << RESET;
    gotoXY(x, y + 6); cout << GREEN << "  ##      ## " << DARKGRAY << "@         " << RESET;
    gotoXY(x, y + 7); cout << GREEN << " ##  ###  #  " << DARKGRAY << "@@        " << RESET;
    gotoXY(x, y + 8); cout << GREEN << " ##### ####  " << DARKGRAY << "@         " << RESET;
}

// Ataque Assasin
void dibujarAssasinIzquierdaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "           #####       " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       ####  " << RED << "#" << BROWN << " #       " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##      " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "      ####      #####  " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << "       #####" << RED << "$% %$%$%" << DARKGRAY << "## " << RESET;
    gotoXY(x, y + 6); cout << YELLOW << "         @" << DARKGRAY << " ##" << RED << "$ $%$%$%" << DARKGRAY << "##" << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "   @@@@@@" << RESET << YELLOW << "@@@" << DARKGRAY << "##" << RED << "$%" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##" << RESET;
    gotoXY(x, y + 8); cout << YELLOW << "         @" << DARKGRAY << "  ##### #####" << RESET;
}

void dibujarAssasinDerechaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "       #####        " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "       # " << RED << "#" << BROWN << "  ####    " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "      ##       ##   " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "  #####      ####   " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << " ##" << RED << "$%$%$ $%" << DARKGRAY << "#####    " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << "##" << RED << "$%$%$% %" << DARKGRAY << "## " << RESET << YELLOW << "@      " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << "##" << RED << "$%" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##" << RESET << YELLOW << "@@@" << DARKGRAY << "@@@@@@" << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << "##### #####  " << RESET << YELLOW << "@      " << RESET;
}

void dibujarAssasinArribaAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         ##### " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "         # " << RED << "#" << BROWN << "  #" << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "        ##     " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "   ######      " << DARKGRAY << "@       " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << "  ##" << RED << "$%$%$ %$" << DARKGRAY << "##" << RESET << YELLOW << "@@@      " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << " ##" << RED << "$%$%$% %" << DARKGRAY << "## " << RESET << YELLOW << " @       " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << " ##" << RED << "$%" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##   " << RESET << YELLOW << "@       " << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << " ##### #####           " << RESET;
}

void dibujarAssasinAbajoAtacar(int x, int y) {
    gotoXY(x, y + 1); cout << BROWN << "         #####       " << RESET;
    gotoXY(x, y + 2); cout << BROWN << "         # " << RED << "#" << YELLOW << "  @" << BROWN << "#     " << RESET;
    gotoXY(x, y + 3); cout << BROWN << "        ##    " << YELLOW << "@" << BROWN << "##    " << RESET;
    gotoXY(x, y + 4); cout << BROWN << "   ######   #" << YELLOW << "@@@" << BROWN << "#    " << RESET;
    gotoXY(x, y + 5); cout << DARKGRAY << "  ##" << RED << "$%$%$ $%" << DARKGRAY << "##@      " << RESET;
    gotoXY(x, y + 6); cout << DARKGRAY << " ##" << RED << "$$%$%$ $" << DARKGRAY << "## @      " << RESET;
    gotoXY(x, y + 7); cout << DARKGRAY << " ##" << RED << "$%" << DARKGRAY << "###" << RED << "$%" << DARKGRAY << "##  @      " << RESET;
    gotoXY(x, y + 8); cout << DARKGRAY << " ##### ####   @      " << RESET;
}

// DIBUJOS XD
void borrarJugador(int x, int y, int alto, int ancho) {
    gotoXY(x, y + 1); cout << "                         ";
    gotoXY(x, y + 2); cout << "                         ";
    gotoXY(x, y + 3); cout << "                         ";
    gotoXY(x, y + 4); cout << "                         ";
    gotoXY(x, y + 5); cout << "                         ";
    gotoXY(x, y + 6); cout << "                         ";
    gotoXY(x, y + 7); cout << "                         ";
    gotoXY(x, y + 8); cout << "                         ";
}

void dibujarArdillaBatalla(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1); cout << "     @@@@@@      @@@@   @@   ";
    gotoXY(x, y + 2); cout << "   @@      @@   @   @   @@   ";
    gotoXY(x, y + 3); cout << " @            @@    @@@@@@   ";
    gotoXY(x, y + 4); cout << "@              @          @@@";
    gotoXY(x, y + 5); cout << " @             @    ##    ##@";
    gotoXY(x, y + 6); cout << "   @          @     ##    ##@";
    gotoXY(x, y + 7); cout << "    @      @@@           @@@@";
    gotoXY(x, y + 8); cout << "   @@     @@               @ ";
    gotoXY(x, y + 9); cout << "  @@      @        @@@   @  @";
    gotoXY(x, y + 10); cout << " @      @@            @@  @@ ";
    gotoXY(x, y + 11); cout << " @     @          @       @  ";
    gotoXY(x, y + 12); cout << " @@    @           @    @ @@ ";
    gotoXY(x, y + 13); cout << "   @   @           @      @  ";
    gotoXY(x, y + 14); cout << "    @   @         @ @   @@   ";
    gotoXY(x, y + 15); cout << "      @@@@@@@@@@@@@@ @@@@@   ";
    cout << RESET;
}

void dibujarArdillaIzquierda(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "   @@   @@@@      @@@@@@     ";
    gotoXY(x, y + 2);  cout << "   @@   @   @   @@      @@   ";
    gotoXY(x, y + 3);  cout << "   @@@@@@    @@            @ ";
    gotoXY(x, y + 4);  cout << "@@@          @              @";
    gotoXY(x, y + 5);  cout << "@##    ##    @             @ ";
    gotoXY(x, y + 6);  cout << "@##    ##     @          @   ";
    gotoXY(x, y + 7);  cout << "@@@@           @@@      @    ";
    gotoXY(x, y + 8);  cout << " @               @@     @@   ";
    gotoXY(x, y + 9);  cout << "@  @   @@@        @      @@  ";
    gotoXY(x, y + 10); cout << " @@  @@            @@      @ ";
    gotoXY(x, y + 11); cout << "  @       @          @     @ ";
    gotoXY(x, y + 12); cout << " @@ @    @           @    @@ ";
    gotoXY(x, y + 13); cout << "  @      @           @   @   ";
    gotoXY(x, y + 14); cout << "   @@   @ @         @   @    ";
    gotoXY(x, y + 15); cout << "   @@@@@ @@@@@@@@@@@@@@      ";
    cout << RESET;
}

void borrarArdilla(int x, int y) {
    gotoXY(x, y + 1); cout << "                             ";
    gotoXY(x, y + 2); cout << "                             ";
    gotoXY(x, y + 3); cout << "                             ";
    gotoXY(x, y + 4); cout << "                             ";
    gotoXY(x, y + 5); cout << "                             ";
    gotoXY(x, y + 6); cout << "                             ";
    gotoXY(x, y + 7); cout << "                             ";
    gotoXY(x, y + 8); cout << "                             ";
    gotoXY(x, y + 9); cout << "                             ";
    gotoXY(x, y + 10); cout << "                             ";
    gotoXY(x, y + 11); cout << "                             ";
    gotoXY(x, y + 12); cout << "                             ";
    gotoXY(x, y + 13); cout << "                             ";
    gotoXY(x, y + 14); cout << "                             ";
    gotoXY(x, y + 15); cout << "                             ";
}

void dibujarZorro(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << "                   @@@             @@@@ ";
    gotoXY(x, y + 2);  cout << "                @@@   @@@        @@@  @@";
    gotoXY(x, y + 3);  cout << "                @@      @@@@@@@@@@    @@";
    gotoXY(x, y + 4);  cout << "                @@                    @@";
    gotoXY(x, y + 5);  cout << "     @@@@@      @@                    @@";
    gotoXY(x, y + 6);  cout << "   @@@  @@       @@                  @@ ";
    gotoXY(x, y + 7);  cout << "  @@    @@       @@   @@@      @@@   @@ ";
    gotoXY(x, y + 8);  cout << " @@@    @@       @@   @@@      @@@   @@ ";
    gotoXY(x, y + 9);  cout << "@@       @@@@   @@                   @@@";
    gotoXY(x, y + 10); cout << "@@        @@@@   @@      @@@@       @@@ ";
    gotoXY(x, y + 11); cout << "@@            @@  @@@     @@       @@@  ";
    gotoXY(x, y + 12); cout << "@@@           @@    @@@         @@@@    ";
    gotoXY(x, y + 13); cout << "  @@          @@@@@@@           @@@     ";
    gotoXY(x, y + 14); cout << "   @@@        @@                 @@@    ";
    gotoXY(x, y + 15); cout << "     @@@     @                   @@@    ";
    gotoXY(x, y + 16); cout << "       @@@@@@@                   @@@    ";
    gotoXY(x, y + 17); cout << "             @@@@@@@@@@@@@@@@@@@@@@     ";
    gotoXY(x, y + 18); cout << "              @@@@ @@@@  @@@@  @@@@     ";
    gotoXY(x, y + 19); cout << "               @@   @@    @@    @@      ";
    cout << RESET;
}

void dibujarZorroIzquierda(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << " @@@@             @@@                   ";
    gotoXY(x, y + 2);  cout << "@@  @@@        @@@   @@@                ";
    gotoXY(x, y + 3);  cout << "@@    @@@@@@@@@@      @@                ";
    gotoXY(x, y + 4);  cout << "@@                    @@                ";
    gotoXY(x, y + 5);  cout << "@@                    @@      @@@@@     ";
    gotoXY(x, y + 6);  cout << " @@                  @@       @@  @@@   ";
    gotoXY(x, y + 7);  cout << " @@   @@@      @@@   @@       @@    @@  ";
    gotoXY(x, y + 8);  cout << " @@   @@@      @@@   @@       @@    @@@ ";
    gotoXY(x, y + 9);  cout << "@@@                   @@   @@@@       @@";
    gotoXY(x, y + 10); cout << " @@@       @@@@      @@   @@@@        @@";
    gotoXY(x, y + 11); cout << "  @@@       @@     @@@  @@@           @@";
    gotoXY(x, y + 12); cout << "    @@@@         @@@    @@            @@";
    gotoXY(x, y + 13); cout << "     @@@          @@@@@@@@          @@  ";
    gotoXY(x, y + 14); cout << "    @@@                           @@@   ";
    gotoXY(x, y + 15); cout << "    @@@                         @@@     ";
    gotoXY(x, y + 16); cout << "    @@@                   @@@@@@        ";
    gotoXY(x, y + 17); cout << "     @@@@@@@@@@@@@@@@@@@@@@             ";
    gotoXY(x, y + 18); cout << "     @@@@  @@@@   @@@@ @@@@             ";
    gotoXY(x, y + 19); cout << "      @@    @@     @@   @@              ";
    cout << RESET;
}

void sol(int x, int y) {
    cout << YELLOW;
    gotoXY(x, y + 1);   cout << "           ##    ##   ##           ";
    gotoXY(x, y + 2);   cout << "      #    ###   ##  ###           ";
    gotoXY(x, y + 3);   cout << "       ##   ### ### ###   ###      ";
    gotoXY(x, y + 4);   cout << "        ### ##### ##### ####       ";
    gotoXY(x, y + 5);   cout << "   #### ###################  ####  ";
    gotoXY(x, y + 6);   cout << "     #######           ########    ";
    gotoXY(x, y + 7);   cout << " ########                 #########";
    gotoXY(x, y + 8);   cout << "     ###                   ###     ";
    gotoXY(x, y + 9);   cout << "########                   ########";
    gotoXY(x, y + 10);  cout << "  ######                   ###     ";
    gotoXY(x, y + 11);  cout << "   #####                   ######  ";
    gotoXY(x, y + 12);  cout << "#########                 #########";
    gotoXY(x, y + 13);  cout << "    #########         #########    ";
    gotoXY(x, y + 14);  cout << "  ###   ###################   ###  ";
    gotoXY(x, y + 15);  cout << "       ###  ### ### ###  ###       ";
    gotoXY(x, y + 16);  cout << "      ##   ###  ###  ###   ##      ";
    gotoXY(x, y + 17);  cout << "           ###   ##  ###           ";
    gotoXY(x, y + 18);  cout << "                 #                 ";
    cout << RESET;
}

void arbusto(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "            ##########            ";
    gotoXY(x, y + 2);  cout << "       ######        #######      ";
    gotoXY(x, y + 3);  cout << "  #####    ##    ##         ##    ";
    gotoXY(x, y + 4);  cout << "  ##   ##                ##   ##  ";
    gotoXY(x, y + 5);  cout << "##        ###        ###       ###";
    gotoXY(x, y + 6);  cout << " ###        ##      ##        ### ";
    gotoXY(x, y + 7);  cout << "   ############################   ";
    cout << RESET;
}

void arbol(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);   cout << "         ##########    ######       ";
    gotoXY(x, y + 2);   cout << "        #          ####      ##     ";
    gotoXY(x, y + 3);   cout << " #######                     #      ";
    gotoXY(x, y + 4);   cout << "#              ##           ######  ";
    gotoXY(x, y + 5);   cout << "#          #####                  # ";
    gotoXY(x, y + 6);   cout << " ####       ####      ##          ##";
    gotoXY(x, y + 7);   cout << "  ##        # #      ##          ## ";
    gotoXY(x, y + 8);   cout << " #     ###  ####    ##   #   ###    ";
    gotoXY(x, y + 9);   cout << " #    # ###### #   # #####     ##   ";
    gotoXY(x, y + 10);  cout << " ####    ####  #####          ##    ";
    cout << RESET;
    cout << BROWN;
    gotoXY(x, y + 11);  cout << "           #     ##"; cout << RESET; cout << GREEN << " ##########      "; cout << RESET;
    cout << BROWN;
    gotoXY(x, y + 12);  cout << "           ##    #                  ";
    gotoXY(x, y + 13);  cout << "            #   #                   ";
    gotoXY(x, y + 14);  cout << "            #   ##                  ";
    gotoXY(x, y + 15);  cout << "           ##    #                  ";
    gotoXY(x, y + 16);  cout << "           #     ##                 ";
    gotoXY(x, y + 17);  cout << "           #      #                 ";
    gotoXY(x, y + 18);  cout << "          #        #                ";
    gotoXY(x, y + 19);  cout << "         ############               ";
    cout << RESET;
}

void bloque1(int x, int y) {
    gotoXY(x, y + 1); cout << "|___|";
    gotoXY(x, y + 2); cout << "__|__";
}

void bloque2(int x, int y) {
    gotoXY(x, y + 1); cout << "L_L_L";
    gotoXY(x, y + 2); cout << "_L_L_";
}

void bloque3(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1); cout << " _______ ";
    gotoXY(x, y + 2); cout << "]_______]";
    cout << RESET;
}

void bloque4(int x, int y, char* color) {
    cout << color;
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "]_]";
    cout << RESET;
}

void rio(int x, int y, char* color) {
    cout << color;
    gotoXY(x, y + 1); cout << "\\ / \\ / \\ / ";
    gotoXY(x, y + 2); cout << " \\   \\   \\  ";
    gotoXY(x, y + 3); cout << "/ / / / / / ";
    cout << RESET;
}

void dibujarCapibaraIzquierda3(int x, int y) {
    gotoXY(x, y + 1); cout << "     #####       ";
    gotoXY(x, y + 2); cout << " ####  # #       ";
    gotoXY(x, y + 3); cout << "##       ##      ";
    gotoXY(x, y + 4); cout << "####      #####  ";
    gotoXY(x, y + 5); cout << " #####        ## ";
    gotoXY(x, y + 6); cout << "     ##       ## ";
    gotoXY(x, y + 7); cout << "     ##  ###   ##";
    gotoXY(x, y + 8); cout << "    #####   #####";
}

void arbusto_pequenio(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "     #######      ";
    gotoXY(x, y + 2);  cout << "  ####     ####   ";
    gotoXY(x, y + 3);  cout << "##   #   ##    ## ";
    gotoXY(x, y + 4);  cout << "##################";
    cout << RESET;
}

void arbol_pequenio(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);   cout << "      ##########       ";
    gotoXY(x, y + 2);   cout << "     #          ##     ";
    gotoXY(x, y + 3);   cout << " ####             #    ";
    gotoXY(x, y + 4);   cout << "#                 ###  ";
    gotoXY(x, y + 5);   cout << "#                    # ";
    gotoXY(x, y + 6);   cout << " #                    #";
    gotoXY(x, y + 7);   cout << "  ####       ######### ";
    cout << RESET;
    cout << BROWN;
    gotoXY(x, y + 8);   cout << "      ##    #          ";
    gotoXY(x, y + 9);   cout << "       #   #           ";
    gotoXY(x, y + 10);  cout << "       #   ##          ";
    gotoXY(x, y + 11);  cout << "      #      #         ";
    gotoXY(x, y + 12);  cout << "     #        #        ";
    gotoXY(x, y + 13);  cout << "    ############       ";
    cout << RESET;
}

void dibujarRectangulo(int x, int y) {
    gotoXY(x, y + 1); cout << " ________ ";
    gotoXY(x, y + 2); cout << "|        |";
    gotoXY(x, y + 3); cout << "|________|";
}

void piso1(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque1(x, y);
        x += 5;
    }
}

void piso2(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque2(x, y);
        x += 5;
    }
}

void piso3(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque3(x, y);
        x += 9;
    }
}

void pasto(int x, int y, int longitud, char* color) {
    cout << color;
    gotoXY(x, y + 1);  cout << "\\ | /    ";
    cout << RESET;
}

void piso4(int x, int y, int longitud, char* color) {
    for (int i = 0; i < longitud; i++) {
        pasto(x, y, longitud, color);
        x += 10;
    }
}

void dibujarZorroAtaque(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << "      @@@            @@@    ";
    gotoXY(x, y + 2);  cout << "     @@@@@          @@@@@   ";
    gotoXY(x, y + 3);  cout << "   @@@@@@@@@@@@@@@@@@@@@@@@ ";
    gotoXY(x, y + 4);  cout << "   @@@@@@            @@@@@@ ";
    gotoXY(x, y + 5);  cout << "   @@@@                @@@@ ";
    gotoXY(x, y + 6);  cout << "    @@                  @@  ";
    gotoXY(x, y + 7);  cout << "    @@   @@       @@    @@  ";
    gotoXY(x, y + 8);  cout << "    @@   @@       @@    @@  ";
    gotoXY(x, y + 9);  cout << "   @@                    #@ ";
    gotoXY(x, y + 10); cout << "    @@                  @@@@";
    gotoXY(x, y + 11); cout << "     @@      @@@       @    ";
    gotoXY(x, y + 12); cout << "       @@@@         @@@     ";
    gotoXY(x, y + 13); cout << "  @@@@@@@@@@@      @@@      ";
    gotoXY(x, y + 14); cout << " @           @@@@        @@ ";
    gotoXY(x, y + 15); cout << "@                @@@@  @@  @";
    gotoXY(x, y + 16); cout << "@                    @@    @";
    gotoXY(x, y + 17); cout << "@                         @ ";
    gotoXY(x, y + 18); cout << " @                     @@@  ";
    gotoXY(x, y + 19); cout << "  @@@@@@@@@@@@@@@@@@@@@     ";
    cout << RESET;
}

void corazon(int x, int y) {
    cout << RED;
    gotoXY(x, y + 1); cout << " @@  @@ ";
    gotoXY(x, y + 2); cout << "@@@@@@@@";
    gotoXY(x, y + 3); cout << " @@@@@@ ";
    gotoXY(x, y + 4); cout << "  @@@@  ";
    gotoXY(x, y + 5); cout << "   @@   ";
    cout << RESET;
}

void aguilaxd1(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "@@@                                                                                   @@@@";
    gotoXY(x, y + 2);  cout << "@  @@@                                                                              @@   @";
    gotoXY(x, y + 3);  cout << " @    @@@@@@                                                                  @@@@@@    @ ";
    gotoXY(x, y + 4);  cout << " @          @@@@@@                                                      @@@@@@          @ ";
    gotoXY(x, y + 5);  cout << " @                @@@@@@                   @@@@                    @@@@@                @ ";
    gotoXY(x, y + 6);  cout << "  @                     @@@@             @@    @@             @@@@@                   @@  ";
    gotoXY(x, y + 7);  cout << "   @                        @@@@@@      @ " << WHITE << " _  _ " << BROWN << " @      @@@@@@                        @   ";
    gotoXY(x, y + 8);  cout << "   @                              @@@@@@@ " << WHITE << "|_||_|" << BROWN << " @@@@@@@                              @   ";
    cout << RESET;
    gotoXY(x, y + 9);  cout << BROWN << "    @@                                  " << YELLOW << " \\      / " << BROWN << "                                  @@    " << RESET;
    gotoXY(x, y + 10); cout << BROWN << "      @                                 " << YELLOW << "  \\    /  " << BROWN << "                                 @      " << RESET;
    gotoXY(x, y + 11); cout << BROWN << "       @                                " << YELLOW << "   \\  /   " << BROWN << "                               @@       " << RESET;
    gotoXY(x, y + 12); cout << BROWN << "         @@@                            " << YELLOW << "    \\/    " << BROWN << "                            @@@         ";
    gotoXY(x, y + 13); cout << "            @                                                               @@            ";
    gotoXY(x, y + 14); cout << "              @@                                                          @@              ";
    gotoXY(x, y + 15); cout << "                @@@                                                    @@@                ";
    gotoXY(x, y + 16); cout << "                   @@@@@@@                                      @@@@@@@                   ";
    gotoXY(x, y + 17); cout << "                          @@@@@@@                        @@@@@@@@                         ";
    gotoXY(x, y + 18); cout << "                                 @@@@                @@@@                                 ";
    gotoXY(x, y + 19); cout << "                                    @                @                                    ";
    gotoXY(x, y + 20); cout << "                                     @              @                                     ";
    gotoXY(x, y + 21); cout << "                                    @    @      @    @                                    ";
    gotoXY(x, y + 22); cout << "                                   @    @        @    @                                   ";
    gotoXY(x, y + 23); cout << "                                  @    @  @    @  @    @                                  ";
    gotoXY(x, y + 24); cout << "                                  @   @   @    @   @   @                                  ";
    gotoXY(x, y + 25); cout << "                                  @@@@@   @    @    @@@@                                  ";
    gotoXY(x, y + 26); cout << "                                     @    @    @    @                                     ";
    gotoXY(x, y + 27); cout << "                                      @@@@@    @@@@@                                      ";
    gotoXY(x, y + 28); cout << "                                          @    @                                          ";
    gotoXY(x, y + 29); cout << "                                           @@@@                                           ";
    cout << RESET;
}

void dibujarCapibaraDerecha2(int x, int y) {
    gotoXY(x, y + 1); cout << "       #####     ";
    gotoXY(x, y + 2); cout << "       # #  #### ";
    gotoXY(x, y + 3); cout << "      ##       ##";
    gotoXY(x, y + 4); cout << "  #####      ####";
    gotoXY(x, y + 5); cout << " ##        ##### ";
    gotoXY(x, y + 6); cout << " ##       ##     ";
    gotoXY(x, y + 7); cout << " ##   ###  ##    ";
    gotoXY(x, y + 8); cout << " #####   #####   ";
}

void lobo_ganador(int x, int y) {
    cout << DARKGRAY;
    gotoXY(x, y + 0); cout << "                                                                               @@        ";
    gotoXY(x, y + 1); cout << "                                                                            @@@@@@       ";
    gotoXY(x, y + 2); cout << "                                                                         @@@@@@@@@@      ";
    gotoXY(x, y + 3); cout << "                                                                      @@@@@@@   @@@@     ";
    gotoXY(x, y + 4); cout << "                                                                   @@@@@@         @@     ";
    gotoXY(x, y + 5); cout << "                                                                @@@@@@            @@     ";
    gotoXY(x, y + 6); cout << "                                                  @@@@@@@@@@@@@@@@@@              @@     ";
    gotoXY(x, y + 7); cout << "                                            @@@@@@@@    @@@@   @@@@               @@     ";
    gotoXY(x, y + 8); cout << "                                         @@@@   @@@        @@@@@@@               @@@     ";
    gotoXY(x, y + 9); cout << "                                     @@@@@@    @@@@    @@@@@@@@@@@               @       ";
    gotoXY(x, y + 10); cout << "                                   @@@@@@@@          @@@@   @@@@@@@@            @        ";
    gotoXY(x, y + 11); cout << "                                  @@@@@@@@@@@@@    @@       @ @@@@             @         ";
    gotoXY(x, y + 12); cout << "                                @@@@      @@@   @@     @ @@@  @@              @@         ";
    gotoXY(x, y + 13); cout << "                              @@@@   @@   @   @%    @  @@@   @@               @@    @@@@ ";
    gotoXY(x, y + 14); cout << "                             @@@   @@@      @@@   @@@  @@  #@%                @@  @@@@@@@";
    gotoXY(x, y + 15); cout << "                            @@@@  @@@@     @@@   @@@@  @@  @@%                @@@@@@@@@@@";
    gotoXY(x, y + 16); cout << "                           @@@@@  @@@@    @@@   @@ @@  @@  @@%                  @@@ @@@@ ";
    gotoXY(x, y + 17); cout << "                             @@@@@@@@@   @@@    @@ @@      *@@%                     @@@  ";
    gotoXY(x, y + 18); cout << "                        @@@@@@@@@@@@@    @@@   @@  @@       @@%                   @@@    ";
    gotoXY(x, y + 19); cout << "                      @@@@@@@@       @@  @@@   @@  @@@       @@@                @@@      ";
    gotoXY(x, y + 20); cout << "                     @@@             @@   @@@   @@  @@        @@             @@@@        ";
    gotoXY(x, y + 21); cout << "                 @@@@              @@@@@@  @@@   @  @@@       @@           @@@           ";
    gotoXY(x, y + 22); cout << "              @@@         @@@    @@     @@ @@@@      @@        @          @@             ";
    gotoXY(x, y + 23); cout << "            @@@@       @@@@@@  @@@       @@  @@@     @@@       @        @@@              ";
    gotoXY(x, y + 24); cout << "             @@     @@@    @@@@@         @@@   @@@  @@@@    @  @@      @@@               ";
    gotoXY(x, y + 25); cout << "               @@@         @@@       @@@@@@@@@  @@@@@@@     @@        @@@                ";
    gotoXY(x, y + 26); cout << "                  @@@@@      @@@@@@@@@@@  @@@@@   @@@@@   @ @@     @@@@@@                ";
    gotoXY(x, y + 27); cout << "                        @@@@@@@@@              @   @@@@   @  @@    @@@@@                 ";
    gotoXY(x, y + 28); cout << "                @@@                            @@    @   @@  @@    @@@@@                 ";
    gotoXY(x, y + 29); cout << "              @@@         @@@                            @@  @@@   @@@@@@                ";
    gotoXY(x, y + 30); cout << "           @@@@     @@@@@@         @   @     @          @@@   @@@   @@ @@@               ";
    gotoXY(x, y + 31); cout << "          @@@@@@@@@@@@@@          @    @      @@        @@     @@@   @  @@               ";
    gotoXY(x, y + 32); cout << "              @@@@  @@@    @     %@   @@@     @@@      @@@       @@@@@@   @              ";
    gotoXY(x, y + 33); cout << "             @@@#   @@@@@@#    @@@    @@@       @@     @@@   @@     @@@@                 ";
    gotoXY(x, y + 34); cout << "           @@@     @@@@      @@@@     @@@@       @@@   @@@     @@       @                ";
    gotoXY(x, y + 35); cout << "          @@@    @@@@      @@@@      @@@ @@@      @@@@@@@@@    @@@@                      ";
    gotoXY(x, y + 36); cout << "        @@@@  @@@  @@    @@@@      @@@@   @@@@      @@@@@@@     @@@@                     ";
    gotoXY(x, y + 37); cout << "      @@@@@@@@@    @    @@@@     @@@        @@@@        @@@@    @@@@@                    ";
    gotoXY(x, y + 38); cout << "    @@@@@@@@@         @@@@   @@@@@           @@@@          @@    @@@@@@                  ";
    gotoXY(x, y + 39); cout << "        @@@         @@@@   @@@@@     @@@@@     @@@@    @     @   @@@ @@@                 ";
    gotoXY(x, y + 40); cout << "      @@@@        @@@@    @@@@@    @@@@ @@@     @@@@    @@       @@@  @@@                ";
    gotoXY(x, y + 41); cout << "    @@@@    @@   @@@@    @@@@@   @@@@    @@@     @@@@    @@       @@   @@@               ";
    gotoXY(x, y + 42); cout << "   @@@   @@@    @@@@    @@@@@     @@@@    @@@     @@@@   @@       @@    @@               ";
    gotoXY(x, y + 43); cout << "  @@@@@@@@     @@@@   @@@@@@@@@@@         @@@@     @@@@  @@@  @@  @@@    @               ";
    gotoXY(x, y + 44); cout << " @@  @@@@     @@@@        @@@@@@@@@@@@@@@@@@@      @@@@@ @@@   @@ @@@                    ";
    gotoXY(x, y + 45); cout << "    @@@@    @@@@%                 @@@@@@@@@        @@@@@@@@@   @@ @@@                    ";
    gotoXY(x, y + 46); cout << "   @@@     @@@@@@@@@@@%                          @@@@@@@@@@   @@@@@@@                    ";
    gotoXY(x, y + 47); cout << "  @@       @@@@@@@@@@@@@@@@@@@                @@@@@@  %@@@@   @@@@@@@                    ";
    gotoXY(x, y + 48); cout << "         @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     %@@@   @@  @@@@                   ";
    gotoXY(x, y + 49); cout << "        @@@@@@            @@@@@@@@@@@@@@@@@@@@@@@      @@@   @@@  @@@@                   ";
    gotoXY(x, y + 50); cout << "       @@@                @@@@@@@@@@@     @@@@@        @@    @@    @@                    ";
    gotoXY(x, y + 51); cout << "      @                  @@@@@          @@@@@          @@   @@     @@                    ";
    gotoXY(x, y + 52); cout << "                       @@@@           @@@             @@   @@      @                     ";
    cout << RESET;
}

void trofeo(int x, int y) {
    cout << YELLOW;
    gotoXY(x, y + 1);  cout << "       ###   ############   ###        ";
    gotoXY(x, y + 2);  cout << "       #######          #######        ";
    gotoXY(x, y + 3);  cout << "       ###                  ###        ";
    gotoXY(x, y + 4);  cout << "      ##                      ##       ";
    gotoXY(x, y + 5);  cout << "      ##                      ##       ";
    gotoXY(x, y + 6);  cout << "      ##                      ##       ";
    gotoXY(x, y + 7);  cout << "   ###   ####            ####   ###    ";
    gotoXY(x, y + 8);  cout << "   ###         #########        ###    ";
    gotoXY(x, y + 9);  cout << "   ###       ##         ##      ###    ";
    gotoXY(x, y + 10); cout << "   ###       # ######### #      ###    ";
    gotoXY(x, y + 11); cout << "  ##         #   #####   #         ##  ";
    gotoXY(x, y + 12); cout << "  ##        #             #        ##  ";
    gotoXY(x, y + 13); cout << "  ##        #             #        ##  ";
    gotoXY(x, y + 14); cout << "  ##        #             #        ##  ";
    gotoXY(x, y + 15); cout << "  ##        #             #        ##  ";
    gotoXY(x, y + 16); cout << "   ###      #  ########   #     ###    ";
    gotoXY(x, y + 17); cout << "      ###    #############    ###      ";
    gotoXY(x, y + 18); cout << "         #####################         ";
    gotoXY(x, y + 19); cout << "                @@@@@@@                ";
    gotoXY(x, y + 20); cout << "       @@@@@@@@@@@@@@@@@@@@@@@@@       ";
    gotoXY(x, y + 21); cout << "           @@@@@@@@@@@@@@@@@           ";
    gotoXY(x, y + 22); cout << "           @@             @@           ";
    gotoXY(x, y + 23); cout << "           @@ FELICIDADES @@           ";
    gotoXY(x, y + 24); cout << "           @@             @@           ";
    gotoXY(x, y + 25); cout << "           @@@@@@@@@@@@@@@@@           ";
    gotoXY(x, y + 26); cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ";
    gotoXY(x, y + 27); cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    gotoXY(x, y + 28); cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    cout << RESET;
}

void trofeo_perdedor(int x, int y) {
    cout << YELLOW;
    gotoXY(x, y + 1);  cout << "        ##   #### ### ###   # #        ";
    gotoXY(x, y + 2);  cout << "       ## ####          ## ###         ";
    gotoXY(x, y + 3);  cout << "       # #                  ###        ";
    gotoXY(x, y + 4);  cout << "      ##                      ##       ";
    gotoXY(x, y + 5);  cout << "      #                       ##       ";
    gotoXY(x, y + 6);  cout << "       #                       #       ";
    gotoXY(x, y + 7);  cout << "   ##    # ##            # ##   # #    ";
    gotoXY(x, y + 8);  cout << "   # #         # ## # ##         #     ";
    gotoXY(x, y + 9);  cout << "    ##        #         ##      # #    ";
    gotoXY(x, y + 10); cout << "   # #       # ## # # ## #      ##     ";
    gotoXY(x, y + 11); cout << "   #         #   # # #   #         #   ";
    gotoXY(x, y + 12); cout << "  #         #             #         #  ";
    gotoXY(x, y + 13); cout << "  #         #             #        ##  ";
    gotoXY(x, y + 14); cout << "   #                      #        #   ";
    gotoXY(x, y + 15); cout << "  ##        #             #         #  ";
    gotoXY(x, y + 16); cout << "   ###      #   ### ###         ###    ";
    gotoXY(x, y + 17); cout << "      ###    ### # # ####     ###      ";
    gotoXY(x, y + 18); cout << "         ######## # # ## #####         ";
    gotoXY(x, y + 19); cout << "                 @ @@@                 ";
    gotoXY(x, y + 20); cout << "       @@@ @@@@ @@@@ @@ @@@@@@@       ";
    gotoXY(x, y + 21); cout << "           @@@ @@@@@@ @@ @@@           ";
    gotoXY(x, y + 22); cout << "            @             @@           ";
    gotoXY(x, y + 23); cout << "           @    pendejo   @@           ";
    gotoXY(x, y + 24); cout << "           @@             @@           ";
    gotoXY(x, y + 25); cout << "           @@@ @@ @@@@ @@@@@           ";
    gotoXY(x, y + 26); cout << "     @ @@ @@@@@  @@@@@@ @@@ @@@ @@     ";
    gotoXY(x, y + 27); cout << "@@@@@ @@@@ @@@@  @@@@@@@ @ @ @ @@@@@@@@";
    gotoXY(x, y + 28); cout << "@@@@ @@@@@@ @@ @@ @@@@@@@ @@@@@@ @@@@@@";
    cout << RESET;
}

void enemigo_durmiente(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << "      @@@            @@@    ";
    gotoXY(x, y + 2);  cout << "     @@@@@          @@@@@   ";
    gotoXY(x, y + 3);  cout << "   @@@@@@@@@@@@@@@@@@@@@@@@ ";
    gotoXY(x, y + 4);  cout << "   @@@@@@            @@@@@@ ";
    gotoXY(x, y + 5);  cout << "   @@@@                @@@@ ";
    gotoXY(x, y + 6);  cout << "    @@                  @@  ";
    gotoXY(x, y + 7);  cout << "    @@   @@       @@    @@  ";
    gotoXY(x, y + 8);  cout << "    @@   @@       @@    @@  ";
    gotoXY(x, y + 9);  cout << "   @@                    #@ ";
    gotoXY(x, y + 10); cout << "    @@                  @@@@";
    gotoXY(x, y + 11); cout << "     @@      @@@       @    ";
    gotoXY(x, y + 12); cout << "       @@@@         @@@     ";
    gotoXY(x, y + 13); cout << "  @@@@@@@@@@@      @@@      ";
    gotoXY(x, y + 14); cout << " @           @@@@        @@ ";
    gotoXY(x, y + 15); cout << "@                @@@@  @@  @";
    gotoXY(x, y + 16); cout << "@                    @@    @";
    gotoXY(x, y + 17); cout << "@                         @ ";
    gotoXY(x, y + 18); cout << " @                     @@@  ";
    gotoXY(x, y + 19); cout << "  @@@@@@@@@@@@@@@@@@@@@     ";
    cout << RESET;
}

void lobo_perdedor(int x, int y) {
    cout << DARKGRAY;
    gotoXY(x, y + 1);  cout << "                             @@@@@                                             ";
    gotoXY(x, y + 2);  cout << "                     @@@@@@                                                    ";
    gotoXY(x, y + 3);  cout << "                 @@@@@      @@@           @@@@                                 ";
    gotoXY(x, y + 4);  cout << "              @@@@@                             @@@                            ";
    gotoXY(x, y + 5);  cout << "           @@@@@                                    @@                         ";
    gotoXY(x, y + 6);  cout << "         @@@@@                                         @@@                     ";
    gotoXY(x, y + 7);  cout << "       @@@@@                                             @@                    ";
    gotoXY(x, y + 8);  cout << "      @@@@                                              @  @@                  ";
    gotoXY(x, y + 9);  cout << "     @@@                                                  @  @                 ";
    gotoXY(x, y + 10); cout << "    @@@                                                     @ @                ";
    gotoXY(x, y + 11); cout << "   @@@                                                       @                 ";
    gotoXY(x, y + 12); cout << "  @@@@                                                        @                ";
    gotoXY(x, y + 13); cout << " @@@@@                     @@                                                  ";
    gotoXY(x, y + 14); cout << " @@@@                     @@@@@@@                                 @            ";
    gotoXY(x, y + 15); cout << "@@@@@                      @@@@  @@@                                           ";
    gotoXY(x, y + 16); cout << "@@@@                         @@@   @@@                             @           ";
    gotoXY(x, y + 17); cout << "@@@@ @                    @      +    @@@   @                                  ";
    gotoXY(x, y + 18); cout << "@@@@ @                    @                    @@                              ";
    gotoXY(x, y + 19); cout << "@@@@ @                    @@              @@@      @@                          ";
    gotoXY(x, y + 20); cout << "@#@@ @                      @@@            @@ @@      @@                       ";
    gotoXY(x, y + 21); cout << "@@@@ @                       @@@       @       @@  #@    @       @@            ";
    gotoXY(x, y + 22); cout << "@@@@ @@   @                     @@@      @@@@@@@    @@@   @@@@@@@@             ";
    gotoXY(x, y + 23); cout << "@@@@# @   @                        @@        @@@@@@@@@@@   @@@@@@@             ";
    gotoXY(x, y + 24); cout << " @@@@ @@@@@@                      @  @              @@@@@   @@@                ";
    gotoXY(x, y + 25); cout << " @@@@@  @@@@@@                      @                 #@@@  @  @@@             ";
    gotoXY(x, y + 26); cout << "  @@@@  @@@@@@@                     @@      @     @@   @@@@  @   @@@           ";
    gotoXY(x, y + 27); cout << "   @@@@  @@@@@@@@                    @@    @@       @@@@@@@@@       @@@@@@     ";
    gotoXY(x, y + 28); cout << "    @@@@  @@@@@@@@@                   @    @@   @      @@@@@@@@@@@    @@@      ";
    gotoXY(x, y + 29); cout << "     @@@@  @@@@@@@@@@@                %@   @@@  @@                  @@@        ";
    gotoXY(x, y + 30); cout << "       @@@@  @@@    @@@@@              @   @@@@  @@@  @@    @@@@@@@@@          ";
    gotoXY(x, y + 31); cout << "        @@@@  @@@     @@@@@@@       @  @@  @@@@   @@@   @@     @@              ";
    gotoXY(x, y + 32); cout << "          @@@@  @@      @@@@        @  @@  @@@@@@@  @@@@   @%@@@@@             ";
    gotoXY(x, y + 33); cout << "             @@@  @@     @@@@@      @  @@  @@@    @@@@@@@@@        @@          ";
    gotoXY(x, y + 34); cout << "               @@@@@     @   @@@   @@  @@@ @@@@        @@@@@@@@                ";
    gotoXY(x, y + 35); cout << "                   @@@         @@  @@ @@@@# @@@@       @@@@  @@@@@@@@@@*       ";
    gotoXY(x, y + 36); cout << "                        @@@@       @  @@@@@@  @@@@@     @@@     @@@@           ";
    gotoXY(x, y + 37); cout << "                                   @@  @ @@     @@@@@   @@@@      @@@  @       ";
    gotoXY(x, y + 38); cout << "                                   @@  @@   @@@@@@@@@@   @@@ @     @@@ @@      ";
    gotoXY(x, y + 39); cout << "                                   @@   @@ @@      %@@   @@@  @    @@@ @@@@    ";
    gotoXY(x, y + 40); cout << "                                   @@@   @@@@  @@   @@@  @@@@ @@@@@@@@ @@ @@@  ";
    gotoXY(x, y + 41); cout << "                                   @@@@     @ @@@@@  @@  @@@@   @@@%@  @@@   @@";
    gotoXY(x, y + 42); cout << "                                    @@@@         @@  @   @@@@  @@@@@@  @@  @@  ";
    gotoXY(x, y + 43); cout << "                                    @@ @@@@@   @@@  @   @@@@    @@@@  @@@      ";
    gotoXY(x, y + 44); cout << "                                    @@    @@@@@@@      @@@@     @@@   @@       ";
    gotoXY(x, y + 45); cout << "                                    @@      @@@@      @@@@      @@   @@        ";
    gotoXY(x, y + 46); cout << "                                    @@     @@@@     @@@@@@@@   @   @@@         ";
    gotoXY(x, y + 47); cout << "                                     @          @@@@@@@@@@@@@    @@@@       @  ";
    gotoXY(x, y + 48); cout << "                                     @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@       @   ";
    gotoXY(x, y + 49); cout << "                                     @@  @@@@@               @@@@@@       @@   ";
    gotoXY(x, y + 50); cout << "                                      @    @@@   @@@@@@@@@@@  @@@@@     @@@@   ";
    gotoXY(x, y + 51); cout << "                                           @@@@  @@@       @@  @@@@@@@@@@@@    ";
    gotoXY(x, y + 52); cout << "                                            @@@  @@@        @@ @@@@@@@@@@@   @ ";
    gotoXY(x, y + 53); cout << "                                             @@@  @@@       @  @@@@@@@@@    @  ";
    gotoXY(x, y + 54); cout << "                                              @@@   @@@       @@@  @@@     @   ";
    gotoXY(x, y + 55); cout << "                                               @@@@   @@@@@@@@@@@@@      @@    ";
    gotoXY(x, y + 56); cout << "                                                 @@@@                 @@@      ";
    gotoXY(x, y + 57); cout << "                                                   @@@@@@@       @@@@@@        ";
    gotoXY(x, y + 58); cout << "                                                    @@@@@@@@@@@@@@@            ";
    cout << RESET;
}

void dibujarBellota(int x, int y) {
    cout << BROWN;
    gotoXY(x, y + 1);  cout << "#@";
    gotoXY(x, y + 2);  cout << "@#";
    cout << RESET;
}

void BorrarBellota(int x, int y) {
    gotoXY(x, y + 1);  cout << "  ";
    gotoXY(x, y + 2);  cout << "  ";
}

// Funciones del zorro
void dibujarZorroEnemigo(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << "                   @@@             @@@@ ";
    gotoXY(x, y + 2);  cout << "                @@@   @@@        @@@  @@";
    gotoXY(x, y + 3);  cout << "                @@      @@@@@@@@@@    @@";
    gotoXY(x, y + 4);  cout << "                @@                    @@";
    gotoXY(x, y + 5);  cout << "     @@@@@      @@                    @@";
    gotoXY(x, y + 6);  cout << "   @@@  @@       @@                  @@ ";
    gotoXY(x, y + 7);  cout << "  @@    @@       @@   @@@      @@@   @@ ";
    gotoXY(x, y + 8);  cout << " @@@    @@       @@   @@@      @@@   @@ ";
    gotoXY(x, y + 9);  cout << "@@       @@@@   @@                   @@@";
    gotoXY(x, y + 10); cout << "@@        @@@@   @@      @@@@       @@@ ";
    gotoXY(x, y + 11); cout << "@@            @@  @@@     @@       @@@  ";
    gotoXY(x, y + 12); cout << "@@@           @@    @@@         @@@@    ";
    gotoXY(x, y + 13); cout << "  @@          @@@@@@@           @@@     ";
    gotoXY(x, y + 14); cout << "   @@@        @@                 @@@    ";
    gotoXY(x, y + 15); cout << "     @@@     @                   @@@    ";
    gotoXY(x, y + 16); cout << "       @@@@@@@                   @@@    ";
    gotoXY(x, y + 17); cout << "             @@@@@@@@@@@@@@@@@@@@@@     ";
    gotoXY(x, y + 18); cout << "              @@@@ @@@@  @@@@  @@@@     ";
    gotoXY(x, y + 19); cout << "               @@   @@    @@    @@      ";
    cout << RESET;
}

void borrarZorro(int x, int y) {
    gotoXY(x, y + 1);  cout << "                                        ";
    gotoXY(x, y + 2);  cout << "                                        ";
    gotoXY(x, y + 3);  cout << "                                        ";
    gotoXY(x, y + 4);  cout << "                                        ";
    gotoXY(x, y + 5);  cout << "                                        ";
    gotoXY(x, y + 6);  cout << "                                        ";
    gotoXY(x, y + 7);  cout << "                                        ";
    gotoXY(x, y + 8);  cout << "                                        ";
    gotoXY(x, y + 9);  cout << "                                        ";
    gotoXY(x, y + 10); cout << "                                        ";
    gotoXY(x, y + 11); cout << "                                        ";
    gotoXY(x, y + 12); cout << "                                        ";
    gotoXY(x, y + 13); cout << "                                        ";
    gotoXY(x, y + 14); cout << "                                        ";
    gotoXY(x, y + 15); cout << "                                        ";
    gotoXY(x, y + 16); cout << "                                        ";
    gotoXY(x, y + 17); cout << "                                        ";
    gotoXY(x, y + 18); cout << "                                        ";
    gotoXY(x, y + 19); cout << "                                        ";
}

// Nivel cocodrilos
void miniCocodrile(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "                           @@@@@@@                          ";
    gotoXY(x, y + 2);  cout << "                @@@@@ @@@@@@     @@@@@@@@@                  ";
    gotoXY(x, y + 3);  cout << "             @@@@   @@@                  @@@@               ";
    gotoXY(x, y + 4);  cout << "         @@@@ ##                            @@@@@           ";
    gotoXY(x, y + 5);  cout << "  @@@@@@@@                                      @@@@        ";
    gotoXY(x, y + 6);  cout << "@@@@                                                @@@     ";
    gotoXY(x, y + 7);  cout << "@@@                                                    @@   ";
    gotoXY(x, y + 8);  cout << "  @@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@      @@@@@@@@@    @@ ";
    gotoXY(x, y + 9);  cout << "                      @@@@@@         @@@@@@@@        @@   @@";
    gotoXY(x, y + 10); cout << "                                                      @@  @@";
    gotoXY(x, y + 11); cout << "                                                       @@@  ";
    cout << RESET;
}

void miniCocodrileRight(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "                          @@@@@@@                            ";
    gotoXY(x, y + 2);  cout << "                  @@@@@@@@      @@@@@@ @@@@@                 ";
    gotoXY(x, y + 3);  cout << "               @@@                   @@@   @@@@              ";
    gotoXY(x, y + 4);  cout << "           @@@@                             ## @@@@          ";
    gotoXY(x, y + 5);  cout << "      @@@@@@                                      @@@@@@@@   ";
    gotoXY(x, y + 6);  cout << "     @@                                                  @@@@";
    gotoXY(x, y + 7);  cout << "   @@                                                     @@@";
    gotoXY(x, y + 8);  cout << " @@   @@@@@@@@@@      @@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@   ";
    gotoXY(x, y + 9);  cout << "@@   @@        @@@@@@@@         @@@@@@                       ";
    gotoXY(x, y + 10); cout << "@@  @@                                                       ";
    gotoXY(x, y + 11); cout << "  @@@                                                        ";
    cout << RESET;
}

void miniCocodrileAttack(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "@@@@@              @@@@@@@@@@@@@@                           ";
    gotoXY(x, y + 2);  cout << "@@   @@        @@@@@@@@@@@@     @@@@@@@@                    ";
    gotoXY(x, y + 3);  cout << "  @@   @@@@@@@@@@@@@@@          @@@     @@@                 ";
    gotoXY(x, y + 4);  cout << "    @    ##                                @@@@@            ";
    gotoXY(x, y + 5);  cout << "     @                                          @@@@@@      ";
    gotoXY(x, y + 6);  cout << "  @@@@                                                @     ";
    gotoXY(x, y + 7);  cout << "@@@@@@@@@@@@@@@@@    @@@@@@@@@@      @@@@@@@@@@@@@     @    ";
    gotoXY(x, y + 8);  cout << "                @@@@@@        @@@@@@@@            @@    @   ";
    gotoXY(x, y + 9);  cout << "                                                   @@@   @@@";
    gotoXY(x, y + 10); cout << "                                                      @@  @@";
    gotoXY(x, y + 11); cout << "                                                       @@@  ";
    cout << RESET;
}

void miniCocodrileAttackRight(int x, int y) {
    cout << GREEN;
    gotoXY(x, y + 1);  cout << "                           @@@@@@@@@@@@@@             @@@@@";
    gotoXY(x, y + 2);  cout << "                    @@@@@@@@     @@@@@@@@@@@@       @@   @@";
    gotoXY(x, y + 3);  cout << "                 @@@                  @@@@@@@@@@@@@@   @@  ";
    gotoXY(x, y + 4);  cout << "            @@@@@                               ##   @@    ";
    gotoXY(x, y + 5);  cout << "      @@@@@@@                                       @@     ";
    gotoXY(x, y + 6);  cout << "    @@@                                              @@@@  ";
    gotoXY(x, y + 7);  cout << "   @      @@@@@@@@@@@@@      @@@@@@@@@@    @@@@@@@@@@@@@@@@";
    gotoXY(x, y + 8);  cout << "  @     @@            @@@@@@@@        @@@@@@               ";
    gotoXY(x, y + 9);  cout << "@@@  @@@@                                                  ";
    gotoXY(x, y + 10); cout << "@@  @@                                                     ";
    gotoXY(x, y + 11); cout << "  @@@                                                      ";
    cout << RESET;
}

void borrarCocodrile1(int x, int y) {
    gotoXY(x, y + 1);  cout << "                                                             ";
    gotoXY(x, y + 2);  cout << "                                                             ";
    gotoXY(x, y + 3);  cout << "                                                             ";
    gotoXY(x, y + 4);  cout << "                                                             ";
    gotoXY(x, y + 5);  cout << "                                                             ";
    gotoXY(x, y + 6);  cout << "                                                             ";
    gotoXY(x, y + 7);  cout << "                                                             ";
    gotoXY(x, y + 8);  cout << "                                                             ";
    gotoXY(x, y + 9);  cout << "                                                             ";
    gotoXY(x, y + 10); cout << "                                                             ";
    gotoXY(x, y + 11); cout << "                                                             ";
}

void dibujarBolaDeFuego(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1); cout << "    ++ *   ";
    gotoXY(x, y + 2); cout << "** ++++**  ";
    gotoXY(x, y + 3); cout << "***+++++** ";
    gotoXY(x, y + 4); cout << "++++===++++";
    gotoXY(x, y + 5); cout << " ==------= ";
    gotoXY(x, y + 6); cout << "  ==-----  ";
    cout << RESET;
}

void borrarBolaDeFuego(int x, int y) {
    gotoXY(x, y + 1); cout << "           ";
    gotoXY(x, y + 2); cout << "           ";
    gotoXY(x, y + 3); cout << "           ";
    gotoXY(x, y + 4); cout << "           ";
    gotoXY(x, y + 5); cout << "           ";
    gotoXY(x, y + 6); cout << "           ";
}

void sol1(int x, int y) {
    gotoXY(x, y);     cout << "  \\  |  / ";
    gotoXY(x, y + 1); cout << "   .-*-.   ";
    gotoXY(x, y + 2); cout << "- (  *  ) -";
    gotoXY(x, y + 3); cout << "   ^-*-^   ";
    gotoXY(x, y + 4); cout << "  /  |  \\ ";
}

void sol2(int x, int y) {
    gotoXY(x, y);     cout << "   \\ | /  ";
    gotoXY(x, y + 1); cout << " '   *   ' ";
    gotoXY(x, y + 2); cout << "- (  *  ) -";
    gotoXY(x, y + 3); cout << " '   *   ' ";
    gotoXY(x, y + 4); cout << "   / | \\  ";
}

void sol3(int x, int y) {
    gotoXY(x, y);     cout << "   \\ | /  ";
    gotoXY(x, y + 1); cout << " .   *   . ";
    gotoXY(x, y + 2); cout << " -- ( ) -- ";
    gotoXY(x, y + 3); cout << " .   *   . ";
    gotoXY(x, y + 4); cout << "   / | \\  ";
}

void sol4(int x, int y) {
    gotoXY(x, y);     cout << "  \\  |  / ";
    gotoXY(x, y + 1); cout << "    -O-    ";
    gotoXY(x, y + 2); cout << " --( O )-- ";
    gotoXY(x, y + 3); cout << "    -O-    ";
    gotoXY(x, y + 4); cout << "  /  |  \\ ";
}

void sol5(int x, int y) {
    gotoXY(x, y);     cout << "   \\ | /  ";
    gotoXY(x, y + 1); cout << " *   *   * ";
    gotoXY(x, y + 2); cout << "-(   *   )-";
    gotoXY(x, y + 3); cout << " *   *   * ";
    gotoXY(x, y + 4); cout << "   / | \\  ";
}

void sol6(int x, int y) {
    gotoXY(x, y);     cout << "  \\  |  / ";
    gotoXY(x, y + 1); cout << "  .-'*'-.  ";
    gotoXY(x, y + 2); cout << "- (  *  ) -";
    gotoXY(x, y + 3); cout << "   `-*-`   ";
    gotoXY(x, y + 4); cout << "  /  |  \\ ";
}

void sol7(int x, int y) {
    gotoXY(x, y);     cout << "   \\ | /  ";
    gotoXY(x, y + 1); cout << "  '  *  '  ";
    gotoXY(x, y + 2); cout << " - ( * ) - ";
    gotoXY(x, y + 3); cout << "  '  *  '  ";
    gotoXY(x, y + 4); cout << "   / | \\  ";
}

void sol8(int x, int y) {
    gotoXY(x, y);     cout << "   \\ | /  ";
    gotoXY(x, y + 1); cout << "  '  *  '  ";
    gotoXY(x, y + 2); cout << " - ( * ) - ";
    gotoXY(x, y + 3); cout << "  '  *  '  ";
    gotoXY(x, y + 4); cout << "   / | \\  ";
}

void sol9(int x, int y) {
    gotoXY(x, y);     cout << "  \\  |  / ";
    gotoXY(x, y + 1); cout << "   .-*-.   ";
    gotoXY(x, y + 2); cout << "- (  *  ) -";
    gotoXY(x, y + 3); cout << "   `-*-'   ";
    gotoXY(x, y + 4); cout << "  /  |  \\ ";
}

void borrar_soljsjjss(int x, int y) {
    gotoXY(x, y);     cout << "           ";
    gotoXY(x, y + 1); cout << "           ";
    gotoXY(x, y + 2); cout << "           ";
    gotoXY(x, y + 3); cout << "           ";
    gotoXY(x, y + 4); cout << "           ";
    gotoXY(x, y + 5); cout << "           ";
}

void luna1(int x, int y) {
    gotoXY(x, y);     cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .:::::::. ";
    gotoXY(x, y + 2); cout << ":::::::::::";
    gotoXY(x, y + 3); cout << ":::::::::::";
    gotoXY(x, y + 4); cout << "`:::::::::'";
    gotoXY(x, y + 5); cout << "  `':::''  ";
}

void luna2(int x, int y) {
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .::::. `. ";
    gotoXY(x, y + 2); cout << ":::::::.  :";
    gotoXY(x, y + 3); cout << "::::::::  :";
    gotoXY(x, y + 4); cout << "`::::::' .'";
    gotoXY(x, y + 5); cout << "  `'::'-'  ";
}

void luna3(int x, int y) {
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .::::  `. ";
    gotoXY(x, y + 2); cout << "::::::    :";
    gotoXY(x, y + 3); cout << "::::::    :";
    gotoXY(x, y + 4); cout << "`:::::  .' ";
    gotoXY(x, y + 5); cout << "  `'::'-'  ";
}

void luna4(int x, int y) {
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .::'   `. ";
    gotoXY(x, y + 2); cout << ":::       :";
    gotoXY(x, y + 3); cout << ":::       :";
    gotoXY(x, y + 4); cout << "`::.     .'";
    gotoXY(x, y + 5); cout << "  `':..-'  ";
}

void luna5(int x, int y) {
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .'     `. ";
    gotoXY(x, y + 2); cout << ":         :";
    gotoXY(x, y + 3); cout << ":         :";
    gotoXY(x, y + 4); cout << "`.       .'";
    gotoXY(x, y + 5); cout << "  `-...-'  ";
}

void luna6(int x, int y) {
    gotoXY(x, y);     cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .'   `::. ";
    gotoXY(x, y + 2); cout << ":       :::";
    gotoXY(x, y + 3); cout << ":       :::";
    gotoXY(x, y + 4); cout << "`.     .::'";
    gotoXY(x, y + 5); cout << "  `-..:''  ";
}

void luna7(int x, int y) {
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .'  ::::. ";
    gotoXY(x, y + 2); cout << ":    ::::::";
    gotoXY(x, y + 3); cout << ":    ::::::";
    gotoXY(x, y + 4); cout << "`.   :::::'";
    gotoXY(x, y + 5); cout << "  `-.::''  ";

}

void luna8(int x, int y)
{
    gotoXY(x, y);	  cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .' .::::. ";
    gotoXY(x, y + 2); cout << ":  ::::::::";
    gotoXY(x, y + 3); cout << ":  ::::::::";
    gotoXY(x, y + 4); cout << "`. '::::::'";
    gotoXY(x, y + 5); cout << "  `-.::''  ";
}

void luna9(int x, int y) {
    gotoXY(x, y);     cout << "   _..._   ";
    gotoXY(x, y + 1); cout << " .:::::::. ";
    gotoXY(x, y + 2); cout << ":::::::::::";
    gotoXY(x, y + 3); cout << ":::::::::::";
    gotoXY(x, y + 4); cout << "`:::::::::'";
    gotoXY(x, y + 5); cout << "  `':::''  ";
}

void borrar_luna(int x, int y) {
    gotoXY(x, y);     cout << "           ";
    gotoXY(x, y + 1); cout << "           ";
    gotoXY(x, y + 2); cout << "           ";
    gotoXY(x, y + 3); cout << "           ";
    gotoXY(x, y + 4); cout << "           ";
    gotoXY(x, y + 5); cout << "           ";
}

void nubexdjsjjs(int x, int y) {
    gotoXY(x + 4, y + 1); cout << "======";
    gotoXY(x + 2, y + 2); cout << "==     ====";
    gotoXY(x, y + 3); cout << "===         ===";
    gotoXY(x + 1, y + 4); cout << "=============";
}

void dibujarDragon(int x, int y) {
    cout << DARK_GREEN;
    gotoXY(x, y + 1);   cout << "   @@@@@                                              ";
    gotoXY(x, y + 2);   cout << " @@@   @@@                                            ";
    gotoXY(x, y + 3);   cout << "@@@@    @@                                            ";
    gotoXY(x, y + 4);   cout << "   @@   @@   @@@                                      ";
    gotoXY(x, y + 5);   cout << "    @@   @@@@@@   @@@@@@@@@@@@@@@@@@                  ";
    gotoXY(x, y + 6);   cout << "     @@     @@@@@@@@@ @@@    @@@                      ";
    gotoXY(x, y + 7);   cout << "      @@      @@@@@@@ @@     @@                       ";
    gotoXY(x, y + 8);   cout << "     @@@@@@    @@  @@  @     @@                       ";
    gotoXY(x, y + 9);   cout << "     @@@  @@@  @@  @@ @@   @@@@@@                     ";
    gotoXY(x, y + 10);  cout << "   @@   @@@   @@  @@  @@  @@                          ";
    gotoXY(x, y + 11);  cout << "@@@@@@@@        @@@@@@  @@@@@                         ";
    gotoXY(x, y + 12);  cout << "  @@@     @@@      @@    @ @@@@@               @@@@@@@";
    gotoXY(x, y + 13);  cout << "   @@@@@@@@             @      @@@            @    @  ";
    gotoXY(x, y + 14);  cout << "         @@                      @@@         @     @  ";
    gotoXY(x, y + 15);  cout << "       @@@@@@@                     @@        @    @   ";
    gotoXY(x, y + 16);  cout << "     @@  @@@@@  @                   @@       @  @     ";
    gotoXY(x, y + 17);  cout << "     @@@@ @@   @@                    @        @ @     ";
    gotoXY(x, y + 18);  cout << "       @@@@@@@@@         @@          @@       @  @    ";
    gotoXY(x, y + 19);  cout << "        @@   @@       @@@@            @       @  @    ";
    gotoXY(x, y + 20);  cout << "             @@@@   @@@               @@     @@  @    ";
    gotoXY(x, y + 21);  cout << "            @@  @@@@@                 @@    @@  @     ";
    gotoXY(x, y + 22);  cout << "            @@    @@          @@@      @@  @@  @@     ";
    gotoXY(x, y + 23);  cout << "            @@    @@       @@@@        @@@@@  @@      ";
    gotoXY(x, y + 24);  cout << "             @@    @@     @@@@@              @@       ";
    gotoXY(x, y + 25);  cout << "              @@    @@     @@ @@@          @@@        ";
    gotoXY(x, y + 26);  cout << "           @@@@@@ @@@@@    @@    @@@@@@@@@@           ";
    gotoXY(x, y + 27);  cout << "           @@@@@@@@@@@      @@                        ";
    gotoXY(x, y + 28);  cout << "                    @@@@@@@@@                         ";
    cout << RESET;
}

void dibujarDragonDerecha(int x, int y) {
    cout << DARK_GREEN;
    gotoXY(x, y + 1);   cout << "                                                 @@@@   ";
    gotoXY(x, y + 2);   cout << "                                       @@       @@  @@  ";
    gotoXY(x, y + 3);   cout << "                                        @@@@   @@   @@  ";
    gotoXY(x, y + 4);   cout << "                   @@@@@@@@@@@@@@@@@@@   @@@@ @@   @@   ";
    gotoXY(x, y + 5);   cout << "                   @@@@@@@   @@@@ @@@@@@@@@@@@@   @@    ";
    gotoXY(x, y + 6);   cout << "                         @@     @@ @@@@@@@ @@@   @@     ";
    gotoXY(x, y + 7);   cout << "                         @@    @@@ @@ @@@@     @@       ";
    gotoXY(x, y + 8);   cout << "                        @@@@   @@  @@  @@  @@@@         ";
    gotoXY(x, y + 9);   cout << "                     @@@@@ @@@  @@ @@  @@@   @@         ";
    gotoXY(x, y + 10);  cout << "                            @@  @@@ @@@@@     @@@@      ";
    gotoXY(x, y + 11);  cout << "@@@@@@@                   @@@@@  @@@@@           @@@@@@@";
    gotoXY(x, y + 12);  cout << "@    @@               @@@@@  @@             @@@@@  @@@@ ";
    gotoXY(x, y + 13);  cout << " @     @            @@@                      @@  @@     ";
    gotoXY(x, y + 14);  cout << "  @@   @          @@@                       @@          ";
    gotoXY(x, y + 15);  cout << "    @  @        @@                    @@ @@@@@@@@@@     ";
    gotoXY(x, y + 16);  cout << "    @  @       @@@                    @@    @@ @@@@@    ";
    gotoXY(x, y + 17);  cout << "   @  @        @@          @@          @@@@@@@@@@@@     ";
    gotoXY(x, y + 18);  cout << "   @  @       @@@            @@@@        @@   @@@       ";
    gotoXY(x, y + 19);  cout << "   @   @      @@                @@@   @@@@     @        ";
    gotoXY(x, y + 20);  cout << "   @@   @     @@                  @@@@@@ @@             ";
    gotoXY(x, y + 21);  cout << "    @@   @   @@      @@@           @@    @@             ";
    gotoXY(x, y + 22);  cout << "     @@  @@@@@@       @@@@@        @@   @@              ";
    gotoXY(x, y + 23);  cout << "      @@                @@@@      @@    @@              ";
    gotoXY(x, y + 24);  cout << "       @@@            @@@ @@     @@@   @@               ";
    gotoXY(x, y + 25);  cout << "         @@@@@@@@@@@@@@   @@    @@    @@                ";
    gotoXY(x, y + 26);  cout << "                         @@    @@     @@                ";
    gotoXY(x, y + 27);  cout << "                        @@     @@@@@@ @@@@@@            ";
    gotoXY(x, y + 28);  cout << "                        @@@@@@@@@                       ";
    cout << RESET;
}

void dibujarDragonAtaqueIzquierda(int x, int y) {
    cout << DARK_GREEN;
    gotoXY(x, y + 1);   cout << "            @@@@@                                ";
    gotoXY(x, y + 2);   cout << "          @@@   @@@                              ";
    gotoXY(x, y + 3);   cout << "         @@@@    @@                              ";
    gotoXY(x, y + 4);   cout << "            @@   @@   @@@                        ";
    gotoXY(x, y + 5);   cout << "             @@   @@@@@@   @@@@@@@@@@@@@@@@@@    ";
    gotoXY(x, y + 6);   cout << "              @@     @@@@@@@@@ @@@    @@@        ";
    gotoXY(x, y + 7);   cout << "               @@      @@@@@@@ @@     @@         ";
    gotoXY(x, y + 8);   cout << "              @@@@@@    @@  @@  @     @@         ";
    gotoXY(x, y + 9);   cout << "              @@@  @@@  @@  @@ @@   @@@@@@       ";
    gotoXY(x, y + 10);  cout << "           @@   @@@   @@  @@  @@  @@             ";
    gotoXY(x, y + 11);  cout << "        @@@@@@@@        @@@@@@  @@@@@            ";
    gotoXY(x, y + 12);  cout << "          @@@     @@@      @@    @ @@@@@         ";
    gotoXY(x, y + 13);  cout << "           @@@@@@@@             @      @@@       ";
    gotoXY(x, y + 14);  cout << "                 @@                      @@@     ";
    gotoXY(x, y + 15);  cout << "               @@@@@@@                     @@    ";
    gotoXY(x, y + 16);  cout << "             @@  @@@@@  @                   @@   ";
    gotoXY(x, y + 17);  cout << "             @@@@ @@   @@                    @   ";
    gotoXY(x, y + 18);  cout << "               @@@@@@@@@         @@          @@  ";
    gotoXY(x, y + 19);  cout << "  @              @@   @@       @@@@            @ ";
    gotoXY(x, y + 20);  cout << " @ @                   @@@@   @@@ @@@@@@       @@";
    gotoXY(x, y + 21);  cout << "@   @@                @@  @@@@@ @@@     @@@   @@ ";
    gotoXY(x, y + 22);  cout << " @    @@@@@@            @@@@@@            @@ @@  ";
    gotoXY(x, y + 23);  cout << "  @@@       @@@     @@@@@                  @@    ";
    gotoXY(x, y + 24);  cout << "     @@@       @@@@@                     @@      ";
    gotoXY(x, y + 25);  cout << "        @@@                            @@@       ";
    gotoXY(x, y + 26);  cout << "           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@         ";
    gotoXY(x, y + 27);  cout << "                   @@@@@@@@@@@  @@@@@            ";
    gotoXY(x, y + 28);  cout << "                            @@@@@@@@@            ";
    cout << RESET;
}

void dibujarDragonAtaqueDerecha(int x, int y) {
    cout << DARK_GREEN;
    gotoXY(x, y + 1);   cout << "                                     @@@@    ";
    gotoXY(x, y + 2);   cout << "                           @@       @@  @@   ";
    gotoXY(x, y + 3);   cout << "                            @@@@   @@   @@   ";
    gotoXY(x, y + 4);   cout << "       @@@@@@@@@@@@@@@@@@@   @@@@ @@   @@    ";
    gotoXY(x, y + 5);   cout << "       @@@@@@@   @@@@ @@@@@@@@@@@@@   @@     ";
    gotoXY(x, y + 6);   cout << "             @@     @@ @@@@@@@ @@@   @@      ";
    gotoXY(x, y + 7);   cout << "             @@    @@@ @@ @@@@     @@        ";
    gotoXY(x, y + 8);   cout << "            @@@@   @@  @@  @@  @@@@          ";
    gotoXY(x, y + 9);   cout << "         @@@@@ @@@  @@ @@  @@@   @@          ";
    gotoXY(x, y + 10);  cout << "                @@  @@@ @@@@@     @@@@       ";
    gotoXY(x, y + 11);  cout << "              @@@@@  @@@@@           @@@@@@@ ";
    gotoXY(x, y + 12);  cout << "          @@@@@  @@             @@@@@  @@@@  ";
    gotoXY(x, y + 13);  cout << "        @@@                      @@  @@      ";
    gotoXY(x, y + 14);  cout << "      @@@                       @@           ";
    gotoXY(x, y + 15);  cout << "    @@                    @@ @@@@@@@@@@      ";
    gotoXY(x, y + 16);  cout << "   @@@                    @@    @@ @@@@@     ";
    gotoXY(x, y + 17);  cout << "   @@          @@          @@@@@@@@@@@@      ";
    gotoXY(x, y + 18);  cout << "  @@@            @@@@        @@   @@         ";
    gotoXY(x, y + 19);  cout << "@@                  @@@   @@@@            @  ";
    gotoXY(x, y + 20);  cout << "@@    @@@@@@          @@@@@@             @ @ ";
    gotoXY(x, y + 21);  cout << "@@ @@@     @@@           @@            @@   @";
    gotoXY(x, y + 22);  cout << "  @@          @@@@@@   @@        @@@@@@    @ ";
    gotoXY(x, y + 23);  cout << "@@                  @@@@@@    @@@       @@@  ";
    gotoXY(x, y + 24);  cout << "  @@                      @@@@        @@@    ";
    gotoXY(x, y + 25);  cout << "   @@@                            @@@        ";
    gotoXY(x, y + 26);  cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@           ";
    gotoXY(x, y + 27);  cout << "            @@     @@@@@@ @@@@@@             ";
    gotoXY(x, y + 28);  cout << "            @@@@@@@@@                        ";
    cout << RESET;
}

void borrarDragon(int x, int y) {
    gotoXY(x, y + 1);   cout << "                                                        ";
    gotoXY(x, y + 2);   cout << "                                                        ";
    gotoXY(x, y + 3);   cout << "                                                        ";
    gotoXY(x, y + 4);   cout << "                                                        ";
    gotoXY(x, y + 5);   cout << "                                                        ";
    gotoXY(x, y + 6);   cout << "                                                        ";
    gotoXY(x, y + 7);   cout << "                                                        ";
    gotoXY(x, y + 8);   cout << "                                                        ";
    gotoXY(x, y + 9);   cout << "                                                        ";
    gotoXY(x, y + 10);  cout << "                                                        ";
    gotoXY(x, y + 11);  cout << "                                                        ";
    gotoXY(x, y + 12);  cout << "                                                        ";
    gotoXY(x, y + 13);  cout << "                                                        ";
    gotoXY(x, y + 14);  cout << "                                                        ";
    gotoXY(x, y + 15);  cout << "                                                        ";
    gotoXY(x, y + 16);  cout << "                                                        ";
    gotoXY(x, y + 17);  cout << "                                                        ";
    gotoXY(x, y + 18);  cout << "                                                        ";
    gotoXY(x, y + 19);  cout << "                                                        ";
    gotoXY(x, y + 20);  cout << "                                                        ";
    gotoXY(x, y + 21);  cout << "                                                        ";
    gotoXY(x, y + 22);  cout << "                                                        ";
    gotoXY(x, y + 23);  cout << "                                                        ";
    gotoXY(x, y + 24);  cout << "                                                        ";
    gotoXY(x, y + 25);  cout << "                                                        ";
    gotoXY(x, y + 26);  cout << "                                                        ";
    gotoXY(x, y + 27);  cout << "                                                        ";
    gotoXY(x, y + 28);  cout << "                                                        ";
}

void dibujarBolaRocosa(int x, int y) {
    cout << DARKGRAY;
    gotoXY(x, y + 1); cout << "        -==*    ";
    gotoXY(x, y + 2); cout << "   -+===+###*   ";
    gotoXY(x, y + 3); cout << " +++=**+%#####  ";
    gotoXY(x, y + 4); cout << "#*+#***#*#*++*# ";
    gotoXY(x, y + 5); cout << "#%@@%%***#%###*#";
    gotoXY(x, y + 6); cout << " @@@%@@%@##*#%##";
    gotoXY(x, y + 7); cout << "   %@%%@%@#+###%";
    gotoXY(x, y + 8); cout << "    @@@@%#%%%%% ";
    gotoXY(x, y + 9); cout << "      @%@%#%%   ";
    cout << RESET;
}

void borrarBolaRocosa(int x, int y) {
    gotoXY(x, y + 1); cout << "                ";
    gotoXY(x, y + 2); cout << "                ";
    gotoXY(x, y + 3); cout << "                ";
    gotoXY(x, y + 4); cout << "                ";
    gotoXY(x, y + 5); cout << "                ";
    gotoXY(x, y + 6); cout << "                ";
    gotoXY(x, y + 7); cout << "                ";
    gotoXY(x, y + 8); cout << "                ";
    gotoXY(x, y + 9); cout << "                ";
}

// Dibujo de llamarada:
void dibujoLlamarada(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << " @@   @@@   @                   ";
    gotoXY(x, y + 2);  cout << "@  @@@@@@@@@@@@    @@@@ @@@@@@  ";
    gotoXY(x, y + 3);  cout << " @       @   @@  @@@  @  @    @@";
    gotoXY(x, y + 4);  cout << "  @@@@@@@ @  @     @@@@   @  @@ ";
    gotoXY(x, y + 5);  cout << "            @@@ @ @@ @@@@  @@@  ";
    gotoXY(x, y + 6);  cout << "               @ @@@@@@  @@     ";
    cout << RESET;
}

void dibujoLlamaradaIzquierda(int x, int y) {
    cout << ORANGE;
    gotoXY(x, y + 1);  cout << "                    @   @@@   @@";
    gotoXY(x, y + 2);  cout << "  @@@@@@@ @@@@    @@@@@@@@@@@@  ";
    gotoXY(x, y + 3);  cout << "@@     @  @  @@@  @@   @       @";
    gotoXY(x, y + 4);  cout << " @@   @   @@@@     @  @ @@@@@@@ ";
    gotoXY(x, y + 5);  cout << "  @ @@  @@@@ @@ @ @@@           ";
    gotoXY(x, y + 6);  cout << "      @@  @@@@@@ @              ";
    cout << RESET;
}

void borrarLlamarada(int x, int y) {
    gotoXY(x, y + 1);  cout << "                                ";
    gotoXY(x, y + 2);  cout << "                                ";
    gotoXY(x, y + 3);  cout << "                                ";
    gotoXY(x, y + 4);  cout << "                                ";
    gotoXY(x, y + 5);  cout << "                                ";
    gotoXY(x, y + 6);  cout << "                                ";
}

void borrarcapibaraxd1(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "          ";
    gotoXY(x, y + 3); cout << "          ";
    gotoXY(x, y + 4); cout << "          ";
    gotoXY(x, y + 5); cout << "          ";
    gotoXY(x, y + 6); cout << "          ";
}

void borrarcapibaraxd2(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "          ";
    gotoXY(x, y + 3); cout << "          ";
    gotoXY(x, y + 4); cout << "          ";
    gotoXY(x, y + 5); cout << "          ";
    gotoXY(x, y + 6); cout << "          ";
}

void borrarzorroxd1(int x, int y) {
    gotoXY(x, y + 1);  cout << "                         ";
    gotoXY(x, y + 2);  cout << "                         ";
    gotoXY(x, y + 3);  cout << "                         ";
    gotoXY(x, y + 4);  cout << "                         ";
    gotoXY(x, y + 5);  cout << "                         ";
    gotoXY(x, y + 6);  cout << "                         ";
    gotoXY(x, y + 7);  cout << "                         ";
    gotoXY(x, y + 8);  cout << "                         ";
    gotoXY(x, y + 9);  cout << "                         ";
    gotoXY(x, y + 10); cout << "                         ";
    gotoXY(x, y + 11); cout << "                         ";
    gotoXY(x, y + 12); cout << "                         ";

}

void borrarcocodriloxd1(int x, int y) {
    gotoXY(x, y + 1);    cout << "                      ";
    gotoXY(x, y + 2);    cout << "                      ";
    gotoXY(x, y + 3);    cout << "                      ";
    gotoXY(x, y + 4);    cout << "                      ";
    gotoXY(x, y + 5);    cout << "                      ";
    gotoXY(x, y + 6);    cout << "                      ";
    gotoXY(x, y + 7);   cout << "                       ";
    gotoXY(x, y + 8);   cout << "                      ";
}

void borrarardillaxd1(int x, int y) {
    gotoXY(x, y + 1);  cout << "                      ";
    gotoXY(x, y + 2);  cout << "                      ";
    gotoXY(x, y + 3);  cout << "                      ";
    gotoXY(x, y + 4);  cout << "                      ";
    gotoXY(x, y + 5);  cout << "                      ";
    gotoXY(x, y + 6);  cout << "                      ";
    gotoXY(x, y + 7);  cout << "                      ";
    gotoXY(x, y + 8);  cout << "                      ";
    gotoXY(x, y + 9);  cout << "                      ";
    gotoXY(x, y + 10); cout << "                      ";

}

void borrarardillaxd2(int x, int y) {
    gotoXY(x, y + 1);  cout << "                    ";
    gotoXY(x, y + 2);  cout << "                    ";
    gotoXY(x, y + 3);  cout << "                    ";
    gotoXY(x, y + 4);  cout << "                    ";
    gotoXY(x, y + 5);  cout << "                    ";
    gotoXY(x, y + 6);  cout << "                    ";
    gotoXY(x, y + 7);  cout << "                    ";
    gotoXY(x, y + 8);  cout << "                    ";
    gotoXY(x, y + 9);  cout << "                    ";
    gotoXY(x, y + 10); cout << "                    ";
}

void borrarbellotaxd1(int x, int y) {
    gotoXY(x, y + 1); cout << " ";
}

void borrarbolafuegoxd1(int x, int y) {
    gotoXY(x, y + 1); cout << "         ";
    gotoXY(x, y + 2); cout << "         ";
    gotoXY(x, y + 3); cout << "         ";
}

void capibaraxd1(int x, int y) {
    gotoXY(x, y + 1); cout << "    ##### ";
    gotoXY(x, y + 2); cout << "    # #  #";
    gotoXY(x, y + 3); cout << " ###    ##";
    gotoXY(x, y + 4); cout << "#      #  ";
    gotoXY(x, y + 5); cout << "#  #  #   ";
    gotoXY(x, y + 6); cout << "### ###   ";
}

void capibaraxd2(int x, int y) {
    gotoXY(x, y + 1); cout << " #####    ";
    gotoXY(x, y + 2); cout << "#  # #    ";
    gotoXY(x, y + 3); cout << "##    ### ";
    gotoXY(x, y + 4); cout << "  #      #";
    gotoXY(x, y + 5); cout << "   #  #  #";
    gotoXY(x, y + 6); cout << "   ### ###";
}

void zorroxd1(int x, int y) {
    gotoXY(x, y + 1);  cout << "           @@       @@   ";
    gotoXY(x, y + 2);  cout << "          @  @     @  @  ";
    gotoXY(x, y + 3);  cout << "   @@    @    @@@@@    @ ";
    gotoXY(x, y + 4);  cout << "  @  @   @             @ ";
    gotoXY(x, y + 5);  cout << " @   @   @   ##   ##   @ ";
    gotoXY(x, y + 6);  cout << "@    @  @               @";
    gotoXY(x, y + 7);  cout << "@     @  @     ###     @ ";
    gotoXY(x, y + 8);  cout << "@      @@@            @  ";
    gotoXY(x, y + 9);  cout << " @@@                  @  ";
    gotoXY(x, y + 10); cout << "    @@@@@             @  ";
    gotoXY(x, y + 11); cout << "        @     @@@     @  ";
    gotoXY(x, y + 12); cout << "        @@@@@@   @@@@@   ";

}

void cocodriloxd1(int x, int y) {
    gotoXY(x, y + 1);    cout << "               @@@    ";
    gotoXY(x, y + 2);    cout << "              @   @   ";
    gotoXY(x, y + 3);    cout << "             @  @@@   ";
    gotoXY(x, y + 4);    cout << "             @  @     ";
    gotoXY(x, y + 5);    cout << " @@ @  @@@ @@   @     ";
    gotoXY(x, y + 6);    cout << " @@@             @    ";
    gotoXY(x, y + 7);   cout << " @@@@@ @  @@@@ @@@@    ";
    gotoXY(x, y + 8);   cout << "       @@@            ";
}

void ardillaxd1(int x, int y) {
    gotoXY(x, y + 1);  cout << "  @@@@@   @@@  @@     ";
    gotoXY(x, y + 2);  cout << " @     @ @  @@@@@     ";
    gotoXY(x, y + 3);  cout << "  @     @        @@   ";
    gotoXY(x, y + 4);  cout << "  @    @@   #    #@   ";
    gotoXY(x, y + 5);  cout << " @    @ @       @@@   ";
    gotoXY(x, y + 6);  cout << " @     @    @@  @ @   ";
    gotoXY(x, y + 7);  cout << " @     @      @    @  ";
    gotoXY(x, y + 8);  cout << "  @    @       @    @ ";
    gotoXY(x, y + 9);  cout << "   @    @     @ @  @  ";
    gotoXY(x, y + 10); cout << "    @@@@@@@@@@ @@@@   ";

}

void ardillaxd2(int x, int y) {
    gotoXY(x, y + 1);  cout << "    @@  @@@   @@@@@ ";
    gotoXY(x, y + 2);  cout << "    @@@@@  @ @     @";
    gotoXY(x, y + 3);  cout << "  @@        @     @ ";
    gotoXY(x, y + 4);  cout << "  @@    @   @@    @ ";
    gotoXY(x, y + 5);  cout << "  @@@       @ @    @";
    gotoXY(x, y + 6);  cout << "  @ @  @@    @     @";
    gotoXY(x, y + 7);  cout << " @    @      @     @";
    gotoXY(x, y + 8);  cout << "@    @       @    @ ";
    gotoXY(x, y + 9);  cout << " @  @ @     @    @  ";
    gotoXY(x, y + 10); cout << "  @@@@ @@@@@@@@@@   ";
}

void bellotaxd1(int x, int y) {
    gotoXY(x, y + 1); cout << "@";
}

void bolafuegoxd1(int x, int y) {
    gotoXY(x, y + 1); cout << "    +    ";
    gotoXY(x, y + 2); cout << "  *+++*  ";
    gotoXY(x, y + 3); cout << "   ***   ";
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dibujarCapibaraIzquierda(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagoIzquierda(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorIzquierda(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldadoIzquierda(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAsesinoIzquierda(capibara.x, capibara.y);
    }
}

void dibujarCapibaraDerecha(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagoDerecha(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorDerecha(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldadoDerecha(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAsesinoDerecha(capibara.x, capibara.y);
    }
}

void dibujarCapibaraDerechaCaminando(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagoDerechaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorDerechaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldadoDerechaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAsesinoDerechaCaminando(capibara.x, capibara.y);
    }
}

void dibujarCapibaraIzquierdaCaminando(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagoIzquierdaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorIzquierdaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldadoIzquierdaCaminando(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAsesinoIzquierdaCaminando(capibara.x, capibara.y);
    }
}

// Detectar clase ataque izquierda
void dibujarClaseAtaqueIzquierda(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagicianIzquierdaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorIzquierdaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldierIzquierdaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAssasinIzquierdaAtacar(capibara.x, capibara.y);
    }
}

// Detectar clase ataque derecha
void dibujarClaseAtaqueDerecha(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagicianDerechaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorDerechaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldierDerechaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAssasinDerechaAtacar(capibara.x, capibara.y);
    }
}

// Detectar clase ataque arriba
void dibujarClaseAtaqueArriba(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagicianArribaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorArribaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldierArribaAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAssasinArribaAtacar(capibara.x, capibara.y);
    }
}

// Detectar clase ataque abajo
void dibujarClaseAtaqueAbajo(int numeroClase, Capibara& capibara) {
    if (numeroClase == 1) {
        dibujarMagicianAbajoAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 2) {
        dibujarWarriorAbajoAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 3) {
        dibujarSoldierAbajoAtacar(capibara.x, capibara.y);
    }
    else if (numeroClase == 4) {
        dibujarAssasinAbajoAtacar(capibara.x, capibara.y);
    }
}

void textoSinSleep(char* tex, int x, int y) {
    while (*tex) {
        switch (*tex) {
        case 'A': case 'a': a(x, y); break;
        case 'Á': case 'á': a(x, y); break;
        case 'B': case 'b': b(x, y); break;
        case 'C': case 'c': c(x, y); break;
        case 'D': case 'd': d(x, y); break;
        case 'E': case 'e': e(x, y); break;
        case 'É': case 'é': e(x, y); break;
        case 'F': case 'f': f(x, y); break;
        case 'G': case 'g': g(x, y); break;
        case 'H': case 'h': h(x, y); break;
        case 'I': case 'i': i(x, y); break;
        case 'Í': case 'í': i(x, y); break;
        case 'J': case 'j': j(x, y); break;
        case 'K': case 'k': k(x, y); break;
        case 'L': case 'l': l(x, y); break;
        case 'M': case 'm': m(x, y); break;
        case 'N': case 'n': n(x, y); break;
        case 'O': case 'o': o(x, y); break;
        case 'Ó': case 'ó': o(x, y); break;
        case 'P': case 'p': p(x, y); break;
        case 'Q': case 'q': q(x, y); break;
        case 'R': case 'r': r(x, y); break;
        case 'S': case 's': s(x, y); break;
        case 'T': case 't': t(x, y); break;
        case 'U': case 'u': u(x, y); break;
        case 'Ú': case 'ú': u(x, y); break;
        case 'V': case 'v': v(x, y); break;
        case 'W': case 'w': w(x, y); break;
        case 'X': case 'x': xx(x, y); break;
        case 'Y': case 'y': yy(x, y); break;
        case 'Z': case 'z': z(x, y); break;
        case '0': number0(x, y); break;
        case '1': number1(x, y); break;
        case '2': number2(x, y); break;
        case '3': number3(x, y); break;
        case '4': number4(x, y); break;
        case '5': number5(x, y); break;
        case '6': number6(x, y); break;
        case '7': number7(x, y); break;
        case '8': number8(x, y); break;
        case '9': number9(x, y); break;
        case ',': coma(x, y); break;
        case '!': admiracion(x, y); break;
        case ':': dospuntos(x, y); break;
        case ';': puntoycoma(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case '(': parentesis_abierto_3(x, y); break;
        case ')': parentesis_cerrado_3(x, y); break;
        case '=': igualxd(x, y); break;
        case ' ':
            break;
        default: break;
        }
        if (*tex == '0') {
            x += 4;
        }
        else if (*tex == '1') {
            x += 4;
        }
        else if (*tex == '2') {
            x += 4;
        }
        else if (*tex == '3') {
            x += 4;
        }
        else if (*tex == '4') {
            x += 4;
        }
        else if (*tex == '5') {
            x += 4;
        }
        else if (*tex == '6') {
            x += 4;
        }
        else if (*tex == '7') {
            x += 4;
        }
        else if (*tex == '8') {
            x += 4;
        }
        else if (*tex == '9') {
            x += 4;
        }
        else if (*tex == 'a') {
            x += 4;
        }
        else if (*tex == 'b') {
            x += 4;
        }
        else if (*tex == 'c') {
            x += 4;
        }
        else if (*tex == 'd') {
            x += 4;
        }
        else if (*tex == 'e') {
            x += 4;
        }
        else if (*tex == 'f') {
            x += 4;
        }
        else if (*tex == 'g') {
            x += 4;
        }
        else if (*tex == 'h') {
            x += 4;
        }
        else if (*tex == 'i') {
            x += 4;
        }
        else if (*tex == 'j') {
            x += 4;
        }
        else if (*tex == 'k') {
            x += 4;
        }
        else if (*tex == 'l') {
            x += 4;
        }
        else if (*tex == 'm') {
            x += 5;
        }
        else if (*tex == 'n') {
            x += 4;
        }
        else if (*tex == 'o') {
            x += 4;
        }
        else if (*tex == 'p') {
            x += 4;
        }
        else if (*tex == 'q') {
            x += 4;
        }
        else if (*tex == 'r') {
            x += 4;
        }
        else if (*tex == 's') {
            x += 4;
        }
        else if (*tex == 't') {
            x += 4;
        }
        else if (*tex == 'u') {
            x += 4;
        }
        else if (*tex == 'v') {
            x += 5;
        }
        else if (*tex == 'w') {
            x += 5;
        }
        else if (*tex == 'x') {
            x += 4;
        }
        else if (*tex == 'y') {
            x += 3;
        }
        else if (*tex == 'z') {
            x += 3;
        }
        else if (*tex == '!') {
            x += 2;
        }
        else if (*tex == '.') {
            x += 4;
        }
        else if (*tex == ':') {
            x += 4;
        }
        else if (*tex == ';') {
            x += 4;
        }
        else if (*tex == ',') {
            x += 2;
        }
        else if (*tex == '-') {
            x += 3;
        }
        else if (*tex == '(') {
            x += 2;
        }
        else if (*tex == ')') {
            x += 2;
        }
        else if (*tex == '=') {
            x += 3;
        }
        else if (*tex == ' ') {
            x += 1;
        }
        else if (*tex != ' ') {
            x += 4; // Espacio entre caracteres
        }
        tex++;
    }
}

void textoGrandeSinSleep(char* instruccion, int x, int y) {
    while (*instruccion) {
        switch (*instruccion) {
        case 'A': dibujarletraA(x, y); break;
        case 'B': dibujarletraB(x, y); break;
        case 'C': dibujarletraC(x, y); break;
        case 'D': dibujarletraD(x, y); break;
        case 'E': dibujarletraE(x, y); break;
        case 'F': dibujarletraF(x, y); break;
        case 'G': dibujarletraG(x, y); break;
        case 'H': dibujarletraH(x, y); break;
        case 'I': dibujarletraI(x, y); break;
        case 'J': dibujarletraJ(x, y); break;
        case 'K': dibujarletraK(x, y); break;
        case 'L': dibujarletraL(x, y); break;
        case 'M': dibujarletraM(x, y); break;
        case 'N': dibujarletraN(x, y); break;
        case 'O': dibujarletraO(x, y); break;
        case 'P': dibujarletraP(x, y); break;
        case 'Q': dibujarletraQ(x, y); break;
        case 'R': dibujarletraR(x, y); break;
        case 'S': dibujarletraS(x, y); break;
        case 'T': dibujarletraT(x, y); break;
        case 'U': dibujarletraU(x, y); break;
        case 'V': dibujarletraV(x, y); break;
        case 'W': dibujarletraW(x, y); break;
        case 'X': dibujarletraX(x, y); break;
        case 'Y': dibujarletraY(x, y); break;
        case 'Z': dibujarletraZ(x, y); break;
        case '(': dibujarparentesisabierto(x, y); break;
        case ')': dibujarparentesiscerrado(x, y); break;
        case '!': admiracion_grande_xd(x, y); break;
        case ',': coma(x, y + 1); break;
        case ':': dospuntos(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case ' ':   break;
        default: break;
        }
        if (*instruccion == '(') {
            x += 3;
        }
        else if (*instruccion == ')') {
            x += 3;
        }
        else if (*instruccion == '!') {
            x += 3;
        }
        else if (*instruccion != ' ') {
            x += 6;
        }
        else if (*instruccion == ' ') {
            x += 6;
        }
        instruccion++;
    }
}

void textoConSleep(char* tex, int x, int y) {
    while (*tex) {
        switch (*tex) {
        case 'A': case 'a': a(x, y); break;
        case 'Á': case 'á': a(x, y); break;
        case 'B': case 'b': b(x, y); break;
        case 'C': case 'c': c(x, y); break;
        case 'D': case 'd': d(x, y); break;
        case 'E': case 'e': e(x, y); break;
        case 'É': case 'é': e(x, y); break;
        case 'F': case 'f': f(x, y); break;
        case 'G': case 'g': g(x, y); break;
        case 'H': case 'h': h(x, y); break;
        case 'I': case 'i': i(x, y); break;
        case 'Í': case 'í': i(x, y); break;
        case 'J': case 'j': j(x, y); break;
        case 'K': case 'k': k(x, y); break;
        case 'L': case 'l': l(x, y); break;
        case 'M': case 'm': m(x, y); break;
        case 'N': case 'n': n(x, y); break;
        case 'O': case 'o': o(x, y); break;
        case 'Ó': case 'ó': o(x, y); break;
        case 'P': case 'p': p(x, y); break;
        case 'Q': case 'q': q(x, y); break;
        case 'R': case 'r': r(x, y); break;
        case 'S': case 's': s(x, y); break;
        case 'T': case 't': t(x, y); break;
        case 'U': case 'u': u(x, y); break;
        case 'Ú': case 'ú': u(x, y); break;
        case 'V': case 'v': v(x, y); break;
        case 'W': case 'w': w(x, y); break;
        case 'X': case 'x': xx(x, y); break;
        case 'Y': case 'y': yy(x, y); break;
        case 'Z': case 'z': z(x, y); break;
        case '0': number0(x, y); break;
        case '1': number1(x, y); break;
        case '2': number2(x, y); break;
        case '3': number3(x, y); break;
        case '4': number4(x, y); break;
        case '5': number5(x, y); break;
        case '6': number6(x, y); break;
        case '7': number7(x, y); break;
        case '8': number8(x, y); break;
        case '9': number9(x, y); break;
        case ',': coma(x, y); break;
        case '!': admiracion(x, y); break;
        case ':': dospuntos(x, y); break;
        case ';': puntoycoma(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case '(': parentesis_abierto_3(x, y); break;
        case ')': parentesis_cerrado_3(x, y); break;
        case '=': igualxd(x, y); break;
        case ' ':
            break;
        default: break;
        }
        if (*tex == '0') {
            x += 4;
        }
        else if (*tex == '1') {
            x += 4;
        }
        else if (*tex == '2') {
            x += 4;
        }
        else if (*tex == '3') {
            x += 4;
        }
        else if (*tex == '4') {
            x += 4;
        }
        else if (*tex == '5') {
            x += 4;
        }
        else if (*tex == '6') {
            x += 4;
        }
        else if (*tex == '7') {
            x += 4;
        }
        else if (*tex == '8') {
            x += 4;
        }
        else if (*tex == '9') {
            x += 4;
        }
        else if (*tex == 'a') {
            x += 4;
        }
        else if (*tex == 'b') {
            x += 4;
        }
        else if (*tex == 'c') {
            x += 4;
        }
        else if (*tex == 'd') {
            x += 4;
        }
        else if (*tex == 'e') {
            x += 4;
        }
        else if (*tex == 'f') {
            x += 4;
        }
        else if (*tex == 'g') {
            x += 4;
        }
        else if (*tex == 'h') {
            x += 4;
        }
        else if (*tex == 'i') {
            x += 4;
        }
        else if (*tex == 'j') {
            x += 4;
        }
        else if (*tex == 'k') {
            x += 4;
        }
        else if (*tex == 'l') {
            x += 4;
        }
        else if (*tex == 'm') {
            x += 5;
        }
        else if (*tex == 'n') {
            x += 4;
        }
        else if (*tex == 'o') {
            x += 4;
        }
        else if (*tex == 'p') {
            x += 4;
        }
        else if (*tex == 'q') {
            x += 4;
        }
        else if (*tex == 'r') {
            x += 4;
        }
        else if (*tex == 's') {
            x += 4;
        }
        else if (*tex == 't') {
            x += 4;
        }
        else if (*tex == 'u') {
            x += 4;
        }
        else if (*tex == 'v') {
            x += 5;
        }
        else if (*tex == 'w') {
            x += 5;
        }
        else if (*tex == 'x') {
            x += 4;
        }
        else if (*tex == 'y') {
            x += 3;
        }
        else if (*tex == 'z') {
            x += 3;
        }
        else if (*tex == '!') {
            x += 2;
        }
        else if (*tex == '.') {
            x += 4;
        }
        else if (*tex == ':') {
            x += 4;
        }
        else if (*tex == ';') {
            x += 4;
        }
        else if (*tex == ',') {
            x += 2;
        }
        else if (*tex == '-') {
            x += 3;
        }
        else if (*tex == '(') {
            x += 2;
        }
        else if (*tex == ')') {
            x += 2;
        }
        else if (*tex == '=') {
            x += 3;
        }
        else if (*tex == ' ') {
            x += 1;
        }
        else if (*tex != ' ') {
            x += 4; // Espacio entre caracteres
        }
        _sleep(60);
        tex++;
    }
}

void textoGrandeConSleep(char* instruccion, int x, int y) {
    while (*instruccion) {
        switch (*instruccion) {
        case 'A': dibujarletraA(x, y); break;
        case 'B': dibujarletraB(x, y); break;
        case 'C': dibujarletraC(x, y); break;
        case 'D': dibujarletraD(x, y); break;
        case 'E': dibujarletraE(x, y); break;
        case 'F': dibujarletraF(x, y); break;
        case 'G': dibujarletraG(x, y); break;
        case 'H': dibujarletraH(x, y); break;
        case 'I': dibujarletraI(x, y); break;
        case 'J': dibujarletraJ(x, y); break;
        case 'K': dibujarletraK(x, y); break;
        case 'L': dibujarletraL(x, y); break;
        case 'M': dibujarletraM(x, y); break;
        case 'N': dibujarletraN(x, y); break;
        case 'O': dibujarletraO(x, y); break;
        case 'P': dibujarletraP(x, y); break;
        case 'Q': dibujarletraQ(x, y); break;
        case 'R': dibujarletraR(x, y); break;
        case 'S': dibujarletraS(x, y); break;
        case 'T': dibujarletraT(x, y); break;
        case 'U': dibujarletraU(x, y); break;
        case 'V': dibujarletraV(x, y); break;
        case 'W': dibujarletraW(x, y); break;
        case 'X': dibujarletraX(x, y); break;
        case 'Y': dibujarletraY(x, y); break;
        case 'Z': dibujarletraZ(x, y); break;
        case '(': dibujarparentesisabierto(x, y); break;
        case ')': dibujarparentesiscerrado(x, y); break;
        case '!': admiracion_grande_xd(x, y); break;
        case ',': coma(x, y + 1); break;
        case ':': dospuntos(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case ' ':   break;
        default: break;
        }
        if (*instruccion == '(') {
            x += 3;
        }
        else if (*instruccion == ')') {
            x += 3;
        }
        else if (*instruccion == '!') {
            x += 3;
        }
        else if (*instruccion != ' ') {
            x += 6;
        }
        else if (*instruccion == ' ') {
            x += 6;
        }
        _sleep(60);
        instruccion++;
    }
}

//Dibujar palabras y rectangulos
void drawCapyAdventures(int x, int y) {

    dibujarRectanguloHueco(x + 2, y, 47, 8);

    textoGrandeSinSleep("CAPY ADVENTURES", x + 5, y + 1);
}

void drawStartingTitle(int x, int y) {
    dibujarRectanguloHueco(x, y, 42, 10);
    textoGrandeSinSleep("STARTING GAME", x + 4, y + 2);
}

void drawStartImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    textoGrandeSinSleep("START(S)", x + 5, y + 3);
}

void drawLevelsImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 26, 8);
    //Dibujar en ascii Levels
    textoGrandeSinSleep("LEVELS(L)", x + 5, y + 3);
}

void drawExtitImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 20, 8);
    //Dibujar en ascii EXIT
    textoGrandeSinSleep("EXIT(E)", x + 5, y + 3);

}

void drawExtitImputSelected(int x, int y) {
    //Dibujar en ascii EXIT
    cout << YELLOW;
    dibujarRectanguloHueco(x + 2, y + 2, 20, 8);
    textoGrandeSinSleep("EXIT(E)", x + 5, y + 3);
    cout << RESET;
}

void drawChoosingClass(int x, int y) {
    dibujarRectanguloHueco(x + 2, y, 42, 8);
    //dibujar en ascii CHOOSING
    dibujarletraC(x + 5, y + 1);
    dibujarletraH(x + 11, y + 1);
    dibujarletraO(x + 17, y + 1);
    dibujarletraO(x + 23, y + 1);
    dibujarletraS(x + 29, y + 1);
    dibujarletraI(x + 35, y + 1);
    dibujarletraN(x + 41, y + 1);
    dibujarletraG(x + 47, y + 1);

    //Dibujar en ascii CLASS
    dibujarletraC(x + 55, y + 1);
    dibujarletraL(x + 61, y + 1);
    dibujarletraA(x + 67, y + 1);
    dibujarletraS(x + 73, y + 1);
    dibujarletraS(x + 79, y + 1);
}

void drawMagicanImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 30, 8);
    //Dibujar en ascii MAGICAN
    dibujarletraM(x + 5, y + 3);
    dibujarletraA(x + 11, y + 3);
    dibujarletraG(x + 17, y + 3);
    dibujarletraI(x + 23, y + 3);
    dibujarletraC(x + 29, y + 3);
    dibujarletraA(x + 35, y + 3);
    dibujarletraN(x + 41, y + 3);
    dibujarparentesisabierto(x + 49, y + 3);
    dibujarletraM(x + 52, y + 3);
    dibujarparentesiscerrado(x + 58, y + 3);
}

void drawWarriorImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 30, 8);
    //Dibujar en ascii WARRIOR
    dibujarletraW(x + 5, y + 3);
    dibujarletraA(x + 11, y + 3);
    dibujarletraR(x + 17, y + 3);
    dibujarletraR(x + 23, y + 3);
    dibujarletraI(x + 29, y + 3);
    dibujarletraO(x + 35, y + 3);
    dibujarletraR(x + 41, y + 3);
    dibujarparentesisabierto(x + 49, y + 3);
    dibujarletraW(x + 52, y + 3);
    dibujarparentesiscerrado(x + 58, y + 3);
}

void drawSoldierImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 30, 8);
    //Dibujar en ascii SOLDIER
    dibujarletraS(x + 5, y + 3);
    dibujarletraO(x + 11, y + 3);
    dibujarletraL(x + 17, y + 3);
    dibujarletraD(x + 23, y + 3);
    dibujarletraI(x + 29, y + 3);
    dibujarletraE(x + 35, y + 3);
    dibujarletraR(x + 41, y + 3);
    dibujarparentesisabierto(x + 49, y + 3);
    dibujarletraS(x + 52, y + 3);
    dibujarparentesiscerrado(x + 58, y + 3);
}

void drawAssasinImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 30, 8);
    //Dibujar en ascii ASSESIN
    dibujarletraA(x + 5, y + 3);
    dibujarletraS(x + 11, y + 3);
    dibujarletraS(x + 17, y + 3);
    dibujarletraA(x + 23, y + 3);
    dibujarletraS(x + 29, y + 3);
    dibujarletraI(x + 35, y + 3);
    dibujarletraN(x + 41, y + 3);
    dibujarparentesisabierto(x + 49, y + 3);
    dibujarletraA(x + 52, y + 3);
    dibujarparentesiscerrado(x + 58, y + 3);
}

void drawContinueImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 32, 8);
    //Dibujar en ascii OPTIONS
    dibujarletraC(x + 5, y + 3);
    dibujarletraO(x + 11, y + 3);
    dibujarletraN(x + 17, y + 3);
    dibujarletraT(x + 23, y + 3);
    dibujarletraI(x + 29, y + 3);
    dibujarletraN(x + 35, y + 3);
    dibujarletraU(x + 41, y + 3);
    dibujarletraE(x + 47, y + 3);
    dibujarparentesisabierto(x + 53, y + 3);
    dibujarletraC(x + 56, y + 3);
    dibujarparentesiscerrado(x + 62, y + 3);
}

void drawPreviewImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    //Dibujar RESTART
    dibujarletraP(x + 5, y + 3);
    dibujarletraR(x + 11, y + 3);
    dibujarletraE(x + 17, y + 3);
    dibujarletraV(x + 23, y + 3);
    dibujarletraI(x + 29, y + 3);
    dibujarletraE(x + 35, y + 3);
    dibujarletraW(x + 41, y + 3);
}

// Dibujar Pantallas
void drawScreenChooseClass() {
    Console::Clear();
    drawChoosingClass(1, 0);
    flechitajsjsjs(0, 12);
    drawMagicanImput(10, 8);
    drawWarriorImput(10, 17);
    drawSoldierImput(90, 8);
    drawAssasinImput(90, 17);
    drawContinueImput(90, 35);
}

void drawScreenChooseClassMagician(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    cout << color;
    flechitajsjsjs(0, 11);
    drawMagicanImput(10, 8);
    cout << RESET;
    drawWarriorImput(10, 17);
    drawSoldierImput(90, 8);
    drawAssasinImput(90, 17);
    drawContinueImput(90, 35);
}

void drawScreenChooseClassWarrior(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    cout << color;
    flechitajsjsjs(0, 20);
    drawWarriorImput(10, 17);
    cout << RESET;
    drawSoldierImput(90, 8);
    drawAssasinImput(90, 17);
    drawContinueImput(90, 35);
}

void drawScreenChooseClassSoldier(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    drawWarriorImput(10, 17);
    cout << color;
    flechitajsjsjs(80, 11);
    drawSoldierImput(90, 8);
    cout << RESET;
    drawAssasinImput(90, 17);
    drawContinueImput(90, 35);
}

void drawScreenChooseClassAssasin(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    drawWarriorImput(10, 17);
    drawSoldierImput(90, 8);
    cout << color;
    flechitajsjsjs(80, 20);
    drawAssasinImput(90, 16);
    cout << RESET;
    drawContinueImput(90, 35);
}

void drawScreenChooseClassMagicianChecked(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    cout << color;
    drawMagicanImput(10, 8);
    cout << RESET;
    drawWarriorImput(10, 17);
    drawSoldierImput(90, 8);
    drawAssasinImput(90, 17);
    cout << color;
    flechitajsjsjs(80, 38);
    drawContinueImput(90, 35);
    cout << RESET;
}

void drawScreenChooseClassWarriorChecked(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    cout << color;
    drawWarriorImput(10, 17);
    cout << RESET;
    drawSoldierImput(90, 8);
    drawAssasinImput(90, 17);
    cout << color;
    flechitajsjsjs(80, 38);
    drawContinueImput(90, 35);
    cout << RESET;
}

void drawScreenChooseClassSoldierChecked(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    drawWarriorImput(10, 17);
    cout << color;
    drawSoldierImput(90, 8);
    cout << RESET;
    drawAssasinImput(90, 17);
    cout << color;
    flechitajsjsjs(80, 38);
    drawContinueImput(90, 35);
    cout << RESET;
}

void drawScreenChooseClassAssasinChecked(char* color) {
    Console::Clear();
    drawChoosingClass(1, 0);
    drawMagicanImput(10, 8);
    drawWarriorImput(10, 17);
    drawSoldierImput(90, 8);
    cout << color;
    drawAssasinImput(90, 16);
    cout << RESET;
    cout << color;
    flechitajsjsjs(80, 38);
    drawContinueImput(90, 35);
    cout << RESET;
}

// Nombre
void drawNameInput(int x, int y) {
    dibujarletraC(x, y);
    dibujarletraO(x + 6, y);
    dibujarletraL(x + 12, y);
    dibujarletraO(x + 18, y);
    dibujarletraC(x + 24, y);
    dibujarletraA(x + 30, y);
    dibujarletraR(x + 36, y);
    dibujarletraT(x + 46, y);
    dibujarletraU(x + 52, y);
    dibujarletraN(x + 62, y);
    dibujarletraO(x + 68, y);
    dibujarletraM(x + 74, y);
    dibujarletraB(x + 80, y);
    dibujarletraR(x + 86, y);
    dibujarletraE(x + 92, y);
}

void drawEnterInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 17, 8);
    //Dibujar en ascii ENTER
    dibujarletraE(x + 5, y + 3);
    dibujarletraN(x + 11, y + 3);
    dibujarletraT(x + 17, y + 3);
    dibujarletraE(x + 23, y + 3);
    dibujarletraR(x + 29, y + 3);
}

char* nameInput() {
    char* nuevoNombre = new char[20];
    Console::Clear();
    drawStartingTitle(0, 0);

    drawNameInput((WIDTH / 4) - 10, 11);

    dibujarRectanguloHueco((WIDTH / 3), 20, 23, 4);
    sol(200, 2);
    arbol(172, 40);
    arbusto(60, 52);
    arbusto(140, 52);
    corazon(114, 45);
    cout << BROWN;
    dibujarCapibaraIzquierda3(120, 51);
    dibujarCapibaraDerecha2(99, 51);
    cout << RESET;
    piso3(23, 59, 22);
    drawEnterInput((WIDTH / 3) + 5, 23);
    gotoXY((WIDTH / 3) + 5, 22);
    cin >> nuevoNombre;
    return nuevoNombre;
}

// Botones 
void drawRestartImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    //Dibujar RESTART
    dibujarletraR(x + 5, y + 3);
    dibujarletraE(x + 11, y + 3);
    dibujarletraS(x + 17, y + 3);
    dibujarletraT(x + 23, y + 3);
    dibujarletraA(x + 29, y + 3);
    dibujarletraR(x + 35, y + 3);
    dibujarletraT(x + 41, y + 3);
}

void drawYesImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 18, 8);
    //Dibujar YES
    dibujarletraY(x + 5, y + 3);
    dibujarletraE(x + 11, y + 3);
    dibujarletraS(x + 17, y + 3);
    dibujarparentesisabierto(x + 25, y + 3);
    dibujarletraY(x + 28, y + 3);
    dibujarparentesiscerrado(x + 34, y + 3);
}

void drawMenuImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 25, 8);
    //Dibujar YES
    dibujarletraM(x + 5, y + 3);
    dibujarletraE(x + 11, y + 3);
    dibujarletraN(x + 17, y + 3);
    dibujarletraU(x + 23, y + 3);
    dibujarparentesisabierto(x + 29, y + 3);
    dibujarletraY(x + 35, y + 3);
    dibujarparentesiscerrado(x + 41, y + 3);
}

void drawChooseCheckpointImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 58, 8);
    //Dibujar CHOOSE
    dibujarletraC(x + 5, y + 3);
    dibujarletraH(x + 11, y + 3);
    dibujarletraO(x + 17, y + 3);
    dibujarletraO(x + 23, y + 3);
    dibujarletraS(x + 29, y + 3);
    dibujarletraE(x + 35, y + 3);
    //Dibujar CHECKPOINT
    dibujarletraC(x + 45, y + 3);
    dibujarletraH(x + 51, y + 3);
    dibujarletraE(x + 57, y + 3);
    dibujarletraC(x + 63, y + 3);
    dibujarletraK(x + 69, y + 3);
    dibujarletraP(x + 75, y + 3);
    dibujarletraO(x + 81, y + 3);
    dibujarletraI(x + 87, y + 3);
    dibujarletraN(x + 93, y + 3);
    dibujarletraT(x + 98, y + 3);
    dibujarparentesisabierto(x + 105, y + 3);
    dibujarletraC(x + 108, y + 3);
    dibujarparentesiscerrado(x + 114, y + 3);

}

void drawExtitGameImput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 33, 8);
    //Dibujar en ascii EXIT
    dibujarletraE(x + 5, y + 3);
    dibujarletraX(x + 11, y + 3);
    dibujarletraI(x + 17, y + 3);
    dibujarletraT(x + 23, y + 3);
    //Dibujar GAME
    dibujarletraG(x + 30, y + 3);
    dibujarletraA(x + 36, y + 3);
    dibujarletraM(x + 42, y + 3);
    dibujarletraE(x + 48, y + 3);

    dibujarparentesisabierto(x + 55, y + 3);
    dibujarletraE(x + 58, y + 3);
    dibujarparentesiscerrado(x + 64, y + 3);
}

void drawScreenRestart() {
    Console::Clear();
    drawRestartImput(WIDTH / 3, 0);
    drawYesImput(1, 9);
    drawChooseCheckpointImput(1, 18);
    drawExtitGameImput(1, 27);
}

bool validateInputName(char* name) {
    char caracterActual;
    bool sonCaracteresNumericos;
    bool sonCaracteresEspeciales;

    for (int i = 0; name[i] != '\0'; i++) {
        caracterActual = name[i];
        sonCaracteresNumericos = caracterActual >= '0' && caracterActual <= '9';
        sonCaracteresEspeciales = (caracterActual >= 32 && caracterActual <= 47) ||
            (caracterActual >= 58 && caracterActual <= 64) ||
            (caracterActual >= 91 && caracterActual <= 96) ||
            (caracterActual >= 123 && caracterActual <= 126);
        if (sonCaracteresNumericos || sonCaracteresEspeciales) {
            return false;
        }
    }
    return true;
}

void drawCapibaraClass(int x, int y, int number) {
    if (number == 1) {
        dibujarCapibaraBatallaMagician(x, y);
    }
    else if (number == 2) {
        dibujarCapibaraBatallaWarrior(x, y);
    }
    else if (number == 3) {
        dibujarCapibaraBatallaSoldier(x, y);
    }
    else if (number == 4) {
        dibujarCapibaraBatallaAssasin(x, y);
    }
}

// Decoracion
void decoracion1() {
    sol(200, 2);

    arbol(172, 40);

    arbusto(60, 52);

    arbusto(140, 52);

    corazon(114, 45);

    aguilaxd1(107, 10);

    cout << BROWN;
    dibujarCapibaraIzquierda3(120, 51);

    dibujarCapibaraDerecha2(99, 51);
    cout << RESET;

    piso3(23, 59, 22);
}

void pantalla_ganador_xd1(int numeroClase) {
    Console::Clear();
    Console::CursorVisible = false;
    lobo_ganador(1, 5);

    dibujarRectanguloHueco(100, 3, 35, 30);
    textoSinSleep("YOU  WIN ! ! !", 110, 7);

    //estadisticas(110, 15);

    trofeo(184, 4);

    cout << DARKGRAY;
    piso1(180, 32, 6);
    cout << RESET;

    drawCapibaraClass(100, 40, numeroClase);

    cout << DARKGRAY;
    piso1(100, 57, 16);
    cout << RESET;

    enemigo_durmiente(190, 37);

}

void pantalla_perdedor_xd1(int numeroDeClase) {
    Console::Clear();
    lobo_perdedor(0, 5);

    dibujarRectanguloHueco(100, 3, 35, 30);
    textoSinSleep("DEFEAT ! ! !", 110, 7);

    //estadisticas(110, 15);


    trofeo_perdedor(184, 4);

    piso1(180, 32, 6);

    drawCapibaraClass(100, 40, numeroDeClase);

    piso1(100, 57, 16);

    enemigo_durmiente(190, 37);

}

int chooseClassMenu() {
    bool chooseMagician = false;
    bool chooseWarrior = false;
    bool chooseSoldier = false;
    bool chooseAssasin = false;
    bool screenChooseMagician = false;
    bool screenChooseWarrior = false;
    bool screenChooseSoldier = false;
    bool screenChooseAssasin = false;
    bool screenChooseContinue = false;
    bool classChossed = false;
    char teclaClass;
    int numeroElegido;
    drawScreenChooseClass();
    while (classChossed == false) {
        if (_kbhit()) {
            teclaClass = _getch();
            teclaClass = toupper(teclaClass);
            if (teclaClass == 'M') {
                drawScreenChooseClassMagician(YELLOW);
                numeroElegido = 1;
                screenChooseMagician = true;
                screenChooseWarrior = false;
                screenChooseSoldier = false;
                screenChooseAssasin = false;
            }
            else if (teclaClass == 'W') {
                drawScreenChooseClassWarrior(YELLOW);
                numeroElegido = 2;
                screenChooseMagician = false;
                screenChooseWarrior = true;
                screenChooseSoldier = false;
                screenChooseAssasin = false;
            }
            else if (teclaClass == 'S') {
                drawScreenChooseClassSoldier(YELLOW);
                numeroElegido = 3;
                screenChooseMagician = false;
                screenChooseWarrior = false;
                screenChooseSoldier = true;
                screenChooseAssasin = false;
            }
            else if (teclaClass == 'A') {
                drawScreenChooseClassAssasin(YELLOW);
                numeroElegido = 4;
                screenChooseMagician = false;
                screenChooseWarrior = false;
                screenChooseSoldier = false;
                screenChooseAssasin = true;
            }
            else if (teclaClass == 'C' && ((screenChooseMagician == true) || (screenChooseWarrior == true) || (screenChooseSoldier == true) || (screenChooseAssasin == true))) {
                screenChooseContinue = true;
            }

            if (teclaClass == ' ') {
                if (screenChooseMagician == true) {
                    drawScreenChooseClassMagician(GREEN);
                    chooseMagician = true;
                }
                else if (screenChooseWarrior == true) {
                    drawScreenChooseClassWarrior(GREEN);
                    chooseWarrior = true;
                }
                else if (screenChooseSoldier == true) {
                    drawScreenChooseClassSoldier(GREEN);
                    chooseSoldier = true;
                }
                else if (screenChooseAssasin == true) {
                    drawScreenChooseClassAssasin(GREEN);
                    chooseAssasin = true;
                }
            }
        }
        if (screenChooseContinue == true) {
            if (screenChooseMagician == true) {
                drawScreenChooseClassMagicianChecked(GREEN);
            }
            else if (screenChooseWarrior == true) {
                drawScreenChooseClassWarriorChecked(GREEN);
            }
            else if (screenChooseSoldier == true) {
                drawScreenChooseClassSoldierChecked(GREEN);
            }
            else if (screenChooseAssasin == true) {
                drawScreenChooseClassAssasinChecked(GREEN);
            }
            classChossed = true;
        }
    }
    return numeroElegido;
}

void animateLoadingBar(int x, int y, int repeticiones, int tamanio) {
    int contador = 1;
    int coordenadaBarraX = x + 2;
    int coordenadaBarraY = y + 2;
    gotoXY(x + 1, y); cout << "LOADING....";
    while (contador <= repeticiones) {
        dibujarRectanguloHueco(x, y, tamanio, 3);
        gotoXY(coordenadaBarraX, coordenadaBarraY);
        for (int i = 0; i < (tamanio + 20); i++) {
            gotoXY(coordenadaBarraX + i, coordenadaBarraY);
            cout << " ";
        }
        cout << CYAN;
        for (int i = 0; i < (tamanio + 20); i++) {
            gotoXY(coordenadaBarraX + i, coordenadaBarraY);
            cout << "/";
            _sleep(100);
        }
        contador++;
        cout << RESET;
    }
}

void drawScreenPreviewClass(int number) {
    Console::Clear();
    drawPreviewImput(WIDTH / 3 + 5, 0);
    drawCapibaraClass((WIDTH / 3) + 13, 20, number);
    animateLoadingBar(WIDTH - 50, 50, 3, 24);
}

// Animacion de cargando...
void loadingAnimation() {
    int mitadPantallaAncho = (WIDTH / 3) + 2;
    int mitadPantallaAlto = (HEIGHT / 3) + 2;
    int coordenadaBarraX = mitadPantallaAncho + 12;
    int coordenadaBarraY = mitadPantallaAlto + 12;
    int repeticiones = 0;
    Console::Clear();
    dibujarletraL(mitadPantallaAncho, mitadPantallaAlto);
    dibujarletraO(mitadPantallaAncho + 7, mitadPantallaAlto);
    dibujarletraA(mitadPantallaAncho + 14, mitadPantallaAlto);
    dibujarletraD(mitadPantallaAncho + 21, mitadPantallaAlto);
    dibujarletraI(mitadPantallaAncho + 28, mitadPantallaAlto);
    dibujarletraN(mitadPantallaAncho + 35, mitadPantallaAlto);
    dibujarletraG(mitadPantallaAncho + 42, mitadPantallaAlto);
    while (repeticiones <= 3) {
        dibujarRectanguloHueco(mitadPantallaAncho + 10, mitadPantallaAlto + 10, 12, 3);
        if (repeticiones % 2 == 0) {
            drawCapibaraFace(mitadPantallaAncho + 65, mitadPantallaAlto + 10);
        }
        else {
            drawCapibaraFace1(mitadPantallaAncho + 65, mitadPantallaAlto + 10);
        }
        gotoXY(coordenadaBarraX, coordenadaBarraY);
        cout << "                    ";
        cout << CYAN;
        for (int i = 0; i < 20; i++) {
            gotoXY(coordenadaBarraX + i, coordenadaBarraY);
            cout << "/";
            _sleep(100);
        }
        repeticiones++;
        cout << RESET;
        borrarCapibaraFace(mitadPantallaAncho + 65, mitadPantallaAlto + 10);
    }
}

// Funciones aleatorias:
void definir_posicionEnemigo(Capibara& capibara, Enemigo& enemigo) {
    bool perteneceCapi = false;
    int xAleatorio;
    int yAleatorio;
    do {
        perteneceCapi = false;
        xAleatorio = numeroAleatorio(0, Console::WindowWidth - enemigo.anchoEnemigo - enemigo.dxEnemigo);
        yAleatorio = numeroAleatorio(10, Console::WindowHeight - enemigo.altoEnemigo - enemigo.dyEnemigo);

        // Verificando si el punto generado pertenece al un punto del capibara
        if ((xAleatorio + enemigo.anchoEnemigo > capibara.x) &&
            (xAleatorio < capibara.x + capibara.ancho) &&
            (yAleatorio + enemigo.altoEnemigo > capibara.y) &&
            (yAleatorio < capibara.y + capibara.alto)) {
            perteneceCapi = true;
        }

    } while (perteneceCapi);

    enemigo.xEnemigo = xAleatorio;
    enemigo.yEnemigo = yAleatorio;
}

int generarPocion(Potion& pocion) {
    int numero = numeroAleatorio(1, 4);
    if (numero == 1) {
        pocion_cheta(pocion.x, pocion.y);
        return numero;
    }
    else if (numero == 2) {
        pocion_fuerza(pocion.x, pocion.y);
        return numero;
    }
    else if (numero == 3) {
        pocion_mana(pocion.x, pocion.y);
        return numero;
    }
    else if (numero == 4) {
        pocion_vida(pocion.x, pocion.y);
        return numero;
    }
}

void definir_posicionObjeto1(Capibara& capibara, Enemigo& enemigo, Potion& pocion) {
    bool perteneceCapi = false;
    bool perteneceEnemigo = false;
    int xAleatorio;
    int yAleatorio;
    do {
        perteneceCapi = false;
        xAleatorio = numeroAleatorio(0, Console::WindowWidth - pocion.ancho - 10);
        yAleatorio = numeroAleatorio(0, Console::WindowHeight - pocion.alto - 10);

        // Verificando si el punto generado pertenece al un punto del capibara
        if ((xAleatorio + enemigo.anchoEnemigo > capibara.x) &&
            (xAleatorio < capibara.x + capibara.ancho) &&
            (yAleatorio + enemigo.altoEnemigo > capibara.y) &&
            (yAleatorio < capibara.y + capibara.alto)) {
            perteneceCapi = true;
        }

        // Verificando si el punto generado pertenece al un punto del capibara
        if ((xAleatorio + capibara.ancho > enemigo.xEnemigo) &&
            (xAleatorio < enemigo.xEnemigo + enemigo.anchoEnemigo) &&
            (yAleatorio + capibara.alto > enemigo.yEnemigo) &&
            (yAleatorio < enemigo.yEnemigo + enemigo.altoEnemigo)) {
            perteneceEnemigo = true;
        }

        if (!perteneceCapi && !perteneceEnemigo) {
            break;
        }

    } while (perteneceCapi || perteneceEnemigo);

    pocion.x = xAleatorio;
    pocion.y = yAleatorio;
}

// Movimiento:
void movimientoArdilla(Capibara& capibara, Enemigo& Ardilla, Bellota& bellota, bool& moverArribaCapibara) {

    if (Ardilla.tiempoAlejamiento <= 50) {
        bool colisionConsola = false;

        int xCapibaraActual = capibara.x;
        int yCapibaraActual = capibara.y + capibara.alto / 2;
        int xArdilla = Ardilla.xEnemigo;
        int yArdilla = Ardilla.yEnemigo + Ardilla.altoEnemigo / 2;

        // Capibara esta a la derecha
        if (capibara.x > Ardilla.xEnemigo) {
            xArdilla += Ardilla.anchoEnemigo;
        }
        // Capibara esta a la izquierda
        else {
            xCapibaraActual += capibara.ancho;
        }
        // Distancia entre capibara y ardilla
        int distanciaEntreArdillaYCapibara = calcular_distancia_entreDosPuntos(xCapibaraActual, yCapibaraActual, xArdilla, yArdilla);



        if (distanciaEntreArdillaYCapibara < 40) {
            Ardilla.alejandose = true;
            // Si el Ardilla esta en la izquierda de la capibara
            if (xCapibaraActual > xArdilla) {
                Ardilla.xEnemigo -= 5;
                Ardilla.tiempoAlejamiento++;
            }
            // Si el Ardilla esta en la derecha de la capibara
            if (xCapibaraActual < xArdilla) {
                Ardilla.xEnemigo += 5;
                Ardilla.tiempoAlejamiento++;
            }
            if (moverArribaCapibara) {
                if (yCapibaraActual > yArdilla) {
                    Ardilla.yEnemigo -= 5;
                    Ardilla.tiempoAlejamiento++;
                }
            }
            else {
                if (yCapibaraActual < yArdilla) {
                    Ardilla.yEnemigo += 5;
                    Ardilla.tiempoAlejamiento++;
                }
            }
        }
        else {
            Ardilla.alejandose = false;
        }

        // Colision Consola con la ardilla

        if (Ardilla.xEnemigo < 0) {
            Ardilla.xEnemigo = 0;
            colisionConsola = true;
        }
        else if (Ardilla.xEnemigo > (Console::WindowWidth - Ardilla.anchoEnemigo - Ardilla.dxEnemigo)) {
            Ardilla.xEnemigo = Console::WindowWidth - Ardilla.anchoEnemigo - Ardilla.dxEnemigo;
            colisionConsola = true;
        }

        if (Ardilla.yEnemigo < 0) {
            Ardilla.yEnemigo = 0;
            colisionConsola = true;
        }
        else if (Ardilla.yEnemigo > (Console::WindowHeight - Ardilla.altoEnemigo - Ardilla.dyEnemigo)) {
            Ardilla.yEnemigo = Console::WindowHeight - Ardilla.altoEnemigo - Ardilla.dyEnemigo;
            colisionConsola = true;
        }

        if (colisionConsola) {
            definir_posicionEnemigo(capibara, Ardilla);
            Console::Clear();
        }
        moverArribaCapibara = false;
        colisionConsola = false;
    }
}

void movimientoBellota(Enemigo& ardilla, Capibara& capibara, Bellota& bellota, bool moverArribaCapibara) {
    // Cuando la ardilla no est� descansando y el contador de bellotas sigue en pie, sigue disparando bellotas
    if (!ardilla.descansando && bellota.tiempoDisparo > 0) {
        capibara.recibeDanio = false;
        BorrarBellota(bellota.x, bellota.y);

        float dirX, dirY;

        if (capibara.x - bellota.x != 0) {
            dirX = (capibara.x - bellota.x) / abs(capibara.x - bellota.x);
        }
        else {
            dirX = 0;
        }

        if (capibara.y - bellota.y != 0) {
            dirY = (capibara.y - bellota.y) / abs(capibara.y - bellota.y);
        }
        else {
            dirY = 0;
        }

        if (dirX != 0 || dirY != 0) {
            bellota.x += dirX * bellota.dx;
            bellota.y += dirY * bellota.dy;
        }

        // Colisiones con el capibara
        if ((bellota.x + bellota.ancho > capibara.x && bellota.x < capibara.x + capibara.ancho) &&
            (bellota.y + bellota.alto > capibara.y && bellota.y < capibara.y + capibara.alto)) {
            capibara.recibeDanio = true;
            bellota.desaparecer = true;
        }

        // Distancia entre bellota y capibara
        int distancia = calcular_distancia_entreDosPuntos(bellota.x, bellota.y, ardilla.xEnemigo + ardilla.anchoEnemigo / 2, ardilla.yEnemigo + ardilla.altoEnemigo / 2);

        if (distancia > 120) {
            bellota.desaparecer = true;
        }

        // Dibuja la bellota solo si no debe desaparecer
        if (!bellota.desaparecer) {
            dibujarBellota(bellota.x, bellota.y);
        }
        else {
            BorrarBellota(bellota.x, bellota.y);
            // Reiniciar la posici�n de la bellota en la ardilla
            bellota.x = ardilla.xEnemigo + (ardilla.anchoEnemigo / 2);
            bellota.y = ardilla.yEnemigo + (ardilla.altoEnemigo / 2);
            bellota.desaparecer = false;
            bellota.tiempoDisparo--;
        }

        if (capibara.recibeDanio) {
            if (capibara.mana <= 0) {
                capibara.vida -= 10;
                capibara.cambiarMana = true;
            }
            else {
                capibara.cambiarMana = true;
                capibara.vida -= 1;
                capibara.contadorDeInmunidad++;
            }
        }
    }
}

void dibujarArdilla(Capibara& capibara, Enemigo& Ardilla, Bellota& bellota, bool& moverArribaCapibara) {
    borrarArdilla(Ardilla.xEnemigo, Ardilla.yEnemigo);
    if (Ardilla.vida > 0) {
        if (!Ardilla.descansando) {
            movimientoArdilla(capibara, Ardilla, bellota, moverArribaCapibara);
            movimientoBellota(Ardilla, capibara, bellota, moverArribaCapibara);
        }
        else {
            Ardilla.tiempoDescanso--;
            if (Ardilla.tiempoDescanso <= 0) {
                Ardilla.descansando = false;
                Ardilla.alejandose = true;
                Ardilla.tiempoAlejamiento = 0;
                bellota.tiempoDisparo = 10;
            }
        }
        if (Ardilla.xEnemigo < WIDTH / 2) {
            dibujarArdillaBatalla(Ardilla.xEnemigo, Ardilla.yEnemigo);
        }
        else {
            // dibujar ardilla izquierda
            dibujarArdillaIzquierda(Ardilla.xEnemigo, Ardilla.yEnemigo);
        }
    }
    else {
        Console::Clear();
        cout << "Ganaste!!" << endl;
    }
}

void moverJugador(Capibara& capibara, Enemigo& enemigo, char& tecla, Potion& pocion, bool& moverIzquierda, bool& moverArriba) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    if (tecla == 'W' && capibara.y > capibara.dx) {
        nuevoY -= capibara.dy;
        moverArriba = true;
    }
    if (tecla == 'S' && capibara.y < Console::WindowHeight - capibara.alto - capibara.dy) {
        nuevoY += capibara.dy;
        moverArriba = false;
    }
    if (tecla == 'D' && capibara.x < (Console::WindowWidth - capibara.ancho - capibara.dx)) {
        nuevoX += capibara.dx;
        moverIzquierda = false;
    }
    if (tecla == 'A' && capibara.x > capibara.dy) {
        nuevoX -= capibara.dx;
        moverIzquierda = true;
    }

    // Colisiones con el enemigo
    if (nuevoY + capibara.alto > enemigo.yEnemigo &&
        nuevoY < enemigo.yEnemigo + enemigo.altoEnemigo &&
        nuevoX + capibara.ancho > enemigo.xEnemigo &&
        nuevoX < enemigo.xEnemigo + enemigo.anchoEnemigo) {
        if (tecla == 'W') {
            nuevoY = enemigo.yEnemigo + enemigo.altoEnemigo;
        }
        else if (tecla == 'S') {
            nuevoY = enemigo.yEnemigo - capibara.alto;
        }
        else if (tecla == 'D') {
            nuevoX = enemigo.xEnemigo - capibara.ancho;
        }
        else if (tecla == 'A') {
            nuevoX = enemigo.xEnemigo + enemigo.anchoEnemigo;
        }
    }

    // Colisiones con pocion
    if (!pocion.desaparecer &&
        nuevoX + capibara.ancho > pocion.x &&
        nuevoX < pocion.x + pocion.ancho &&
        nuevoY + capibara.alto > pocion.y &&
        nuevoY < pocion.y + pocion.alto) {
        borrar_pocion(pocion.x, pocion.y);
        capibara.recibeMejora = true;
        pocion.desaparecer = true;

        capibara.estamina += pocion.aumentarFuerza;
        if (capibara.estamina > 100) {
            capibara.estamina = 100;
        }
        capibara.vida += pocion.aumentarVida;
        if (capibara.vida > 100) {
            capibara.vida = 100;
        }
        capibara.mana += pocion.aumentarMana;
        if (capibara.mana > 100) {
            capibara.mana = 100;
        }
    }
    capibara.x = nuevoX;
    capibara.y = nuevoY;
}

void capibaraAtaque(Capibara& capibara, Enemigo& enemigo, Bellota& bellota, bool& moverArribaCapibara) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;
    if (capibara.atacar) {
        int margen = enemigo.margen; // Usar el margen del enemigo

        // Capibara ataca por arriba
        if (nuevoY + capibara.alto > enemigo.yEnemigo - margen &&
            nuevoY < enemigo.yEnemigo + margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = true;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por abajo
        else if (nuevoY < enemigo.yEnemigo + enemigo.altoEnemigo + margen &&
            nuevoY + capibara.alto > enemigo.yEnemigo + enemigo.altoEnemigo - margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarArriba = true;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por izquierda
        else if (nuevoX + capibara.ancho > enemigo.xEnemigo - margen &&
            nuevoX < enemigo.xEnemigo + margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = true;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por la derecha
        else if (nuevoX < enemigo.xEnemigo + enemigo.anchoEnemigo + margen &&
            nuevoX + capibara.ancho > enemigo.xEnemigo + enemigo.anchoEnemigo - margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        else {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
        }

        if (capibara.contadorDeGolpes >= enemigo.golpesMaximos) {
            capibara.contadorDeGolpes = 0;
            borrarArdilla(enemigo.xEnemigo, enemigo.yEnemigo);
            definir_posicionEnemigo(capibara, enemigo);
            bellota.tiempoDisparo = 10;
            enemigo.descansando = false;
            enemigo.tiempoAlejamiento = 0;
            dibujarArdilla(capibara, enemigo, bellota, moverArribaCapibara);
        }
    }
}

void capibaraAtaqueZorro(Capibara& capibara, Enemigo& enemigo, bool& moverArribaCapibara) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;
    if (capibara.atacar) {
        int margen = enemigo.margen; // Usar el margen del enemigo

        // Capibara ataca por arriba
        if (nuevoY + capibara.alto > enemigo.yEnemigo - margen &&
            nuevoY < enemigo.yEnemigo + margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = true;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina >= 0 && capibara.estamina <= 100) {
                enemigo.vida -= enemigo.danioRecibido * 2;
                capibara.contadorDeGolpesFuertes++;
            }
            else if (capibara.estamina <= 0) {
                enemigo.vida -= enemigo.danioRecibido;
            }
        }
        // Capibara ataca por abajo
        else if (nuevoY < enemigo.yEnemigo + enemigo.altoEnemigo + margen &&
            nuevoY + capibara.alto > enemigo.yEnemigo + enemigo.altoEnemigo - margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarArriba = true;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por izquierda
        else if (nuevoX + capibara.ancho > enemigo.xEnemigo - margen &&
            nuevoX < enemigo.xEnemigo + margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = true;
            capibara.atacarIzquierda = false;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por la derecha
        else if (nuevoX < enemigo.xEnemigo + enemigo.anchoEnemigo + margen &&
            nuevoX + capibara.ancho > enemigo.xEnemigo + enemigo.anchoEnemigo - margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        else {
            capibara.atacarArriba = false;
            capibara.atacarAbajo = false;
            capibara.atacarDerecha = false;
            capibara.atacarIzquierda = false;
        }
    }
}

void coordenadasAleatorias(int& tamanio, Enemigo& enemigo, Coordenada*& coordenada) {

    Coordenada* coordenadas_usadas = new Coordenada[tamanio];

    for (int i = 0; i < tamanio; i++) {
        bool coordenada_repetida;
        do {
            coordenada_repetida = false;
            coordenada[i].x = numeroAleatorio(5, WIDTH - 50);
            coordenada[i].y = numeroAleatorio(5, HEIGHT - 30);
            for (int j = 0; j < i; j++) {
                int coordenadaXMedio = coordenada[i].x + coordenada[i].ancho / 2;
                int coordenadaYMedio = coordenada[i].y + 1;
                int coordenada_usadaXMedio = coordenadas_usadas[j].x + coordenadas_usadas[j].ancho / 2;
                int coordenada_usadaYMedio = coordenadas_usadas[j].y + 1;
                int distancia = calcular_distancia_entreDosPuntos(coordenadaXMedio, coordenadaYMedio, coordenada_usadaXMedio, coordenada_usadaYMedio);
                if (distancia < 30) {
                    coordenada_repetida = true;
                    break;
                }
            }
        } while (coordenada_repetida);

        coordenadas_usadas[i] = coordenada[i];
    }

    delete[] coordenada;
    coordenada = coordenadas_usadas;
}

void moverHaciaCoordenada(Enemigo& Zorro, int objetivo_x, int objetivo_y) {
    int dir_x;
    int dir_y;
    const double epsilon = 0.001; // Margen de error permitido

    while (abs(Zorro.xEnemigo - objetivo_x) > epsilon || abs(Zorro.yEnemigo - objetivo_y) > epsilon) {
        borrarZorro(Zorro.xEnemigo, Zorro.yEnemigo);

        if (objetivo_x > Zorro.xEnemigo) {
            dir_x = 1;
        }
        else if (objetivo_x < Zorro.xEnemigo) {
            dir_x = -1;
        }
        else {
            dir_x = 0;
        }

        if (objetivo_y > Zorro.yEnemigo) {
            dir_y = 1;
        }
        else if (objetivo_y < Zorro.yEnemigo) {
            dir_y = -1;
        }
        else {
            dir_y = 0;
        }

        double nuevo_x = Zorro.xEnemigo + dir_x * Zorro.dxEnemigo;
        double nuevo_y = Zorro.yEnemigo + dir_y * Zorro.dyEnemigo;

        // Ajusta las coordenadas si están suficientemente cerca del objetivo
        if (abs(nuevo_x - objetivo_x) < abs(dir_x * Zorro.dxEnemigo)) {
            nuevo_x = objetivo_x;
        }

        if (abs(nuevo_y - objetivo_y) < abs(dir_y * Zorro.dyEnemigo)) {
            nuevo_y = objetivo_y;
        }

        Zorro.xEnemigo = nuevo_x;
        Zorro.yEnemigo = nuevo_y;

        dibujarZorroEnemigo(Zorro.xEnemigo, Zorro.yEnemigo);
    }
}

void moverHaciaCoordenadaCapibara(Capibara& capibara, int numeroClase, int objetivo_x, int objetivo_y) {
    int dir_x;
    int dir_y;
    const double epsilon = 0.001; // Margen de error permitido

    while (abs(capibara.x - objetivo_x) > epsilon || abs(capibara.y - objetivo_y) > epsilon) {
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);

        if (objetivo_x > capibara.x) {
            dir_x = 1;
        }
        else if (objetivo_x < capibara.x) {
            dir_x = -1;
        }
        else {
            dir_x = 0;
        }

        if (objetivo_y > capibara.y) {
            dir_y = 1;
        }
        else if (objetivo_y < capibara.y) {
            dir_y = -1;
        }
        else {
            dir_y = 0;
        }

        double nuevo_x = capibara.x + dir_x * capibara.dx;
        double nuevo_y = capibara.y + dir_y * capibara.dy;

        // Ajusta las coordenadas si están suficientemente cerca del objetivo
        if (abs(nuevo_x - objetivo_x) < abs(dir_x * capibara.dx)) {
            nuevo_x = objetivo_x;
        }

        if (abs(nuevo_y - objetivo_y) < abs(dir_y * capibara.dy)) {
            nuevo_y = objetivo_y;
        }

        capibara.x = nuevo_x;
        capibara.y = nuevo_y;

        dibujarCapibaraDerecha(numeroClase, capibara);
    }
}

void definir_posicionCapibara(Capibara& capibara, Enemigo& enemigo, int numeroClase) {
    bool perteneceEnemigo = false;
    int xAleatorio;
    int yAleatorio;
    do {
        perteneceEnemigo = false;
        xAleatorio = numeroAleatorio(0, Console::WindowWidth - capibara.ancho - capibara.dx);
        yAleatorio = numeroAleatorio(10, Console::WindowHeight - capibara.alto - capibara.dy);

        // Verificando si el punto generado pertenece al un punto del capibara
        if ((xAleatorio + capibara.ancho > enemigo.xEnemigo) &&
            (xAleatorio < enemigo.xEnemigo + enemigo.anchoEnemigo) &&
            (yAleatorio + capibara.alto > enemigo.yEnemigo) &&
            (yAleatorio < enemigo.yEnemigo + enemigo.altoEnemigo)) {
            perteneceEnemigo = true;
        }

    } while (perteneceEnemigo);
    moverHaciaCoordenadaCapibara(capibara, numeroClase, xAleatorio, yAleatorio);
}

void ordenarDistancias(Enemigo& Zorro, Coordenada*& coordenadas, int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        for (int j = 0; j < tamanio - i - 1; j++) {
            int xZorroMedio = Zorro.xEnemigo + Zorro.anchoEnemigo / 2;
            int yZorroMedio = Zorro.yEnemigo + Zorro.altoEnemigo / 2;
            int xCoordenadaMedioA = coordenadas[j].x + coordenadas[j].ancho / 2;
            int yCoordenadaMedioA = coordenadas[j].y + coordenadas[j].alto / 2;
            int xCoordenadaMedioB = coordenadas[j + 1].x + coordenadas[j + 1].ancho / 2;
            int yCoordenadaMedioB = coordenadas[j + 1].y + coordenadas[j + 1].alto / 2;

            int distanciaA = calcular_distancia_entreDosPuntos(xZorroMedio, yZorroMedio, xCoordenadaMedioA, yCoordenadaMedioA);
            int distanciaB = calcular_distancia_entreDosPuntos(xZorroMedio, yZorroMedio, xCoordenadaMedioB, yCoordenadaMedioB);

            if (distanciaA > distanciaB) {
                Coordenada temp = coordenadas[j];
                coordenadas[j] = coordenadas[j + 1];
                coordenadas[j + 1] = temp;
            }
        }
    }
}

void movimientoZorro(Capibara& capibara, Enemigo& Zorro, Coordenada*& coordenadas, int tamanio, bool& coordenadasOrdenadas, int& indiceActual) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    bool todasLasCoordenadasEncontradas = false;
    if (!coordenadasOrdenadas) {
        ordenarDistancias(Zorro, coordenadas, tamanio);
        coordenadasOrdenadas = true;
    }

    while (indiceActual < tamanio) {
        Coordenada objetivo = coordenadas[indiceActual];
        if (objetivo.coordenadaEncontrada == false) {
            moverHaciaCoordenada(Zorro, objetivo.x + objetivo.ancho / 2, objetivo.y + 1);
            // Colisiones con el capibara
            int margen = Zorro.margen; // Usar el margen del enemigo

            if (nuevoY + capibara.alto > Zorro.yEnemigo - margen &&
                nuevoY < Zorro.yEnemigo + margen &&
                capibara.x + capibara.ancho > Zorro.xEnemigo - margen &&
                capibara.x < Zorro.xEnemigo + Zorro.anchoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoY < Zorro.yEnemigo + Zorro.altoEnemigo + margen &&
                nuevoY + capibara.alto > Zorro.yEnemigo + Zorro.altoEnemigo - margen &&
                capibara.x + capibara.ancho > Zorro.xEnemigo - margen &&
                capibara.x < Zorro.xEnemigo + Zorro.anchoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoX + capibara.ancho > Zorro.xEnemigo - margen &&
                nuevoX < Zorro.xEnemigo + margen &&
                capibara.y + capibara.alto > Zorro.yEnemigo - margen &&
                capibara.y < Zorro.yEnemigo + Zorro.altoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoX < Zorro.xEnemigo + Zorro.anchoEnemigo + margen &&
                nuevoX + capibara.ancho > Zorro.xEnemigo + Zorro.anchoEnemigo - margen &&
                capibara.y + capibara.alto > Zorro.yEnemigo - margen &&
                capibara.y < Zorro.yEnemigo + Zorro.altoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }

            if (abs(Zorro.xEnemigo - (objetivo.x + objetivo.ancho / 2)) < 0.001 &&
                abs(Zorro.yEnemigo - (objetivo.y + 1)) < 0.001) {
                coordenadas[indiceActual].coordenadaEncontrada = true;
                indiceActual++;
                Zorro.contadorDePasos++;
            }
        }
    }

    for (int i = 0; i < tamanio; i++) {
        if (coordenadas[i].coordenadaEncontrada) {
            todasLasCoordenadasEncontradas = true;
        }
        else {
            todasLasCoordenadasEncontradas = false;
            break;
        }
    }

    // Si el movimiento choca con el capibara que le quite 10 de vida

    if (todasLasCoordenadasEncontradas && Zorro.contadorDePasos == tamanio) {
        Zorro.alejandose = false;
        Zorro.descansando = true;
        indiceActual = 0;
        coordenadasOrdenadas = false;
    }
}

void golpearAlCapibara1(Capibara& capibara, Enemigo& Zorro, int numeroClase) {
    bool colisionConsola = false;
    if (capibara.mana <= 0) {
        capibara.vida -= 10;
        capibara.cambiarMana = true;
    }
    else {
        capibara.cambiarMana = true;
        capibara.vida -= 1;
        capibara.contadorDeInmunidad++;
    }

    dibujarZorroAtaque(Zorro.xEnemigo, Zorro.yEnemigo);

    definir_posicionCapibara(capibara, Zorro, numeroClase);

    // Colision consola con el capibara
    if (capibara.x < 0) {
        capibara.x = 0;
        colisionConsola = true;
    }
    else if (capibara.x > (Console::WindowWidth - capibara.ancho - capibara.dx)) {
        capibara.x = Console::WindowWidth - capibara.ancho - capibara.dx;
        colisionConsola = true;
    }

    if (capibara.y < 0) {
        capibara.y = 0;
        colisionConsola = true;
    }
    else if (capibara.y > (Console::WindowHeight - capibara.alto - capibara.dy)) {
        capibara.y = Console::WindowHeight - capibara.alto - capibara.dy;
        colisionConsola = true;
    }

    if (colisionConsola) {
        definir_posicionCapibara(capibara, Zorro, numeroClase);
        Console::Clear();
    }
    colisionConsola = false;
}

void ataqueZorro(Capibara& capibara, Enemigo& Zorro, int numeroClase) {
    int xCapibaraActual = capibara.x;
    int yCapibaraActual = capibara.y + capibara.alto / 2;
    int xArdilla = Zorro.xEnemigo;
    int yArdilla = Zorro.yEnemigo + Zorro.altoEnemigo / 2;
    int distancia = calcular_distancia_entreDosPuntos(xCapibaraActual, yCapibaraActual, xArdilla, yArdilla);
    int numeroAleatorioGenerado = numeroAleatorio(1, 100);

    if (distancia < 20 && numeroAleatorioGenerado > 20) {
        golpearAlCapibara1(capibara, Zorro, numeroClase);
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
    }
}

void dibujarZorro(Capibara& capibara, Enemigo& Zorro, Coordenada*& coordenadas, int tamanio, bool& coordenadasOrdenadas, int& indiceActual, int numeroClase) {
    borrarZorro(Zorro.xEnemigo, Zorro.yEnemigo);

    if (Zorro.vida > 0) {
        if (Zorro.alejandose) {
            borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
            movimientoZorro(capibara, Zorro, coordenadas, tamanio, coordenadasOrdenadas, indiceActual);
        }
        else {
            if (Zorro.tiempoDescanso > 30) {
                ataqueZorro(capibara, Zorro, numeroClase);
            }
            Zorro.tiempoDescanso--;
            if (Zorro.tiempoDescanso <= 0 && Zorro.descansando) {
                Zorro.descansando = false;
                Zorro.alejandose = true;
                Zorro.tiempoDescanso = 100;
                Zorro.contadorDePasos = 0;
                Zorro.dxEnemigo = 1; // reiniciar dxEnemigo a un valor inicial si es necesario
                Zorro.dyEnemigo = 1; // reiniciar dyEnemigo a un valor inicial si es necesario
                for (int i = 0; i < tamanio; i++) {
                    coordenadas[i].coordenadaEncontrada = false;
                }
                coordenadasAleatorias(tamanio, Zorro, coordenadas);
            }
        }
        if (Zorro.xEnemigo < WIDTH / 2) {
            dibujarZorroEnemigo(Zorro.xEnemigo, Zorro.yEnemigo);
        }
        else {
            dibujarZorroIzquierda(Zorro.xEnemigo, Zorro.yEnemigo);
        }
    }
}

void capibaraAtaqueCocodrilos(Capibara& capibara, Enemigo*& enemigos, int tamanioCocodrilos, bool& moverArribaCapibara) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    // Inicializar booleanos de ataque
    capibara.atacarArriba = false;
    capibara.atacarAbajo = false;
    capibara.atacarDerecha = false;
    capibara.atacarIzquierda = false;

    if (capibara.atacar) {
        for (int i = 0; i < tamanioCocodrilos; i++) {
            int margen = enemigos[i].margen;

            // Capibara ataca por arriba
            if (nuevoY + capibara.alto > enemigos[i].yEnemigo - margen &&
                nuevoY < enemigos[i].yEnemigo + margen &&
                capibara.x + capibara.ancho > enemigos[i].xEnemigo - margen &&
                capibara.x < enemigos[i].xEnemigo + enemigos[i].anchoEnemigo + margen) {
                capibara.atacarAbajo = true;
                capibara.contadorDeGolpes++;
                if (capibara.estamina <= 0) {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido;
                }
                else {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido * 10;
                    capibara.contadorDeGolpesFuertes++;
                }
            }
            // Capibara ataca por abajo
            else if (nuevoY < enemigos[i].yEnemigo + enemigos[i].altoEnemigo + margen &&
                nuevoY + capibara.alto > enemigos[i].yEnemigo + enemigos[i].altoEnemigo - margen &&
                capibara.x + capibara.ancho > enemigos[i].xEnemigo - margen &&
                capibara.x < enemigos[i].xEnemigo + enemigos[i].anchoEnemigo + margen) {
                capibara.atacarArriba = true;
                capibara.contadorDeGolpes++;
                if (capibara.estamina <= 0) {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido;
                }
                else {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido * 10;
                    capibara.contadorDeGolpesFuertes++;
                }
            }
            // Capibara ataca por izquierda
            else if (nuevoX + capibara.ancho > enemigos[i].xEnemigo - margen &&
                nuevoX < enemigos[i].xEnemigo + margen &&
                capibara.y + capibara.alto > enemigos[i].yEnemigo - margen &&
                capibara.y < enemigos[i].yEnemigo + enemigos[i].altoEnemigo + margen) {
                capibara.atacarDerecha = true;
                capibara.contadorDeGolpes++;
                if (capibara.estamina <= 0) {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido;
                }
                else {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido * 10;
                    capibara.contadorDeGolpesFuertes++;
                }
            }
            // Capibara ataca por la derecha
            else if (nuevoX < enemigos[i].xEnemigo + enemigos[i].anchoEnemigo + margen &&
                nuevoX + capibara.ancho > enemigos[i].xEnemigo + enemigos[i].anchoEnemigo - margen &&
                capibara.y + capibara.alto > enemigos[i].yEnemigo - margen &&
                capibara.y < enemigos[i].yEnemigo + enemigos[i].altoEnemigo + margen) {
                capibara.atacarIzquierda = true;
                capibara.contadorDeGolpes++;
                if (capibara.estamina <= 0) {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido;
                }
                else {
                    capibara.cambiarEstamina = true;
                    enemigos[i].vida -= enemigos[i].danioRecibido * 10;
                    capibara.contadorDeGolpesFuertes++;
                }
            }
        }
    }
}

void definir_posicionCapibara2(Capibara& capibara, Enemigo*& enemigo, int tamanioCocodrilos, int numeroClase) {
    bool perteneceEnemigo = false;
    int xAleatorio;
    int yAleatorio;
    do {
        perteneceEnemigo = false;
        xAleatorio = numeroAleatorio(0, Console::WindowWidth - capibara.ancho - capibara.dx - 15);
        yAleatorio = numeroAleatorio(15, Console::WindowHeight - capibara.alto - capibara.dy - 15);

        for (int i = 0; i < tamanioCocodrilos; i++) {

            // Verificando si el punto generado pertenece al un punto del capibara
            if ((xAleatorio + capibara.ancho > enemigo[i].xEnemigo) &&
                (xAleatorio < enemigo[i].xEnemigo + enemigo[i].anchoEnemigo) &&
                (yAleatorio + capibara.alto > enemigo[i].yEnemigo) &&
                (yAleatorio < enemigo[i].yEnemigo + enemigo[i].altoEnemigo)) {
                perteneceEnemigo = true;
            }
        }
    } while (perteneceEnemigo);
    moverHaciaCoordenadaCapibara(capibara, numeroClase, xAleatorio, yAleatorio);
}

// Movimiento jugador
void moverJugadorCocodrile(Capibara& capibara, Enemigo*& enemigos, int& tamanioEnemigos, Bloque*& bloques, int& tamanioBloques, char& tecla, Potion& pocion, bool& moverIzquierda, bool& moverArriba, int numeroClase) {
    bool colisionCocodrilo = false;
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    if (tecla == 'W' && capibara.y > capibara.dy) {
        nuevoY -= capibara.dy;
        moverArriba = true;
    }
    if (tecla == 'S' && capibara.y < Console::WindowHeight - capibara.alto - capibara.dy) {
        nuevoY += capibara.dy;
        moverArriba = false;
    }
    if (tecla == 'D' && capibara.x < Console::WindowWidth - capibara.ancho - capibara.dx) {
        nuevoX += capibara.dx;
        moverIzquierda = false;
    }
    if (tecla == 'A' && capibara.x > capibara.dx) {
        nuevoX -= capibara.dx;
        moverIzquierda = true;
    }

    // Colisiones con el enemigo
    for (int i = 0; i < tamanioEnemigos; i++) {
        if (enemigos[i].vida > 0) {

            if (nuevoY + capibara.alto > enemigos[i].yEnemigo &&
                nuevoY < enemigos[i].yEnemigo + enemigos[i].altoEnemigo &&
                nuevoX + capibara.ancho > enemigos[i].xEnemigo &&
                nuevoX < enemigos[i].xEnemigo + enemigos[i].anchoEnemigo) {
                // Ajustar la posición del jugador para evitar la colisión
                if (tecla == 'W') {
                    nuevoY = enemigos[i].yEnemigo + enemigos[i].altoEnemigo;
                }
                else if (tecla == 'S') {
                    nuevoY = enemigos[i].yEnemigo - capibara.alto;
                }
                else if (tecla == 'D') {
                    nuevoX = enemigos[i].xEnemigo - capibara.ancho;
                }
                else if (tecla == 'A') {
                    nuevoX = enemigos[i].xEnemigo + enemigos[i].anchoEnemigo;
                }
                colisionCocodrilo = true;
                if (enemigos[i].dxEnemigo > 0) {
                    miniCocodrileAttackRight(enemigos[i].xEnemigo, enemigos[i].yEnemigo);
                }
                else {
                    miniCocodrileAttack(enemigos[i].xEnemigo, enemigos[i].yEnemigo);
                }
            }
        }
    }

    // Colisiones con los bloques
    for (int i = 0; i < tamanioBloques; i++) {
        if (capibara.vida > 0) {
            if (nuevoY + capibara.alto > bloques[i].y &&
                nuevoY < bloques[i].y + bloques[i].alto &&
                nuevoX + capibara.ancho > bloques[i].x &&
                nuevoX < bloques[i].x + bloques[i].ancho) {
                // Ajustar la posición del jugador para evitar la colisión
                if (tecla == 'W') {
                    nuevoY = bloques[i].y + bloques[i].alto;
                }
                else if (tecla == 'S') {
                    nuevoY = bloques[i].y - capibara.alto;
                }
                else if (tecla == 'D') {
                    nuevoX = bloques[i].x - capibara.ancho;
                }
                else if (tecla == 'A') {
                    nuevoX = bloques[i].x + bloques[i].ancho;
                }
            }
        }
    }

    // Colisiones con pocion
    if (!pocion.desaparecer &&
        nuevoX + capibara.ancho > pocion.x &&
        nuevoX < pocion.x + pocion.ancho &&
        nuevoY + capibara.alto > pocion.y &&
        nuevoY < pocion.y + pocion.alto) {
        borrar_pocion(pocion.x, pocion.y);
        capibara.recibeMejora = true;
        pocion.desaparecer = true;

        capibara.estamina += pocion.aumentarFuerza;
        if (capibara.estamina > 100) {
            capibara.estamina = 100;
        }
        capibara.vida += pocion.aumentarVida;
        if (capibara.vida > 100) {
            capibara.vida = 100;
        }
        capibara.mana += pocion.aumentarMana;
        if (capibara.mana > 100) {
            capibara.mana = 100;
        }
    }

    capibara.x = nuevoX;
    capibara.y = nuevoY;

    if (colisionCocodrilo) {
        int numeroGenerado = numeroAleatorio(1, 100);
        if (numeroGenerado > 50) {
            definir_posicionCapibara2(capibara, enemigos, tamanioEnemigos, numeroClase);
            if (capibara.mana <= 0) {
                capibara.vida -= 10;
                capibara.cambiarMana = true;
            }
            else {
                capibara.cambiarMana = true;
                capibara.vida -= 1;
                capibara.contadorDeInmunidad++;
            }
        }
    }
}

void moverCocodrilo(Capibara& capibara, Enemigo& cocodrilo) {
    // Mueve el cocodrilo
    cocodrilo.direccionDerecha = false;
    cocodrilo.direccionIzquierda = false;
    cocodrilo.xEnemigo += cocodrilo.dxEnemigo;

    // Verifica si se sale de los límites y ajusta la dirección si es necesario
    if (cocodrilo.xEnemigo < 0) {
        cocodrilo.xEnemigo = 0;
        cocodrilo.dxEnemigo = -cocodrilo.dxEnemigo; // Invierte la dirección
    }
    else if (cocodrilo.xEnemigo >= WIDTH - cocodrilo.anchoEnemigo) {
        cocodrilo.xEnemigo = WIDTH - cocodrilo.anchoEnemigo;
        cocodrilo.dxEnemigo = -cocodrilo.dxEnemigo; // Invierte la dirección
    }

    if (cocodrilo.dxEnemigo > 0) {
        cocodrilo.direccionIzquierda = true;
    }
    else {
        cocodrilo.direccionDerecha = true;
    }
}

void moverBolaDeFuego(Capibara& capibara, Enemigo*& cocodrilos, Enemigo& cocodrilo, Bloque*& bloques, int& tamanioBloques, int tamanioCocodrilos) {
    capibara.recibeDanio = false;
    cocodrilo.bolaDeFuego.y += cocodrilo.bolaDeFuego.dy;
    if (cocodrilo.bolaDeFuego.y > (HEIGHT - cocodrilo.bolaDeFuego.alto - cocodrilo.bolaDeFuego.dy) || (cocodrilo.bolaDeFuego.y < 0)) {
        cocodrilo.bolaDeFuego.activo = false;
    }

    // Colisiones con el capibara
    if ((cocodrilo.bolaDeFuego.x + cocodrilo.bolaDeFuego.ancho > capibara.x && cocodrilo.bolaDeFuego.x < capibara.x + capibara.ancho) &&
        (cocodrilo.bolaDeFuego.y + cocodrilo.bolaDeFuego.alto > capibara.y && cocodrilo.bolaDeFuego.y < capibara.y + capibara.alto)) {
        capibara.recibeDanio = true;
    }

    // Colisiones con los bloques
    for (int i = 0; i < tamanioBloques; i++) {
        if (cocodrilo.bolaDeFuego.y + capibara.alto > bloques[i].y &&
            cocodrilo.bolaDeFuego.y < bloques[i].y + bloques[i].alto &&
            cocodrilo.bolaDeFuego.x + capibara.ancho > bloques[i].x &&
            cocodrilo.bolaDeFuego.x < bloques[i].x + bloques[i].ancho) {
            // Ajustar la posición del jugador para evitar la colisión
            cocodrilo.bolaDeFuego.activo = false;
        }
    }

    if (!cocodrilo.bolaDeFuego.activo) {
        if (cocodrilo.bolaDeFuego.id == 0) {
            int yInicial = 5;
            cocodrilo.bolaDeFuego.y = yInicial; // Actualiza la posición de la bola de fuego
            cocodrilos[1].bolaDeFuego.activo = true;
        }

        if (cocodrilo.bolaDeFuego.id == 1) {
            int yInicial = HEIGHT - 15;
            cocodrilo.bolaDeFuego.y = yInicial; // Actualiza la posición de la bola de fuego
            cocodrilos[0].bolaDeFuego.activo = true;
        }
    }

    if (capibara.recibeDanio) {
        if (capibara.mana <= 0) {
            capibara.vida -= 1;
            capibara.cambiarMana = true;
        }
        else {
            capibara.cambiarMana = true;
            capibara.vida -= 1;
            capibara.contadorDeInmunidad++;
        }
    }
}

void lanzarBolasDeFuego(Capibara& capibara, Enemigo*& cocodrilos, Enemigo& cocodrilo, int tamanioCocodrilos, Bloque*& bloques, int& tamanioBloques) {
    if (cocodrilo.bolaDeFuego.activo) {
        borrarBolaDeFuego(cocodrilo.bolaDeFuego.x, cocodrilo.bolaDeFuego.y);
        cocodrilo.bolaDeFuego.x = cocodrilo.xEnemigo + (cocodrilo.anchoEnemigo / 2);
        moverBolaDeFuego(capibara, cocodrilos, cocodrilo, bloques, tamanioBloques, tamanioCocodrilos);
        // chequear si su turno esta activo y luego dibujar
        if (cocodrilo.bolaDeFuego.activo) {
            dibujarBolaDeFuego(cocodrilo.bolaDeFuego.x, cocodrilo.bolaDeFuego.y);
        }
    }
}

void dibujarMiniCocodrilo(Capibara& capibara, Enemigo*& cocodrilos, int& tamanioCocodrilos) {
    for (int i = 0; i < tamanioCocodrilos; i++) {
        borrarCocodrile1(cocodrilos[i].xEnemigo, cocodrilos[i].yEnemigo);
        if (cocodrilos[i].vida > 0) {
            moverCocodrilo(capibara, cocodrilos[i]);
            if (cocodrilos[i].direccionDerecha) {
                miniCocodrile(cocodrilos[i].xEnemigo, cocodrilos[i].yEnemigo);
            }
            else {
                miniCocodrileRight(cocodrilos[i].xEnemigo, cocodrilos[i].yEnemigo);
            }
        }
    }
}

// HACER UNA FUNCION QUE VERIFIQUE A QUE COCODRILO LE TOCA DISPARAR
int verificarTurno(Enemigo*& cocodrilos, int tamanioCocodrilos) {
    if (cocodrilos[0].bolaDeFuego.activo) {
        cocodrilos[1].bolaDeFuego.activo = false;
        return 0;
    }
    else {
        cocodrilos[1].bolaDeFuego.activo = true;
    }

    if (cocodrilos[1].bolaDeFuego.activo) {
        cocodrilos[0].bolaDeFuego.activo = false;
        return 1;
    }
    else {
        cocodrilos[1].bolaDeFuego.activo = true;
    }
}

void turnoDeLanzamiento(Capibara& capibara, Enemigo*& cocodrilos, int tamanioCocodrilos, Bloque*& bloques, int& tamanioBloques) {
    int numeroDeTurno;
    numeroDeTurno = verificarTurno(cocodrilos, tamanioCocodrilos);
    lanzarBolasDeFuego(capibara, cocodrilos, cocodrilos[numeroDeTurno], tamanioCocodrilos, bloques, tamanioBloques);
}

void mover_soljsjsjjs(int x1, int y1, int dx, int dy) {
    cout << YELLOW;
    sol1(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol2(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol3(x1, y1);
    _sleep(50);
    borrar_soljsjjss(x1, y1);

    sol4(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol5(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol6(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol7(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol8(x1, y1);
    borrar_soljsjjss(x1, y1);

    sol9(x1, y1);
    borrar_soljsjjss(x1, y1);
    cout << RESET;
}

void mover_lunajsjsjjs(int x1, int y1, int dx, int dy) {
    cout << BLUE;
    luna1(x1, y1);
    borrar_luna(x1, y1);

    luna2(x1, y1);
    borrar_luna(x1, y1);

    luna3(x1, y1);
    borrar_luna(x1, y1);

    luna4(x1, y1);
    borrar_luna(x1, y1);

    luna5(x1, y1);
    borrar_luna(x1, y1);

    luna6(x1, y1);
    borrar_luna(x1, y1);

    luna7(x1, y1);
    borrar_luna(x1, y1);

    luna8(x1, y1);
    borrar_luna(x1, y1);

    luna9(x1, y1);
    borrar_luna(x1, y1);
    cout << RESET;
}

void moverHaciaCoordenadaDragon(Enemigo& dragon, int objetivo_x, int objetivo_y) {
    int dir_x;
    int dir_y;
    const double epsilon = 0.001; // Margen de error permitido

    while (abs(dragon.xEnemigo - objetivo_x) > epsilon || abs(dragon.yEnemigo - objetivo_y) > epsilon) {
        borrarDragon(dragon.xEnemigo, dragon.yEnemigo);

        if (objetivo_x > dragon.xEnemigo) {
            dir_x = 1;
        }
        else if (objetivo_x < dragon.xEnemigo) {
            dir_x = -1;
        }
        else {
            dir_x = 0;
        }

        if (objetivo_y > dragon.yEnemigo) {
            dir_y = 1;
        }
        else if (objetivo_y < dragon.yEnemigo) {
            dir_y = -1;
        }
        else {
            dir_y = 0;
        }

        double nuevo_x = dragon.xEnemigo + dir_x * dragon.dxEnemigo;
        double nuevo_y = dragon.yEnemigo + dir_y * dragon.dyEnemigo;

        // Ajusta las coordenadas si están suficientemente cerca del objetivo
        if (abs(nuevo_x - objetivo_x) < abs(dir_x * dragon.dxEnemigo)) {
            nuevo_x = objetivo_x;
        }

        if (abs(nuevo_y - objetivo_y) < abs(dir_y * dragon.dyEnemigo)) {
            nuevo_y = objetivo_y;
        }

        dragon.xEnemigo = nuevo_x;
        dragon.yEnemigo = nuevo_y;

        dibujarDragon(dragon.xEnemigo, dragon.yEnemigo);
    }
}

void movimientoDragon1(Capibara& capibara, Enemigo& dragon, bool& moverArribaCapibara) {

    if (dragon.tiempoAlejamiento <= 50) {
        bool colisionConsola = false;

        int xCapibaraActual = capibara.x;
        int yCapibaraActual = capibara.y + capibara.alto / 2;
        int xdragon = dragon.xEnemigo;
        int ydragon = dragon.yEnemigo + dragon.altoEnemigo / 2;

        // Capibara esta a la derecha
        if (capibara.x > dragon.xEnemigo) {
            xdragon += dragon.anchoEnemigo;
        }
        // Capibara esta a la izquierda
        else {
            xCapibaraActual += capibara.ancho;
        }
        // Distancia entre capibara y dragon
        int distanciaEntredragonYCapibara = calcular_distancia_entreDosPuntos(xCapibaraActual, yCapibaraActual, xdragon, ydragon);



        if (distanciaEntredragonYCapibara < 40) {
            dragon.alejandose = true;
            // Si el dragon esta en la izquierda de la capibara
            if (xCapibaraActual > xdragon) {
                dragon.xEnemigo -= 5;
                dragon.tiempoAlejamiento++;
            }
            // Si el dragon esta en la derecha de la capibara
            if (xCapibaraActual < xdragon) {
                dragon.xEnemigo += 5;
                dragon.tiempoAlejamiento++;
            }
            if (moverArribaCapibara) {
                if (yCapibaraActual > ydragon) {
                    dragon.yEnemigo -= 5;
                    dragon.tiempoAlejamiento++;
                }
            }
            else {
                if (yCapibaraActual < ydragon) {
                    dragon.yEnemigo += 5;
                    dragon.tiempoAlejamiento++;
                }
            }
        }
        else {
            dragon.alejandose = false;
        }

        if (dragon.xEnemigo < 0) {
            dragon.xEnemigo = 0;
            colisionConsola = true;
        }
        else if (dragon.xEnemigo > (Console::WindowWidth - dragon.anchoEnemigo - dragon.dxEnemigo)) {
            dragon.xEnemigo = Console::WindowWidth - dragon.anchoEnemigo - dragon.dxEnemigo;
            colisionConsola = true;
        }

        if (dragon.yEnemigo < 0) {
            dragon.yEnemigo = 0;
            colisionConsola = true;
        }
        else if (dragon.yEnemigo > (Console::WindowHeight - dragon.altoEnemigo - dragon.dyEnemigo)) {
            dragon.yEnemigo = Console::WindowHeight - dragon.altoEnemigo - dragon.dyEnemigo;
            colisionConsola = true;
        }

        if (colisionConsola) {
            definir_posicionEnemigo(capibara, dragon);
            Console::Clear();
        }
        moverArribaCapibara = false;
        colisionConsola = false;
    }
}

void lanzarBolaDeFuegoDragon(Capibara& capibara, Enemigo& enemigo, bool& moverArriba) {
    if (!enemigo.descansando && enemigo.bolaDeFuego.tiempoDisparo > 0) {
        capibara.recibeDanio = false;
        borrarBolaDeFuego(enemigo.bolaDeFuego.x, enemigo.bolaDeFuego.y);

        float dirX, dirY;

        if (capibara.x - enemigo.bolaDeFuego.x != 0) {
            dirX = (capibara.x - enemigo.bolaDeFuego.x) / abs(capibara.x - enemigo.bolaDeFuego.x);
        }
        else {
            dirX = 0;
        }

        if (capibara.y - enemigo.bolaDeFuego.y != 0) {
            dirY = (capibara.y - enemigo.bolaDeFuego.y) / abs(capibara.y - enemigo.bolaDeFuego.y);
        }
        else {
            dirY = 0;
        }

        if (dirX != 0 || dirY != 0) {
            enemigo.bolaDeFuego.x += dirX * enemigo.bolaDeFuego.dx;
            enemigo.bolaDeFuego.y += dirY * enemigo.bolaDeFuego.dy;
        }

        // Colisiones con el capibara
        if ((enemigo.bolaDeFuego.x + enemigo.bolaDeFuego.ancho > capibara.x && enemigo.bolaDeFuego.x < capibara.x + capibara.ancho) &&
            (enemigo.bolaDeFuego.y + enemigo.bolaDeFuego.alto > capibara.y && enemigo.bolaDeFuego.y < capibara.y + capibara.alto)) {
            capibara.recibeDanio = true;
            enemigo.bolaDeFuego.desaparecer = true;
        }

        // Distancia entre bellota y capibara
        int distancia = calcular_distancia_entreDosPuntos(enemigo.bolaDeFuego.x, enemigo.bolaDeFuego.y, enemigo.xEnemigo + enemigo.anchoEnemigo / 2, enemigo.yEnemigo + enemigo.altoEnemigo / 2);

        if (distancia > 100) {
            enemigo.bolaDeFuego.desaparecer = true;
        }

        // Dibuja la bellota solo si no debe desaparecer
        if (!enemigo.bolaDeFuego.desaparecer) {
            dibujarBolaDeFuego(enemigo.bolaDeFuego.x, enemigo.bolaDeFuego.y);
        }
        else {
            borrarBolaDeFuego(enemigo.bolaDeFuego.x, enemigo.bolaDeFuego.y);
            // Reiniciar la posici�n de la bellota en la enemigo
            enemigo.bolaDeFuego.x = enemigo.xEnemigo + (enemigo.anchoEnemigo / 2);
            enemigo.bolaDeFuego.y = enemigo.yEnemigo + (enemigo.altoEnemigo / 2);
            enemigo.bolaDeFuego.desaparecer = false;
            enemigo.bolaDeFuego.tiempoDisparo--;
        }

        if (capibara.recibeDanio) {
            if (capibara.mana <= 0) {
                capibara.vida -= 10;
                capibara.cambiarMana = true;
            }
            else {
                capibara.cambiarMana = true;
                capibara.vida -= 1;
                capibara.contadorDeInmunidad++;
            }
        }
    }
}

// Movimiento Dragon:
void iniciarDragon1(Capibara& capibara, Enemigo& enemigo, BolaDeFuego& bolaDeFuego, bool& moverArribaCapibara, int numeroClase) {
    borrarDragon(enemigo.xEnemigo, enemigo.yEnemigo);
    if (enemigo.vida > 0) {
        if (!enemigo.descansando) {
            movimientoDragon1(capibara, enemigo, moverArribaCapibara);
            lanzarBolaDeFuegoDragon(capibara, enemigo, moverArribaCapibara);
        }
        else {
            enemigo.tiempoDescanso--;
            if (enemigo.tiempoDescanso <= 0) {
                enemigo.descansando = false;
                enemigo.alejandose = true;
                enemigo.tiempoAlejamiento = 0;
                bolaDeFuego.tiempoDisparo = 5;
            }
        }

        if (enemigo.xEnemigo < WIDTH / 2) {
            dibujarDragonDerecha(enemigo.xEnemigo, enemigo.yEnemigo);
        }
        else {
            dibujarDragon(enemigo.xEnemigo, enemigo.yEnemigo);
        }
    }
}

void movimientoenemigo(Capibara& capibara, Enemigo& enemigo, Coordenada*& coordenadas, int tamanio, bool& coordenadasOrdenadas, int& indiceActual) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    bool todasLasCoordenadasEncontradas = false;
    if (!coordenadasOrdenadas) {
        ordenarDistancias(enemigo, coordenadas, tamanio);
        coordenadasOrdenadas = true;
    }

    while (indiceActual < tamanio) {
        Coordenada objetivo = coordenadas[indiceActual];
        if (objetivo.coordenadaEncontrada == false) {
            moverHaciaCoordenadaDragon(enemigo, objetivo.x + objetivo.ancho / 2, objetivo.y + 1);
            // Colisiones con el capibara
            int margen = enemigo.margen; // Usar el margen del enemigo

            if (nuevoY + capibara.alto > enemigo.yEnemigo - margen &&
                nuevoY < enemigo.yEnemigo + margen &&
                capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
                capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoY < enemigo.yEnemigo + enemigo.altoEnemigo + margen &&
                nuevoY + capibara.alto > enemigo.yEnemigo + enemigo.altoEnemigo - margen &&
                capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
                capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoX + capibara.ancho > enemigo.xEnemigo - margen &&
                nuevoX < enemigo.xEnemigo + margen &&
                capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
                capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
            else if (nuevoX < enemigo.xEnemigo + enemigo.anchoEnemigo + margen &&
                nuevoX + capibara.ancho > enemigo.xEnemigo + enemigo.anchoEnemigo - margen &&
                capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
                capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }

            if (abs(enemigo.xEnemigo - (objetivo.x + objetivo.ancho / 2)) < 0.001 &&
                abs(enemigo.yEnemigo - (objetivo.y + 1)) < 0.001) {
                coordenadas[indiceActual].coordenadaEncontrada = true;
                indiceActual++;
                enemigo.contadorDePasos++;
            }
        }
    }

    for (int i = 0; i < tamanio; i++) {
        if (coordenadas[i].coordenadaEncontrada) {
            todasLasCoordenadasEncontradas = true;
        }
        else {
            todasLasCoordenadasEncontradas = false;
            break;
        }
    }

    // Si el movimiento choca con el capibara que le quite 10 de vida

    if (todasLasCoordenadasEncontradas && enemigo.contadorDePasos == tamanio) {
        enemigo.alejandose = false;
        enemigo.descansando = true;
        indiceActual = 0;
        coordenadasOrdenadas = false;
    }
}

void golpearAlCapibara2(Capibara& capibara, Enemigo& enemigo, int numeroClase) {
    bool colisionConsola = false;
    if (capibara.mana <= 0) {
        capibara.vida -= 10;
        capibara.cambiarMana = true;
    }
    else {
        capibara.cambiarMana = true;
        capibara.vida -= 1;
        capibara.contadorDeInmunidad++;
    }

    if (enemigo.xEnemigo < WIDTH / 2) {
        dibujarDragonAtaqueIzquierda(enemigo.xEnemigo, enemigo.yEnemigo);
    }
    else {
        dibujarDragonAtaqueDerecha(enemigo.xEnemigo, enemigo.yEnemigo);
    }

    definir_posicionCapibara(capibara, enemigo, numeroClase);

    // Colision consola con el capibara
    if (capibara.x < 0) {
        capibara.x = 0;
        colisionConsola = true;
    }
    else if (capibara.x > (Console::WindowWidth - capibara.ancho - capibara.dx)) {
        capibara.x = Console::WindowWidth - capibara.ancho - capibara.dx;
        colisionConsola = true;
    }

    if (capibara.y < 0) {
        capibara.y = 0;
        colisionConsola = true;
    }
    else if (capibara.y > (Console::WindowHeight - capibara.alto - capibara.dy)) {
        capibara.y = Console::WindowHeight - capibara.alto - capibara.dy;
        colisionConsola = true;
    }

    if (colisionConsola) {
        definir_posicionCapibara(capibara, enemigo, numeroClase);
        Console::Clear();
    }
    colisionConsola = false;
}

void ataqueenemigo(Capibara& capibara, Enemigo& enemigo, int numeroClase) {
    int xCapibaraActual = capibara.x;
    int yCapibaraActual = capibara.y + capibara.alto / 2;
    int xDragon = enemigo.xEnemigo;
    int yDragon = enemigo.yEnemigo + enemigo.altoEnemigo / 2;
    int distancia = calcular_distancia_entreDosPuntos(xCapibaraActual, yCapibaraActual, xDragon, yDragon);
    int numeroAleatorioGenerado = numeroAleatorio(1, 100);

    if (distancia < 20 && numeroAleatorioGenerado > 20) {
        golpearAlCapibara2(capibara, enemigo, numeroClase);
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
    }
}

void iniciarDragon2(Capibara& capibara, Enemigo& enemigo, Coordenada*& coordenadas, int tamanio, bool& coordenadasOrdenadas, int& indiceActual, int numeroClase) {
    borrarDragon(enemigo.xEnemigo, enemigo.yEnemigo);

    if (enemigo.vida > 0) {
        if (enemigo.alejandose) {
            borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
            movimientoenemigo(capibara, enemigo, coordenadas, tamanio, coordenadasOrdenadas, indiceActual);
        }
        else {
            if (enemigo.tiempoDescanso > 30) {
                ataqueenemigo(capibara, enemigo, numeroClase);
            }
            enemigo.tiempoDescanso--;
            if (enemigo.tiempoDescanso <= 0 && enemigo.descansando) {
                enemigo.descansando = false;
                enemigo.alejandose = true;
                enemigo.tiempoDescanso = 100;
                enemigo.contadorDePasos = 0;
                enemigo.dxEnemigo = 1; // reiniciar dxEnemigo a un valor inicial si es necesario
                enemigo.dyEnemigo = 1; // reiniciar dyEnemigo a un valor inicial si es necesario
                for (int i = 0; i < tamanio; i++) {
                    coordenadas[i].coordenadaEncontrada = false;
                }
                coordenadasAleatorias(tamanio, enemigo, coordenadas);
            }
        }

        if (enemigo.xEnemigo < WIDTH / 2) {
            dibujarDragonDerecha(enemigo.xEnemigo, enemigo.yEnemigo);
        }
        else {
            dibujarDragon(enemigo.xEnemigo, enemigo.yEnemigo);
        }
    }
}

// Ataque al dragon:
void capibaraAtaqueDragon(Capibara& capibara, Enemigo& enemigo, Coordenada* coordenadas, int& tamanio, bool& coordenadasOrdenadas, int& indiceActual, BolaDeFuego& bolaDeFuego, bool& moverArribaCapibara, bool& dragon1, bool& dragon2) {
    int nuevoX = capibara.x;
    int nuevoY = capibara.y;

    // Inicializar booleanos de ataque
    capibara.atacarArriba = false;
    capibara.atacarAbajo = false;
    capibara.atacarDerecha = false;
    capibara.atacarIzquierda = false;

    if (capibara.atacar) {
        int margen = enemigo.margen;

        // Capibara ataca por arriba
        if (nuevoY + capibara.alto > enemigo.yEnemigo - margen &&
            nuevoY < enemigo.yEnemigo + margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarAbajo = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por abajo
        else if (nuevoY < enemigo.yEnemigo + enemigo.altoEnemigo + margen &&
            nuevoY + capibara.alto > enemigo.yEnemigo + enemigo.altoEnemigo - margen &&
            capibara.x + capibara.ancho > enemigo.xEnemigo - margen &&
            capibara.x < enemigo.xEnemigo + enemigo.anchoEnemigo + margen) {
            capibara.atacarArriba = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por izquierda
        else if (nuevoX + capibara.ancho > enemigo.xEnemigo - margen &&
            nuevoX < enemigo.xEnemigo + margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarDerecha = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
        // Capibara ataca por la derecha
        else if (nuevoX < enemigo.xEnemigo + enemigo.anchoEnemigo + margen &&
            nuevoX + capibara.ancho > enemigo.xEnemigo + enemigo.anchoEnemigo - margen &&
            capibara.y + capibara.alto > enemigo.yEnemigo - margen &&
            capibara.y < enemigo.yEnemigo + enemigo.altoEnemigo + margen) {
            capibara.atacarIzquierda = true;
            capibara.contadorDeGolpes++;
            if (capibara.estamina <= 0) {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido;
            }
            else {
                capibara.cambiarEstamina = true;
                enemigo.vida -= enemigo.danioRecibido * 10;
                capibara.contadorDeGolpesFuertes++;
            }
        }
    }
}

void lanzamientoDeBolaRocosa(Capibara& capibara, Enemigo& enemigo, Coordenada*& coordenadasBolasRocosas, Coordenada& bolaRocosa, int& tamanioBolasRocosas) {
    capibara.recibeDanio = false;
    bolaRocosa.y += bolaRocosa.dy;
    if (bolaRocosa.y > (HEIGHT - bolaRocosa.alto - bolaRocosa.dy) || (bolaRocosa.y < 0)) {
        bolaRocosa.activo = false;
    }

    // Colisiones con el capibara
    if ((bolaRocosa.x + bolaRocosa.ancho > capibara.x && bolaRocosa.x < capibara.x + capibara.ancho) &&
        (bolaRocosa.y + bolaRocosa.alto > capibara.y && bolaRocosa.y < capibara.y + capibara.alto)) {
        capibara.recibeDanio = true;
        bolaRocosa.activo = false;
    }

    if (!bolaRocosa.activo) {
        bolaRocosa.y = bolaRocosa.yInicial; // Actualiza la posición de la bola de fuego
    }

    if (capibara.recibeDanio) {
        if (capibara.mana <= 0) {
            capibara.vida -= 10;
            capibara.cambiarMana = true;
        }
        else {
            capibara.cambiarMana = true;
            capibara.vida -= 1;
            capibara.contadorDeInmunidad++;
        }
    }
}

void lanzarBolasRocosas(Capibara& capibara, Enemigo& enemigo, Llamarada*& llamaradas, Coordenada*& coordenadasBolasRocosas, int& tamanioBolasRocosas) {
    for (int i = 0; i < tamanioBolasRocosas; i++) {
        if (coordenadasBolasRocosas[i].activo) {
            borrarBolaRocosa(coordenadasBolasRocosas[i].x, coordenadasBolasRocosas[i].y);
            lanzamientoDeBolaRocosa(capibara, enemigo, coordenadasBolasRocosas, coordenadasBolasRocosas[i], tamanioBolasRocosas);
            if (coordenadasBolasRocosas[i].activo) {
                dibujarBolaRocosa(coordenadasBolasRocosas[i].x, coordenadasBolasRocosas[i].y);
            }
        }
    }
}

void lanzarLlamarada(Capibara& capibara, Enemigo& enemigo, Llamarada*& llamaradas, int& tamanioLlamaradas, bool& moverArribaCapibara) {
    if (!enemigo.descansando && llamaradas[1].tiempoDisparo > 0) {
        capibara.recibeDanio = false;
        // Borrar las llamaradas anteriores
        for (int i = 0; i < tamanioLlamaradas; i++) {
            borrarLlamarada(llamaradas[i].x, llamaradas[i].y);
        }

        int dxDirection;
        if (capibara.x > enemigo.xEnemigo) {
            dxDirection = 2; // Capibara a la derecha del dragon, llamaradas hacia la izquierda
        }
        else {
            dxDirection = -2; // Capibara a la izquierda del dragon, llamaradas hacia la derecha
        }

        llamaradas[0].dx = dxDirection;
        llamaradas[0].dy = -2; // Diagonal arriba
        llamaradas[1].dx = dxDirection;
        llamaradas[1].dy = 0; // Hacia adelante
        llamaradas[2].dx = dxDirection;
        llamaradas[2].dy = 2; // Diagonal abajo

        // Actualizar las posiciones de las llamaradas
        for (int i = 0; i < tamanioLlamaradas; i++) {
            llamaradas[i].x += llamaradas[i].dx;
            llamaradas[i].y += llamaradas[i].dy;


            // Colisiones con el capibara
            if ((llamaradas[i].x + llamaradas[i].ancho > capibara.x && llamaradas[i].x < capibara.x + capibara.ancho) &&
                (llamaradas[i].y + llamaradas[i].alto > capibara.y && llamaradas[i].y < capibara.y + capibara.alto)) {
                capibara.recibeDanio = true;
                llamaradas[i].desaparecer = true;
            }

            // Verificar colisiones con los límites de la consola en función de dx y dy
            int margen = 2; // margen de seguridad para manejar altas velocidades
            if ((llamaradas[i].dx > 0 && llamaradas[i].x + llamaradas[i].ancho >= WIDTH - margen) ||
                (llamaradas[i].dx < 0 && llamaradas[i].x <= margen) ||
                (llamaradas[i].dy > 0 && llamaradas[i].y + llamaradas[i].alto >= HEIGHT - margen) ||
                (llamaradas[i].dy < 0 && llamaradas[i].y <= margen)) {
                llamaradas[i].desaparecer = true;
            }
            // Dibujar o reiniciar las llamaradas
            if (!enemigo.llamaradas[i].desaparecer) {
                if (enemigo.xEnemigo < WIDTH / 2) {
                    dibujoLlamarada(llamaradas[i].x, llamaradas[i].y);
                }
                else {
                    dibujoLlamaradaIzquierda(llamaradas[i].x, llamaradas[i].y);
                }
            }
            else {
                borrarLlamarada(llamaradas[i].x, llamaradas[i].y);
                // Reiniciar la posicion de la llamarada enemigo
                llamaradas[i].x = enemigo.xEnemigo + (enemigo.anchoEnemigo / 2);
                llamaradas[i].y = enemigo.yEnemigo + (enemigo.altoEnemigo / 2);
                llamaradas[i].desaparecer = false;
                llamaradas[i].tiempoDisparo--;
            }

            if (capibara.recibeDanio) {
                if (capibara.mana <= 0) {
                    capibara.vida -= 10;
                    capibara.cambiarMana = true;
                }
                else {
                    capibara.cambiarMana = true;
                    capibara.vida -= 1;
                    capibara.contadorDeInmunidad++;
                }
            }
        }
    }
}

void iniciarDragon3(Capibara& capibara, Enemigo& enemigo, Llamarada*& llamaradas, int& tamanioLlamaradas, bool& moverArribaCapibara, int numeroClase) {
    borrarDragon(enemigo.xEnemigo, enemigo.yEnemigo);
    if (enemigo.vida > 0) {
        if (!enemigo.descansando) {
            movimientoDragon1(capibara, enemigo, moverArribaCapibara);
            lanzarLlamarada(capibara, enemigo, llamaradas, tamanioLlamaradas, moverArribaCapibara);
        }
        else {
            enemigo.tiempoDescanso--;
            if (enemigo.tiempoDescanso <= 0) {
                enemigo.descansando = false;
                enemigo.alejandose = true;
                enemigo.tiempoAlejamiento = 0;
                llamaradas[0].tiempoDisparo = 5;
                llamaradas[1].tiempoDisparo = 5;
                llamaradas[2].tiempoDisparo = 5;
                // Borrar las llamaradas
                for (int i = 0; i < tamanioLlamaradas; i++) {
                    llamaradas[i].activo = false;
                }
            }
        }

        if (enemigo.xEnemigo < WIDTH / 2) {
            dibujarDragonDerecha(enemigo.xEnemigo, enemigo.yEnemigo);
        }
        else {
            dibujarDragon(enemigo.xEnemigo, enemigo.yEnemigo);
        }
    }
}

Potion generarPocion() {
    int numero = numeroAleatorio(1, 4);
    Potion nuevaPocion; // Inicialización de la poción
    nuevaPocion.id = numero;

    switch (numero) {
    case 1: // pocion cheta
        nuevaPocion.aumentarFuerza = 100;
        nuevaPocion.aumentarMana = 100;
        nuevaPocion.aumentarVida = 100;
        break;
    case 2: // pocion fuerza
        nuevaPocion.aumentarFuerza = 100;
        break;
    case 3: // pocion mana
        nuevaPocion.aumentarMana = 100;
        break;
    case 4: // pocion vida
        nuevaPocion.aumentarVida = 100;
        break;
    }

    nuevaPocion.ancho = 10;
    nuevaPocion.alto = 5;
    nuevaPocion.desaparecer = false;
    return nuevaPocion;
}

void definir_posicionObjeto2(Capibara& capibara, Enemigo*& cocodrilos, int tamanioCocodrilos, Potion& pocion) {
    bool posicionValida = false;
    int xAleatorio, yAleatorio;

    while (!posicionValida) {
        xAleatorio = numeroAleatorio(0, Console::WindowWidth - pocion.ancho - 10);
        yAleatorio = numeroAleatorio(10, Console::WindowHeight - pocion.alto - 10);

        bool perteneceCapi = (xAleatorio >= capibara.x && xAleatorio < capibara.x + capibara.ancho) &&
            (yAleatorio >= capibara.y && yAleatorio < capibara.y + capibara.alto);

        bool perteneceEnemigo = false;
        for (int i = 0; i < tamanioCocodrilos; i++) {
            if ((xAleatorio >= cocodrilos[i].xEnemigo && xAleatorio < cocodrilos[i].xEnemigo + cocodrilos[i].anchoEnemigo) &&
                (yAleatorio >= cocodrilos[i].yEnemigo && yAleatorio < cocodrilos[i].yEnemigo + cocodrilos[i].altoEnemigo)) {
                perteneceEnemigo = true;
                break;
            }
        }

        if (!perteneceCapi && !perteneceEnemigo) {
            posicionValida = true;
        }
    }

    pocion.x = xAleatorio;
    pocion.y = yAleatorio;
}

// MENUS DE NIVELES:
void tipo_de_nivel_ardilla_texto() {
    dibujarRectanguloHueco(0, 0, 51, 63);
    textoSinSleep("ardilla:", 5, 1);
    textoSinSleep("movimiento:", 5, 4);
    textoSinSleep("se escapa del capibara", 5, 7);
    textoSinSleep("durante un tiempo", 5, 10);
    textoSinSleep("determinado.", 5, 13);
    textoSinSleep("ataques:", 5, 20);
    textoSinSleep("lanza un total de 20", 5, 23);
    textoSinSleep("bellotas durante su", 5, 26);
    textoSinSleep("escape.", 5, 29);
    textoSinSleep("objetivo:", 5, 36);
    textoSinSleep("esquivar las bellotas y", 5, 39);
    textoSinSleep("derrotar a la ardilla.", 5, 42);
    drawContinueImput(5, 50);
}

void tipo_de_nivel_zorro_texto() {
    dibujarRectanguloHueco(0, 0, 51, 63);
    textoSinSleep("zorro:", 5, 1);
    textoSinSleep("movimiento:", 5, 4);
    textoSinSleep("se mueve por coordenadas", 5, 7);
    textoSinSleep("aleatorioas, intenta no", 5, 10);
    textoSinSleep("pasar por su camino.", 5, 13);
    textoSinSleep("ataques:", 5, 20);
    textoSinSleep("golpea y causa un gran", 5, 23);
    textoSinSleep("danio aleatoriamente", 5, 26);
    textoSinSleep("consejo:", 5, 33);
    textoSinSleep("jugaras con tu suerte,", 5, 36);
    textoSinSleep("si tienes pociones,", 5, 39);
    textoSinSleep("usalas!!!", 5, 42);
    drawContinueImput(5, 50);
}

void tipo_de_nivel_cocodrilo_texto() {
    dibujarRectanguloHueco(0, 0, 51, 63);
    textoSinSleep("cocodrilo:", 5, 1);
    textoSinSleep("movimiento:", 5, 4);
    textoSinSleep("se mueve de izquierda a", 5, 7);
    textoSinSleep("derecha.", 5, 10);
    textoSinSleep("ataques:", 5, 17);
    textoSinSleep("lanza bolas de fuego.", 5, 20);
    textoSinSleep("consejo:", 5, 27);
    textoSinSleep("derrotar a los cocodrilos", 5, 30);
    textoSinSleep("para que salga el boss", 5, 33);
    drawContinueImput(5, 50);
}

void tipo_de_nivel_dragon_texto() {
    dibujarRectanguloHueco(0, 0, 51, 63);
    textoSinSleep("dragon:", 5, 1);
    textoSinSleep("movimiento:", 5, 4);
    textoSinSleep("vuela en patrones mas", 5, 7);
    textoSinSleep("complejos, realiza", 5, 10);
    textoSinSleep("maniobrea rapidas y puede", 5, 13);
    textoSinSleep("girar en el aire.", 5, 16);
    textoSinSleep("ataques:", 5, 20);
    textoSinSleep("lanza bolas de fuego.", 5, 23);
    textoSinSleep("lanza rafagas de llamas.", 5, 26);
    textoSinSleep("azota con su cola.", 5, 29);
    textoSinSleep("consejo:", 5, 33);
    textoSinSleep("manten un movimiento", 5, 36);
    textoSinSleep("constante para evitar", 5, 39);
    textoSinSleep("los ataques, utiliza", 5, 42);
    textoSinSleep("el entorno para cubrirte!!!", 5, 45);
}

void tipo_de_nivel_ardilla_animation1() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    ardillaxd2(200, 10);

    capibaraxd1(110, 50);
}

void tipo_de_nivel_ardilla_animation2() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    ardillaxd1(110, 10);

    capibaraxd2(170, 30);

    bellotaxd1(155, 25);
}

void tipo_de_nivel_ardilla_animation3() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    ardillaxd1(110, 10);

    capibaraxd2(170, 30);

    bellotaxd1(169, 29);
}

void borrar_tipo_de_nivel_ardilla_animation1() {
    borrarardillaxd2(200, 10);

    borrarcapibaraxd1(110, 50);
}

void borrar_tipo_de_nivel_ardilla_animation2() {
    borrarardillaxd1(110, 10);

    borrarcapibaraxd2(170, 30);

    borrarbellotaxd1(155, 25);
}

void borrar_tipo_de_nivel_ardilla_animation3() {

    borrarardillaxd1(110, 10);

    borrarcapibaraxd2(170, 30);

    borrarbellotaxd1(169, 29);
}

void tipo_de_nivel_zorro_animation1() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    zorroxd1(200, 10);

    capibaraxd1(110, 50);

}

void tipo_de_nivel_zorro_animation2() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd1(110, 10);

    zorroxd1(170, 30);
}

void tipo_de_nivel_zorro_animation3() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd2(170, 30);

    zorroxd1(110, 10);
}

void borrar_tipo_de_nivel_zorro_animation1() {

    borrarzorroxd1(200, 10);

    borrarcapibaraxd1(110, 50);

}

void borrar_tipo_de_nivel_zorro_animation2() {

    borrarcapibaraxd1(110, 10);

    borrarzorroxd1(170, 30);
}

void borrar_tipo_de_nivel_zorro_animation3() {
    borrarcapibaraxd2(170, 30);

    borrarzorroxd1(110, 10);
}

void tipo_de_nivel_cocodrilo_animation1() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd1(110, 50);

    cocodriloxd1(200, 10);
}

void tipo_de_nivel_cocodrilo_animation2() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd1(110, 30);

    cocodriloxd1(150, 10);

    bolafuegoxd1(170, 20);
}

void tipo_de_nivel_cocodrilo_animation3() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd2(170, 30);

    cocodriloxd1(110, 10);

    bolafuegoxd1(160, 20);

    bolafuegoxd1(120, 35);
}

void borrar_tipo_de_nivel_cocodrilo_animation1() {
    borrarcapibaraxd1(110, 50);

    borrarcocodriloxd1(200, 10);
}

void borrar_tipo_de_nivel_cocodrilo_animation2() {
    borrarcapibaraxd1(110, 30);

    borrarcocodriloxd1(150, 10);

    borrarbolafuegoxd1(170, 20);
}

void borrar_tipo_de_nivel_cocodrilo_animation3() {
    borrarcapibaraxd2(170, 30);

    borrarcocodriloxd1(110, 10);

    borrarbolafuegoxd1(160, 20);

    borrarbolafuegoxd1(120, 35);
}

void tipo_de_nivel_dragon_animation1() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd1(110, 50);

    dibujarDragon(165, 5);

    bolafuegoxd1(170, 35);
    bolafuegoxd1(140, 35);
    bolafuegoxd1(110, 35);
}

void tipo_de_nivel_dragon_animation2() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd1(110, 50);

    dibujarDragon(130, 5);

    bolafuegoxd1(170, 40);
    bolafuegoxd1(140, 40);
    bolafuegoxd1(110, 40);
}

void tipo_de_nivel_dragon_animation3() {
    dibujarRectanguloHueco(102, 0, 65, 63);

    capibaraxd2(170, 50);

    dibujarDragon(110, 5);

    bolafuegoxd1(170, 45);
    bolafuegoxd1(140, 45);
    bolafuegoxd1(110, 45);
}

void borrar_tipo_de_nivel_dragon_animation1() {

    borrarcapibaraxd1(110, 50);

    borrarDragon(165, 5);

    borrarbolafuegoxd1(170, 35);
    borrarbolafuegoxd1(140, 35);
    borrarbolafuegoxd1(110, 35);
}

void borrar_tipo_de_nivel_dragon_animation2() {
    borrarcapibaraxd1(110, 50);

    borrarDragon(130, 5);

    borrarbolafuegoxd1(170, 40);
    borrarbolafuegoxd1(140, 40);
    borrarbolafuegoxd1(110, 40);
}

void borrar_tipo_de_nivel_dragon_animation3() {
    borrarcapibaraxd2(170, 50);

    borrarDragon(110, 5);

    borrarbolafuegoxd1(170, 45);
    borrarbolafuegoxd1(140, 45);
    borrarbolafuegoxd1(110, 45);
}

void dibujarBarraStats(int x, int y, int vida, int MAX_STAT, char* titulo, char* color) {

    gotoXY(x + 2, y + 2); cout << titulo;
    gotoXY(x + 12, y + 2);
    for (int i = 0; i < MAX_STAT; ++i) {
        if (i < vida) {

            cout << color;
            cout << "/";
            cout << RESET;
        }
        else {
            cout << " ";
        }
    }
}

void actualizarBarras(Capibara& capibara, Potion& pocion) {
    if (!pocion.desaparecer) {
        if (capibara.cambiarMana) {
            capibara.mana = capibara.mana -= 25;
            if (capibara.contadorDeInmunidad >= capibara.contadorDeInmunidadMax || capibara.mana <= 0) {
                capibara.mana = 0;
                capibara.contadorDeInmunidad = 0;
            }
            capibara.cambiarMana = false;
        }

        if (capibara.cambiarEstamina) {
            capibara.estamina = capibara.estamina -= 50;
            if (capibara.contadorDeGolpesFuertes >= capibara.contadorDeGolpesFuertesMax || capibara.estamina <= 0) {
                capibara.estamina = 0;
                capibara.contadorDeGolpesFuertes = 0;
            }
            capibara.cambiarEstamina = false;
        }
    }
}

void fondo1() {

    arbusto_pequenio(10, 5);
    arbusto_pequenio(10, 20);
    arbusto_pequenio(20, 40);
    arbusto_pequenio(40, 30);
    arbusto_pequenio(90, 25);
    arbusto_pequenio(110, 15);
    arbusto_pequenio(110, 45);
    arbusto_pequenio(150, 25);
    arbusto_pequenio(180, 40);

    arbol_pequenio(180, 2);
    arbol_pequenio(140, 40);
    arbol_pequenio(40, 2);
    arbol_pequenio(65, 35);

}

void fondo2() {
    arbusto_pequenio(10, 5);
    arbusto_pequenio(10, 20);
    arbusto_pequenio(20, 40);
    arbusto_pequenio(40, 30);
    arbusto_pequenio(90, 25);
    arbusto_pequenio(110, 15);
    arbusto_pequenio(110, 45);
    arbusto_pequenio(150, 25);
    arbusto_pequenio(180, 40);
    arbusto_pequenio(180, 2);
    arbusto_pequenio(140, 40);
    arbusto_pequenio(40, 2);
    arbusto_pequenio(65, 35);
}

void fondo3() {
    arbusto_pequenio(20, 40);
    arbusto_pequenio(40, 30);
    arbusto_pequenio(90, 25);
    dibujarRectangulo(20, (HEIGHT / 3));
    dibujarRectangulo(70, (HEIGHT / 3));
    dibujarRectangulo(120, (HEIGHT / 3));
    dibujarRectangulo(180, (HEIGHT / 3));
    arbusto_pequenio(110, 15);
    arbusto_pequenio(150, 25);
    arbusto_pequenio(180, 40);
    arbusto_pequenio(140, 40);
    arbusto_pequenio(65, 35);
}

// Decoraciones
void decoracion() {
    sol(192, 3);

    arbol(172, 40);

    arbusto(92, 52);

    dibujarCapibaraIzquierda3(145, 51);

    dibujarDragonDerecha(70, 10);

    piso3(86, 59, 14);

}

void fondo_niveles_xdjjsjs() {

    piso4(2, 68, 20, GREEN);

    arbol(192, 46);

    piso3(1, 68, 20);

    sol(170, 3);

    cout << RED;
    aguilaxd1(45, 30);
    cout << RESET;

    cout << BROWN;
    dibujarCapibaraIzquierda3(160, 61);

    dibujarCapibaraDerecha2(2, 61);
    cout << RESET;

    rio(50, 68, CYAN);
    rio(62, 68, CYAN);

}

void mover_flecha2(int& x, int& y, int alto, int ancho, char tecla, int& dx, int& dy, int limitex1, int limitex2, int limitey1, int limitey2) {

    if (x < limitex1) {
        if (tecla == DERECHA && x < (Console::WindowWidth - ancho - dx)) x += dx;
    }
    else {
        if (tecla == DERECHA && x > 0) x -= dx;
    }

    if (x > limitex2) {
        if (tecla == IZQUIERDA && x > 0) x -= dx;
    }
    else {
        if (tecla == IZQUIERDA && x < (Console::WindowWidth - ancho - dx)) x += dx;
    }


    if (y < limitey2) {
        if (tecla == ABAJO && y < Console::WindowHeight - alto) y += dy;
    }
    else {
        if (tecla == ABAJO && y > 0) y -= dy;
    }

    if (y > limitey1) {
        if (tecla == ARRIBA && y > 0) y -= dy;
    }
    else {
        if (tecla == ARRIBA && y < Console::WindowHeight - alto) y += dy;
    }

}

void pasar_de_nivel(char* color_yes, char* color_no, char* color_exit) {

    textoGrandeSinSleep("NEXT LEVEL", 10, 4);

    cout << color_yes;
    dibujarRectanguloHueco(17, 13, 20, 8);
    textoGrandeSinSleep("YES (Y)", 20, 14);
    cout << RESET;


    cout << color_no;
    dibujarRectanguloHueco(17, 22, 17, 8);
    textoGrandeSinSleep("NO (N)", 20, 23);
    cout << RESET;


    cout << color_exit;
    dibujarRectanguloHueco(17, 49, 34, 8);
    textoGrandeSinSleep("CONTINUE (C)", 20, 50);
    cout << RESET;

    decoracion();

}

void pasar_nivel_escoger(int& x, int& y, char tecla, bool& pasarNivel, bool& seleccionado) {
    if (kbhit()) {
        tecla = _getch();
        tecla = toupper(tecla);

        if (tecla == 'Y' && y == 14) {
            pasar_de_nivel(GREEN, RESET, RESET);
            pasarNivel = true;
        }

        if (tecla == 'N' && y == 23) {
            pasar_de_nivel(RESET, GREEN, RESET);
            pasarNivel = false;
        }

        if (tecla == 'C') {
            if (pasarNivel) {
                pasar_de_nivel(GREEN, RESET, GREEN);
            }
            else {
                pasar_de_nivel(RESET, GREEN, GREEN);
            }
            seleccionado = true;
        }
    }
}

void escoger_pasar_nivel(bool& pasarNivel) {

    char tecla;
    Console::CursorVisible = false;

    int x = 10, y = 14;
    int alto = 3, ancho = 4;
    int dx = 0, dy = 9;
    int limitex1 = 0, limitex2 = 0;
    int limitey1 = 17, limitey2 = 23;
    bool seleccionado = false;

    pasar_de_nivel(RESET, RESET, RESET);

    while (seleccionado == false) {

        borrar_fleschitajsjajsja(x, y);

        if (kbhit()) {
            tecla = _getch();
            mover_flecha2(x, y, alto, ancho, tecla, dx, dy, limitex1, limitex2, limitey1, limitey2);
        }

        fleschitajsjajsja(x, y);

        _sleep(1);

        pasar_nivel_escoger(x, y, tecla, pasarNivel, seleccionado);

    }
}

// RCS
bool respuesta1(int x, int y, int a) {

    if (x == 18 && y == 15 && a == 270) {
        return true;
    }

    return false;
}

bool respuesta2(double x, double y, double a) {

    if (x == 15 && y == 62.5 && a == 937.5) {
        return true;
    }

    return false;
}

bool respuesta3(int x) {

    if (x == 53.33) {
        return true;
    }

    return false;
}

bool respuesta4(int x) {

    if (x == 214.29) {
        return true;
    }

    return false;
}

void problema_mate_rc_1(bool& repetirNivel, bool& nuevoRC) {
    Console::Clear();

    int x;
    int y;
    int a;
    char generarOtroRC;

    dibujarRectanguloHueco(0, 0, 117, 63);

    textoSinSleep("con 108 metros de malla de alambre se construyen 5", 2, 1);
    textoSinSleep("compartimentos rectangulares (n=5) de iguales dimenciones.", 3, 4);
    textoSinSleep("y que no se colocara malla en la parte limitada por la pared,", 2, 7);
    textoSinSleep("como se muestra en la figura.", 2, 10);

    gotoXY(3, 20); cout << "                                                  ";
    gotoXY(3, 21); cout << "          pared                                   ";
    gotoXY(3, 22); cout << "           ||                                     ";
    gotoXY(3, 23); cout << "           \\/                                    ";
    gotoXY(3, 24); cout << "        _______________________                   ";
    gotoXY(3, 25); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 26); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 27); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 28); cout << "         |___|___|___|___|___|                    ";
    gotoXY(3, 29); cout << "                                                  ";

    textoSinSleep("determine las dimenciones y el area maxima que puede tener", 3, 34);
    textoSinSleep("cada compartimento.", 3, 37);

    gotoXY(20, 45); cout << "Al momento de colocar la respuesta, no redondear y colocar punto y no coma; ejemplo es 13.5";
    gotoXY(20, 46); cout << "si la respuesta no tiene decimal, solo colocar el numero entero.";

    do {
        gotoXY(20, 50); cout << "Si deseas responder esta pregunta apreta (S), sino para generar un nuevo RC apreta (N): "; cin >> generarOtroRC;
        generarOtroRC = toupper(generarOtroRC);
    } while (generarOtroRC != 'S' && generarOtroRC != 'N');

    if (generarOtroRC == 'S') {
        gotoXY(20, 54); cout << "X max: "; cin >> x;
        gotoXY(40, 54); cout << "Y max: "; cin >> y;
        gotoXY(60, 54); cout << "A max: "; cin >> a;
        if (respuesta1(x, y, a)) {
            // aca le pones el de la segunda oportinidad x haber acertado la pregunta xd
            repetirNivel = true;
        }
        else {
            //aca pones lo q pasa si falla la pregunta
            repetirNivel = false;
        }
    }
    else {
        nuevoRC = true;
    }

    //lo mismo para todos jsjjsjsjs

    // Respuesta = 
    // X max:  18 m
    // Y max:  15 m
    // A max: 270 m2
}

void problema_mate_rc_2(bool& repetirNivel, bool& nuevoRC) {
    Console::Clear();
    double x = 00.00;
    double y = 00.00;
    double a = 000.00;
    char generarOtroRC;

    dibujarRectanguloHueco(0, 0, 117, 63);

    textoSinSleep("con 150 metros de malla de alambre se construyen 5", 2, 1);
    textoSinSleep("compartimentos rectangulares (n es 5) de iguales dimenciones.", 3, 4);
    textoSinSleep("y que no se colocara malla en la parte limitada por la pared,", 2, 7);
    textoSinSleep("como se muestra en la figura.", 2, 10);

    gotoXY(3, 20); cout << "                                                  ";
    gotoXY(3, 21); cout << "          pared                                   ";
    gotoXY(3, 22); cout << "           ||                                     ";
    gotoXY(3, 23); cout << "           \\/                                    ";
    gotoXY(3, 24); cout << "        _______________________                   ";
    gotoXY(3, 25); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 26); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 27); cout << "         |   |   |   |   |   |                    ";
    gotoXY(3, 28); cout << "         |___|___|___|___|___|                    ";
    gotoXY(3, 29); cout << "                                                  ";

    textoSinSleep("determine las dimenciones y el area maxima que puede tener", 3, 34);
    textoSinSleep("cada compartimento.", 3, 37);


    gotoXY(20, 45); cout << "Al momento de colocar la respuesta, no redondear y colocar punto y no coma; ejemplo es 13.5";
    gotoXY(20, 46); cout << "si la respuesta no tiene decimal, solo colocar el numero entero.";

    do {
        gotoXY(20, 50); cout << "Si deseas responder esta pregunta apreta (S), sino para generar un nuevo RC apreta (N): "; cin >> generarOtroRC;
        generarOtroRC = toupper(generarOtroRC);
    } while (generarOtroRC != 'S' && generarOtroRC != 'N');

    if (generarOtroRC == 'S') {
        gotoXY(20, 54); cout << "X max: "; cin >> x;
        gotoXY(40, 54); cout << "Y max: "; cin >> y;
        gotoXY(60, 54); cout << "A max: "; cin >> a;
        if (respuesta2(x, y, a)) {
            // aca le pones el de la segunda oportinidad x haber acertado la pregunta xd
            repetirNivel = true;
        }
        else {
            //aca pones lo q pasa si falla la pregunta
            repetirNivel = false;
        }
    }
    else {
        nuevoRC = true;
    }

    //lo mismo para todos jsjjsjsjs

    // Respuesta = 
    // X max:  15 m
    // Y max:  62,5 m
    // A max: 937,5 m2
}

void problema_mate_rc_3(bool& repetirNivel, bool& nuevoRC) {
    Console::Clear();
    double x = 00.00;
    char generarOtroRC;

    dibujarRectanguloHueco(0, 0, 117, 63);

    textoSinSleep("un turista acaba de regresar de europa, gasto 30 dolares diarios", 2, 1);
    textoSinSleep("en italia, 20 dolares diarios en alemania y 20 dolares diarios en", 3, 4);
    textoSinSleep("espania por concepto de alojamiento. en alimentacion se gasto", 2, 7);
    textoSinSleep("20; 30 y 20 dolares diarios en italia, alemania y espania,", 2, 10);
    textoSinSleep("respectivamente. en cada pais gasto 10 dolares diarios en otros", 3, 13);
    textoSinSleep("gastos. los gastos totales fueron 340 dolares por alojamiento", 3, 16);
    textoSinSleep("350 dolares por comidas y 150 dolares en otros gastos.", 3, 19);
    textoSinSleep("", 3, 22);
    textoSinSleep("que porcentaje total gastado en alojamiento en espania, ", 3, 25);
    textoSinSleep("representa el total gastado en alojamiento en alemania.", 3, 28);

    gotoXY(20, 45); cout << "Al momento de colocar la respuesta, no redondear y colocar punto y no coma; ejemplo es 13.5";
    gotoXY(20, 46); cout << "si la respuesta no tiene decimal, solo colocar el numero entero.";

    do {
        gotoXY(20, 50); cout << "Si deseas responder esta pregunta apreta (S), sino para generar un nuevo RC apreta (N): "; cin >> generarOtroRC;
        generarOtroRC = toupper(generarOtroRC);
    } while (generarOtroRC != 'S' && generarOtroRC != 'N');


    if (generarOtroRC == 'S') {
        gotoXY(20, 54); cout << "El porcentaje es: "; cin >> x;
        if (respuesta3(x)) {
            // aca le pones el de la segunda oportinidad x haber acertado la pregunta xd
            repetirNivel = true;
        }
        else {
            //aca pones lo q pasa si falla la pregunta
            repetirNivel = false;
        }
    }
    else {
        nuevoRC = true;
    }
    //lo mismo para todos jsjjsjsjs

    // Respuesta = 53,33%
}

void problema_mate_rc_4(bool& repetirNivel, bool& nuevoRC) {
    Console::Clear();
    double x = 000.00;
    char generarOtroRC;

    dibujarRectanguloHueco(0, 0, 117, 63);

    textoSinSleep("un turista acaba de regresar de europa, gasto 30 dolares diarios", 2, 1);
    textoSinSleep("en italia, 20 dolares diarios en alemania y 20 dolares diarios en", 3, 4);
    textoSinSleep("espania por concepto de alojamiento. en alimentacion se gasto", 2, 7);
    textoSinSleep("20; 30 y 20 dolares diarios en italia, alemania y espania,", 2, 10);
    textoSinSleep("respectivamente. en cada pais gasto 10 dolares diarios en otros", 3, 13);
    textoSinSleep("gastos. los gastos totales fueron 420 dolares por alojamiento", 3, 16);
    textoSinSleep("410 dolares por comidas y 180 dolares en otros gastos.", 3, 19);
    textoSinSleep("", 3, 22);
    textoSinSleep("que porcentaje total gastado en alojamiento en espania, ", 3, 25);
    textoSinSleep("representa el total gastado en alojamiento en alemania.", 3, 28);

    gotoXY(20, 45); cout << "Al momento de colocar la respuesta, no redondear y colocar punto y no coma; ejemplo es 13.5";
    gotoXY(20, 46); cout << "si la respuesta no tiene decimal, solo colocar el numero entero.";

    do {
        gotoXY(20, 50); cout << "Si deseas responder esta pregunta apreta (S), sino para generar un nuevo RC apreta (N): "; cin >> generarOtroRC;
        generarOtroRC = toupper(generarOtroRC);
    } while (generarOtroRC != 'S' || generarOtroRC != 'N');

    if (generarOtroRC == 'S') {
        gotoXY(20, 54); cout << "El porcentaje es: "; cin >> x;

        if (respuesta4(x)) {
            repetirNivel = true;
        }
        else {
            //aca pones lo q pasa si falla la pregunta
            repetirNivel = false;
        }
    }
    else {
        nuevoRC = true;
    }


    //lo mismo para todos jsjjsjsjs

    // Respuesta = 214,29%
}

void generarRC(bool& repetirNivel, bool& nuevoRC) {
    int numero = numeroAleatorio(1, 4);

    if (numero == 1) {
        problema_mate_rc_1(repetirNivel, nuevoRC);
    }
    else if (numero == 2) {
        problema_mate_rc_2(repetirNivel, nuevoRC);
    }
    else if (numero == 3) {
        problema_mate_rc_3(repetirNivel, nuevoRC);
    }
    else if (numero == 4) {
        problema_mate_rc_4(repetirNivel, nuevoRC);
    }
}

void reglas_ardilla(bool desdeOpcionLevels, bool& nivelArdilla, char* nombre, bool& pasarNivel) {
    Console::Clear();
    bool ardillaStartGame = false;
    bool ardillaExecuted = false;
    nivelArdilla = false;
    tipo_de_nivel_ardilla_texto();
    while (true) {
        ardillaExecuted = false;
        char tecla;
        _sleep(500);
        borrar_tipo_de_nivel_ardilla_animation3();
        tipo_de_nivel_ardilla_animation1();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                ardillaStartGame = true;
            }

            if (ardillaStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                ardillaExecuted = true;
                nivelArdilla = true;
            }
        }

        if (ardillaExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_ardilla_animation1();
        tipo_de_nivel_ardilla_animation2();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                ardillaStartGame = true;
            }

            if (ardillaStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                ardillaExecuted = true;
                nivelArdilla = true;
            }
        }


        if (ardillaExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_ardilla_animation2();
        tipo_de_nivel_ardilla_animation3();
        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                ardillaStartGame = true;
            }

            if (ardillaStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                ardillaExecuted = true;
                nivelArdilla = true;
            }
        }

        if (ardillaExecuted && pasarNivel == false) {
            break;
        }

    }
}

void reglas_zorro(bool desdeOpcionLevels, bool& nivelZorro, char* nombre, bool& pasarNivel) {
    Console::Clear();
    bool zorroStartGame = false;
    bool zorroExecuted = false;
    nivelZorro = false;
    tipo_de_nivel_zorro_texto();
    while (true) {
        char tecla;
        _sleep(500);
        borrar_tipo_de_nivel_zorro_animation3();
        tipo_de_nivel_zorro_animation1();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                zorroStartGame = true;
            }

            if (zorroStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                zorroExecuted = true;
                nivelZorro = true;
            }
        }

        if (zorroExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_zorro_animation1();
        tipo_de_nivel_zorro_animation2();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                zorroStartGame = true;
            }

            if (zorroStartGame && tecla == ' ') {
                if (desdeOpcionLevels) {
                    bool nombreValidado = false;
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                zorroExecuted = true;
                nivelZorro = true;
            }
        }

        if (zorroExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_zorro_animation2();
        tipo_de_nivel_zorro_animation3();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                zorroStartGame = true;
            }

            if (zorroStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                zorroExecuted = true;
                nivelZorro = true;
            }
        }

        if (zorroExecuted && pasarNivel == false) {
            break;
        }
    }
}

void reglas_cocodrilo(bool desdeOpcionLevels, bool& nivelCocodrilo, char* nombre, bool& pasarNivel) {
    Console::Clear();
    bool cocodrileStartGame = false;
    bool cocodrileExecuted = false;
    nivelCocodrilo = false;
    tipo_de_nivel_cocodrilo_texto();
    while (true) {
        char tecla;
        _sleep(500);
        borrar_tipo_de_nivel_cocodrilo_animation3();
        tipo_de_nivel_cocodrilo_animation1();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                cocodrileStartGame = true;
            }

            if (cocodrileStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                cocodrileExecuted = true;
                nivelCocodrilo = true;
            }
        }

        if (cocodrileExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_cocodrilo_animation1();
        tipo_de_nivel_cocodrilo_animation2();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                cocodrileStartGame = true;
            }

            if (cocodrileStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                cocodrileExecuted = true;
                nivelCocodrilo = true;
            }
        }

        if (cocodrileExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_cocodrilo_animation2();
        tipo_de_nivel_cocodrilo_animation3();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                cocodrileStartGame = true;
            }

            if (cocodrileStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                cocodrileExecuted = true;
                nivelCocodrilo = true;
            }
        }

        if (cocodrileExecuted && pasarNivel == false) {
            break;
        }
    }
}

void reglas_dragon(bool desdeOpcionLevels, bool& nivelDragon, char* nombre, bool& pasarNivel) {
    Console::Clear();
    bool dragonStartGame = false;
    bool dragonExecuted = false;
    nivelDragon = false;
    tipo_de_nivel_dragon_texto();
    drawContinueImput(5, 50);
    while (true) {
        char tecla;
        _sleep(500);
        borrar_tipo_de_nivel_dragon_animation3();
        tipo_de_nivel_dragon_animation1();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                dragonStartGame = true;
            }

            if (dragonStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                dragonExecuted = true;
                nivelDragon = true;
            }
        }

        if (dragonExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_dragon_animation1();
        tipo_de_nivel_dragon_animation2();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                dragonStartGame = true;
            }

            if (dragonStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                dragonExecuted = true;
                nivelDragon = true;
            }
        }

        if (dragonExecuted && pasarNivel == false) {
            break;
        }

        _sleep(500);
        borrar_tipo_de_nivel_dragon_animation2();
        tipo_de_nivel_dragon_animation3();

        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'C') {
                cout << YELLOW;
                drawContinueImput(5, 50);
                cout << RESET;
                dragonStartGame = true;
            }

            if (dragonStartGame && tecla == ' ') {
                bool nombreValidado = false;
                if (desdeOpcionLevels) {
                    do {
                        nombre = nameInput();
                        nombreValidado = validateInputName(nombre);
                        gotoXY((WIDTH / 3) - 8, 50);
                        if (nombreValidado == false) {
                            cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                            _getch();
                        }
                    } while (nombreValidado == false);
                }
                dragonExecuted = true;
                nivelDragon = true;
            }
        }

        if (dragonExecuted && pasarNivel == false) {
            break;
        }
    }
}

void fondo4(int& x1, int& y1, int& dx, int& dy) {
    // Animacion de fondo
    cout << CYAN;
    nubexdjsjjs(10, 9);
    nubexdjsjjs(15, 11);
    nubexdjsjjs(60, 9);
    nubexdjsjjs(65, 11);
    nubexdjsjjs(110, 9);
    nubexdjsjjs(115, 11);
    nubexdjsjjs(160, 9);
    nubexdjsjjs(165, 11);
    cout << RESET;

    if (x1 < 80) {
        mover_lunajsjsjjs(x1, y1, dx, dy);
        if (x1 < 80) {
            x1 += dx;
        }
        else {
            dx = 0;
        }
    }
    else {
        mover_soljsjsjjs(x1, y1, dx, dy);
        if (x1 >= 80 && x1 < WIDTH - 30) {
            x1 += dx;
        }
    }

}

void startGameDragon(int& enemigosDerrotados, int numeroClase, char* nombre, bool& pasarNivel) {
    srand(time(NULL));
    Console::Clear();
    Console::CursorVisible = false;
    bool nivelDragon = false;
    bool desdeOpcionLevels = false;
    pasarNivel = false;

    // Datos de la luna y sol:
    int x1Luna = 10, y1Luna = 9;
    int dxLuna = 1, dyLuna = 0;
    // Datos capibara
    Capibara capibara;
    capibara.x = Console::WindowWidth / 2 - 23;
    capibara.y = Console::WindowHeight / 2;
    capibara.dx = 5;
    capibara.dy = 5;
    capibara.ancho = 17;
    capibara.alto = 8;
    capibara.contadorDeGolpes = 0;
    capibara.vida = 100;
    capibara.estamina = 0;
    capibara.mana = 0;
    // Datos del dragon
    // Dragon
    int xDragon = 0;
    int yDragon = 0;
    int dxDragon = 1;
    int dyDragon = 1;
    int altoDragon = 30;
    int anchoDragon = 56;
    int vidaDragon = 100;
    Enemigo Dragon = crearEnemigo2("Dragon", xDragon, yDragon, dxDragon, dyDragon, altoDragon, anchoDragon, vidaDragon);
    Dragon.descansando = false;
    Dragon.alejandose = true;
    Dragon.tiempoAlejamiento = 0;
    Dragon.tiempoDescanso = 100;
    Dragon.margen = 2;
    Dragon.danioRecibido = 1;
    Dragon.turnoDeAtaque = true;
    Dragon.golpesMaximos = 3;
    Dragon.tiempoDisparo = 5;

    // Bola de fuego
    // Bola de fuego cocodrilo 1
    BolaDeFuego bolaDeFuego1;
    bolaDeFuego1.x = Dragon.xEnemigo + Dragon.anchoEnemigo / 2;
    bolaDeFuego1.y = Dragon.yEnemigo + Dragon.altoEnemigo / 2;
    bolaDeFuego1.dx = 1;
    bolaDeFuego1.dy = 1;
    bolaDeFuego1.id = 0;
    bolaDeFuego1.alto = 7;
    bolaDeFuego1.ancho = 13;
    bolaDeFuego1.activo = false;
    bolaDeFuego1.xInicial = bolaDeFuego1.x;
    bolaDeFuego1.yInicial = bolaDeFuego1.y;
    bolaDeFuego1.tiempoDisparo = 5;
    Dragon.bolaDeFuego = bolaDeFuego1;

    // Booleanos que detectan el movimiento del capibara
    bool moverIzquierda = false;
    bool moverArriba = false;
    bool capibaraMoviendose = false;
    bool dragon1 = false;
    bool dragon2 = true;
    bool dragon3 = false;
    char tecla;
    int tamanio = 3;
    Coordenada* coordenadas = new Coordenada[tamanio];
    int tamanioBolasRocosas = 7;
    Coordenada* coordenadasBolasRocosas = new Coordenada[tamanioBolasRocosas];
    coordenadasBolasRocosas[0].x = 20;
    coordenadasBolasRocosas[0].y = 0;
    coordenadasBolasRocosas[0].dy = 1;
    coordenadasBolasRocosas[0].xInicial = 20;
    coordenadasBolasRocosas[0].yInicial = 0;
    coordenadasBolasRocosas[1].x = 50;
    coordenadasBolasRocosas[1].y = 0;
    coordenadasBolasRocosas[1].dy = 1;
    coordenadasBolasRocosas[1].xInicial = 50;
    coordenadasBolasRocosas[1].yInicial = 0;
    coordenadasBolasRocosas[2].x = 90;
    coordenadasBolasRocosas[2].y = 0;
    coordenadasBolasRocosas[2].dy = 1;
    coordenadasBolasRocosas[2].xInicial = 90;
    coordenadasBolasRocosas[2].yInicial = 0;
    coordenadasBolasRocosas[3].x = 130;
    coordenadasBolasRocosas[3].y = 0;
    coordenadasBolasRocosas[3].dy = 1;
    coordenadasBolasRocosas[3].xInicial = 130;
    coordenadasBolasRocosas[3].yInicial = 0;
    coordenadasBolasRocosas[4].x = 170;
    coordenadasBolasRocosas[4].y = 0;
    coordenadasBolasRocosas[4].dy = 1;
    coordenadasBolasRocosas[4].xInicial = 170;
    coordenadasBolasRocosas[4].yInicial = 0;
    coordenadasBolasRocosas[5].x = 210;
    coordenadasBolasRocosas[5].y = 0;
    coordenadasBolasRocosas[5].dy = 1;
    coordenadasBolasRocosas[5].xInicial = 210;
    coordenadasBolasRocosas[5].yInicial = 0;
    coordenadasBolasRocosas[6].x = 230;
    coordenadasBolasRocosas[6].y = 0;
    coordenadasBolasRocosas[6].dy = 1;
    coordenadasBolasRocosas[6].xInicial = 230;
    coordenadasBolasRocosas[6].yInicial = 0;

    // Arreglo de llamaradas
    int tamanioLlamaradas = 3;
    Llamarada* llamaradas = new Llamarada[tamanioLlamaradas];
    Llamarada llamarada1;
    llamarada1.x = Dragon.xEnemigo + Dragon.anchoEnemigo / 2;
    llamarada1.y = Dragon.yEnemigo + Dragon.altoEnemigo / 2;
    llamarada1.dx = 2;
    llamarada1.dy = -2;
    llamarada1.id = 0;
    llamarada1.alto = 7;
    llamarada1.ancho = 37;
    llamarada1.activo = false;
    llamarada1.xInicial = llamarada1.x;
    llamarada1.yInicial = llamarada1.y;
    llamarada1.tiempoDisparo = 5;
    Llamarada llamarada2;
    llamarada2.x = Dragon.xEnemigo + Dragon.anchoEnemigo / 2;
    llamarada2.y = Dragon.yEnemigo + Dragon.altoEnemigo / 2;
    llamarada2.dx = 2;
    llamarada2.dy = 0;
    llamarada2.id = 0;
    llamarada2.alto = 7;
    llamarada2.ancho = 37;
    llamarada2.activo = false;
    llamarada2.xInicial = llamarada2.x;
    llamarada2.yInicial = llamarada2.y;
    llamarada2.tiempoDisparo = 5;
    Llamarada llamarada3;
    llamarada3.x = Dragon.xEnemigo + Dragon.anchoEnemigo / 2;
    llamarada3.y = Dragon.yEnemigo + Dragon.altoEnemigo / 2;
    llamarada3.dx = 2;
    llamarada3.dy = 2;
    llamarada3.id = 0;
    llamarada3.alto = 7;
    llamarada3.ancho = 37;
    llamarada3.activo = false;
    llamarada3.xInicial = llamarada3.x;
    llamarada3.yInicial = llamarada3.y;
    llamarada3.tiempoDisparo = 5;
    Dragon.llamaradas[0] = llamarada1;
    Dragon.llamaradas[1] = llamarada2;
    Dragon.llamaradas[2] = llamarada3;


    // Variables locales
    bool coordenadasOrdenadas = false;
    int indiceActual = 0;
    bool dragonDerrotado = false;

    // Pocion

    Potion nuevaPocion = generarPocion();
    definir_posicionObjeto1(capibara, Dragon, nuevaPocion);


    dibujarCapibaraIzquierda(numeroClase, capibara);
    coordenadasAleatorias(tamanio, Dragon, coordenadas);
    while (capibara.vida > 0) {
        capibara.cambiarEstamina = false;
        capibara.cambiarMana = false;
        dragonDerrotado = false;
        capibara.atacar = false;
        capibaraMoviendose = false;
        capibara.recibeMejora = false;
        fondo4(x1Luna, y1Luna, dxLuna, dyLuna);
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            if (tecla == 'F') {
                capibara.atacar = true;
                capibaraAtaqueDragon(capibara, Dragon, coordenadas, tamanio, coordenadasOrdenadas, indiceActual, bolaDeFuego1, moverArriba, dragon1, dragon2);
            }
            moverJugador(capibara, Dragon, tecla, nuevaPocion, moverIzquierda, moverArriba);
            capibaraMoviendose = true;
        }

        if (capibara.recibeMejora) {
            nuevaPocion = generarPocion();
            definir_posicionObjeto1(capibara, Dragon, nuevaPocion);
        }

        if (!nuevaPocion.desaparecer) {
            if (nuevaPocion.id == 1) {
                pocion_cheta(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 2) {
                pocion_fuerza(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 3) {
                pocion_mana(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 4) {
                pocion_vida(nuevaPocion.x, nuevaPocion.y);
            }
        }

        if (dragon1) {
            iniciarDragon2(capibara, Dragon, coordenadas, tamanio, coordenadasOrdenadas, indiceActual, numeroClase);
        }
        if (dragon2) {
            iniciarDragon3(capibara, Dragon, Dragon.llamaradas, tamanioLlamaradas, moverArriba, numeroClase);
        }
        if (dragon3) {
            iniciarDragon1(capibara, Dragon, bolaDeFuego1, moverArriba, numeroClase);
        }


        if (capibara.contadorDeGolpes >= Dragon.golpesMaximos) {
            // Borrar las llamaradas
            for (int i = 0; i < tamanioLlamaradas; i++) {
                llamaradas[i].activo = false;
            }
            bool estadoCambiado = false;
            capibara.contadorDeGolpes = 0;
            borrarDragon(Dragon.xEnemigo, Dragon.yEnemigo);
            definir_posicionEnemigo(capibara, Dragon);
            Dragon.bolaDeFuego.tiempoDisparo = 5;
            Dragon.descansando = false;
            Dragon.tiempoAlejamiento = 0;
            Dragon.tiempoDescanso = 100;
            Dragon.alejandose = true;
            if (dragon1) {
                Dragon.descansando = false;
                Dragon.alejandose = true;
                Dragon.tiempoDescanso = 100;
                Dragon.contadorDePasos = 0;
                Dragon.dxEnemigo = 1; // reiniciar dxEnemigo a un valor inicial si es necesario
                Dragon.dyEnemigo = 1; // reiniciar dyEnemigo a un valor inicial si es necesario
                for (int i = 0; i < tamanio; i++) {
                    coordenadas[i].coordenadaEncontrada = false;
                }
                coordenadasAleatorias(tamanio, Dragon, coordenadas);
                dragon1 = false;
                dragon2 = true;
                estadoCambiado = true;
                //iniciarDragon2(capibara, Dragon, coordenadas, tamanio, coordenadasOrdenadas, indiceActual);
            }

            if (dragon2 && !estadoCambiado) {
                Dragon.descansando = false;
                Dragon.alejandose = true;
                Dragon.tiempoAlejamiento = 0;
                llamaradas[0].tiempoDisparo = 5;
                llamaradas[1].tiempoDisparo = 5;
                llamaradas[2].tiempoDisparo = 5;
                dragon2 = false;
                dragon3 = true;
                estadoCambiado = true;
                //iniciarDragon1(capibara, Dragon, bolaDeFuego1, moverArriba);
            }

            if (dragon3 && !estadoCambiado) {
                Dragon.descansando = false;
                Dragon.alejandose = true;
                Dragon.tiempoAlejamiento = 0;
                Dragon.bolaDeFuego.tiempoDisparo = 5;
                dragon3 = false;
                dragon1 = true; // Regresar al dragon 1
            }
            // Reiniciar las bolas rocosas
            for (int i = 0; i < tamanioBolasRocosas; i++) {
                coordenadasBolasRocosas[i].activo = true;
            }
        }
        lanzarBolasRocosas(capibara, Dragon, llamaradas, coordenadasBolasRocosas, tamanioBolasRocosas);
        if (capibara.atacar && capibara.atacarArriba) {
            dibujarClaseAtaqueArriba(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarAbajo) {
            dibujarClaseAtaqueAbajo(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarDerecha) {
            dibujarClaseAtaqueDerecha(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarIzquierda) {
            dibujarClaseAtaqueIzquierda(numeroClase, capibara);
        }
        else if (capibara.atacar) {
            if (moverIzquierda) {
                dibujarClaseAtaqueIzquierda(numeroClase, capibara);
            }
            else {
                dibujarClaseAtaqueDerecha(numeroClase, capibara);
            }
        }
        else {
            if (moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraIzquierdaCaminando(numeroClase, capibara);
            }
            else if (moverIzquierda && !capibaraMoviendose) {
                dibujarCapibaraIzquierda(numeroClase, capibara);
            }
            else if (!moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraDerechaCaminando(numeroClase, capibara);
            }
            else {
                dibujarCapibaraDerecha(numeroClase, capibara);
            }
        }

        if (Dragon.vida <= 0) {
            dragonDerrotado = true;
        }

        if (dragonDerrotado) {
            break;
        }

        gotoXY(0, 0);
        cout << "Nombre: " << nombre << endl;
        dibujarBarraStats(0, 2, capibara.vida, 100, "VIDA: ", RED);
        dibujarBarraStats(WIDTH / 2 + 5, 2, capibara.mana, 100, "MANA: ", BLUE);
        dibujarBarraStats(WIDTH / 3 - 10, 6, capibara.estamina, 100, "ESTAMINA: ", GREEN);
        dibujarBarraStats(0, HEIGHT - 5, Dragon.vida, 100, "DRAGON: ", CYAN);
        actualizarBarras(capibara, nuevaPocion);
        _sleep(10);
    }

    if (Dragon.vida <= 0) {
        // Mostrar GANASTE!!
        capibara.estamina = 0;
        capibara.mana = 0;
        enemigosDerrotados++;
        Console::Clear();
        if (enemigosDerrotados == 4) {
            pantalla_ganador_xd1(numeroClase);
            drawExtitImput((WIDTH / 3) + 10, HEIGHT - 15);
            bool salirDelJuego = false;
            bool botonExitSeleccionado = false;
            char tecla;
            while (salirDelJuego == false) {
                if (_kbhit()) {
                    tecla = _getch();
                    tecla = toupper(tecla);
                    if (tecla == 'E') {
                        drawExtitImputSelected((WIDTH / 3) + 10, HEIGHT - 15);
                        botonExitSeleccionado = true;
                    }

                    if (tecla == ' ') {
                        if (botonExitSeleccionado == true) {
                            salirDelJuego = true;
                        }
                    }
                }
            }
            if (salirDelJuego) {
                Console::Clear();
                exit(0);
            }
        }
    }

    if (capibara.vida <= 0) {
        Console::Clear();
        bool repetirNivel = true;
        bool nuevoRC = false;
        do {
            nuevoRC = false;
            generarRC(repetirNivel, nuevoRC);
        } while (nuevoRC);

        if (repetirNivel) {
            reglas_dragon(desdeOpcionLevels, nivelDragon, nombre, pasarNivel);

            if (nivelDragon == true) {
                startGameDragon(enemigosDerrotados, numeroClase, nombre, pasarNivel);
            }
        }
        else {
            // Mostrar pantalla de perdedor
            pantalla_perdedor_xd1(numeroClase);
            _getch();
        }
    }
}

void startGameCocodrile(int& enemigosDerrotados, int numeroClase, char* nombre, bool& pasarNivel) {
    srand(time(NULL));
    Console::Clear();
    Console::CursorVisible = false;
    bool nivelCocodrilo = false;
    bool desdeOpcionLevels = false;
    // Datos capibara
    Capibara capibara;
    capibara.x = Console::WindowWidth / 2 - 23;
    capibara.y = Console::WindowHeight / 2;
    capibara.dx = 5;
    capibara.dy = 5;
    capibara.ancho = 17;
    capibara.alto = 8;
    capibara.contadorDeGolpes = 0;
    capibara.vida = 100;
    capibara.estamina = 0;
    capibara.mana = 0;
    // Datos de los mini cocodrilos
    // Cocodrile1
    int xCocodrile1 = 0;
    int yCocodrile1 = 10;
    int dxCocodrile1 = 1;
    int dyCocodrile1 = 1;
    int altoCocodrile1 = 11;
    int anchoCocodrile1 = 61;
    int vidaCocodrile1 = 100;
    Enemigo Cocodrile1 = crearEnemigo2("Cocodrile1", xCocodrile1, yCocodrile1, dxCocodrile1, dyCocodrile1, altoCocodrile1, anchoCocodrile1, vidaCocodrile1);
    Cocodrile1.descansando = false;
    Cocodrile1.alejandose = true;
    Cocodrile1.tiempoAlejamiento = 0;
    Cocodrile1.tiempoDescanso = 100;
    Cocodrile1.margen = 2;
    Cocodrile1.danioRecibido = 1;
    Cocodrile1.turnoDeAtaque = true;
    // Cocodrile2
    int xCocodrile2 = 0;
    int yCocodrile2 = HEIGHT - 20;
    int dxCocodrile2 = 1;
    int dyCocodrile2 = 1;
    int altoCocodrile2 = 11;
    int anchoCocodrile2 = 61;
    int vidaCocodrile2 = 100;
    Enemigo Cocodrile2 = crearEnemigo2("Cocodrile2", xCocodrile2, yCocodrile2, dxCocodrile2, dyCocodrile2, altoCocodrile2, anchoCocodrile2, vidaCocodrile2);
    Cocodrile2.descansando = false;
    Cocodrile2.alejandose = true;
    Cocodrile2.tiempoAlejamiento = 0;
    Cocodrile2.tiempoDescanso = 100;
    Cocodrile2.margen = 2;
    Cocodrile2.danioRecibido = 1;
    Cocodrile2.turnoDeAtaque = false;

    // Arreglo de cocodrilos
    int tamanioCocodrilos = 2;
    Enemigo* cocodrilos = new Enemigo[2];
    cocodrilos[0] = Cocodrile1;
    cocodrilos[1] = Cocodrile2;

    // Creando bolas de fuego
    // Bola de fuego cocodrilo 1
    BolaDeFuego bolaDeFuego1;
    bolaDeFuego1.x = cocodrilos[0].xEnemigo + cocodrilos[0].anchoEnemigo / 2;
    bolaDeFuego1.y = cocodrilos[0].yEnemigo;
    bolaDeFuego1.dy = 1;
    bolaDeFuego1.id = 0;
    bolaDeFuego1.alto = 7;
    bolaDeFuego1.ancho = 13;
    // Bola de fuego cocodrilo 2
    BolaDeFuego bolaDeFuego2;
    bolaDeFuego2.x = cocodrilos[1].xEnemigo + cocodrilos[1].anchoEnemigo / 2;
    bolaDeFuego2.y = cocodrilos[1].yEnemigo;
    bolaDeFuego2.dy = -1;
    bolaDeFuego2.id = 1;
    bolaDeFuego2.alto = 7;
    bolaDeFuego2.ancho = 13;

    cocodrilos[0].bolaDeFuego = bolaDeFuego1;
    cocodrilos[1].bolaDeFuego = bolaDeFuego2;

    // Booleanos que detectan el movimiento del capibara
    bool moverIzquierda = false;
    bool moverArriba = false;
    bool capibaraMoviendose = false;

    char tecla;
    int tamanio = 3;
    Coordenada* coordenadas = new Coordenada[tamanio];

    // Variables locales
    bool coordenadasOrdenadas = false;
    int indiceActual = 0;

    // Datos de los bloques
    int tamanioBloques = 4;
    Bloque* bloques = new Bloque[tamanioBloques];

    bloques[0].x = 20;
    bloques[0].y = HEIGHT / 3;
    bloques[1].x = 70;
    bloques[1].y = HEIGHT / 3;
    bloques[2].x = 120;
    bloques[2].y = HEIGHT / 3;
    bloques[3].x = 180;
    bloques[3].y = HEIGHT / 3;

    // Pocion

    Potion nuevaPocion = generarPocion();
    definir_posicionObjeto2(capibara, cocodrilos, tamanioCocodrilos, nuevaPocion);


    dibujarCapibaraIzquierda(numeroClase, capibara);
    while (capibara.vida > 0) {
        capibara.cambiarEstamina = false;
        capibara.cambiarMana = false;
        capibara.atacar = false;
        capibara.recibeMejora = false;
        capibaraMoviendose = false;
        fondo3();
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            if (tecla == 'F') {
                capibara.atacar = true;
                capibaraAtaqueCocodrilos(capibara, cocodrilos, tamanioCocodrilos, moverArriba);
            }
            moverJugadorCocodrile(capibara, cocodrilos, tamanioCocodrilos, bloques, tamanioBloques, tecla, nuevaPocion, moverIzquierda, moverArriba, numeroClase);
            capibaraMoviendose = true;
        }

        if (capibara.recibeMejora) {
            nuevaPocion = generarPocion();
            definir_posicionObjeto2(capibara, cocodrilos, tamanioCocodrilos, nuevaPocion);
        }

        if (!nuevaPocion.desaparecer) {
            if (nuevaPocion.id == 1) {
                pocion_cheta(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 2) {
                pocion_fuerza(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 3) {
                pocion_mana(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 4) {
                pocion_vida(nuevaPocion.x, nuevaPocion.y);
            }
        }

        dibujarMiniCocodrilo(capibara, cocodrilos, tamanioCocodrilos);
        turnoDeLanzamiento(capibara, cocodrilos, tamanioCocodrilos, bloques, tamanioBloques);
        if (capibara.atacar && capibara.atacarArriba) {
            dibujarClaseAtaqueArriba(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarAbajo) {
            dibujarClaseAtaqueAbajo(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarDerecha) {
            dibujarClaseAtaqueDerecha(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarIzquierda) {
            dibujarClaseAtaqueIzquierda(numeroClase, capibara);
        }
        else if (capibara.atacar) {
            if (moverIzquierda) {
                dibujarClaseAtaqueIzquierda(numeroClase, capibara);
            }
            else {
                dibujarClaseAtaqueDerecha(numeroClase, capibara);
            }
        }
        else {
            if (moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraIzquierdaCaminando(numeroClase, capibara);
            }
            else if (moverIzquierda && !capibaraMoviendose) {
                dibujarCapibaraIzquierda(numeroClase, capibara);
            }
            else if (!moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraDerechaCaminando(numeroClase, capibara);
            }
            else {
                dibujarCapibaraDerecha(numeroClase, capibara);
            }
        }

        if (cocodrilos[1].vida <= 0 && cocodrilos[0].vida <= 0) {
            break;
        }
        gotoXY(0, 0);
        cout << "Nombre: " << nombre << endl;
        dibujarBarraStats(0, 2, capibara.vida, 100, "VIDA: ", RED);
        dibujarBarraStats(WIDTH / 2 + 5, 2, capibara.mana, 100, "MANA: ", BLUE);
        dibujarBarraStats(WIDTH / 3 - 10, 6, capibara.estamina, 100, "ESTAMINA: ", GREEN);
        dibujarBarraStats(0, HEIGHT - 5, cocodrilos[0].vida, 100, "C1: ", CYAN);
        dibujarBarraStats(WIDTH / 2 + 5, HEIGHT - 5, cocodrilos[1].vida, 100, "C2: ", CYAN);
        actualizarBarras(capibara, nuevaPocion);
    }

    if (cocodrilos[0].vida <= 0 && cocodrilos[1].vida <= 0) {
        // Siguiente nivel
        // Dragon!
        Console::Clear();
        enemigosDerrotados++;
        capibara.estamina = 0;
        capibara.mana = 0;
        escoger_pasar_nivel(pasarNivel);
        if (pasarNivel) {
            startGameDragon(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
    }

    if (capibara.vida <= 0) {
        Console::Clear();
        bool nuevoRC = false;
        bool repetirNivel = true;
        do {
            nuevoRC = false;
            generarRC(repetirNivel, nuevoRC);
        } while (nuevoRC);

        if (repetirNivel) {
            reglas_cocodrilo(desdeOpcionLevels, nivelCocodrilo, nombre, pasarNivel);

            if (nivelCocodrilo == true) {
                startGameCocodrile(enemigosDerrotados, numeroClase, nombre, pasarNivel);
            }
        }
        else {
            // Mostrar pantalla de perdedor
            pantalla_perdedor_xd1(numeroClase);
            _getch();
        }
    }
}

void startGameZorro(int& enemigosDerrotados, int numeroClase, char* nombre, bool& pasarNivel) {
    srand(time(NULL));
    Console::Clear();
    Console::CursorVisible = false;
    bool nivelZorro = false;
    bool desdeOpcionLevels = false;
    // Datos capibara
    Capibara capibara;
    capibara.x = Console::WindowWidth / 2 - 23;
    capibara.y = Console::WindowHeight / 2;
    capibara.dx = 5;
    capibara.dy = 5;
    capibara.ancho = 17;
    capibara.alto = 8;
    capibara.contadorDeGolpes = 0;
    capibara.vida = 100;
    capibara.estamina = 0;
    capibara.mana = 0;
    // Datos del enemigo
    int xFox = 0;
    int yFox = 0;
    int dxFox = 1;
    int dyFox = 1;
    int altoFox = 20;
    int anchoFox = 45;
    int vidaFox = 100;
    Enemigo Fox = crearEnemigo2("Fox", xFox, yFox, dxFox, dyFox, altoFox, anchoFox, vidaFox);
    Fox.descansando = false;
    Fox.alejandose = true;
    Fox.tiempoAlejamiento = 0;
    Fox.tiempoDescanso = 100;
    Fox.margen = 2;
    Fox.danioRecibido = 1;


    // Booleanos que detectan el movimiento del capibara
    bool moverIzquierda = false;
    bool moverArriba = false;
    bool capibaraMoviendose = false;

    char tecla;
    int tamanio = 3;
    Coordenada* coordenadas = new Coordenada[tamanio];

    // Pocion

    Potion nuevaPocion = generarPocion();
    definir_posicionObjeto1(capibara, Fox, nuevaPocion);


    // Variables locales
    bool coordenadasOrdenadas = false;
    int indiceActual = 0;

    dibujarCapibaraIzquierda(numeroClase, capibara);
    coordenadasAleatorias(tamanio, Fox, coordenadas);
    while (capibara.vida > 0) {
        capibara.cambiarEstamina = false;
        capibara.cambiarMana = false;
        capibara.recibeMejora = false;
        capibara.atacar = false;
        capibaraMoviendose = false;
        fondo2();
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
        // DibujarEnemigo
        dibujarZorro(capibara, Fox, coordenadas, tamanio, coordenadasOrdenadas, indiceActual, numeroClase);
        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            if (tecla == 'F') {
                capibara.atacar = true;
                capibaraAtaqueZorro(capibara, Fox, moverArriba);
            }
            moverJugador(capibara, Fox, tecla, nuevaPocion, moverIzquierda, moverArriba);
            capibaraMoviendose = true;
        }

        if (capibara.recibeMejora) {
            nuevaPocion = generarPocion();
            definir_posicionObjeto1(capibara, Fox, nuevaPocion);
        }

        if (!nuevaPocion.desaparecer) {
            if (nuevaPocion.id == 1) {
                pocion_cheta(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 2) {
                pocion_fuerza(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 3) {
                pocion_mana(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 4) {
                pocion_vida(nuevaPocion.x, nuevaPocion.y);
            }
        }

        if (capibara.atacar && capibara.atacarArriba) {
            dibujarClaseAtaqueArriba(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarAbajo) {
            dibujarClaseAtaqueAbajo(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarDerecha) {
            dibujarClaseAtaqueDerecha(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarIzquierda) {
            dibujarClaseAtaqueIzquierda(numeroClase, capibara);
        }
        else if (capibara.atacar) {
            if (moverIzquierda) {
                dibujarClaseAtaqueIzquierda(numeroClase, capibara);
            }
            else {
                dibujarClaseAtaqueDerecha(numeroClase, capibara);
            }
        }
        else {
            if (moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraIzquierdaCaminando(numeroClase, capibara);
            }
            else if (moverIzquierda && !capibaraMoviendose) {
                dibujarCapibaraIzquierda(numeroClase, capibara);
            }
            else if (!moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraDerechaCaminando(numeroClase, capibara);
            }
            else {
                dibujarCapibaraDerecha(numeroClase, capibara);
            }
        }

        gotoXY(0, 0);
        cout << "Nombre: " << nombre << endl;
        dibujarBarraStats(0, 2, capibara.vida, 100, "VIDA: ", RED);
        dibujarBarraStats(WIDTH / 2 + 5, 2, capibara.mana, 100, "MANA: ", BLUE);
        dibujarBarraStats(WIDTH / 3 - 10, 6, capibara.estamina, 100, "ESTAMINA: ", GREEN);
        dibujarBarraStats(0, HEIGHT - 5, Fox.vida, 100, "ZORRO: ", CYAN);
        actualizarBarras(capibara, nuevaPocion);

        if (Fox.vida <= 0) {
            break;
        }
    }

    if (Fox.vida <= 0) {
        // Siguiente nivel
        Console::Clear();
        capibara.estamina = 0;
        capibara.mana = 0;
        enemigosDerrotados++;
        escoger_pasar_nivel(pasarNivel);
        if (pasarNivel) {
            startGameCocodrile(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
    }

    if (capibara.vida <= 0) {
        Console::Clear();
        bool nuevoRC = false;
        bool repetirNivel = true;
        do {
            nuevoRC = false;
            generarRC(repetirNivel, nuevoRC);
        } while (nuevoRC);

        if (repetirNivel) {
            reglas_zorro(desdeOpcionLevels, nivelZorro, nombre, pasarNivel);
            if (nivelZorro == true) {
                startGameZorro(enemigosDerrotados, numeroClase, nombre, pasarNivel);
            }
        }
        else {
            // MOSTRAR DERROTA
            pantalla_perdedor_xd1(numeroClase);
            _getch();
        }
    }
}

void startGameArdilla(int& enemigosDerrotados, int numeroClase, char* nombre, bool& pasarNivel) {
    Console::Clear();
    Console::CursorVisible = false;
    bool nivelArdilla = false;
    bool desdeOpcionLevels = false;
    // Declarando variables para la ardilla
    int xArdilla = Console::WindowWidth / 2;
    int yArdilla = Console::WindowHeight / 2;
    int dxArdilla = 5;
    int dyArdilla = 5;
    int altoArdilla = 14;
    int anchoArdilla = 30;

    // Creando enemigo ardilla
    Enemigo ardilla = crearEnemigo1("Ardilla", xArdilla, yArdilla, dxArdilla, dyArdilla, altoArdilla, anchoArdilla);
    ardilla.tiempoAlejamiento = 0;
    ardilla.tiempoDescanso = 100;
    ardilla.margen = 2;
    ardilla.vida = 100;
    ardilla.danioRecibido = 2;
    ardilla.golpesMaximos = 3;

    // Creando bellota
    Bellota bellota;
    bellota.x = xArdilla + (anchoArdilla / 2);
    bellota.y = yArdilla + (altoArdilla / 2);
    bellota.dx = 1;
    bellota.dy = 1;
    bellota.ancho = 3;
    bellota.alto = 3;
    bellota.tiempoDisparo = 10;

    // Datos capibara
    Capibara capibara;
    capibara.x = Console::WindowWidth / 2 - 23;
    capibara.y = Console::WindowHeight / 2;
    capibara.dx = 5;
    capibara.dy = 5;
    capibara.ancho = 17;
    capibara.alto = 8;
    capibara.contadorDeGolpes = 0;
    capibara.vida = 100;
    capibara.estamina = 0;
    capibara.mana = 0;

    // Pocion

    Potion nuevaPocion = generarPocion();
    definir_posicionObjeto1(capibara, ardilla, nuevaPocion);


    // Booleanos que detectan el movimiento del capibara
    bool moverIzquierda = false;
    bool moverArriba = false;
    bool capibaraMoviendose = false;

    char tecla;

    dibujarCapibaraIzquierda(numeroClase, capibara);

    while (capibara.vida > 0) {
        capibara.recibeMejora = false;
        capibara.cambiarEstamina = false;
        capibara.cambiarMana = false;
        capibara.atacar = false;
        capibaraMoviendose = false;
        fondo1();
        borrarJugador(capibara.x, capibara.y, capibara.alto, capibara.ancho);
        dibujarArdilla(capibara, ardilla, bellota, moverArriba);
        if (kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            if (tecla == 'F') {
                capibara.atacar = true;
                capibaraAtaque(capibara, ardilla, bellota, moverArriba);
            }
            moverJugador(capibara, ardilla, tecla, nuevaPocion, moverIzquierda, moverArriba);
            capibaraMoviendose = true;
        }

        if (capibara.recibeMejora) {
            nuevaPocion = generarPocion();
            definir_posicionObjeto1(capibara, ardilla, nuevaPocion);
        }

        if (!nuevaPocion.desaparecer) {
            if (nuevaPocion.id == 1) {
                pocion_cheta(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 2) {
                pocion_fuerza(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 3) {
                pocion_mana(nuevaPocion.x, nuevaPocion.y);
            }
            else if (nuevaPocion.id == 4) {
                pocion_vida(nuevaPocion.x, nuevaPocion.y);
            }
        }

        if (capibara.atacar && capibara.atacarArriba) {
            dibujarClaseAtaqueArriba(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarAbajo) {
            dibujarClaseAtaqueAbajo(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarDerecha) {
            dibujarClaseAtaqueDerecha(numeroClase, capibara);
        }
        else if (capibara.atacar && capibara.atacarIzquierda) {
            dibujarClaseAtaqueIzquierda(numeroClase, capibara);
        }
        else if (capibara.atacar) {
            if (moverIzquierda) {
                dibujarClaseAtaqueIzquierda(numeroClase, capibara);
            }
            else {
                dibujarClaseAtaqueDerecha(numeroClase, capibara);
            }
        }
        else {
            if (moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraIzquierdaCaminando(numeroClase, capibara);
            }
            else if (moverIzquierda && !capibaraMoviendose) {
                dibujarCapibaraIzquierda(numeroClase, capibara);
            }
            else if (!moverIzquierda && capibaraMoviendose) {
                dibujarCapibaraDerechaCaminando(numeroClase, capibara);
            }
            else {
                dibujarCapibaraDerecha(numeroClase, capibara);
            }
        }
        gotoXY(0, 0);
        cout << "Nombre: " << nombre << endl;
        dibujarBarraStats(0, 2, capibara.vida, 100, "VIDA: ", RED);
        dibujarBarraStats(WIDTH / 2 + 5, 2, capibara.mana, 100, "MANA: ", BLUE);
        dibujarBarraStats(WIDTH / 3 - 10, 6, capibara.estamina, 100, "ESTAMINA: ", GREEN);
        dibujarBarraStats(0, HEIGHT - 5, ardilla.vida, 100, "ARDILLA: ", CYAN);
        actualizarBarras(capibara, nuevaPocion);


        if (ardilla.vida <= 0) {
            break;
        }

        _sleep(10);
    }

    // Iniciar nivel Zorro
    if (ardilla.vida <= 0) {
        Console::Clear();
        capibara.estamina = 0;
        capibara.mana = 0;
        enemigosDerrotados++;
        escoger_pasar_nivel(pasarNivel);
        if (pasarNivel) {
            startGameZorro(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
    }

    if (capibara.vida <= 0) {
        bool nuevoRC = false;
        bool repetirNivel = true;
        Console::Clear();
        do {
            nuevoRC = false;
            generarRC(repetirNivel, nuevoRC);
        } while (nuevoRC);

        if (repetirNivel) {
            reglas_ardilla(desdeOpcionLevels, nivelArdilla, nombre, pasarNivel);
            if (nivelArdilla == true) {
                startGameArdilla(enemigosDerrotados, numeroClase, nombre, pasarNivel);
            }
        }
        else {
            // Mostrar pantalla perdedor
            pantalla_perdedor_xd1(numeroClase);
            _getch();
        }
    }
}

void drawCreditsInput(int x, int y) {

    dibujarRectanguloHueco(x + 2, y + 2, 29, 8);
    //Dibujar en ascii OPTIONS
    dibujarletraC(x + 5, y + 3);
    dibujarletraR(x + 11, y + 3);
    dibujarletraE(x + 17, y + 3);
    dibujarletraD(x + 23, y + 3);
    dibujarletraI(x + 29, y + 3);
    dibujarletraT(x + 35, y + 3);
    dibujarletraS(x + 41, y + 3);
    dibujarparentesisabierto(x + 47, y + 3);
    dibujarletraC(x + 50, y + 3);
    dibujarparentesiscerrado(x + 56, y + 3);
}

void drawInstructionsInput(int x, int y) {

    dibujarRectanguloHueco(x + 2, y + 2, 44, 8);
    //Dibujar en ascii OPTIONS
    dibujarletraI(x + 5, y + 3);
    dibujarletraN(x + 11, y + 3);
    dibujarletraS(x + 17, y + 3);
    dibujarletraT(x + 23, y + 3);
    dibujarletraR(x + 29, y + 3);
    dibujarletraU(x + 35, y + 3);
    dibujarletraC(x + 41, y + 3);
    dibujarletraT(x + 47, y + 3);
    dibujarletraI(x + 53, y + 3);
    dibujarletraO(x + 59, y + 3);
    dibujarletraN(x + 65, y + 3);
    dibujarletraS(x + 71, y + 3);
    dibujarparentesisabierto(x + 77, y + 3);
    dibujarletraI(x + 80, y + 3);
    dibujarparentesiscerrado(x + 86, y + 3);
}

void drawMenuInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    //Dibujar en ascii START
    dibujarletraM(x + 5, y + 3);
    dibujarletraE(x + 11, y + 3);
    dibujarletraN(x + 17, y + 3);
    dibujarletraU(x + 23, y + 3);
    dibujarparentesisabierto(x + 35, y + 3);
    dibujarletraM(x + 38, y + 3);
    dibujarparentesiscerrado(x + 44, y + 3);
}

void drawMenuInputSelected(int x, int y) {
    cout << YELLOW;
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    //Dibujar en ascii START
    dibujarletraM(x + 5, y + 3);
    dibujarletraE(x + 11, y + 3);
    dibujarletraN(x + 17, y + 3);
    dibujarletraU(x + 23, y + 3);
    dibujarparentesisabierto(x + 35, y + 3);
    dibujarletraM(x + 38, y + 3);
    dibujarparentesiscerrado(x + 44, y + 3);
    cout << RESET;
}

void pantalla_niveles() {

    dibujarRectanguloHueco(2 * (Console::WindowWidth / 5), (Console::WindowHeight / 6), 16, 5);

    textoConSleep("niveles", 2 * (Console::WindowWidth / 5) + 2, (Console::WindowHeight / 6) + 1);


    dibujarRectanguloHueco(30, 20, 5, 5);
    number1(33, 21);

    dibujarRectanguloHueco(60, 20, 5, 5);
    number2(64, 21);

    dibujarRectanguloHueco(90, 20, 5, 5);
    number3(94, 21);

    dibujarRectanguloHueco(120, 20, 5, 5);
    number4(124, 21);

    fondo_niveles_xdjjsjs();
}

void mover_flecha(int& x, int& y, int alto, int ancho, char tecla, int& dx, int& dy, bool& menuSeleccionado, bool& flechitasSeleccionadas) {

    if (tecla == ARRIBA && y > 0) y -= dy;

    if (tecla == ABAJO && y < Console::WindowHeight - alto) y += dy;

    if (x < 100) {
        if (tecla == DERECHA && x < (Console::WindowWidth - ancho - dx)) {
            menuSeleccionado = false;
            x += dx;
            flechitasSeleccionadas = true;
            drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);
        }
    }
    else {
        if (tecla == DERECHA && x > 0) {
            menuSeleccionado = false;
            x -= dx;
            flechitasSeleccionadas = true;
            drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);
        }
    }

    if (x > 26) {
        if (tecla == IZQUIERDA && x > 0) {
            x -= dx;
            menuSeleccionado = false;
            flechitasSeleccionadas = true;
            drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);
        }
    }
    else {
        if (tecla == IZQUIERDA && x < (Console::WindowWidth - ancho - dx)) {
            x += dx;
            menuSeleccionado = false;
            flechitasSeleccionadas = true;
            drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);
        }
    }
}

void escoger_nivel(bool& nivelArdilla, bool& nivelZorro, bool& nivelCocodrilo, bool& nivelDragon, int& x, int& y, char tecla, bool& volverMenu, bool& botonMenuSeleccionado, bool& flechitasSeleccionadas, char* nombre, bool& pasarNivel, bool& salirDelBucle) {
    if (kbhit()) {
        tecla = _getch();
        tecla = toupper(tecla);

        if (tecla == ' ' && x == 26 && !botonMenuSeleccionado) {
            Console::Clear();
            reglas_ardilla(true, nivelArdilla, nombre, pasarNivel);
            salirDelBucle = true;
        }

        if (tecla == ' ' && x == 56 && !botonMenuSeleccionado) {
            Console::Clear();
            reglas_zorro(true, nivelZorro, nombre, pasarNivel);
            salirDelBucle = true;
        }

        if (tecla == ' ' && x == 86 && !botonMenuSeleccionado) {
            Console::Clear();
            reglas_cocodrilo(true, nivelCocodrilo, nombre, pasarNivel);
            salirDelBucle = true;
        }

        if (tecla == ' ' && x == 116 && !botonMenuSeleccionado) {
            Console::Clear();
            reglas_dragon(true, nivelDragon, nombre, pasarNivel);
            salirDelBucle = true;
        }

        if (tecla == 'M') {
            drawMenuInputSelected((WIDTH / 3) + 10, HEIGHT - 15);
            botonMenuSeleccionado = true;
            flechitasSeleccionadas = false;
        }

        if (tecla == ' ' && !flechitasSeleccionadas && botonMenuSeleccionado) {
            volverMenu = true;
            salirDelBucle = true;
        }
    }
}

bool escogerNiveles(bool& nivelArdilla, bool& nivelZorro, bool& nivelCocodrilo, bool& nivelDragon, char* nombre, bool& pasarNivel) {
    char tecla;
    Console::CursorVisible = false;

    int x = 26, y = 20;
    int alto = 3, ancho = 4;
    int dx = 30, dy = 0;

    bool volverMenu = false;
    bool botonMenuSeleccionado = false;
    bool flechitasSeleccionadas = false;
    bool salirDelBucle = false;

    pantalla_niveles();

    drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);

    while (!volverMenu && !salirDelBucle) {
        borrar_flecha_jsjaja(x, y);

        if (kbhit()) {
            tecla = getch();
            tecla = toupper(tecla);
            mover_flecha(x, y, alto, ancho, tecla, dx, dy, botonMenuSeleccionado, flechitasSeleccionadas);
        }

        fleschitajsjaja(x, y);

        _sleep(1);
        escoger_nivel(nivelArdilla, nivelZorro, nivelCocodrilo, nivelDragon, x, y, tecla, volverMenu, botonMenuSeleccionado, flechitasSeleccionadas, nombre, pasarNivel, salirDelBucle);
    }

    return true;
}

void pantalla_de_los_creditos() {
    dibujarRectanguloHueco(0, 0, 78, 35);
    cout << RED;
    textoConSleep("dibujantes: ", 5, 1);
    cout << RESET;
    cout << BROWN;
    textoConSleep("- Joao Jimenez", 7, 5);
    textoConSleep("- Eduardo Damian", 7, 9);
    textoConSleep("- Ivan Carrillo", 7, 13);
    cout << RESET;
    cout << RED;
    textoConSleep("animadores:", 5, 17);
    cout << RESET;
    cout << BROWN;
    textoConSleep("- Alvaro Neyra", 7, 21);
    textoConSleep("- Ivan Carrillo", 7, 25);
    textoConSleep("- Joao Jimenez", 7, 29);
    cout << RESET;
    cout << RED;
    textoConSleep("programacion:", 72, 1);
    cout << RESET;
    cout << BROWN;
    textoConSleep("- Alvaro Neyra", 75, 5);
    textoConSleep("- Ivan Carrillo", 75, 9);
    textoConSleep("- Joao Jimenez", 75, 13);
    textoConSleep("- David Palomino", 75, 17);
    cout << RESET;
    cout << RED;
    textoConSleep("video", 75, 21);
    cout << RESET;
    cout << BROWN;
    textoConSleep("- David Palomino", 75, 25);
    textoConSleep("- Eduardo Damian", 75, 29);
    cout << RESET;
}

void como_ganar(int x, int y) {
    Console::Clear();
    cout << YELLOW;
    dibujarRectanguloHueco(x + 1, y + 0, 110, 55);
    cout << WHITE;
    textoConSleep("Como se gana?:", x + 4, y + 1);

    cout << CYAN;
    textoConSleep("Ganas cuando terminas de derrotar a todos los enemigos", x + 4, y + 5);
    textoConSleep("y puedas rescatar a tu amada esposa.", x + 4, y + 9);
    cout << WHITE;
    textoConSleep("Cuando termina el juego:", x + 4, y + 13);
    cout << CYAN;
    textoConSleep("Finalizando el juego la consola te muestra el menu,", x + 4, y + 17);
    textoConSleep("en la que te da opciones si quieres reiniciar o", x + 4, y + 21);
    textoConSleep("o salir del juego. Si presionas en reiniciar el", x + 4, y + 25);
    textoConSleep("juego, entonces comenzaras desde el principio y ", x + 4, y + 29);
    textoConSleep("si presionas salir, sales del juego. ", x + 4, y + 33);
    textoConSleep("Los enemigos, tambien cuentan con poderes para", x + 4, y + 37);
    textoConSleep("poder impedir el avance del capibara. El capibara", x + 4, y + 41);
    textoConSleep("debe derrotar diversos enemigos con sus respectivos", x + 4, y + 45);
    textoConSleep("jefes, ya que al derrotar a cada jefe tendras un obsequio.", x + 4, y + 49);
    cout << RESET;
}

void iniciar_juego(int x, int y) {
    Console::Clear();
    cout << YELLOW;
    dibujarRectanguloHueco(x + 1, y + 0, 110, 45);
    cout << WHITE;
    textoConSleep("Como inicia este juego?:", x + 4, y + 1);

    cout << CYAN;
    textoConSleep("El juego inicia con el capibara, en donde", x + 4, y + 5);
    textoConSleep("se encuentra solo en una zona para iniciar el camino", x + 4, y + 9);
    textoConSleep("de su aventura, en donde todo su viaje se encontrara", x + 4, y + 13);
    textoConSleep("con implementos que ayudaran aumentar su poder.", x + 4, y + 17);
    textoConSleep("Asi mismo, encontrara enemigos que haran que impidan", x + 4, y + 21);
    textoConSleep("rescatar a su amada esposa brigitte.", x + 4, y + 25);
    textoConSleep("Los enemigos, tambien cuentan con poderes para", x + 4, y + 29);
    textoConSleep("impedir el avance del capibara. El capibara debe", x + 4, y + 33);
    textoConSleep("derrotar diversos enemigos con sus respectivos jefes,", x + 4, y + 37);
    textoConSleep("ya que al derrotar a cada jefe tendras un obsequio.", x + 4, y + 41);
    cout << RED;
    flechita(x + 110, y + 48);
    textoConSleep("CONTINUAR", x + 100, y + 55);

    bool iniciandoInstrucciones = false;
    char tecla;

    while (iniciandoInstrucciones == false) {
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == DERECHA) {
                setWindow();
                como_ganar(x, y);
                iniciandoInstrucciones = true;
            }
        }
    }
}

void instrucciones(int x, int y) {
    Console::CursorVisible = false;
    Console::Clear;
    cout << YELLOW;
    dibujarRectanguloHueco(x + 1, y + 0, 110, 25);
    cout << WHITE;
    textoConSleep("De que trata el juego:", x + 4, y + 1);

    cout << CYAN;
    textoConSleep("En este juego, tendras la simulacion de combatir con", x + 4, y + 5);
    textoConSleep("diversos enemigos, en donde tu papel principal sera el", x + 4, y + 9);
    textoConSleep("derrotar a los enemigos en todo el camino de tu", x + 4, y + 13);
    textoConSleep("aventura, hasta rescatar a su Brigitte (la esposa).", x + 4, y + 17);
    cout << RED;
    flechita(x + 100, y + 30);
    textoConSleep("CONTINUAR", x + 90, y + 37);
    cout << RESET;

    bool iniciandoInstrucciones = false;
    char tecla;

    while (iniciandoInstrucciones == false) {
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == DERECHA) {
                setWindow();
                iniciar_juego(x, y);
                iniciandoInstrucciones = true;
            }
        }
    }
}

void drawScreenStart() {
    Console::Clear();
    drawCapyAdventures(1, 0);
    flechitajsjsjs(5, 11);
    drawStartImput(17, 8);
    drawInstructionsInput(17, 17);
    drawLevelsImput(17, 26);
    drawCreditsInput(17, 35);
    drawExtitImput(17, 44);
    decoracion1();
}

void drawScreenStartStart(char* color) {
    Console::Clear();
    drawCapyAdventures(1, 0);
    cout << YELLOW;
    flechitajsjsjs(5, 11);
    drawStartImput(17, 8);
    cout << RESET;
    drawInstructionsInput(17, 17);
    drawLevelsImput(17, 26);
    drawCreditsInput(17, 35);
    drawExtitImput(17, 44);
    decoracion1();
}

void drawScreenStartInstructions(char* color) {
    Console::Clear();
    drawCapyAdventures(1, 0);
    drawStartImput(17, 8);
    cout << YELLOW;
    flechitajsjsjs(5, 20);
    drawInstructionsInput(17, 17);
    cout << RESET;
    drawLevelsImput(17, 26);
    drawCreditsInput(17, 35);
    drawExtitImput(17, 44);
    decoracion1();
}

void drawScreenStartLevels(char* color) {
    Console::Clear();
    drawCapyAdventures(1, 0);
    drawStartImput(17, 8);
    drawInstructionsInput(17, 17);
    cout << color;
    flechitajsjsjs(5, 29);
    drawLevelsImput(17, 26);
    cout << RESET;
    drawCreditsInput(17, 35);
    drawExtitImput(17, 44);
    decoracion1();
}

void drawScreenStartCredits(char* color) {
    Console::Clear();
    drawCapyAdventures(1, 0);
    drawStartImput(17, 8);
    drawInstructionsInput(17, 17);
    drawLevelsImput(17, 26);
    cout << color;
    flechitajsjsjs(5, 38);
    drawCreditsInput(17, 35);
    cout << RESET;
    drawExtitImput(17, 44);
    decoracion1();
}

void drawScreenStartExit(char* color) {
    Console::Clear();
    drawCapyAdventures(1, 0);
    drawStartImput(17, 8);
    drawInstructionsInput(17, 17);
    drawLevelsImput(17, 26);
    drawCreditsInput(17, 35);
    cout << color;
    flechitajsjsjs(5, 47);
    drawExtitImput(17, 44);
    cout << RESET;
    decoracion1();
}

void screenMenu() {
    char* nombre;
    char tecla;
    bool pantallaOpcionInicio = false;
    bool pantallaOpcionInstructions = false;
    bool pantallaOpcionCredits = false;
    bool pantallaOpcionLevels = false;
    bool pantallaOpcionExit = false;
    bool iniciarJuego = false;
    bool menuLevels = false;
    bool instructionsMenu = false;
    bool menuCredits = false;
    bool exitGame = false;
    bool nombreValidado;
    bool pasarNivel = false;
    bool nivelArdilla = false;
    bool nivelZorro = false;
    bool nivelCocodrile = false;
    bool nivelDragon = false;
    int numeroClase;
    int enemigosDerrotados = 0;
    drawScreenStart();
    while (iniciarJuego == false && instructionsMenu == false && menuLevels == false && menuCredits == false && exitGame == false) {
        if (_kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            if (tecla == 'S') {
                drawScreenStartStart(YELLOW);
                pantallaOpcionInicio = true;
                pantallaOpcionLevels = false;
                pantallaOpcionInstructions = false;
                pantallaOpcionCredits = false;
                pantallaOpcionExit = false;
            }
            else if (tecla == 'I') {
                drawScreenStartInstructions(YELLOW);
                pantallaOpcionInicio = false;
                pantallaOpcionLevels = false;
                pantallaOpcionInstructions = true;
                pantallaOpcionCredits = false;
                pantallaOpcionExit = false;
            }
            else if (tecla == 'L') {
                drawScreenStartLevels(YELLOW);
                pantallaOpcionInicio = false;
                pantallaOpcionInstructions = false;
                pantallaOpcionLevels = true;
                pantallaOpcionCredits = false;
                pantallaOpcionExit = false;
            }
            else if (tecla == 'C') {
                drawScreenStartCredits(YELLOW);
                pantallaOpcionInicio = false;
                pantallaOpcionLevels = false;
                pantallaOpcionInstructions = false;
                pantallaOpcionCredits = true;
                pantallaOpcionExit = false;
            }
            else if (tecla == 'E') {
                drawScreenStartExit(YELLOW);
                pantallaOpcionInicio = false;
                pantallaOpcionLevels = false;
                pantallaOpcionInstructions = false;
                pantallaOpcionCredits = false;
                pantallaOpcionExit = true;
            }

            if (tecla == ' ') {
                if (pantallaOpcionInicio == true) {
                    iniciarJuego = true;
                }
                else if (pantallaOpcionLevels == true) {
                    menuLevels = true;
                }
                else if (pantallaOpcionInstructions == true) {
                    instructionsMenu = true;
                }
                else if (pantallaOpcionCredits == true) {
                    menuCredits = true;
                }
                else if (pantallaOpcionExit == true) {
                    exitGame = true;
                }
            }
        }
    }

    if (iniciarJuego) {
        do {
            nombre = nameInput();
            nombreValidado = validateInputName(nombre);
            gotoXY((WIDTH / 3) - 8, 50);
            if (nombreValidado == false) {
                cout << "Nombre ingresado incorrectamente, apreta una tecla para intentar denuevo...";
                _getch();
            }
        } while (nombreValidado == false);
        numeroClase = chooseClassMenu();
        drawScreenPreviewClass(numeroClase);

        startGameArdilla(enemigosDerrotados, numeroClase, nombre, pasarNivel);

        if (pasarNivel == false) {
            Console::Clear();
            screenMenu();
        }
    }
    else if (instructionsMenu) {
        Console::Clear();
        instrucciones(5, 0);
        drawMenuInput((WIDTH / 3) + 10, HEIGHT - 15);
        bool volverMenu = false;
        bool botonMenuSeleccionado = false;
        char tecla;
        while (volverMenu == false) {
            if (_kbhit()) {
                tecla = _getch();
                tecla = toupper(tecla);
                if (tecla == 'M') {
                    drawMenuInputSelected((WIDTH / 3) + 10, HEIGHT - 15);
                    botonMenuSeleccionado = true;
                }

                if (tecla == ' ') {
                    if (botonMenuSeleccionado == true) {
                        volverMenu = true;
                    }
                }
            }
        }
        if (volverMenu) {
            screenMenu();
        }
    }
    else if (menuLevels) {
        Console::Clear();
        nombre = "NO DEFINIDO";

        bool volverMenu = escogerNiveles(nivelArdilla, nivelZorro, nivelCocodrile, nivelDragon, nombre, pasarNivel);
        if (nivelArdilla) {
            numeroClase = chooseClassMenu();
            drawScreenPreviewClass(numeroClase);
            startGameArdilla(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
        else if (nivelZorro) {
            numeroClase = chooseClassMenu();
            drawScreenPreviewClass(numeroClase);
            startGameZorro(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
        else if (nivelCocodrile) {
            numeroClase = chooseClassMenu();
            drawScreenPreviewClass(numeroClase);
            startGameCocodrile(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
        else if (nivelDragon) {
            numeroClase = chooseClassMenu();
            drawScreenPreviewClass(numeroClase);
            startGameDragon(enemigosDerrotados, numeroClase, nombre, pasarNivel);
        }
        if (!pasarNivel) {
            Console::Clear();
            screenMenu();
        }
        if (volverMenu) {
            Console::Clear();
            screenMenu();
        }
    }
    else if (menuCredits) {
        Console::Clear();
        pantalla_de_los_creditos();
        drawMenuInput((WIDTH / 3) + 10, HEIGHT - 30);
        bool volverMenu = false;
        bool botonMenuSeleccionado = false;
        char tecla;
        while (volverMenu == false) {
            if (_kbhit()) {
                tecla = _getch();
                tecla = toupper(tecla);
                if (tecla == 'M') {
                    drawMenuInputSelected((WIDTH / 3) + 10, HEIGHT - 30);
                    botonMenuSeleccionado = true;
                }

                if (tecla == ' ') {
                    if (botonMenuSeleccionado == true) {
                        volverMenu = true;
                    }
                }
            }
        }
        if (volverMenu) {
            screenMenu();
        }
    }
    else if (exitGame) {
        Console::Clear();
        cout << "Salir del juego..";
        _getch();
    }
}