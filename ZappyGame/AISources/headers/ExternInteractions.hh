//
// ExternInteractions.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jul  1 17:44:02 2014 ovoyan_s
// Last update Sat Jul 19 12:14:05 2014 ovoyan_s
//

#ifndef					EXTERN_INTERACTIONS_HH_
# define				EXTERN_INTERACTIONS_HH_

/*
**					GENERAL INCLUDES
*/

# include				<iostream>
# include				<string>

/*
**					MY INCLUDES
*/

class					ExternInteractions
{
private:
  unsigned int                          nbPlayer; // The capacity of the player's team
  unsigned int                          groupId; // The id of group of player
  unsigned int                          groupLvl; // The lvl of player's group's members (lvl of group)
  unsigned int                          groupNumber; // The number of persons in the player's group
  std::string				focusedTrentonian;
  int					focusedDirection;
  bool					isFocused;

public:
  ExternInteractions();
  ~ExternInteractions();

  ExternInteractions			&operator=(const ExternInteractions &eaToSet);

  //					Setters

  void                                  setNbPlayer(unsigned int nbPlayerToSet);
  void                                  setGroupId(unsigned int groupIdToSet);
  void                                  setGroupLvl(unsigned int groupLvlToSet);
  void                                  setGroupNumber(unsigned int groupNumberToSet);
  void					setFocusedDirection(int directionToSet);
  void					setFocusedTrentonian(const std::string &trentonianNameToSet);
  void					setIsFocused(bool isFocused);

  //					Getters

  unsigned int                          getNbPlayer() const;
  unsigned int                          getGroupId() const;
  unsigned int                          getGroupLvl() const;
  unsigned int	                        getGroupNumber() const;
  int					getFocusedDirection() const;
  std::string				getFocusedTrentonian() const;
  bool					getIsFocused() const;

  void					findRessources(int ressourcesToSearch[7]);
  unsigned int				connectNbr();
  void					reproduction();
};

#endif				/*	EXTERN_INTERACTIONS_HH_	*/
