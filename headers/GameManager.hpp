// Copyright Grama Nicolae 2020
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Table.hpp"
#include "AI.hpp"

class GameManager {
    private:
    Table table;
    AI bot;

    public:
    
    void startNewGame(const bool startX = false, const bool againstComputer = false) {
        if(!againstComputer) {

        } else {
            if(startX) {

            } else {
                
            }
        }
    }

};

#endif // GAMEMANAGER_HPP