#include "../includes/homebrew.hpp"
#include <SDL2/SDL_video.h>

using namespace std;

CheckArguments
::CheckArguments(char** commands) {
  this->commands = commands;
}

CheckArguments
::~CheckArguments() {
  cout << "Cleaning Objs" << endl;
}

int
main(int ac, char **av) {
  (void)av;
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }
  SDL_Window *window = SDL_CreateWindow("SDK Example", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 320, 240, 0);
  if (!window){
    SDL_Log("Unable to create SDL: %s", SDL_GetError());
    return -1;
  }

  SDL_Delay(3000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  if (ac < 2) {
  	cout << "No input sent, Check docs -h or --help" << endl;
  	return -1;
  }
  cout << "Hello, World!" << endl;
  return 0;
}
/*
#include <SDL2/SDL.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}*/
