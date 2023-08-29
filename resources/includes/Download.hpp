# pragma once
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <sys/socket.h>
# include <stdio.h>
# include <netinet/in.h>


  class TrimInstaller {

   public:
     const char ** DownloadList;
        TrimInstaller();
        ~TrimInstaller();
        void    DownloadResources();
};