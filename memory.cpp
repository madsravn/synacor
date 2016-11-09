#include "memory.h"

Memory::Memory() {
    pc = 0;
}

Memory& Memory::operator>>(numtype& x) {
    x = ops.at(pc);
    ++pc;
    return (*this);
}

void
Memory::load(std::string file) {
    std::ifstream read(file, std::ios::binary);
    std::istreambuf_iterator<char> i(read), e;
    std::vector<unsigned char> inf (i,e);

    for(auto i = 0; i < inf.size(); i += 2) {
        ops.push_back(inf.at(i) + (inf.at(i +1) << 8));
    }
}

Memory::Memory(std::string file) {
    load(file);
    pc = 0;
}

void
Memory::setPC(int x) {
    pc = x;
}

int
Memory::getPC() {
    return pc;
}

int
Memory::getMem(int pos) {
    return ops.at(pos);
}

void
Memory::setMem(int pos, int value) {
    ops.at(pos) = value;
}
