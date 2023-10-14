#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define NUMBER_OF_COMPLAINTS 4

enum complaints {
    DEBUG = 359,
    INFO = 300,
    WARNING = 534,
    ERROR = 394
};


class Harl {
    private:
        void	debug(void);
        void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif