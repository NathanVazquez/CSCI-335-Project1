#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include "Book.hpp"
#include "MoveAll.hpp"
  void testMoveAll(std::vector<Book> catalog,std::vector<Book> cart){

    moveAll("Spanish Literature", catalog, cart);

     for (auto& curr_book : cart){
    
    //std::cout << "Amount of keywords per book: " << curr_book.getKeywords().size() <<"\n";
    curr_book.print();
    //int icons = *curr_book.getIcon();
    //std::cout<<icons;
    

    // std::cout << "Title: " << curr_book.getTitle()<<"\n";
    // std::cout << "Author: " << curr_book.getAuthor()<<"\n";
    // std::cout << "Icon: " << curr_book.getIcon()<<"\n";
    // std::cout << "Blurb: " << curr_book.getBlurb()<<"\n";
    // std::cout << "Price: " << curr_book.getPrice()<<"\n";
    // std::cout << "ISBN: " << curr_book.getISBN()<<"\n";
    // std::cout << "Size of keywords: " << curr_book.getKeywords().size() <<"\n"<<"\n";

   }
  }

  void testPrintAllBooks(std::vector<Book> catalog){

    for (auto& curr_book : catalog){
    
      //std::cout << "Amount of keywords per book: " << curr_book.getKeywords().size() <<"\n";
      curr_book.print();
      //int icons = *curr_book.getIcon();
      //std::cout<<icons;
      

      // std::cout << "Title: " << curr_book.getTitle()<<"\n";
      // std::cout << "Author: " << curr_book.getAuthor()<<"\n";
      // std::cout << "Icon: " << curr_book.getIcon()<<"\n";
      // std::cout << "Blurb: " << curr_book.getBlurb()<<"\n";
      // std::cout << "Price: " << curr_book.getPrice()<<"\n";
      // std::cout << "ISBN: " << curr_book.getISBN()<<"\n";
      // std::cout << "Size of keywords: " << curr_book.getKeywords().size() <<"\n"<<"\n";

    }
  }

  void testPrintAllMovedBooks(std::vector<Book> catalog, std::vector<Book> cart) {

    moveAll("Spanish Literature", catalog, cart);
    std::cout<<"In Catalog"<<"\n"<<"\n";
    for (auto& curr_book : catalog){
    
      //std::cout << "Amount of keywords per book: " << curr_book.getKeywords().size() <<"\n";
      curr_book.print();
      //int icons = *curr_book.getIcon();
      //std::cout<<"icons";

      // std::cout << "Title: " << curr_book.getTitle()<<"\n";
      // std::cout << "Author: " << curr_book.getAuthor()<<"\n";
      // std::cout << "Icon: " << curr_book.getIcon()<<"\n";
      // std::cout << "Blurb: " << curr_book.getBlurb()<<"\n";
      // std::cout << "Price: " << curr_book.getPrice()<<"\n";
      // std::cout << "ISBN: " << curr_book.getISBN()<<"\n";
      // std::cout << "Size of keywords: " << curr_book.getKeywords().size() <<"\n"<<"\n";

    }

    for (auto& curr_book : cart){
      std::cout<<"In Cart"<<"\n"<<"\n";
      //std::cout << "Amount of keywords per book: " << curr_book.getKeywords().size() <<"\n";
      curr_book.print();
      //int icons = *curr_book.getIcon();
      //std::cout<<"icons";

      // std::cout << "Title: " << curr_book.getTitle()<<"\n";
      // std::cout << "Author: " << curr_book.getAuthor()<<"\n";
      // std::cout << "Icon: " << curr_book.getIcon()<<"\n";
      // std::cout << "Blurb: " << curr_book.getBlurb()<<"\n";
      // std::cout << "Price: " << curr_book.getPrice()<<"\n";
      // std::cout << "ISBN: " << curr_book.getISBN()<<"\n";
      // std::cout << "Size of keywords: " << curr_book.getKeywords().size() <<"\n"<<"\n";

    }
  }



int main(){
  
  std::vector<Book> catalog, cart;

  // open file
  //std::string filename = "1000bookInputFile.txt";
  std::string filename = "3bookInputFile.txt";
  std::ifstream fin(filename);

  // define expected format
  std::regex title("(Title: )(.*)");
  std::regex author("(Author: )(.*)");
  std::regex ISBN("(ISBN: )(.*)");
  std::regex icon("(Icon: )(.*)");
  std::regex price("(Price: \\$)(.*)");
  std::regex keywords("(Keywords: )(.*)");
  std::regex blurb("(Blurb: )(.*)");

  // declare helper variables for reading from file
  std::string line;
  std::smatch match;
  Book temp;

  // reads all 7 fields in each iteration and copies the value of each field into Book "temp"
  // pushes "temp" onto the back of "catalog" at the end of the iteration
  while (getline(fin,line)){

    // Title
    if (!std::regex_search(line, match, title)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setTitle(match[2]);

    // Author
    getline(fin,line);
    if (!std::regex_search(line, match, author)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setAuthor(match[2]);

    // ISBN
    getline(fin,line);
    if (!std::regex_search(line, match, ISBN)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setISBN(std::stoll(match[2]));

    // Icon
    getline(fin,line);
    if (!std::regex_search(line, match, icon)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream numstring(match[2]);
    int next_number;
    int* numarray = new int[80];
    for (int i=0 ; i<80; ++i){
      if (!(numstring >> next_number))
        std::cout << "Error reading file format" << std::endl;
      numarray[i] = next_number;
    }
    temp.setIcon(numarray);
    numarray = nullptr;

    // Price
    getline(fin,line);
    if (!std::regex_search(line, match, price)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setPrice(std::stof(match[2]));

    // Keywords
    getline(fin,line);
    if (!std::regex_search(line, match, keywords)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream keyword_string(match[2]);
    std::vector<std::string> keywords;
    while (keyword_string){
      std::string keyword;
      if (!getline(keyword_string >> std::ws, keyword, ',' )) break;
      keywords.push_back(keyword);
    }
    temp.setKeywords(keywords);

    // Blurb
    getline(fin,line);
    if (!std::regex_search(line, match, blurb)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setBlurb(match[2]);

    getline(fin,line);  // skip line between entries
    catalog.push_back(temp);

  }

  // write your test cases here
  //testMoveAll(cart);
  //testPrintAllBooks(catalog);
  testPrintAllMovedBooks(catalog,cart);
  
 

  return 0;
}