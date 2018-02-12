//
// Ressource.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 11:53:34 2014 ovoyan_s
// Last update Fri Jul 18 14:26:35 2014 ovoyan_s
//

#ifndef				RESSOURCE_HH_
# define			RESSOURCE_HH_

/*
**				MY INCLUDES
*/

# include			"Namespaces.hh"

class				Ressource
{
private:
  int				coordX;
  int				coordY;
  RessourceNS::ressourceType	typeOfRessource;
  bool				isInAction;

public:
  Ressource();
  Ressource(const Ressource &ressourceToSet);
  ~Ressource();

  void				setCoordX(int coordToSetX);
  void				setCoordY(int coordToSetY);
  void				setRessourceType(const RessourceNS::ressourceType &ressourceToSet);
  void				setIsInAction(const bool &isInAction);

  int				getCoordX() const;
  int				getCoordY() const;
  RessourceNS::ressourceType	getRessourceType() const;
  bool				getIsInAction() const;
};

#endif				/*	RESSOURCE_HH_	*/
