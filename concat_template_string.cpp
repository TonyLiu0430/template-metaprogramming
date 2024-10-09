#include <utility>
#include <iostream>
using namespace std;

template <typename T, size_t N>
struct string_wrapper {
	constexpr string_wrapper() {}
	constexpr string_wrapper(const T(&str)[N]) {
		std::copy(str, str + N, value);
	}
	char value[N]{};
};

template<typename T, size_t N1, size_t N2>
consteval auto concat(string_wrapper<T, N1> s1, string_wrapper<T, N2> s2) {
	string_wrapper<T, N1 + N2 - 1> result;
	std::copy(s1.value, s1.value + N1 - 1, result.value);
	std::copy(s2.value, s2.value + N2, result.value + N1 - 1);
	return result;
}


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
	Type_t<concat(string_wrapper("st"), string_wrapper("ring"))> s2 = "World";
	cout << s2;
}
