#include <bits/stdc++.h>
using namespace std;

template<int N>
struct Fib {
	static constexpr int value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<>
struct Fib<0> {
	static constexpr int value = 0;
};

template<>
struct Fib<1> {
	static constexpr int value = 1;
};

template<int N, size_t ...Nums>
constexpr array<int, N> getFibSequence_impl(index_sequence<Nums...>) {
    return {{Fib<Nums>::value...}};
}


template<int N>
constexpr auto getFibSequence() {
	return getFibSequence_impl<N>(make_index_sequence<N>{} );
}

int main() {
	auto res = getFibSequence<4>();
	for (auto&& x : res) {
		cout << x << " ";
	}
}
