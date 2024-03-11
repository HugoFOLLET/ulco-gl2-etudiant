#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
	return n+3;
}

int mul2(int n) {
	return n*2;
}

int mycompute(logFunc_t out, int v0){
	out("add3 " + std::to_string(v0) + "\n");
	const int v1 = add3(v0);
	out("mul2 " + std::to_string(v1) + "\n");
	const int v2 = add3(v1);
	return v2;
}

int main() {
	std::cout << "this is log-cpp" << std::endl;

	logFunc_t f1 = [](const std::string &str){
		std::cout << str;
	};

	std::ofstream file;
	file.open("log2.txt");
	logFunc_t f2 = [&file](const std::string &str){
		file << str;
	};

	const int res = mycompute(f1, 12);
	const int res2 = mycompute(f2, 15);
	std::cout << res << std::endl << res2 << std::endl;
	return 0;
}

