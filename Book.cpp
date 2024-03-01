#include "Book.hpp"
#include <iterator>
    //how to do we move all the members of a vector
    //make a new vector, go through all the items in the orinal item and then delete them
    // to copy a  pointer A*  to B*
    //B* = A*
    //A* = nullptr
    //dont delete A* 
    // write and document all methods in this file.
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr; // check if this is correct
        price_= 0.0;
        keywords_ = { "" };
        blurb_ = "";
        //looks good
    }

    Book::~Book()
    {
        //std::cout<< "\n"<<"Destructor Called on " << title_ <<"\n";
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

        keywords_ = std::move(rhs.keywords_);
        // for (auto keyword : rhs.keywords_){
        //     keywords_.push_back(keyword);
        // }

        //Do I need to write a loop here?
        //keywords_ = rhs.keywords_;
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
        icon_ = icon;
        //return icon_;
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
        std::cout<< "Icon: " << *icon_<< "\n"; //this needs to be fixed
        std::cout<< "Price: " << price_<< "\n";
        std::cout<< "Keywords: ";
        bool first_item =true;
        for(std::string word : keywords_){
            first_item ? std::cout<<"" : std::cout<<", "; 
            std::cout<< word;
            first_item = false;
        }
        std::cout<< "\n";
        std::cout<< "Blurb: " << blurb_ << "\n";
        std::cout<<"\n";


    }