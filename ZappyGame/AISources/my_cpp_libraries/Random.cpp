//
// Random.cpp for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:34:18 2014 ovoyan_s
// Last update Sat Jul 12 22:35:36 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Random.hh"

Random::Random()
{
  this->random_number = 0;
}		

void			Random::Srandom()
{
  srandom(Time::MyTime(NULL));
}

void			Random::GetRandom(int limit_of_random)
{
  if (limit_of_random == 0)
    throw MyException("Random Modulo failure");
  this->random_number = random() % limit_of_random; 
}

int			Random::GetRandomNumber()
{
  return (this->random_number);
}

int			Random::GetRandomRN(int limit_of_random)
{
  if (limit_of_random == 0)
    throw MyException("Random Modulo failure");
  return (random() % limit_of_random);
}

char			Random::getRandomChar()
{
  return (random() % 127);
}

Random::~Random()
{

}
