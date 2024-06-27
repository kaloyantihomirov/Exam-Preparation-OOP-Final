#pragma once

#include <iostream>

#include "Player.h"
#include "Artifact.h"
#include "Teleport.h"
#include "Monster.h"

class GameSimulator
{
    Player p;

public:
    Artifact* field[10] = { nullptr, };

    GameSimulator(const char* _name = "OOP Master", int _initialBlood = 150,
                  int _maxBlood = 150, int _power = 42, int _index = 0);

    bool playGame();

    void printField() const;

    ~GameSimulator();
};

GameSimulator::GameSimulator(const char* _name, int _initialBlood,
                             int _maxBlood, int _power, int _index) : p(_name, _initialBlood, _maxBlood, _power, _index)
{
    //it would be better to add a function (add an artifact),
    //as we would be able to forbid the user to add an artifact
    //on the player's position (leaving us without a player) :(
    Teleport t1(231, 2);
    Teleport t2(1231, 5);
    Monster m1("nusha", 50, 80);
    Monster m2("tisho", 10, 40);
    field[2] = t1.clone();
    field[5] = t2.clone();
    field[1] = m1.clone();
    field[8] = m2.clone();
}

bool GameSimulator::playGame()
{
    printField();
    p.printPlayer();

    while(true)
    {
        if (p.getBlood() == 0)
        {
            return false;
        }

        if (p.getIndex() == 9)
        {
            return true;
        }

        std::cout << "Enter next play: -1 or 1:";
        int play;
        std::cin >> play;

        p.setIndex(p.getIndex() + play);

        while (field[p.getIndex()] != nullptr) //we should interact, as it's not an empty cell
        {
            int playerIndexBeforeInteraction = p.getIndex();
            field[p.getIndex()]->interactWithPlayer(p);

            if (!field[p.getIndex()]) //on empty cell
            {
                break;
            }

            if (!field[p.getIndex()]->isAlive())
            {
                delete field[p.getIndex()];
                field[p.getIndex()] = nullptr;
            }

            if (playerIndexBeforeInteraction == p.getIndex())
            {
                break;
            }
        }

        printField();
        p.printPlayer();
    }
}

void GameSimulator::printField() const
{
    for (int i = 0; i < 10; i++)
    {
        if (!field[i])
        {
            std::cout << "*";
        }
        else
        {
            field[i]->draw();
        }
    }
    std::cout << '\n';
}

GameSimulator::~GameSimulator()
{
    for (int i = 0; i < 10; i++)
    {
        delete field[i];
    }
}
