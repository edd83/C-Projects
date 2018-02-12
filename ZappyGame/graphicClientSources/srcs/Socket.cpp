//
// Socket.cpp for Socket in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 21:46:42 2014 lardet
// Last update Sun Jul 13 22:09:07 2014 volpe
//

/*
**			MY INCLUDES
*/

#include		"../headers/Socket.hh"

Socket::Socket()
{
  bzero((char *) &this->_svrAdd, sizeof(this->_svrAdd));
}

Socket::~Socket()
{
  if (close(this->_listenFd) == -1)
    throw RuntimeError("Failed to close socket.");
}

int			Socket::getFd() const
{
  return (this->_listenFd);
}

std::string		Socket::rcvSomething(unsigned int fdSocket)
{
  char		buf[50000];
  int		rd;

  bzero(buf, 50000);
  rd = recv(fdSocket, buf, 50000, 0);
  if (rd <= 0)
    {
      if (close(this->_listenFd) == -1)
	throw RuntimeError("Failed to close socket.");
      throw RuntimeError("Failed to receive something.");
    }

  std::string	strToRet(buf);

  return (strToRet);
}

t_sockaddr_in           *Socket::my_bind_assign(int port_id, unsigned int s_addr_assign)
{
  t_sockaddr_in         *sock_addr_in;

  sock_addr_in = NULL;
  if ((sock_addr_in = static_cast<t_sockaddr_in*>(malloc(sizeof(*sock_addr_in)))) == NULL)
    throw MyException("malloc failure");
  sock_addr_in->sin_family = AF_INET;
  sock_addr_in->sin_port = htons(port_id);
  sock_addr_in->sin_addr.s_addr = s_addr_assign;
  return (sock_addr_in);
}

t_sockaddr_in		*Socket::first_oper_steps(int port_id, int *fd_socket,
						  unsigned int s_addr_assign)
{
  t_protocol            *protocol;
  t_sockaddr_in         *sock_addr_in;

  sock_addr_in = NULL;
  if ((protocol = getprotobyname("TCP")) == NULL)
    throw MyException("getprotobyname failure");
  if ((*fd_socket = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) < 0)
    throw MyException("socket failure");
  if ((sock_addr_in = my_bind_assign(port_id, s_addr_assign))
      == NULL)
    throw MyException("my_bind_assign failure");
  return (sock_addr_in);

}

void			Socket::connectionClient(const char *ip, int port)
{
  t_sockaddr_in		*sock_addr_in;
  unsigned int		ip_address;

  if ((ip_address = inet_addr(ip)) == (in_addr_t)(-1))
    throw MyException("inet_addr failure");
  if ((sock_addr_in = first_oper_steps(port, &this->_listenFd,
                                       (unsigned int)ip_address)) == NULL)
    throw MyException("first_oper_steps failure");
  if (connect(this->_listenFd, (t_sockaddr*)sock_addr_in,
              (socklen_t)sizeof(*sock_addr_in)) < 0)
    throw MyException("connect failure");
}

void			Socket::sendSomething(const std::string &buffer)
{
  if (buffer.size() > 0)
    {
      if (write(this->_listenFd, buffer.c_str(), buffer.size()) == -1)
	throw RuntimeError("Failed to send.");
    }
}
