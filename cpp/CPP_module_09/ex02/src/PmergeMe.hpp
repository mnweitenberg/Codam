#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void	sortContainer(std::vector<int> &vec);
		void	sortContainer(std::list<int> &lst);

	private:
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		
		void	printPerformance(clock_t start_time, int size, std::string type);

		template <typename Container>
		void 	mergeInsertionSort(Container& container);

};

#endif
