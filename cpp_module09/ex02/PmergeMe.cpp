#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        size_t len = std::strlen(argv[i]);
    
        for (size_t j = 0; j < len; j++) {
            if (!std::isdigit(argv[i][j])) {
                throw std::runtime_error("Error: Invailded Inputs");
            }
        }
        
        long num = std::atol(argv[i]);
        if (num > INT_MAX) {
            throw std::runtime_error("Error: input value allowed Only Integer ragne");
        }
        this->_input.push_back(static_cast<int>(num));
    }
    setJacobsthalVector();
}

PmergeMe::PmergeMe(PmergeMe const &ob)
{
    *this = ob;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &ob)
{
    if (this != &ob) {
        return *this;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort()
{
    std::cout << "Before:\t";
    for (std::vector<int>::iterator it = this->_input.begin(); it != this->_input.end(); it++) {
        std::cout << *it << " ";
    }
    vectorToList();
    sortVector();

    sortList();
}

int PmergeMe::makePairVector()
{
    int _unpaired = -1;

    if (this->_input.size() % 2 == 1) {
        _unpaired = this->_input.back();
        this->_input.pop_back();
    }

    size_t j = 0;
    for (size_t i = 0; i < this->_input.size() - 1; i += 2) {
        int first = this->_input[i];
        int second = this->_input[i + 1];
        this->_pairVec.push_back(std::make_pair(first, second));
        if (first < second) {
            std::swap(this->_pairVec[j].first, this->_pairVec[j].second);
        }
        j++;
    }

    return _unpaired;
}

void PmergeMe::setChains()
{
    for (std::vector<std::pair<int, int> >::iterator it = this->_pairVec.begin(); it != this->_pairVec.end(); it++) {
        this->_mainChain.push_back(it->first);
        this->_pendingChain.push_back(it->second);
    }
}

void PmergeMe::mergePair(std::vector<std::pair<int, int> > &container, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        mergePair(container, left, mid);
        mergePair(container, mid + 1, right);
        merge(container, left, mid, right);
    }
}

void PmergeMe::merge(std::vector<std::pair<int, int> > &container, int first, int middle, int last)
{
    std::vector<std::pair<int, int> > sorted;

    int left = first;
    int right = middle + 1;

    while (left <= middle && right <= last) {
        if (container[left].first <= container[right].first) {
            sorted.push_back(container[left++]);
        } else {
            sorted.push_back(container[right++]);
        }
    }

    if (left > middle) {
        while (right <= last) {
            sorted.push_back(container[right++]);
        }
    } else {
        while (left <= middle) {
            sorted.push_back(container[left++]);
        }
    }

    for (int i = first; i <= last; i++) {
        container[i] = sorted[i - first];
    }
}

void PmergeMe::insertPendingChain(int _unpairedValues)
{
    this->_mainChain.insert(this->_mainChain.begin(), this->_pendingChain[0]);

	int count = 0;
	for (std::vector<int>::iterator it = this->_orderToInsertIndex.begin(); it != this->_orderToInsertIndex.end(); it++) {
		int num = this->_pendingChain.at(*it - 1);
		size_t end = *it + count;
		size_t pos = binaryInsert(this->_mainChain, num, 0, end);
		this->_mainChain.insert(this->_mainChain.begin() + pos, num);
		count++;
	}
    if (_unpairedValues != -1) {
        size_t pos = binaryInsert(this->_mainChain, _unpairedValues, 0, this->_mainChain.size() - 1);
        this->_mainChain.insert(this->_mainChain.begin() + pos, _unpairedValues);
    }
}

int PmergeMe::binaryInsert(std::vector<int> &mainChain, int n, int begin, int end)
{
    int mid;

	while (begin <= end) {
		mid = begin + (end - begin) / 2;

		if (n == mainChain.at(mid)) {
			return mid;
		}
		if (n > mainChain.at(mid)) {
			begin = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	if (n > mainChain.at(mid)) {
		return mid + 1;
	} else {
		return mid;
	}
}

void PmergeMe::setJacobsthalVector()
{
    int pre1 = 1;
    int pre2  = 1;
    int cur = 1;

    for (int i = 2; i <= 32; i++) {
        this->_jacobsthal.push_back(cur);
        
        cur = pre2 + 2 * pre1;
        pre1 = pre2;
        pre2 = cur;
    }
}

void PmergeMe::setOrderToInsertIndex(int n)
{
    int pre = 1;
    for (std::vector<int>::iterator it = this->_jacobsthal.begin(); it != this->_jacobsthal.end(); it++) {
        if (*it < n && n <= *(it + 1)) {
            for (int i = n; i > pre; i--) {
                this->_orderToInsertIndex.push_back(i);
            }
            return ;
        } else if (*it < n) {
            for (int i = *it; i > pre; i--) {
                this->_orderToInsertIndex.push_back(i);
            }
        }
        pre = *it;
    }
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    size_t size = this->_input.size();
    //pair 설정
    int _unpairedValues = makePairVector();
    mergePair(this->_pairVec, 0, this->_pairVec.size() - 1);
    setChains();
    // // MainChain 정렬
    setOrderToInsertIndex(this->_pendingChain.size());
    insertPendingChain(_unpairedValues);
    clock_t end = clock();
    std::cout << std::endl;

    std::cout << "After:\t";
    for (std::vector<int>::iterator it = this->_mainChain.begin(); it != this->_mainChain.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of\t" << size << " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "us\n";
}

void PmergeMe::sortList()
{   
    clock_t start = clock();
    size_t size  = this->_inputList.size();
    int _unpairedValues = makePairList();
    
    mergePairOfList(this->_pairList, 0, this->_pairList.size() - 1);
    setChainsOfList();
    insertPendingChainOfList(_unpairedValues);
    clock_t end = clock();
    // for (std::list<int>::iterator it = this->_mainChainList.begin(); it != this->_mainChainList.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    std::cout << "Time to process a range of\t" << size << " elements with std::list   : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "us\n";
}

void PmergeMe::vectorToList()
{
    for (std::vector<int>::iterator it = this->_input.begin(); it != this->_input.end(); it++) {
        this->_inputList.push_back(*it);
    }
}

int PmergeMe::makePairList()
{
    int _unpaired = -1;

    if (this->_inputList.size() % 2 == 1) {
        _unpaired = this->_inputList.back();
        this->_inputList.pop_back();
    }
    for (size_t i = 0; i < this->_inputList.size() - 1; i += 2) {
        int first = getListValue(this->_inputList, i);
        int second = getListValue(this->_inputList, i + 1);
        if (first < second) {
            this->_pairList.push_back(std::make_pair(second, first));
            continue;
        }
        this->_pairList.push_back(std::make_pair(first, second));
    }
    return _unpaired;
}

void PmergeMe::mergePairOfList(std::list<std::pair<int, int> > &container, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        mergePairOfList(container, left, mid);
        mergePairOfList(container, mid + 1, right);
        mergeOfList(container, left, mid, right);
    }
}

void PmergeMe::mergeOfList(std::list<std::pair<int, int> > &container, int first, int middle, int last)
{
    std::list<std::pair<int, int> > sorted;

    int left = first;
    int right = middle + 1;

    while (left <= middle && right <= last) {
        if (getPairInList(container, left).first <= getPairInList(container, right).first) {
            sorted.push_back(getPairInList(container, left++));
        } else {
            sorted.push_back(getPairInList(container, right++));
        }
    }

    if (left > middle) {
        while (right <= last) {
            sorted.push_back(getPairInList(container, right++));
        }
    } else {
        while (left <= middle) {
            sorted.push_back(getPairInList(container, left++));
        }
    }

    for (int i = first; i <= last; i++) {
        setPairInList(container, i, getPairInList(sorted, i - first));
    }
}

void PmergeMe::setChainsOfList()
{
    for (std::list<std::pair<int, int> >::iterator it = this->_pairList.begin(); it != this->_pairList.end(); it++) {
        this->_mainChainList.push_back(it->first);
        this->_pendingChainList.push_back(it->second);
    }
}

void PmergeMe::insertPendingChainOfList(int _unpairedValues)
{
    this->_mainChainList.insert(this->_mainChainList.begin(), getListValue(this->_pendingChainList, 0));

	int count = 0;

	for (std::vector<int>::iterator it = this->_orderToInsertIndex.begin(); it != this->_orderToInsertIndex.end(); it++) {
		int num = getListValue(this->_pendingChainList, *it - 1);
		size_t end = *it + count;
		size_t pos = binaryInsertOfList(this->_mainChainList, num, 0, end);
        std::list<int>::iterator tmp = this->_mainChainList.begin();
        std::advance(tmp, pos);
		this->_mainChainList.insert(tmp, num);
		count++;
	}
    if (_unpairedValues != -1) {
        size_t pos = binaryInsertOfList(this->_mainChainList, _unpairedValues, 0, this->_mainChainList.size() - 1);
        std::list<int>::iterator tmp = this->_mainChainList.begin();
        std::advance(tmp, pos);
        this->_mainChainList.insert(tmp, _unpairedValues);
    }
}

int PmergeMe::binaryInsertOfList(std::list<int> &mainChain, int n, int begin, int end)
{
    int mid;

	while (begin <= end) {
		mid = begin + (end - begin) / 2;

		if (n == getListValue(mainChain, mid)) {
			return mid;
		}
		if (n > getListValue(mainChain, mid)) {
			begin = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	if (n > getListValue(mainChain, mid)) {
		return mid + 1;
	} else {
		return mid;
	}
}

int PmergeMe::getListValue(std::list<int> &list, int idx) {
    std::list<int>::iterator iter = list.begin();
    
    while (idx--) {
        ++iter;
    }
    
    return *iter;
}

void PmergeMe::setListValue(std::list<int> &list, int idx, int value) {
    std::list<int>::iterator iter = list.begin();
    while (idx--) {
        ++iter; 
    }
    
    *iter = value;
}

std::pair<int, int> PmergeMe::getPairInList(std::list<std::pair<int, int> > &container, int idx)
{
    std::list<std::pair<int, int> >::iterator iter = container.begin();
    
    while (idx--) {
        ++iter;
    }
    
    return *iter;
}

void PmergeMe::setPairInList(std::list<std::pair<int, int> > &container, int idx, std::pair<int, int> value)
{
   std::list<std::pair<int, int> >::iterator iter = container.begin();
    while (idx--) {
        ++iter; 
    }
    
    *iter = value;
}
