#include <string>
#include <unordered_map>
#include "sprite.hpp"

using EntityID = int64_t;

template <typename Type>
using ComponentMap = std::unordered_map<EntityID, Type>;

using Sprites = ComponentMap<Sprite>;
