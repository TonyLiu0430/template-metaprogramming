#include <utility>
#include <iostream>
using namespace std;

template <typename T, size_t N>
struct string_wrapper {
	constexpr string_wrapper(const T(&str)[N]) {
		std::copy(str, str + N, value);
	}
	char value[N]{};
};

template<string_wrapper>
struct Type {};

template<>
struct Type<"int"> {
	using type = int;
};

template<>
struct Type<"string"> {
	using type = std::string;
};

template<string_wrapper type_str>
using Type_t = typename Type<type_str>::type;

int main() {
	Type_t<"string"> s = "Hello";
	Type_t<"int"> a = 5;
	cout << s << endl << a;
}
