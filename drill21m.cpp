#include <string>
#include <iostream>
#include <map>
#include <stdexcept>
#include <numeric>

template<typename K, typename V>
void print(const std::map<K, V>& m) {
	//for(auto& i : m) {
	for(std::pair<K,V> i : m) {
		std::cout << i.first << '\t' << i.second << std::endl;
	}
}

void read_map(std::map<std::string, int>& m) {
	std::string s;
	int i = 0;
	while (m.size()<10) {
		std::cin >> s >> i;
		m[s] = i;
		//m.insert(std::make_pair(s, i));
	}
}

int main() {
try {
	std::map<std::string, int> msi;
	msi["a"] = 1;
	msi["b"] = 3;
	msi["ab"] = 7;
	msi["efgh"] = 98;
	msi["xy"] = 76;
	msi["qw"] = 61;
	msi["efh"] = 60;
	msi["xc"] = 23;
	msi["qwertz"] = 11;
	msi["ax"] = 1;
	
	std::cout << "MSI map" << std::endl;
	print(msi);
	
	msi.erase("a");
	std::cout <<std::endl << "Egy elem törlése: " << std::endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	std::cout <<std::endl << "Teljes törlés: " << std::endl;
	print(msi);
	
	std::cout <<std::endl << "Adj meg 10 kulcs-érték párt: " << std::endl;
	read_map(msi);
	std::cout <<std::endl << "msi beolvasás után: " << std::endl;
	print(msi);
	
	int sum = 0;
	for(std::pair<std::string, int> i : msi) {
		sum += i.second;
	}
	std::cout << std::endl << "A számok összege: " << sum << std::endl;
	
	std::map<int, std::string> mis;
	for(std::pair<std::string, int> i : msi) {
		mis[i.second] = i.first;
	}
	std::cout << std::endl << "MIS map" << std::endl;
	print(mis);

} catch (std::exception& e ) {
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "Unknown exception " << '\n';
	return 2;
}
}
