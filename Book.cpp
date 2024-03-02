/*

CSCI 335 Spring 2024
Project 1 - Move Semantics
Contributor: Nathan Vazquez
2/2024

*/

#include "Book.hpp"
#include <iterator>
#include <bits/stdc++.h>

    // write and document all methods in this file.
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

    Book::~Book()
    {
        //not sure what to put here
    }

    Book::Book(const Book& rhs)
    {
        //Copy Constructor
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_; // check if this is correct
        price_= rhs.price_;

        //keywords_ = std::move(rhs.keywords_);
        // for (auto keyword : rhs.keywords_){
        //      keywords_ = std::move(keyword);
        // }

        //Do I need to write a loop here?
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }

    Book& Book::operator=(const Book& rhs)
    {   
        //copy assignment operator
        Book* newbook = new Book(rhs);
        return *newbook;
    }

    Book::Book(Book&& rhs)
    :title_{rhs.title_},author_{rhs.author_},ISBN_{rhs.ISBN_},icon_{rhs.icon_},price_{rhs.price_},keywords_{rhs.keywords_},blurb_{rhs.blurb_}
    {
        keywords_ = std::move(rhs.keywords_);
        
        //move contructor          
    }

    Book& Book::operator=(Book&& rhs)
    {  
        //move assignment operator
        //Book newbook;

        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_; // check if this is correct
        price_= rhs.price_;

        // for (auto keyword : rhs.keywords_){
        //     keywords_.push_back(keyword);
        // }
        keywords_ = std::move(rhs.keywords_);

        //keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
        //-------------------------------
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr; // check if this is correct
        price_= 0.0;
        keywords_ = { "" };
        blurb_ = "";

        return *this;
    }

    const std::string& Book::getTitle() const
    {
        //std::cout<<title_;
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        //std::cout<<author_;
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        //std::cout<<ISBN_;
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        if(icon){ 
            icon_= new int[80];


            for (int i=0; i< 80; i++){
                if(icon[i] >=0 && icon_[i] <= 255){
                    icon_[i] = icon[i];
                }
            }
        }else {
            icon_ = nullptr;

        //return icon_;
        }
    }

    float Book::getPrice() const
    {
        //std::cout<<price_;
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }   

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        //std::cout<<blurb_;
        return blurb_;
    
    }

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
            if(i!=79){
            std::cout<<icon_[i]<< " "; 
            }else{
                std::cout<<icon_[i];
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