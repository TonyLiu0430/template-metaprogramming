#include <iostream>
using namespace std;

struct Transportation {
    void run() {};
};

struct Car : Transportation {
    void run() {
        cout << "car running" << endl;
    };
};

struct Train : Transportation {
    void run() {
        cout << "train running" << endl;
    };
};

struct Animal {};

struct Dog : Animal {
    void run() {
        cout << "Dog Dog Dog" << endl;
    }
};

template<class T, enable_if_t<is_base_of<Transportation, T>::value>* = nullptr>
void run(T t) {
    cout << "Transportation  " << endl;
    t.run();
}

template<class T, enable_if_t<is_base_of<Animal, T>::value>* = nullptr>
void run(T t) {
    cout << "Animal " << endl;
    t.run();
}

int main() {
    Train train;
    run(train);

    Dog dog;
    run(dog);
}
