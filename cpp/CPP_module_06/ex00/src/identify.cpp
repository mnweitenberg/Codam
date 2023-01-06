#include <string>
#include <climits>
#include <sstream> 

bool	isInfOrNan(std::string str) {
	if (str == "-inf" || str == "+inf" || str == "nan"
		|| str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	return (false);
}

bool	isChar(std::string str) {
	if (str.length() == 1)
		return (true);
	return (false);
}

bool	isInt(const std::string str) {
	int sign = 0;
	if (str[0] == '-')
		sign++;
	for (int i = sign; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (false);
	int len = str.size();
	if (str[0] == '-')
		len--;
	if (len > 10)
		return (false);
	std::stringstream ss;
	long temp;
	ss << str;
	ss >> temp;
	if (temp > INT_MAX || temp < INT_MIN)
		 return (false);
	return (true);
}

static bool	hasOneDecimalPoint(std::string input) {
	int count = 0;
	for (unsigned int i = 0; i < input.size(); i++)
		if (input[i] == '.')
			count++;
	if (count == 1)
		return (true);
	return (false);
}

static bool	isDecimal(std::string str, unsigned int len) {
	if (!hasOneDecimalPoint(str))
		return (false);
	unsigned int i = 0;
	if (str[0] == '-')
		i++;
	for (;i < len; i++)
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (false);
	return (true);
}

bool	isFloat(std::string str) {
	if (str[str.size() - 1] != 'f')
		return (false);
	if (!isDecimal(str, str.size() - 2))
		return (false);
	return (true);
}

bool	isDouble(std::string str) {
	if (!isDecimal(str, str.size() - 1))
		return (false);
	return (true);
}
