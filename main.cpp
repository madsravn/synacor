#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>
#include "memory.h"
#include "VM.h"


auto main() -> int {
    VM vm("challenge.bin");
    vm.run();

    return 0;
}
