#ifndef JSONString_hpp__
#define JSONString_hpp__

#include "./AValue.hpp"

namespace JSON {
    class String: public AValue {
        public:
            String(std::string b);
            virtual ~String() {}

            String &operator=(std::string b);

            std::string getString() const;
            String &setString(std::string b);

            std::shared_ptr<IValue> clone() const override;

            std::string toString(unsigned n = 0, char nchar = ' ', unsigned nchar_rep = 4) const final;
        private:
            std::string _val;
    };
}

#endif
