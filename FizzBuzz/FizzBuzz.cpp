#include <iostream>

int main(int argc, char* argv[]) {
	for (int i=1; i<=100; i++) {
		if (!(i % 3)) 
			std::cout << "Fizz";
		if (!(i % 5))
			std::cout << "Buzz";
		else if ((i % 3) && (i % 5))
			std::cout << i;
		std::cout << std::endl;
	}

	return 0;
}
