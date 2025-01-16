#include "PmergeMe.hpp"

template<typename Container>
Container parseInput(int ac, char **av) {
	Container container;
	for (int i = 1; i < ac; i++) {
		container.push_back(std::atoi(av[i]));
	}
	return container;
}

template<typename Container>
void printContainer(Container& container) {
	typename Container::iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it;
		if (it + 1 != container.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

template<typename Container>
void sortContainer(Container& container) {
	PmergeMe sorter;
	std::pair<Container, Container> pair = sorter.pairElements(container);
	sorter.insertionSort(pair.first);
	container = sorter.mergeSortedContainers(pair.first, pair.second);
}

template<typename Container>
void timeSort(Container& container, std::string type) {
	clock_t start = clock();
	sortContainer(container);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << container.size() << " elements with " << type << " : " << elapsed << " us\n";
}

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe [integers...]" << std::endl;
		return 1;
	}

	std::cout << "Testing std::vector...\n";
	std::vector<int> vec = parseInput<std::vector<int> >(ac, av);
	std::cout << "Before: ";
	printContainer(vec);
	timeSort(vec, "std::vector");
	std::cout << "After: ";
	printContainer(vec);

	std::cout << "Testing std::deque...\n";
	std::deque<int> deq = parseInput<std::deque<int> >(ac, av);
	std::cout << "Before: ";
	printContainer(deq);
	timeSort(deq, "std::deque");
	std::cout << "After: ";
	printContainer(deq);
}