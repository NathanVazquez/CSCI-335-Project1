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

#include "Book.hpp"
#include <iterator>
//#include <bits/stdc++.h>

    /** 
        @post:    book constructor
    **/
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr; // check if this is correct
        price_= 0.0;
        //keywords_;
        blurb_ = "";
        //looks good
    }

    /** 
        @post:    book destructor
    **/
    Book::~Book()
    {
        //not sure what to put here
    }

    /** 
        @post:    book copy constructor
    **/
    Book::Book(const Book& rhs)
    {
        //Copy Constructor
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        //icon_ = rhs.icon_; // check if this is correct
        if(rhs.icon_ != nullptr){
            icon_ = new int[80];
            for (int i = 0; i< 80;i++){
                icon_[i] = rhs.icon_[i];
            }
        }
        price_= rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }

    /** 
        @post:    book copy assignment operator
    **/
    Book& Book::operator=(const Book& rhs)
    {   
        //copy assignment operator
        //Book* newbook = new Book(rhs);
        if(this != &rhs){
                    title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        if (icon_ != nullptr)
            {
                delete[] icon_;
                icon_ = nullptr;
            }
            if (rhs.icon_ != nullptr) 
            {
                icon_ = new int[80];
                for (int i = 0; i < 80; ++i) 
                {
                    icon_[i] = rhs.icon_[i];
                }           
            }
        
        price_= rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
        }
        return *this;
    }

    /** 
        @post:    book move contructor
    **/
    Book::Book(Book&& rhs)
    {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        icon_ = std::move(rhs.icon_);
        price_ = std::move(rhs.price_);
        blurb_ = std::move(rhs.blurb_);

        keywords_ = std::move(rhs.keywords_);
        rhs.icon_=nullptr;
        //move contructor          
    }

    /** 
        @post:    book move assignment operator
    **/
    Book& Book::operator=(Book&& rhs)
    {  


               title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        icon_ = std::move(rhs.icon_);
        if (icon_ != nullptr){
            delete[] icon_;
            icon_ = nullptr;
        }
        price_ = std::move(rhs.price_);
        blurb_ = std::move(rhs.blurb_);

        keywords_ = std::move(rhs.keywords_);
        rhs.icon_=nullptr;
        

        return *this;
    }

    /**
        @return: returns book title
    */
    const std::string& Book::getTitle() const
    {
        //std::cout<<title_;
        return title_;
    }
    /**
        @param:  string representing a book title
        @post: Title of book is changed
    */
    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    /**
        @return:  author name as string
    */
    const std::string& Book::getAuthor() const
    {
        //std::cout<<author_;
        return author_;
    }

    /**
        @param:  string representing a book author
        @post: author string is changed
    */
    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    /**
        @return: long long int representing book ISBN
    */
    long long int Book::getISBN() const
    {
        //std::cout<<ISBN_;
        return ISBN_;
    }

    /**
        @param:  string representing a book ISBN
        @post: books ISBN is changed to what the parameter specified
    */
    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    /**
        @return:  return the array of icon
    */
    const int* Book::getIcon() const
    {
        return icon_;
    }

    /**
        @param:  a pointer to an array with a bitmp
        @post: icon pointer is changed to point to the new array
    */
    void Book::setIcon(int* icon)
    {
        icon_ = icon;
    }

    /**
        @return:  return price of the book
    */
    float Book::getPrice() const
    {
        return price_;
    }

    /**
        @param:  a float number representing a book price
        @post: price of book is changed to arg
    */
    void Book::setPrice(float price)
    {
        price_ = price;
    }

    /**
        @return:  return a vector of strings that are the keywords of the book
    */
    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }   

    /**
        @param:  a vector of strings
        @post: the keywords of the book are replaced with the keywords arg
    */
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }


    const std::string& Book::getBlurb() const
    {
        //std::cout<<blurb_;
        return blurb_;
    
    }

    /**
        @param:  sblurb for book
        @post: blurb is changed
    */
    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ =blurb;
    }

    void Book::print() const
    {
        std::cout<< "Title: "<<title_ <<"\n";
        std::cout<< "Author: " << author_<< "\n"; 
        std::cout<< "ISBN: " << ISBN_<< "\n";
        std::cout<< "Icon: ";
        //std::string curr_icon;
        //int *icon_ptr = icon_;
        for (int i = 0 ; i<80;i++){
            //curr_icon+= std::to_string(*icon_ptr) + " ";
            //icon_ptr++;
            std::cout<<icon_[i];
            if(i<79){
            std::cout<< " "; 
            }
           
        
        }

        //curr_icon = curr_icon.substr(0,curr_icon.size()-1);
        
        //std::cout<< "Icon: " << curr_icon<< "\n"; //this needs to be fixed
        std::cout<<std::endl;
        std::cout<<"Price: $";
        std::cout<< std::fixed << std::setprecision(2) <<price_<< "\n";

        std::cout<< "Keywords: ";
        bool first_item =true;
        for(std::string keyword : keywords_){
            first_item ? std::cout<<"" : std::cout<<", "; 
            std::cout<< keyword;
            first_item = false;
        }
        std::cout<< "\n";

        std::cout<< "Blurb: " << blurb_ << "\n";
        std::cout<<"\n";
    }