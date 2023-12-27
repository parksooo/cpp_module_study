#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iterator>
# include <iostream>
# include <exception>

class PmergeMe {
    private	:
            std::vector<int> _input;
			std::vector<int> _mainChain;
            std::vector<int> _pendingChain;
            std::vector<int> _jacobsthal;
            std::vector<std::pair<int, int> > _pairVec;
            std::vector<int> _orderToInsertIndex;

            std::list<int> _inputList;
            std::list<int> _mainChainList;
            std::list<int> _pendingChainList;
            std::list<std::pair<int, int> > _pairList;

            PmergeMe();
            void setJacobsthalVector();
            void setOrderToInsertIndex(int n);
            
            //vector sort
            void sortVector();
            int makePairVector();
            void setChains();
            void mergePair(std::vector<std::pair<int, int> > &container, int left, int right);
            void merge(std::vector<std::pair<int, int> > &container, int first, int middle, int last);
            void insertPendingChain(int _unpairedValues); 
            int binaryInsert(std::vector<int> &mainChain, int n, int begin, int end);
            
            //list sort
            void sortList();
            void vectorToList();
            int makePairList();
            void setChainsOfList();
            void mergePairOfList(std::list<std::pair<int, int> > &container, int left, int right);
            void mergeOfList(std::list<std::pair<int, int> > &container, int first, int middle, int last);
            void insertPendingChainOfList(int _unpairedValues);
            int binaryInsertOfList(std::list<int> &mainChain, int n, int begin, int end);
            int getListValue(std::list<int> &list, int idx);
            void setListValue(std::list<int> &list, int idx, int value);
            std::pair<int, int> getPairInList(std::list<std::pair<int, int> > &container, int idx);
            void setPairInList(std::list<std::pair<int, int> > &container, int idx, std::pair<int, int> value);
    public  :
            PmergeMe(int argc, char **argv);
            PmergeMe(PmergeMe const &ob);
	        PmergeMe &operator=(PmergeMe const &ob);
            ~PmergeMe();
            void sort();
};
#endif