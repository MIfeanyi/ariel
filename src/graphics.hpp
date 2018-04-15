#include <string>
#include "component.hpp"

class Graphics: public Component {
    public:
        Graphics(){};
        void SetFilename(const std::string& src){
            this->src = src;
        }
        std::string getFilename(){
            return src;
        }
    private:
        std::string src;
};