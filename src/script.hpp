#include "chaiscript/chaiscript.hpp"
#include <string>
#include <iostream>

using namespace std;

class Script{
    chaiscript::ChaiScript chai;
    public:
        int Eval(string filename);  
        Script(); 
    
};