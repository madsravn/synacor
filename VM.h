#ifndef VM_H_
#define VM_H_
#include "memory.h"
#include <functional>

class VM {

    public: 
        void run();
        VM(std::string file);

    private:
        std::vector<std::function<void(void)>> prepareInstructions();
        std::vector<char> input;
        // 0 halt
        void halt();
        // 1 set
        void set();
        // 2 push
        void push();
        // 3 pop
        void pop();
        // 4 eq
        void eq();
        // 5 gt
        void gt();
        // 6 jmp
        void jmp();
        // 7 jt
        void jt();
        // 8 jf
        void jf();
        // 9 add
        void add();
        // 10 mult
        void mult();
        // 11 mod
        void mod();
        // 12 and
        void tand();
        // 13 or
        void tor();
        // 14 not
        void tnot();
        // 15 rmem
        void rmem();
        // 16 wmem
        void wmem();
        // 17 call
        void call();
        // 18 ret
        void ret();
        // 19 out
        void out();
        // 20 in
        void in();
        // 21 noop
        void noop();
        std::vector<numtype> stack;
        std::vector<numtype> reg;
        Memory mem;
        numtype read_value(numtype val);
        void write_value(int pos, numtype val);
        
};


#endif
