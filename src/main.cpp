#include "../include/studio.h"

using namespace std;

Studio *backup = nullptr;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: studio <config_path>" << std::endl;
        return -1;
    }
    string configurationFile = argv[1];
    Studio studio(configurationFile);
    studio.start();
    if (backup != nullptr) {
        delete backup;
        backup = nullptr;
    }
    return -1;
}