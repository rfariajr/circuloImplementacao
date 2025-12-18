#include <cmath>
#include <SDL.h>

#include "../include/Defs.hpp"


//Implementação das funções

//Calcula a distância entre dois pixels
int calculaDistancia(struct Circulo c, int coordenadaX, int coordenadaY) {
	float dist = sqrt(pow(c.x - coordenadaX, 2) + pow(c.y - coordenadaY, 2));
	return dist < c.raio ? 1 : 0;

}

//Define a área do quadrado que delimita o círculo
void defineQuadradoDelimitador(struct Circulo c, int *inicioX, int *fimX, int *inicioY, int *fimY) {
	*inicioX = c.x - c.raio < 0 ? 0 : c.x - c.raio;
	*fimX = c.x + c.raio > LARGURA ? LARGURA : c.x + c.raio;
	*inicioY = c.y - c.raio < 0 ? 0 : c.y - c.raio;
	*fimY = c.y + c.raio > ALTURA ? ALTURA : c.y + c.raio;
	return;
}

//Função mais eficiente que gera o circulo
void gerarCirculo(struct Circulo c, SDL_Surface *psurface, SDL_Window *pwindow) {
	
	//Definindo o pixel
	SDL_Rect pixel{0, 0, 1, 1};

	//defino dimensão da área retangular que comporta o círculo
	int inicioX, fimX;
	int inicioY, fimY;
	defineQuadradoDelimitador(c, &inicioX, &fimX, &inicioY, &fimY);
	//inicio o loop dentro dessa área
	for(int i = inicioX; i <= fimX; ++i) {
		for(int j = inicioY; j <= fimY; ++j) {
			//Pixel é colorido casua sua distância do centro seja menor que o raio
			if(calculaDistancia(c, i, j)) {
				pixel.x = i;
				pixel.y = j;
				SDL_FillRect(psurface, &pixel, 0xFFFF0000);
				//SDL_UpdateWindowSurface(pwindow)
			}
		}
	}
       	return;
}

//Função menos eficiente que gera o círculo
void gerarCirculoIneficiente(struct Circulo c, SDL_Surface *psurface, SDL_Window *pwindow) {
	SDL_Rect pixel{0, 0, 1, 1};
	
	for(int i = 0; i <= LARGURA; ++i) {
		for(int j = 0; j <= ALTURA; ++j) {
			if(calculaDistancia(c, i, j)) {
				pixel.x = i;
				pixel.y = j;
				SDL_FillRect(psurface, &pixel, 0xFFFFFFFF);
			}
		}
	}
	return;
}
