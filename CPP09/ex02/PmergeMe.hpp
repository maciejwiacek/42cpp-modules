#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <deque>
#include <iterator>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		template<typename Container>
		std::pair<Container, Container> pairElements(const Container& container) {
			Container first;
			Container second;
			typename Container::const_iterator it = container.begin();
			while (it != container.end()) {
				typename Container::const_iterator next = it;
				++next;

				if (next != container.end()) {
					if (*next > *it) {
						first.push_back(*it);
						second.push_back(*next);
					} else {
						first.push_back(*next);
						second.push_back(*it);
					}
					it = ++next;
				} else {
					first.push_back(*it);
					++it;
				}
			}
			return std::make_pair(first, second);
		}

		template<typename Container>
		void insertionSort(Container& container) {
			typename Container::iterator it;
			typename Container::iterator i;
			for (it = container.begin() + 1; it != container.end(); it++) {
				int key = *it;
				i = it;

				while (i != container.begin() && *(i - 1) > key) {
					*i = *(i - 1);
					i--;
				}

				*i = key;
			}
		}

		template<typename Container>
		Container mergeSortedContainers(const Container& first, const Container& second) {
			Container result;
			typename Container::const_iterator itSmall = first.begin();
			typename Container::const_iterator itLarge = second.begin();

			while (itSmall != first.end() && itLarge != second.end()) {
				if (*itSmall < *itLarge) {
					result.push_back(*itSmall);
					++itSmall;
				} else {
					result.push_back(*itLarge);
					++itLarge;
				}
			}

			while (itSmall != first.end()) {
				result.push_back(*itSmall);
				++itSmall;
			}

			while (itLarge != second.end()) {
				result.push_back(*itLarge);
				++itLarge;
			}

			return result;
		}
};