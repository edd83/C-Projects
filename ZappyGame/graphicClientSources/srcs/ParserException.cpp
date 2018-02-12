//
// ParserException.cpp for ParserException in /home/volpe_p/rendu/Nibbler/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 22:51:22 2014 volpe
// Last update Sat Jul  5 22:57:37 2014 volpe
//

#include	"../headers/ParserException.hh"

ParserException::ParserException(const char * Msg)
{
  std::ostringstream oss;

  oss << Msg;
  this->_msg = oss.str();
}

ParserException::~ParserException() throw()
{

}


const char	*ParserException::what() const throw()
{
  return (this->_msg.c_str());
}
