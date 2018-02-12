//
// NbMath.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sun Jul  6 01:04:12 2014 ovoyan_s
// Last update Sun Jul  6 01:14:10 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"NbMath.hh"

NbMath::NbMath()
{

}

NbMath::~NbMath()
{

}

bool				NbMath::isNumber(const std::string &numberToCheck)
{
  unsigned int			iterator;
  unsigned int			nbComas;

  iterator = 0;
  nbComas = 0;
  while (iterator < numberToCheck.size())
    {
      if (numberToCheck[iterator] != '.' && (numberToCheck[iterator] > '9'
					     || numberToCheck[iterator] < '0'))
	return (false);
      if (numberToCheck[iterator] == '.')
	++nbComas;
      if (nbComas > 1)
	return (false);
      ++iterator;
    }
  return (true);
}

int				NbMath::convertInt(const std::string &numberToConvert)
{
  return (atoi(numberToConvert.c_str()));
}
