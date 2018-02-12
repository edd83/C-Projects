//
// MyException.cpp for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:34:48 2014 ovoyan_s
// Last update Sun Jul 13 01:06:29 2014 volpe
//

#include	 "../headers/MyException.hh"

MyException::MyException(std::string const& error) throw() : Error(error)
{
}

MyException::~MyException() throw()
{
}

char const*		MyException::what() const throw()
{
  return this->Error.c_str();
}
