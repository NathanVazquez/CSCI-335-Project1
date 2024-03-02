/*
CSCI335 Spring 2024
Project 3 - Tavern Class
Given MoveAll.hpp
2/2024

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

//defined the moveAll function. 
/** 
        @param:   the keyword of the books we want to move to the destination vector, a vector to read book objects from and a destination vector to place all the books that have a matching keyword
        @post:    all books with the specified keyword will be moved to the destination vector and then removed from the source vector
    **/
void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest);

