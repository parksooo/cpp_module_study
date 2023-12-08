#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> _vector, std::list<int> _list)
{
    this->_originVector = _vector;
    this->_sortedVector = _vector;
    this->_originList.assign(_list.begin(), _list.end());
    this->_sortedList.assign(_list.begin(), _list.end());
}

PmergeMe::PmergeMe(const PmergeMe &ob)
{
    this->_originVector = ob._originVector;
    this->_sortedVector = ob._originVector;
    this->_originList = ob._originList;
    this->_sortedList = ob._sortedList;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ob)
{
    if (this != &ob) {
        this->_originVector = ob._originVector;
        this->_sortedVector = ob._originVector;
        this->_originList = ob._originList;
        this->_sortedList = ob._sortedList;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::startSort()
{
    vectorSort();
    // listSort();
}

void PmergeMe::setValueOfList(int idx, int value)
{
    std::list<int>::iterator iter = this->_sortedList.begin();
    while (idx--) {
        iter++;
    }
    *iter = value;
}

int PmergeMe::getValueOfList(std::list<int> _list, int idx)
{
    std::list<int> tmp;

    tmp.assign(_list.begin(), _list.end());
    std::list<int>::iterator iter = tmp.begin();
    while(idx--) {
        iter++;
    }
    return *iter;
}

void PmergeMe::printBefore()
{
    std::cout << "Before: ";
}

void PmergeMe::printAfter()
{
    std::cout << "After: ";
}

void PmergeMe::printVector(std::vector<int> _vector)
{
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::printList(std::list<int> _list)
{
    for (std::list<int>::iterator iter = _list.begin(); iter != _list.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

void PmergeMe::vectorSort()
{
    printBefore();
    // printVector(this->_originVector);
    std::clock_t startTime = clock();
    mergeInsertSortInVector(0, this->_originVector.size() - 1, 1000);
    std::clock_t endTime = clock();
    printAfter();
    printVector(this->_sortedVector);
    std::cout << "Time to process a range of " << std::setw(4) << this->_originVector.size() \
                    << " elements with std::vector : " << static_cast<double>(endTime - startTime) * 1000 / CLOCKS_PER_SEC \
                    << "ms" << std::endl;
}

void PmergeMe::listSort()
{
    printBefore();
    printList(this->_originList);
    clock_t startTime = clock();
    mergeInsertSortInList(0, this->_originList.size() - 1, 20);
    clock_t endTime = clock();
    printAfter();
    printList(this->_sortedList);
    std::cout << "Time to process a range of " << std::setw(4) << this->_originList.size() \
                    << " elements with std::list : " << endTime - startTime << "ms" << std::endl;
}

void PmergeMe::mergeInsertSortInVector(int _left, int _right, int _p)
{
    if (_right - _left + 1 <= _p) {
        insertInVector(_left, _right);
    } else if (_left < _right) {
        int _mid = _left + (_right - _left) / 2;
        mergeInsertSortInVector(_left, _mid, _p);
        mergeInsertSortInVector(_mid + 1, _right, _p);
        mergeInVector(_left, _mid, _right);
    }
}

void PmergeMe::mergeInsertSortInList(int _left, int _right, int _p)
{
    if (_right - _left + 1 <= _p) {
        insertInList(_left, _right);
    } else if (_left < _right) {
        int _mid = _left + (_right - _left) / 2;
        mergeInsertSortInList(_left, _mid, _p);
        mergeInsertSortInList(_mid + 1, _right, _p);
        mergeInList(_left, _mid, _right);
    }
}

void PmergeMe::insertInVector(int _left, int _right)
{
    for(int i = _left + 1; i <= _right; i++) {
        int key = this->_sortedVector[i];
        int j = i - 1;

        while (j >= _left && this->_sortedVector[j] > key) {
            this->_sortedVector[j + 1] = this->_sortedVector[j];
            j--;
        }
        this->_sortedVector[j + 1] = key;
    }
}

void PmergeMe::insertInList(int _left, int _right)
{
    for (int i = _left + 1; i <= _right; i++) {
        int key = getValueOfList(this->_sortedList, i);
        int j = i - 1;

        while (j >= _left && getValueOfList(this->_sortedList, j) > key) {
            setValueOfList(j + 1, getValueOfList(this->_sortedList, j));
            j--;
        }
        setValueOfList(j + 1, key);
    }
}

void PmergeMe::mergeInVector(int _l, int _m, int _r)
{
    int n1 = _m - _l + 1;
    int n2 = _r - _m;

    std::vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = this->_sortedVector[_l + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = this->_sortedVector[_m + 1 + i];
    }

    int i, j = 0;
    int k = _l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[i]) {
            this->_sortedVector[k] = left[i];
            i++;
        } else {
            this->_sortedVector[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        this->_sortedVector[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        this->_sortedVector[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInList(int _l, int _m, int _r)
{
    int n1 = _m - _l + 1;
    int n2 = _r - _m;

    std::list<int> left;
    std::list<int> right;

    std::list<int>::iterator iter = this->_sortedList.begin();

    for (int i = 0; i < n1; i++) {
        left.push_back(*iter);
        iter++;
    }

    for (int i = 0; i < n2; i++) {
        right.push_back(*iter);
        iter++;
    }

    int i, j = 0;
    int k = _l;

    while (i < n1 && j < n2) {
        if (getValueOfList(left, i) <= getValueOfList(right, i)) {
            setValueOfList(k, getValueOfList(left, i));
            i++;
        } else {
            setValueOfList(k, getValueOfList(right, j));
            j++;
        }
        k++;
    }

    while (i < n1) {
        setValueOfList(k, getValueOfList(left, i));
        i++;
        k++;
    }
    
    while (j < n2) {
        setValueOfList(k, getValueOfList(right, j));
        j++;
        k++;
    }
}

