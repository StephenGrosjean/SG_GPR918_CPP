//
// Created by efarhan on 10.10.18.
//

#include <iostream>
#include <cstdlib>

#include <ex8/Map.h>
#include <ex8/GameObject.h>
#include <ex8/Creature.h>

Map::Map() {

}

bool Map::AddGameObjectAt (std::unique_ptr<GameObject> gameObject) {
  Vector2D position = gameObject->GetPosition ();
  return AddGameObjectAt(std::move (gameObject), position.x, position.y);
}

bool Map::AddGameObjectAt (std::unique_ptr<GameObject> gameObject, int positionX, int positionY) {
  GameObject * mapPosition = m_Map[positionX][positionY].get ();
  if (mapPosition == nullptr) {

      m_GameObjectsForUpdate.push_back(gameObject.get ());
      m_Map[positionX][positionY] = std::move (gameObject);
      return true;
    }

  return false;
}


bool Map::GameObjectExistAt (Vector2D position) {
  return m_Map[position.x][position.y] != nullptr && !m_Map[position.x][position.y]->IsObjectDestroyed ();
}

bool Map::RemoveObjectAt(Vector2D position) {
  if (m_Map[position.x][position.y] != nullptr) {
      m_Map[position.x][position.y] = nullptr;
      return true;
    }
  return false;
}

bool Map::MoveGameObjetTo(GameObject & gameObject, int positionX, int positionY) {
  if (positionX >= m_Map.size() || positionY >= m_Map[0].size()) {
      return false;
    }
  if (m_Map[positionX][positionY] != nullptr)
    {
      return false;
    }
  Vector2D currentPosition = gameObject.GetPosition ();
  m_Map[positionX][positionY] = std::move (m_Map[currentPosition.x][currentPosition.y]);
  m_Map[currentPosition.x][currentPosition.y] = nullptr;
  gameObject.SetPosition (Vector2D (positionX, positionY));

  return true;
}

void Map::Update () {
  for (auto * gameObject : m_GameObjectsForUpdate) {
      gameObject->Update ();

    }
  //Destroy element


  //Destroy updates elements
  m_GameObjectsForUpdate.remove_if([](GameObject * gameObject) {return gameObject->IsObjectDestroyed (); });
  //Destroy map elements
  for (auto * gameObject : m_GameObjectsForUpdate) {
      if (gameObject->IsObjectDestroyed ()) {
          RemoveObjectAt(gameObject->GetPosition ());
        }
    }
}


void Map::DisplayMap() {
#ifdef WIN32
  system("cls");
#else
  printf("\x1b[H\x1b[J");
#endif
  std::cout << "-------------------------" << std::endl;

  for (int x = 0; x < m_Map.size(); x++) {
      std::cout << "|";
      for (int y = 0; y < m_Map[x].size(); y++) {
          if (GameObjectExistAt (Vector2D (x, y))) {
              std::cout << m_Map[x][y]->GetImage ();
            }
          else {
              std::cout << " ";
            }
        }
      std::cout << "|" << std::endl;
    }
  std::cout << "-------------------------" << std::endl;
#ifdef WIN32
  system("Pause");
#else
  std::cin.ignore();
  std::cin.get ();
#endif
}



int Map::CountCreaturesInMap () {
  int counter = 0;
  for (int x = 0; x < m_Map.size(); x++) {
      for (int y = 0; y < m_Map[x].size(); y++) {
          if (GameObjectOfTypeExistAt<Creature> (Vector2D (x, y))) {
              counter++;
            }
        }

    }

  return counter;
}
GameObject * Map::GetContentAtPosition (Vector2D position)
{
  return m_Map[position.x][position.y].get ();
}
