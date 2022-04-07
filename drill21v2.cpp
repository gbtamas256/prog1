#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>

template<typename C>
void print(const C& c, char sep = '\n'){
	std::cout << "Container elements:\n";
	for(const auto elem : c){
		std::cout << elem << sep;
	}
	
	std::cout << std::endl;
}

/*template<typename T>
T sum(std::vector<T> vec) {
	T osszeg = 0;
	for(auto& i : vec) {
		osszeg += i;
	}
	
	return osszeg;
}*/

int main()
try {
	const std::string iname {"input_floats.txt"};
	std::ifstream ifs {iname};
	if (!ifs) throw std::runtime_error("Could not read filr: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	
	//print(vd);
	
	std::vector<int> vi(vd.size());
	/*for(auto& d : vd) {
		vi.push_back(d);
	}*/
	std::copy(vd.begin(), vd.end(), vi.begin());
	//print(vi);
	
	for(int i = 0; i < vd.size(); i++) {
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}
	
	/*std::cout << "\nSum of vd:\n" << sum(vd) << "\t(" << sum(vi) << ')' << std::endl;
	
	std::cout << "\nvd-vi difference:\n" << sum(vd) - sum(vi) << std::endl;*/
	
	double d_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
	
	double i_sum = std::accumulate(vi.begin(), vi.end(), 0.0);
	
	//double diff_sum = std::inner_product(vd.begin(), vd.end(), vi.begin()); valami nem jó...
	
	std::reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean = d_sum / vd.size();
	std::cout << "Mean value of vd: " << vd_mean << std::endl;
	
	std::vector<double> vd2;
	for(auto& d : vd) {
		if(d < vd_mean){
			vd2.push_back(d);
		}
	}
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);
	
}
catch (std::exception& e ) {
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "Unknown exception " << '\n';
	return 2;
}
