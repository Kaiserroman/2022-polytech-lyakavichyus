#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

struct BasicToken {
    std::string value;
};

struct StringToken : public BasicToken {
    StringToken(std::string s) { value = '"' + s + '"'; }
};
struct NumToken : BasicToken {
    template <typename T> NumToken(T i) { value = std::to_string(i); }
};
struct BoolToken : BasicToken {
    BoolToken(bool b) { value = b ? "true" : "false"; }
};
struct ArrayToken : BasicToken {
    ArrayToken(std::initializer_list<BasicToken> v) {
        value = "[";
        for (std::size_t i = 1; auto s : v) {
            value.append(s.value);
            if (i != v.size()) {
                value.append(",");
                i++;
            }
        }
        value.append("]");
    }
};

struct Json {
    std::unordered_map<std::string, BasicToken> tokens;

    Json(std::unordered_map<std::string, BasicToken> j) { tokens = j; }
    std::string serialize() {
        std::string out = "{";
        for (std::size_t i = 1; const auto & elem : tokens) {
            out.append("\"" + elem.first + "\":" + elem.second.value);
            if (i != tokens.size()) {
                out.append(",");
                i++;
            }
        }
        out.append("}");
        return out;
    }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <unordered_map>

TEST_CASE("Generic tests") {
    CHECK_EQ(Json{ std::unordered_map<std::string, BasicToken>
        {} }.serialize(),
        "{}");

    CHECK_EQ(Json{ std::unordered_map<std::string, BasicToken>{
        {"str_token", StringToken("val")} } }.serialize(),
            "{\"str_token\":\"val\"}");

    CHECK_EQ(Json{ std::unordered_map<std::string, BasicToken>{
        {"int_token", NumToken(999999)}} }.serialize(),
            "{\"int_token\":999999}");

    CHECK_EQ(Json{ std::unordered_map<std::string, BasicToken> {
        {"bool_token", BoolToken(true)}} }.serialize(),
            "{\"bool_token\":true}");

    CHECK_EQ(Json{ std::unordered_map<std::string, BasicToken>{
        {"array_token", ArrayToken({NumToken(1), StringToken("ok")})}} }.serialize(),
            "{\"array_token\":[1,\"ok\"]}");
}