#ifndef PART1_H
# define PART1_H

# include <iostream>
# include <stdio.h>

class Part {
	private:
		char	*_fname;
		char	*_lname;
		int	*_score;
	public:
		Part(char *fname, char *lname, int *score);
		Part();
		char*	getFName(void) {return	(this->_fname);}
		char*	getLName(void) {return	(this->_lname);}
		int*	getScore(void) {return	(this->_score);}
		void	setFName(char*	fname);
		void	setLName(char*	lname);
		void	setScore(int*	score);
		double	getAverage(void);
		friend	std::istream&	operator>>(std::istream& in, Part* part);
		friend	std::ostream&	operator<<(std::ostream& on, Part* part);
		~Part();
};

#endif
