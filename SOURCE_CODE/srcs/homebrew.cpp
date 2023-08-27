#include "../includes/homebrew.hpp"

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
  if (ac < 2) {
  	cout << "No input sent, Check docs -h or --help" << endl;
  	return -1;
  }
  cout << "Hello, World!" << endl;
  return 0;
}
