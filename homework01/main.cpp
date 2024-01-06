#include <iostream>
#include "version.h"

int main() {
    std::cout << "Build '" << version() << "'" << std::endl;
    std::cout << "Hello, World!" << std::endl;
}
