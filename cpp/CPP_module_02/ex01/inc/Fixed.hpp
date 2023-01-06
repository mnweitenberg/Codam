#ifndef FIXED_HPP
# define FIXED_HPP

# include <sstream> 
# include <iostream> 

class Fixed
{
	public:
		Fixed(void);							// constructor
		Fixed(const int integer);				// int constructor
		Fixed(const float floatingPoint);		// float constructor
		Fixed(const Fixed &f);					// copy constructor
		~Fixed(void);							// destructor
		Fixed &	operator = (const Fixed &f);	// copy assignment operator

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;
};

std::ostream &	operator << ( std::ostream & o, Fixed const & i);

#endif