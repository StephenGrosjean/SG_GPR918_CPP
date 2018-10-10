//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_MAP_H
#define SAE918_MAP_H

#include <array>
#include <list>

#include <ex8/Vector2d.h>
#include <ex8/GameObject.h>
#include <ex8/Creature.h>
#include <ex8/Food.h>


const int MAP_SIZE = 10;

class Map {
 public:
  Map();

  bool AddGameObjectAt (std::unique_ptr<GameObject> gameObject);

  bool AddGameObjectAt (std::unique_ptr<GameObject> gameObject, int positionX, int positionY);

  GameObject & GetContentAtPosition (Vector2D position) {
    return *m_Map[position.x][position.y];
  }

  template<typename T> bool GameObjectOfTypeExistAt (Vector2D position) ;


  bool GameObjectExistAt (Vector2D position);

  bool RemoveObjectAt(Vector2D position);

  bool MoveGameObjetTo(GameObject & gameObject, int positionX, int positionY);

  void Update () ;

  void DisplayMap();

  int CountCreaturesInMap ();

 private:
  std::array<std::array<std::unique_ptr<GameObject>, MAP_SIZE>, MAP_SIZE> m_Map;
  std::list<GameObject * > m_GameObjectsForUpdate;
};


template<typename T>
bool Map::GameObjectOfTypeExistAt (Vector2D position) {
  if (m_Map[position.x][position.y] == nullptr) {
      return false;
    }
  T * gameObject = dynamic_cast<T*>(m_Map[position.x][position.y].get ());
  return gameObject != nullptr;
}

#endif //SAE918_MAP_H
