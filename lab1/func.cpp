#include <iostream>
int f(void) {
	int var1 = 1;
	int var2 {3};
	int var3 = 7;
	std::cout << var1 - var2 - var3 << std::endl;
	return 0;
}