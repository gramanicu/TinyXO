// Copyright Grama Nicolae 2020
#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdint.h>
 
class Table {
    private:
    
    // Stores the first 8 cells of the table
    int16_t data1;

    // Stores the last cell and other data
    // - 2 bits the last cells
    // - 1 bit the current player (0 - 0, 1 - X)
    int8_t data2;

    /**
     * @brief Get the state of a bit (cells)
     * 
     * @param index The index of the bit
     * @return char The value of the bit
     */
    char getState(const char index) const {
        if(index < 16) {
            return (data1 >> index) % 2;
        } else {
            return (data2 >> (index - 16)) % 2;
        }
    }

    /**
     * @brief Returns the player who has the turn (0 - 0 , X - 1)
     * 
     * @return char The player
     */
    char getPlayer() const {
        return (data2 >> 2) % 2;
    }

    /**
     * @brief Gives the turn to the other player
     * 
     */
    void switchPlayer() {
        if(getPlayer()) {
            // Set the turn to 0
            data2 = data2 & 3;
        } else {
            // Set the turn to X
            data2 = (1 << 2) | data2;
        }
    }

    /**
     * @brief Set the state of a bit (cells)
     * 
     * @param index The index of the bit
     */
    void setState(const int8_t index) {
        if(index < 16) {
            data1 = data1 | (1 << index);
        } else {
            data2 = data2 | (1 << (16 - (index)));
        }
    }
    
    public:

    Table() {
        start();
    }

    /**
     * @brief Set the value of a cell
     * 
     * @param index The cell index (0 - 8)
     * @return true  The index was valid and the cell was set
     * @return false Invalid index
     */
    bool setCell(const char index) {
        // If X's turn
        if(getPlayer() == 1) {
            if(getState(index*2)) {
                return false;
            } else {
                setState(index*2);
                switchPlayer();
                return true;
            }
        } else {
            if(getState(index*2+1)) {
                return false;
            } else {
                setState(index*2+1);
                switchPlayer();
                return true;
            }
        }
    }

    /**
     * @brief Get the value stored in the cell
     * 
     * @param index The index of the cell (0 - 8)
     * @return char The value of the cell
     */
    char getCell(const char index) {
        if(getState(index*2)) {
            return 'X';
        } else if(getState(index*2+1)) {
            return '0';
        } else {
            return ' ';
        }
    }

    void reset() {
        data1 = 0;
        data2 = 0;
    }

    void start() {
        reset();
        switchPlayer();
    }

    friend std::ostream& operator<<(std::ostream& out, Table& table) {
        for(uint i = 0 ; i < 3 ; ++i) {
            for(uint j = 0; j < 3; ++j) {
                out << table.getCell(i*3+j) << " ";
            }
            out << "\n";
        }
        return out;
    }

};

#endif // TABLE_HPP