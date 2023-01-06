#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string> 

class Convert
{
	public:
		Convert(std::string str);
		Convert(char c);
		Convert(int n);
		Convert(float f);
		Convert(double d);
		Convert(const Convert &src);
		virtual ~Convert(void);
		Convert &operator = (const Convert &src);
};

#endif