/*

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

  int index = 0;
  // for (Book curr_book : source ){
  //   for(std::string curr_keyword : curr_book.getKeywords() ){
  //     if(keyword == curr_keyword){
  //       dest.push_back(std::move(curr_book));
  //       //source.erase(source.begin()+i);
  //       books_moved++;
  //       break;
  //     }
  //     i++;
  //   }
  //   //std::cout<<"\n";
  //   i=0;
  // }

  bool found_keyword = false;
    //for (Book curr_book : source ){
      for(int i = 0; i<source.size();i++){
    //for(std::string curr_keyword : curr_book.getKeywords() ){
      for (int j = 0; j<source[i].getKeywords().size();j++){
      if(keyword == source[i].getKeywords()[j]){
        found_keyword=true;
      }
      index++;
      if(found_keyword){
        dest.push_back(std::move(source[i]));
        books_moved++;
        //source.erase(source.begin()+i); 
      }
    }
    index=0;
  }
  
  
  
  // erase this comment and write your code here


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}