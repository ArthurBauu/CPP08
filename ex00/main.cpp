#include "easyfind.hpp"

int main() {

	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * 10);
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 55);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}

	// const std::vector<int> constVec = vec;
	// try {
	// 	std::vector<int>::const_iterator it = easyfind(const_cast<std::vector<int>&>(constVec), 30);
	// 	std::cout << "Found value in const container: " << *it << std::endl;
	// } catch (const std::runtime_error &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	std::vector<int>::const_iterator it = easyfind(const_cast<std::vector<int>&>(constVec), 35);
	// 	std::cout << "Found value in const container: " << *it << std::endl;
	// } catch (const std::runtime_error &e) {
	// 	std::cerr << e.what() << std::endl;
	// }



	return 0;
}