#include "JSON/JSON.hpp"
#include <iostream>

int main(void)
{
    using namespace std::literals;

    JSON::Object json;
    JSON::Array jarr;

    jarr
        .appendValue(JSON::String("Value1"s))
        .appendValue(JSON::String("Value2"s))
        .appendValue(JSON::String("Value3"s))
        .appendValue(JSON::String("Value4"s));

    json
        .setValue("array"s, jarr)
        .setValue("bool_true"s, JSON::Bool(true))
        .setValue("bool_false"s, JSON::Bool(false))
        .setValue("Number_1"s, JSON::Number(1))
        .setValue("Number_2"s, JSON::Number(1.4))
        .setValue("Number_3"s, JSON::Number(0.0002))
        .setValue("Number_4"s, JSON::Number(125.2002))
        ;


    std::cout << json << std::endl;
    return 0;
}
