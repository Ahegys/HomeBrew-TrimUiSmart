#pragma once

# include <iostream>

class CheckArguments {
  private:
	char **commands;
  public:
	CheckArguments(char **commands);
	~CheckArguments();
};
