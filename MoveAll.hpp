/*
CSCI335 Spring 2024
Project 3 - Tavern Class
Georgina Woo
June 20 2023
Taven.cpp declares the Tavern class along with its private and public members
----------------------------------------------------------------------------------
CSCI 335 Spring 2024
Project 1 - Move Semantics
Contributor: Nathan Vazquez
2/2024

*/

#include <string>
#include <vector>
#include <list>
#include <chrono>
#include "Book.hpp"

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest);