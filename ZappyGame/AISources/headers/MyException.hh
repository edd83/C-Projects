//
// MyException.hh for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 17:34:56 2014 ovoyan_s
// Last update Mon May  5 17:34:57 2014 ovoyan_s
//

#ifndef			MYEXCEPTION_HH_
# define		MYEXCEPTION_HH_

# include		<iostream>
# include		<exception>

class			MyException : public std::exception
{

private:

  std::string const	Error;

public:

  MyException(std::string const& error) throw();
  ~MyException() throw();

  char const*		what() const throw();

};

#endif
