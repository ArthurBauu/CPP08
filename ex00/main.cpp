#include "easyfind.hpp"

int main() {

	// Test avec un conteneur modifiable
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * 10);
	}

	// Test avec une valeur présente
	try {
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
	// Test avec une valeur absente
	try {
		std::vector<int>::iterator it = easyfind(vec, 55);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
	// Modification du conteneur via l'itérateur retourné
	try {
        std::vector<int>::iterator it = easyfind(vec, 50);
        std::cout << "Found value: " << *it << std::endl;
        *it = 999;  // Possible car iterator non-const
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }


	
	// Test avec un conteneur constant
	const std::vector<int> constVec = vec;
    try {
        std::vector<int>::const_iterator it = easyfind(constVec, 30);
        std::cout << "Found value in const container: " << *it << std::endl;
        // *it = 999;  // Erreur de compilation : const_iterator ne permet pas la modification
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }



	return 0;
}