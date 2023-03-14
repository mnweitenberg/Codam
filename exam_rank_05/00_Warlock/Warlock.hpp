#pragma once

#include <iostream>

using namespace std;

class Warlock
{
	public:
		Warlock(const string name, const string title) : _name(name), _title(title) {
			cout << _name << ": This looks like another boring day." << endl;
		}
		~Warlock() { cout << _name << ": My job her is done!" << endl; }

		string	const & getName() const { return _name; }
		string	const & getTitle() const { return _title; }
		void	setTitle(string const &title) { _title = title; }
	
		void	introduce() const {
			cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
		}

	private:
		Warlock() {};
		Warlock(Warlock const & x);
		Warlock & operator= (Warlock const & x);

		string _name;
		string _title;
};
