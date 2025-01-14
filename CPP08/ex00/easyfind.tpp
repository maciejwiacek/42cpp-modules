template <typename T>
int *easyfind(T& container, int num) {
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
		if (*it == num)
			return &(*it);
	return NULL;
}