//
// Inventory.hh for Inventory in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Jul  6 05:05:01 2014 volpe
// Last update Mon Jul  7 11:28:11 2014 volpe
//

#ifndef		INVENTORY_HH_
# define	INVENTORY_HH_

class Inventory
{
private:
  int		food;
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
public:
  Inventory();
  Inventory(int, int, int, int, int, int, int);
  ~Inventory();

  // Getters && Setters
  int		getFood() const;
  int		getLinemate() const;
  int		getDeraumere() const;
  int		getSibur() const;
  int		getMendiane() const;
  int		getPhiras() const;
  int		getThystame() const;

  void		setFood(int);
  void		setLinemate(int);
  void		setDeraumere(int);
  void		setSibur(int);
  void		setMendiane(int);
  void		setPhiras(int);
  void		setThystame(int);

  void		addRes(int id);
  void		delRes(int id);
};
#endif
