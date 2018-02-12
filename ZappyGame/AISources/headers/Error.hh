//
// Error.hh for Error in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:04:16 2014 lardet
// Last Update Sun Apr 27 10:00:06 2014 Bonnet Vivien
//

#ifndef         __ERROR_HH__
# define        __ERROR_HH__

#include	<string>
#include	<exception>

class		RuntimeError : public std::exception
{
  std::string	err;
public:
  RuntimeError(std::string const &);
  virtual ~RuntimeError() throw();

  virtual const char*	what() const throw();
};

#endif
