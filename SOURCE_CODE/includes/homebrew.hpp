#pragma once

# include <iostream>
# include <SDL2/SDL.h>

class CheckArguments {
  private:
	char **commands;
  public:
	CheckArguments(char **commands);
	~CheckArguments();
};
