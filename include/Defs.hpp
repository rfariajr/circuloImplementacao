#ifndef DEFS_HPP
#define DEFS_HPP

#include <SDL.h>

//Dimensões da janela
#define LARGURA 900
#define ALTURA 600

//Coordenadas e dimensões do círculo
#define COORDENADA_X 120
#define COORDENADA_Y 300
#define RAIO 100

//Circulo
struct Circulo {
	int x;
	int y;
	int raio;
};


//Funções necessárias
int calculaDistancia(struct Circulo c, int coordenadaX, int coordenadaY);

void defineQuadradoDelimitador(struct Circulo c, int *inicioX, int *fimX, int *inicioY, int *fimY);

void gerarCirculo(struct Circulo c, SDL_Surface *psurface, SDL_Window *pwindow);

void gerarCirculoIneficiente(struct Circulo c, SDL_Surface *psurface, SDL_Window *pwindow);

#endif
