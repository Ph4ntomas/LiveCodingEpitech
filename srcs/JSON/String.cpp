#include "./String.hpp"

#include <iomanip>
#include <sstream>

namespace JSON {
    String::String(std::string b): AValue(Type::String), _val(b) {}

    String &String::operator=(std::string b) {
        _val = b;
        return *this;
    }

    std::string String::getString() const {
        return _val;
    }
    String &String::setString(std::string b) {
        _val = b;
        return *this;
    }

    std::shared_ptr<IValue> String::clone() const {
        return std::make_shared<String>(_val);
    }

    std::string String::toString(unsigned n, char nchar, unsigned nrep) const {
        std::stringstream sstr;

        sstr << std::quoted(_val);

        return sstr.str();
    }
}
