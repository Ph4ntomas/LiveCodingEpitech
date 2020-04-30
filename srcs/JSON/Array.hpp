#ifndef JSONArray_hpp_
#define JSONArray_hpp_

#include <vector>
#include <memory>

#include "./AValue.hpp"

namespace JSON {
    class Array: public AValue {
        public:
            Array();
            Array(Array const &oth);
            virtual ~Array() {}

            IValue &getValue(size_t const idx);
            Array &setValue(size_t const idx, IValue const &val);
            Array &appendValue(IValue const &val);
            Array &prependValue(IValue const &val);

            IValue &operator[](size_t const idx);

            std::shared_ptr<IValue> clone() const;

            std::string toString(unsigned nest = 0, char nchar = ' ', unsigned nrep = 4) const final;

        private:
            std::vector<std::shared_ptr<IValue>> _container;
    };
}

#endif
