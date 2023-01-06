#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream> 

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &src);
		virtual ~Brain(void);
		Brain &operator = (const Brain &src);

		void				setIdea(size_t i, std::string idea);
		const std::string	getIdea(size_t i) const;
		const std::string	*getIdeaAddress(size_t i) const;

	private:
		std::string _ideas[100];
};

#endif