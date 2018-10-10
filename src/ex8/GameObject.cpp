//
// Created by efarhan on 10.10.18.
//

#include <ex8/GameObject.h>
#include <ex8/Creature.h>
#include <ex8/Food.h>
#include <ex8/Simulation.h>

GameObject::GameObject(Simulation * simulation, Vector2D position) :simulation(simulation), position(position) {

}

GameObject::GameObject(Simulation * simulation) :simulation(simulation) {
    isDestroyed = false;
}

char GameObject::GetImage () {
  return '?';
}

Vector2D GameObject::GetPosition () {
  return position;
}


void GameObject::SetPosition (Vector2D position) {
  this->position = position;
}

bool GameObject::IsObjectDestroyed () {
  return isDestroyed;
}

void GameObject::Destroy () {
  isDestroyed = true;
}

std::unique_ptr<Creature> GameObjectBuilder::BuildCreature (Simulation& simulation) {
  auto creature = std::make_unique<Creature>(&simulation, 20);
  int x = simulation.GetValueRandom(0, MAP_SIZE - 1);
  int y = simulation.GetValueRandom(0, MAP_SIZE - 1);
  creature->SetPosition (Vector2D (x, y));
  return creature;


}

std::unique_ptr<Food> GameObjectBuilder::BuildFood (Simulation& simulation) {
  auto food = std::make_unique<Food>(&simulation);
  int x = simulation.GetValueRandom(0, MAP_SIZE - 1);
  int y = simulation.GetValueRandom(0, MAP_SIZE - 1);
  food->SetPosition (Vector2D (x, y));
  return food;
}

