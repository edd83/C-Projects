//
// Select.cpp for Select in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:08:06 2014 lardet
// Last update Sun Jul 13 01:06:05 2014 volpe
//

#include	 <stdio.h>
#include	"../headers/Select.hh"

Select::Select()
{
}

Select::~Select()
{
}

fd_set		*Select::getReadFds()
{
  return (&this->_readfds);
}

void		Select::launchClient(int listenFd)
{
  FD_ZERO(&this->_readfds);
  FD_SET(0, &this->_readfds);
  FD_SET(listenFd, &this->_readfds);
}
