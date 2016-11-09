#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>
#include "memory.h"
#include "VM.h"


/* Suggestion: 
 *
 *  19:30 < Eelis> { ifstream f(__FILE__, ios::binary); istreambuf_iterator<char> i(f), e; cout << escape(string(i, e)); } // mads-
 *  19:30 < geordi> "#if !defined(GEORDI_PRELUDE) && !defined(__clang__)\n#define GEORDI_PRELUDE\n#include \"prelude-1z.hpp\"\n#endif\nusing namespace std;\n // mads-\n\nint main(int argc, char * 
 *              argv[]){ ifstream f(__FILE__, ios::binary); istreambuf_iterator<char> i(f), e; cout << escape(string(i, e)); }\n"
 *  19:30 < Eelis> for a vector<unsigned char>, say vector<unsigned char>(i, e)
 * 
 *  19:31 < w3z> {ifstream F("challenge.bin",ios::binary|ios::in); vector<char> V{istreambuf_iterator<char>{F},istreambuf_iterator<char>{}};}
 *  19:31 < geordi> <no output>
 *  19:31 < Eelis> ifstream always does in, no need for ios::in
*/

using uchar = unsigned char;
       


auto main() -> int {
    std::vector<int> registers(8,0);
    unsigned int address = 0;
    std::vector<int> stack;

    std::ifstream read ("challenge.bin", std::ios::binary);
    std::istreambuf_iterator<char> i(read), e;
    std::vector<unsigned char> inf(i,e);

    std::vector<unsigned int> ops;
    for(auto i = 0; i < inf.size(); i += 2) {
        ops.push_back(inf.at(i) + (inf.at(i+1) << 8));
    }

    VM vm("challenge.bin");
    vm.run();
    


    int op;
    /*while(infile >> op) {
        std::cout << "OP: " << op << std::endl;
        switch(op) {
            case 0:
                return 0;
                break;
            case 1:
                {
                    int a,b;
                    infile >> a >> b;
                    int value = read_value(b, registers);
                    write_value(a, value, registers);
                }
                break;
            case 2:
                {
                    int a;
                    infile >> a;
                    int value = read_value(a, registers);
                    stack.push_back(value);
                }
                break;
            case 3:
                {
                    int a;
                    infile >> a;
                    int value = stack.back();
                    stack.pop_back();
                    write_value(a, value, registers);
                }
                break;
            case 4:
                {
                    int a,b,c;
                    infile >> a >> b >> c;
                }



            case 9:
                { 
                    int a,b,c;
                    infile >> a >> b >> c;
                    int value = read_value(b, registers) + read_value(c, registers);
                    write_value(a, value, registers);
                }
                break;
            case 19:
                {
                    int a;
                    infile >> a;
                    char value = read_value(a, registers);
                    std::cout << value << std::endl;
                }
                break;

        }
        ++address;
    }*/




    return 0;
}
