#include "PmergeMe.hpp"

bool  checkOverFlow(long long ll){
	int a = ll;
	
	if (static_cast<long long> (a) != ll)
		return(true);
	return (false);
}

bool isNum(const char *arr){
	long long n = 0;
	if (!arr)
		return (0);
	int i = 0;
	
	if (arr[0] == '+')
		i++;
	for (; arr[i]!= '\0' ; i++) {
		if (!std::isdigit(arr[i]))
			return (0);
		n *= 10;
		n += arr[i] - '0';
	}
	
	if ((i == 1 && arr[0] == '+')|| i > 11 || checkOverFlow(n))
		return (0);
	
	return (1);
}

int main(int argc, char **argv) {
    std::vector<int> inputToVector;
	std::list<int> inputToList;

    if (argc == 1) {
    	std::cout << "Error" << std::endl;
        return 1;
	} else {
    	for (int i = 0; i + 1 < argc; i++) {
      		if (!isNum(argv[i + 1])) {
        		std::cout << "Error" << std::endl;
                return 1;
			} else {
        		inputToVector.push_back(atoi(argv[i + 1]));
				// inputToList.push_back(atoi(argv[i + 1]));
			}
		}
	}

	// for (int i = 0; i < inputToVector.size(); i++) {
	// 	std::cout << inputToVector[i] << " ";
	// }

    PmergeMe p(inputToVector, inputToList);    

	p.startSort();
}