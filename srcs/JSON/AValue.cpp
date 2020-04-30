#include "./AValue.hpp"

namespace JSON {
    AValue::AValue(Type t): _type(t) {}

    bool AValue::hasType(Type type) const {
        return type == _type;
    }

    Type AValue::getType() const {
        return _type;
    }
}
