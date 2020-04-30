#include "./IValue.hpp"

namespace JSON {
    std::ostream & operator<<(std::ostream &lhs, IValue const &rhs) {
        return lhs << rhs.toString();
    }
}
