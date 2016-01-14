//
//  main.cpp
//  CPP11
//
//  Created by vikas chauhan on 1/13/16.
//  Copyright © 2016 vikas chauhan. All rights reserved.
//

#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>

class Base {
    public :
    Base():name("Bil"),age(23),sal(1000000){std::cout<< " Constructor " << std::endl;}
    ~Base(){std::cout<< " destructor " << std::endl;}
    void base() { std::cout << " Calling base" ; }
    friend std::ostream& operator<<(std::ostream& os , Base const & op)
    {
        return os << "Item {" << op.name << " " << op.age << " " << op.sal << "}";
    }
    friend std::ostream& operator<<(std::ostream& os , std::shared_ptr<Base> op)
    {
        return os << "Item {" << op->name << " " << op->age << " " << op->sal << "}";
    }
    friend std::ostream& operator<<(std::ostream& os , std::unique_ptr<Base>& op)
    {
        return os << "Item {" << op->name << " " << op->age << " " << op->sal << "}";
    }
private:
    std::string name;
    int         age;
    int         sal;
    
};

void foo(std::shared_ptr<Base> fBp){
    std::cout << " I am in foo "<< fBp.use_count()<<" \n" ;
    fBp.use_count();
    fBp->base();
}

int main(int argc, const char * argv[]) {
    // insert code here...
   // std::unique_ptr<Base[]> bP(new Base[5]);

    
    std::unique_ptr<Base> bP1(new Base());
    //bP->base();
    Base sp1;
    std::shared_ptr<Base> sp = std::make_shared<Base>();
    std::cout<<bP1;
    {
   
    std::shared_ptr<Base> sp1 = sp;
        foo(sp1);
    std::cout << sp.use_count() << "\n";
    std::cout << sp1.use_count() << "\n";

    }
    if(sp.unique()) { std::cout << "I am so lonely" << std::endl ;}
    std::cout << sp.use_count() << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
