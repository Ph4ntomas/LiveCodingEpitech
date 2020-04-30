#include <sstream>
#include <iomanip>

#include "./Object.hpp"

namespace JSON {
    Object::Object(): AValue(Type::Object), _container() {}
    Object::Object(Object const &oth): AValue(Type::Object), _container(oth._container) {}

    IValue &Object::getValue(std::string const &name) {
        return *(_container.at(name));
    }

    Object &Object::setValue(std::string const &name, IValue const &val) {
        _container[name] = val.clone();
        return *this;
    }

    IValue &Object::operator[](std::string const &key) {
        return *(_container.at(key));
    }

    std::shared_ptr<IValue> Object::clone() const {
        return std::make_shared<Object>(*this);
    }

    std::string Object::toString(unsigned nest, char nchar, unsigned nrep) const {
        std::stringstream sstream;
        std::string nesting = std::string(nest * nrep, nchar);
        std::string subnesting = std::string((nest + 1) * nrep, nchar);
        bool first = false;

        sstream << "{";

        for (auto const &[key, value] : _container) {
            if (first)
                sstream << ",";

            first = true;
            sstream << std::endl;

            sstream << subnesting << std::quoted(key)
                    << " : " << value->toString(nest + 1, nchar, nrep);
        }

        if (first)
            sstream << std::endl << nesting;

        sstream << "}";

        return sstream.str();
    }
}
