#include <iostream>
#include <chrono>
#include <SDL.h>

#include "../include/Defs.hpp"


int main(){
	//Abrir SDL
	//Fechar SDL
	//Abrir janela
	//Abrir superficie
	//Gerar Circulo
	//Atualizar superficie
	//Destruir janela
	//g++ -Wall program.cpp -o output_name `sdl2-config --cflags --libs`


	//Abrindo SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Erro ao iniciar a biblioteca SDL." << std::endl;
		SDL_Quit();
		return 1;
	}
	
	//Abrindo janela
	SDL_Window *window = SDL_CreateWindow("Janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGURA, ALTURA, 0);

	//Criando superficie
	SDL_Surface *surfaceWindow = SDL_GetWindowSurface(window);

	//Gerar circulo
	struct Circulo c;
	c.x = COORDENADA_X;
	c.y = COORDENADA_Y;
	c.raio = RAIO;

	//Variaveis para calcular o tempo de execução algoritmo 1
	std::chrono::time_point<std::chrono::high_resolution_clock> inicio, fim;
	std::chrono::duration<float> duracao;
	inicio = std::chrono::high_resolution_clock::now();
	gerarCirculo(c, surfaceWindow, window);
	fim = std::chrono::high_resolution_clock::now();
	duracao = fim - inicio;
	float ms = duracao.count() * 1000.0f;

	
	struct Circulo c2;
	c2.x = LARGURA - 120;
	c2.y = COORDENADA_Y;
	c2.raio = RAIO;

	//Variáveis para calcular o tempo de execução algoritmo 2
	std::chrono::time_point<std::chrono::high_resolution_clock> inicio1, fim1;
	std::chrono::duration<float> duracao1;
	inicio1 = std::chrono::high_resolution_clock::now();
	gerarCirculoIneficiente(c2, surfaceWindow, window);
	fim1 = std::chrono::high_resolution_clock::now();
	duracao1 = fim1 - inicio1;
	float ms1 = duracao1.count() * 1000.0f;

	//Atualizar superficie
	SDL_UpdateWindowSurface(window);

	//Exibindo o tempo de execução
	std::cout << "Tempo de execução da função mais eficiente: " << ms << std::endl;
	std::cout << "Tempo de execução da função menos eficiente: " << ms1 << std::endl;

	//Tempo de exibição da janela
	SDL_Delay(5000);
	
	//Destruindo Janela
	SDL_DestroyWindow(window);

	//Fechando SDL
	SDL_Quit();

	return 0;
}
