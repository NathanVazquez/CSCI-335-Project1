/*
/*
CSCI335 Spring 2024
Project 3 - Tavern Class
Given MoveAll.cpp
2/2024

----------------------------------------------------------------------------------
CSCI 335 Spring 2024
Project 1 - Move Semantics
Contributor: Nathan Vazquez
12/2024

*/
#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest". 
// A Book is moved if any of its keywords match the one specified in this function. 
// Use iterators whenever appropriate. 
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto". 

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // this function will be used to move all the books that have the keyword arguments in its keywords vector into the dest vector
  // this int will be used to keep track of what index we are currently at in the vector for books
  int i = 0;
  // we are iterating through all the books in the source vector
  for (Book curr_book : source ){
    //next we iterate through all the keywords in the current book
    for(std::string curr_keyword : curr_book.getKeywords()){
      //once we find a keyword that matches the keyword arg we want to push that book to the destination vector
      if(keyword == curr_keyword){
        // we push back the current book into the destination vector by moving it
        dest.push_back(std::move(curr_book));
        //next we erase the book from the source register
        //source.erase(source.begin()+i);
        books_moved++;
        //increment books_moved to account for the most recent moved book
        //break out of the for loop since we don't need to review the rest of the keywords and should look at the next book
        break;
      }
      // increment the index 
      i++;
    }
    //once we finish looking through all the books we reset the index to 0
    i=0;
  }

  
  // erase this comment and write your code here


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}