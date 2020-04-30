#ifndef JSONBool_hpp__
#define JSONBool_hpp__

#include "./AValue.hpp"

namespace JSON {
    class Bool: public AValue {
        public:
            Bool(bool b);
            virtual ~Bool() {}

            Bool &operator=(bool b);

            bool getBool() const;
            Bool &setBool(bool b);

            std::shared_ptr<IValue> clone() const override;
            std::string toString(unsigned n = 0, char nchar = ' ', unsigned nchar_rep = 0) const final;
        private:
            bool _val;
    };
}

#endif
