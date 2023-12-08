#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <cstdlib>
# include <iomanip>

class PmergeMe {
    private :
            std::vector<int> _originVector;
            std::vector<int> _sortedVector;
            std::list<int> _originList;
            std::list<int> _sortedList;

            PmergeMe();

            void setValueOfList(int idx, int value);
            int getValueOfList(std::list<int> _list, int idx);

            void printBefore();
            void printAfter();
            void printVector(std::vector<int> _vector);
            void printList(std::list<int> _list);

            void vectorSort();
            void listSort();

            void mergeInsertSortInVector(int _left, int _right, int _p);
            void mergeInsertSortInList(int _left, int _right, int _p);

            void insertInVector(int _left, int _right);
            void insertInList(int _left, int _right);

            void mergeInVector(int _left, int _mid, int _right);
            void mergeInList(int _left, int _mid, int _right);
    public :
            PmergeMe(std::vector<int> _vector, std::list<int> _list);
            PmergeMe(const PmergeMe &ob);
            PmergeMe& operator=(const PmergeMe &ob);
            ~PmergeMe();
            void startSort();
};
#endif