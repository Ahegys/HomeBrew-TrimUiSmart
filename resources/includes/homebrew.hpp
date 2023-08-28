#pragma once

# include <iostream>
# include <cstring>
# define ERROR_COMMAND 3
# define INSTALL_COMMAND 1
# define REMOVE_COMMAND 2
# define SEARCH_COMMAND 4
# define HELP_COMMAND 5

class CheckArguments {
private:
	char **commands;
        std::string ErrorLog;
public:
	              	CheckArguments(char **commands);
	              	~CheckArguments();
	int          	CheckCommandSent();
	void          	PrintHelp();
	void			CheckRepos(char **, int);
	std::string   	MessageLog();
};
