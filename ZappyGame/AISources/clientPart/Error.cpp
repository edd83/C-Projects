//
// Error.cpp for Error in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:04:06 2014 lardet
// Last Update Sat Apr 26 20:05:26 2014 Bonnet Vivien
//

#include		"Error.hh"

RuntimeError::RuntimeError(std::string const &err)
{
  this->err = err;
}

RuntimeError::~RuntimeError() throw()
{
}

const char *	RuntimeError::what() const throw()
{
  return (this->err.c_str());
}
