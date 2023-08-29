# include "../includes/Download.hpp"
# include "../includes/homebrew.hpp"
# include "../includes/Socket.hpp"

using namespace std;

TrimInstaller::TrimInstaller() {
    sck::ConcreteSocketCreation socketObj(120, 200, 300, 400, 0);
    struct sockaddr_in address = socketObj.getAddress();
}

TrimInstaller::~TrimInstaller() {}

void TrimInstaller::DownloadResources() {

}
