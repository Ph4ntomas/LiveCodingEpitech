#ifndef IValue_hpp_
#define IValue_hpp_

#include <ostream>
#include <string>

#include <memory>

namespace JSON {
    enum struct Type {
        Object,
        Array,
        String,
        Boolean,
        Number
    };

    class IValue {
        public:
            virtual ~IValue() {}

            virtual bool hasType(Type type) const = 0;
            virtual Type getType() const = 0;

            virtual std::shared_ptr<IValue> clone() const = 0;

            virtual std::string toString(unsigned nest = 0, char ncar = ' ', unsigned nchar = 4) const = 0;
    };

    std::ostream & operator<<(std::ostream &os, IValue const &);
}

#endif
