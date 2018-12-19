#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "define.h"

struct game{
  int moves;
  player grid[3][3];
  player currentPlayer;
  state currentState;
};
typedef struct game Game;

void newGame(Game *g) {
  for (int i = 0; i < 3; i++){
    for ( int j = 0; j<3; j++){
      g -> grid[i][j] = N;
    }
  }
  g -> currentPlayer = X;
  g -> moves = 0;
  g -> currentState = RUNNING;
}

int main(int n, char *args[n]){
  I(SDL_Init(SDL_INIT_VIDEO));
  SDL_Window *window = P(SDL_CreateWindow("oxo", 100, 100, width, height, SDL_WINDOW_SHOWN));
  SDL_Renderer *renderer = P(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC));

  Game *game = malloc(sizeof(Game));
  newGame(game);

  SDL_Event event;
  while (game->currentState != QUIT){
    while(SDL_PollEvent(&e)){
      switch(event.type){
        case SDL_QUIT:
          game->currentState = QUIT;
          break;
        case SDL_MOUSEBUTTONDOWN:
          click_on_cell(&game,event.button.y/cellheight, event.button.x/cellwidth);
          break;
      }
    }
    I(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255));
    I(SDL_RenderClear(renderer));
    I(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255));
  }

  SDL_DestrowWindow(window);
  SDL_Quit();

  return 0;
}
