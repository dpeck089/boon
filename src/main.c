#include <stdbool.h>
#include <SDL.h>
#include "game.h"


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
SDL_Event events;

bool init(const char*, int, int, int, int, int);
void pollEvents(GameState*);
void render();

int main(int argc, char* args[]) {
  GameState gameState;
  if(init("Chapter 1: Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)) {
    gameState.running = true;
  } else {
    return 1;
  }

  while(gameState.running) {
    pollEvents(&gameState);
    render();
  }

  SDL_Quit();

  return 0;
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags) {
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if(g_pWindow != 0) {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    } else {
      return false;
    }
  } else {
    return false;
  }

  /* this is required to get the title bar */
  for(int i = 0; i < 1000; i++) {
    SDL_PumpEvents();
    SDL_Delay(1);
  }
  return true;
}

void pollEvents(GameState* gameState) {
  while(SDL_PollEvent(&events)) {
    if(events.type == SDL_QUIT) {
      gameState->running = false;
    }
  }
}

void render() {
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}
