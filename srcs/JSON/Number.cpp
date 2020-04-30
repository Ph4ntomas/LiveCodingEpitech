#include "./Number.hpp"

#include <sstream>

namespace JSON {
    Number::Number(double d): AValue(Type::Number), _val(d) {}

    Number &Number::operator=(double d) {
        _val = d;
        return *this;
    }

    double Number::getNumber() const {
        return _val;
    }
    Number &Number::setNumber(double b) {
        _val = b;
        return *this;
    }

    std::shared_ptr<IValue> Number::clone() const {
        return std::make_shared<Number>(_val);
    }

    std::string Number::toString(unsigned n, char nchar, unsigned nrep) const {
        std::stringstream sstr;

        sstr << _val;

        return sstr.str();
    }
}
