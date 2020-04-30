#ifndef AValue_hpp_
#define AValue_hpp_

#include "./IValue.hpp"

namespace JSON {
    class AValue : public IValue {
        public:
            AValue(Type type);
            virtual ~AValue() {}

            virtual bool hasType(Type type) const;
            virtual Type getType() const;

        protected:
            Type _type;
    };
}

#endif
