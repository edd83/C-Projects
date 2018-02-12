//
// NbMath.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sun Jul  6 01:02:19 2014 ovoyan_s
// Last update Sun Jul  6 01:14:47 2014 ovoyan_s
//

#ifndef					NB_MATH_HH_
# define				NB_MATH_HH_

/*
**					GENERAL INCLUDES
*/

# include				<iostream>
# include				<string>

/*
**					C INCLUDES
*/

# include				<cstdlib>

class					NbMath
{
public:
  NbMath();
  ~NbMath();

  static bool				isNumber(const std::string &numberToCheck);
  static int				convertInt(const std::string &numberToConvert);

};

#endif					/*	NB_MATH_HH_	*/
