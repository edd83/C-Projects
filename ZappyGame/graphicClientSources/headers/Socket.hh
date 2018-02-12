//
// Socket.hh for Socket in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 21:33:24 2014 lardet
// Last update Tue Jul  8 11:39:09 2014 ovoyan_s
//

#ifndef			_SOCKET_HH_
# define		_SOCKET_HH_

/*
**			This is the socket part of client
**			that class manages the sockets
*/

/*
**			GENERAL INCLUDES
*/

# include		<iostream>
# include		<stdlib.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/time.h>
# include		<netdb.h>
# include		<strings.h>
# include		<string.h>
# include		<string>
# include		<unistd.h>
# include		<arpa/inet.h>
# include		<cstdio>

/*
**			MY INCLUDES
*/

# include		"Error.hh"
# include		"MyException.hh"

/*
**			MY DEFINES
*/

typedef struct  protoent        t_protocol;
typedef struct  sockaddr        t_sockaddr;
typedef struct  sockaddr_in     t_sockaddr_in;

class			Socket
{
  int			_listenFd;
  struct hostent	*_server;
  struct sockaddr_in	_svrAdd;
public:
  Socket();
  ~Socket();

  t_sockaddr_in		*my_bind_assign(int port_id, unsigned int s_addr_assign);
  t_sockaddr_in		*first_oper_steps(int port_id, int *fd_socket, unsigned int s_addr_assign);
  int			getFd() const;
  std::string		rcvSomething(unsigned int fdSocket);
  void			listenFd();
  void			closeFd(int);
  void			initialiseConnection();
  void			getHost(const char *);
  std::string		readInput();
  void			connectionClient(const char *, int);
  void			sendInSocket();
  void			sendSomething(const std::string &buffer);
  void			writeInSocket(const std::string &strToWrite);
};

#endif
