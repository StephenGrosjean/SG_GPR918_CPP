//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_GAMEOBJECT_H
#define SAE918_GAMEOBJECT_H

#include <memory>
#include <ex8/Vector2d.h>

class Creature;
class Food;
class Simulation;


class GameObject {

 public:
  GameObject(Simulation * simulation, Vector2D position);

  GameObject(Simulation * simulation);

  virtual void Update () = 0;

  virtual void Start () = 0;

  virtual char GetImage ();

  Vector2D GetPosition () ;

  void SetPosition (Vector2D position);

  bool IsObjectDestroyed ();

  void Destroy ();


 protected:
  Vector2D position;
  Simulation * simulation;
  bool isDestroyed;

};

class  GameObjectBuilder {
 public:
  static std::unique_ptr<Creature> BuildCreature (Simulation& simulation);
  static std::unique_ptr<Food> BuildFood (Simulation& simulation);
};
#endif //SAE918_GAMEOBJECT_H
