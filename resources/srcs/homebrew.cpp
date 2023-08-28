#include "../includes/homebrew.hpp"

using namespace std;

CheckArguments::CheckArguments(char **commands) : commands(commands) {
  this->ErrorLog = "No input sent, Check docs -h or --help";
}

CheckArguments::~CheckArguments() {}

void  CheckArguments::CheckRepos(char **commands, int command) {
  if (command == INSTALL_COMMAND) {
      cout << "Installing " << commands << "..." << endl;
      return ;
  }
  else if (command == REMOVE_COMMAND) {
      cout << "Removing " << commands << "..." << endl;
      return ;
  }
  else if (command == SEARCH_COMMAND) {
      cout << "Searching " << commands << "..." << endl;
      return ;
  }

}

int CheckArguments::CheckCommandSent() {
   if (commands && commands[1] && std::strcmp(commands[1], "install") == 0){
     CheckRepos(commands, INSTALL_COMMAND);
     return INSTALL_COMMAND;
   }
   else if (commands && commands[1] && std::strcmp(commands[1], "remove") == 0){
     CheckRepos(commands, REMOVE_COMMAND);
     return REMOVE_COMMAND;
   }
   else if (commands && commands[1] && std::strcmp(commands[1], "search") == 0){
     CheckRepos(commands, SEARCH_COMMAND);
     return SEARCH_COMMAND;
   }
   else if (commands && commands[1] && std::strcmp(commands[1], "--help") == 0){
     PrintHelp();
     return HELP_COMMAND;
   }
   else if (commands && commands[1] && std::strcmp(commands[1], "-h") == 0){
     PrintHelp();
     return HELP_COMMAND;
   }
  return ERROR_COMMAND;
}

void  CheckArguments
::PrintHelp() {
  cout << "use  trim [OPTIONS] <packages> " << endl;
  cout << "OPTIONS: " << endl;
  cout << "       install       -- install packages from repo" << endl;
  cout << "       remove        -- remove packages in local" << endl;
  cout << "       search        -- search in database repo applications" << endl;
}

std::string  CheckArguments
::MessageLog() {
  return this->ErrorLog;
}

int
main(int ac, char **av) {
  CheckArguments Checker(av);
  if (ac < 2) {
  	cout << Checker.MessageLog() << endl;
  	return 1;
  }
  if (Checker.CheckCommandSent() == ERROR_COMMAND) {
    cout << "Command not found! please check docs: -h or --help" << endl;
    return 1;
  }
  return 0;
}
