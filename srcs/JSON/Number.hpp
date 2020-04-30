#ifndef JSONNumber_hpp__
#define JSONNumber_hpp__

#include "./AValue.hpp"

namespace JSON {
    class Number: public AValue {
        public:
            Number(double d);
            virtual ~Number() {}

            Number &operator=(double d);

            double getNumber() const;
            Number &setNumber(double d);

            std::shared_ptr<IValue> clone() const override;

            std::string toString(unsigned n = 0, char nchar = ' ', unsigned nchar_rep = 4) const final;
        private:
            double _val;
    };
}

#endif
