//
// Random.hh for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:35:51 2014 ovoyan_s
// Last update Fri May  9 13:33:29 2014 ovoyan_s
//

#ifndef				RANDOM_HH_
# define			RANDOM_HH_

/*
**				GENERAL INCLUDES
*/

# include			<stdlib.h>

/*
**				MY INCLUDES
*/

# include			"MyException.hh"
# include			"Time.hh"

class				Random
{
private:
  int				random_number;
public:
  Random();
  void				Srandom();
  void				GetRandom(int limit_of_random);
  int				GetRandomNumber();
  int				GetRandomRN(int limit_of_random);
  ~Random();
};

#endif				/*	RANDOM_HH_	*/
