#include <vector>
#include <string>
#include "sprite.hpp"
/* Track (Holds all tracks)
* Keyframe(TYPE,float time)
*/

class KeyFrame {
        int Type; float Time;
        bool Loop;
    public:
        void add();
        KeyFrame();
};

class AnimationTrack {
        std::vector<KeyFrame> Keys;
        float length;
    public:
        void Add(KeyFrame k);
};

class AnimatedSprite: public Sprite {
    //TODO: animation time
        int Hframe, WFrame;
        std::vector<AnimationTrack> Tracks;
    public:
        AnimatedSprite();
        void AddKey(int type, float time, std::string track);
        void AddTrack(std::string track);
        void Update(float t);
        ~AnimatedSprite();
};