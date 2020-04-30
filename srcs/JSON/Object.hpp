#ifndef JSONObject_hpp_
#define JSONObject_hpp_

#include <unordered_map>
#include <memory>

#include "./AValue.hpp"

namespace JSON {
    class Object: public AValue {
        public:
            Object();
            Object(Object const &oth);
            virtual ~Object() {}

            IValue &getValue(std::string const &name);
            Object &setValue(std::string const &name, IValue const &val);

            IValue &operator[](std::string const &key);

            std::shared_ptr<IValue> clone() const;

            std::string toString(unsigned nest = 0, char nchar = ' ', unsigned nrep = 4) const final;

        private:
            std::unordered_map<std::string, std::shared_ptr<IValue>> _container;
    };
}

#endif
