 
#include <string>
#include "component.hpp"
 
class NPC : public Component {
public:
    NPC() {};
 
    void setPhrase(const std::string& phrase) {
        this->phrase = phrase;
    }
 
    std::string getPhrase() const {
        return phrase;
    }
private:
    std::string phrase;
};