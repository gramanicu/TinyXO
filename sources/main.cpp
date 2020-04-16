// Copyright Grama Nicolae 2020
#include <iostream>
#include "../headers/Table.hpp"

int main() {
    Table t;
    t.setCell(0);
    t.setCell(1);
    t.setCell(2);
    t.setCell(3);
    t.setCell(4);
    t.setCell(5);
    t.setCell(6);
    t.setCell(7);
    t.setCell(8);

    std::cout << t << "\n";

    return 0;
}