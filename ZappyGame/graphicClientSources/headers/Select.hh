//
// Select.hh for Select in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:07:54 2014 lardet
// Last update Mon Jul  7 18:06:55 2014 ovoyan_s
//

#ifndef         __SELECT_HH__
# define        __SELECT_HH__

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/time.h>
#include	<cstdlib>
#include	<string>
#include	"Socket.hh"
#include	"Error.hh"

class		Select
{
  fd_set		_readfds;
public:
  Select();
  ~Select();
  fd_set		*getReadFds();
  void			launchClient(int);
};

#endif
