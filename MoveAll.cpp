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

  int i = 0;
  for (Book curr_book : source ){
    //std::cout<<"current book: "<<curr_book.getTitle() <<"\n";
    for(std::string curr_keyword : curr_book.getKeywords()){
      //std::cout<<"current word: "<< curr_keyword <<"!= "<< keyword<<"\n";
      if(keyword == curr_keyword){
        dest.push_back(std::move(curr_book));
        //source.erase(source.begin()+i);
        books_moved++;
        break;
      }
      i++;
    }
    //std::cout<<"\n";
    i=0;
  }
  //std::cout<< "size of cart: "<<dest.size()<<"\n";
  
  
  
  // erase this comment and write your code here


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}