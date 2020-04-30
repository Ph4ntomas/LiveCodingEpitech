#include "./Bool.hpp"

#include <sstream>

namespace JSON {
    Bool::Bool(bool b): AValue(Type::Boolean), _val(b) {}

    Bool &Bool::operator=(bool b) {
        _val = b;
        return *this;
    }

    bool Bool::getBool() const {
        return _val;
    }
    Bool &Bool::setBool(bool b) {
        _val = b;
        return *this;
    }

    std::shared_ptr<IValue> Bool::clone() const {
        return std::make_shared<Bool>(_val);
    }

    std::string Bool::toString(unsigned n, char nchar, unsigned nrep) const {
        std::stringstream sstr;

        sstr << std::boolalpha << _val;

        return sstr.str();
    }
}
