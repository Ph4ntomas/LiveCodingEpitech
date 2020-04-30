#include <sstream>
#include <iomanip>

#include "./Array.hpp"

namespace JSON {
    Array::Array(): AValue(Type::Array), _container() {}
    Array::Array(Array const &oth): AValue(Type::Array), _container(oth._container) {}

    IValue &Array::getValue(size_t const idx) {
        return *(_container.at(idx));
    }

    Array &Array::setValue(size_t const idx, IValue const &val) {
        _container[idx] = val.clone();
        return *this;
    }

    IValue &Array::operator[](size_t const key) {
        return *(_container.at(key));
    }

    std::shared_ptr<IValue> Array::clone() const {
        return std::make_shared<Array>(*this);
    }

    Array &Array::appendValue(IValue const &val) {
        _container.insert(_container.begin(), val.clone());
        return *this;
    }
    Array &Array::prependValue(IValue const &val) {
        _container.insert(_container.end(), val.clone());
        return *this;
    }

    std::string Array::toString(unsigned nest, char nchar, unsigned nrep) const {
        std::stringstream sstream;
        std::string nesting = std::string(nest * nrep, nchar);
        std::string subnesting = std::string((nest + 1) * nrep, nchar);
        bool first = false;

        sstream << "[";

        for (auto const &value : _container) {
            if (first)
                sstream << ",";

            first = true;
            sstream << std::endl;

            sstream << subnesting
                    << value->toString(nest + 1, nchar, nrep);
        }

        if (first)
            sstream << std::endl << nesting;

        sstream << "]";

        return sstream.str();
    }
}
