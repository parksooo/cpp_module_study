#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Error: invalid number of argumnets" << std::endl;
        return 1;
    }
    try {
        PmergeMe p(argc, argv);
        p.sort();
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}