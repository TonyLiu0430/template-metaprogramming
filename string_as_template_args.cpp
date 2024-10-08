//cpp17
#include<bits/stdc++.h>
using namespace std;

#define S(str) decltype(str##_text)

template <char... chars>
using text = std::integer_sequence<char, chars...>;

template <typename T, T... chars>
constexpr text<chars...> operator"" _text() { return { }; }

template<class T>
struct Car {
    void run() {
        cout << "normal Car running" << endl;
    }
};

template<>
struct Car<S("Hello")> {
    void run() {
        cout << "Hello" << endl;
    }
};

int main() {
    Car<S("123")> normal;
    Car<S("Hello")> hello;
    normal.run();
    hello.run();
}
