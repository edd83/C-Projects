//
// ParserException.hh for ParserException in /home/volpe_p/rendu/Nibbler/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 22:52:30 2014 volpe
// Last update Sat Jul  5 22:53:32 2014 volpe
//

#ifndef		PARSEREXCEPTION_HH_
# define	PARSEREXCEPTION_HH_

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

class	ParserException : public std::exception
{
protected:
  std::string	_msg;
public:
  ParserException(const char *);
  virtual	~ParserException() throw();
  virtual const char * what() const throw();
};

#endif
