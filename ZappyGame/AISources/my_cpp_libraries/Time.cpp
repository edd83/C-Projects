//
// Time.cpp for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:43:51 2014 ovoyan_s
// Last update Mon May 12 19:38:03 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Time.hh"

Time::Time()
{

}

time_t			Time::MyTime(time_t *t)
{
  time_t		ret_time;

  if ((ret_time = time(t)) == ((time_t)-1))
    throw MyException ("MyTime Error");
  return (ret_time);
}

int			Time::MySleep(int time_to_sleep)
{
  return (sleep(time_to_sleep));
}

Time::~Time()
{

}
