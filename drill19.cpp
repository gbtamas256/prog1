#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
    S(T vv = 0) : val{vv} { }

    S& operator=(const T&);

    T& get();
    //void set(T new_t) { val = new_t; }
    const T& get() const;

private:
    T val;
};

template<typename T>
T& S<T>::get() {
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s) {
    val = s;
    return *this;
}

template<typename T>
void read_val(T& v) {
	std::cin >> v;
}

int main() {
	S<int> i {1};
	S<char> c {'a'};
	S<double> d {1.5};
	S<std::string> s {"egy"};
	S<std::vector<int>> vi {std::vector<int>{1, 2, 3}};
	
	std::cout << "int: " << i.get()
	<< "\nchar: " << c.get()
	<< "\ndouble: " << d.get()
	<< "\nstring: " << s.get();
	std::cout << "\nvector: ";
   	for (auto& a : vi.get()) {
   		std::cout << a << ' ';
   	}
   	std::cout << std::endl;
	
	std::cout << "int in: ";
	int ii;
	read_val(ii);
	S<int> i2 {ii};
	std::cout << "char in: ";
	char cc;
	read_val(cc);
	S<char> c2 {cc};
	std::cout << "double in: ";
	double dd;
	read_val(dd);
	S<double> d2 {dd};
	std::cout << "string in: ";
	std::string ss;
	read_val(ss);
	S<std::string> s2 {ss};
}





















