#include "script.hpp"

Script::Script(){
    //chai.add(&chai.eval_file,"Eval");
};

int Script::Eval(string filename){
    try{
        chai.eval_file(filename);
    } catch(chaiscript::exception::file_not_found_error er){
        cout<<"File Not Found!"<<endl;
    }
    return 0;
}