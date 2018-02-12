//
// Time.hh for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:44:20 2014 ovoyan_s
// Last update Mon May 12 19:38:12 2014 ovoyan_s
//

#ifndef				TIME_HH_
# define			TIME_HH_

/*
**				GENERAL INCLUDES
*/

# include			<time.h>
# include			<unistd.h>

/*
**				MY INCLUDES
*/

# include			"MyException.hh"

class				Time
{
public:
  Time();
  static time_t			MyTime(time_t *t);
  static int			MySleep(int time_to_sleep);
  ~Time();
};

#endif				/*	TIME_HH_	*/
