#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	public:
		RPN();
		~RPN();

		void 	calculate(std::string line);

	private:
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);

		std::stack<int> _rpn;

		int 	calculateResult(std::string token);
};

#endif
