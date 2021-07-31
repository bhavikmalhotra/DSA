#include <cstring>
class shallow_deep
{
private:
    int age;
    
public:
    char *name;
    shallow_deep(int age,char *name){
        this -> age = age;

        //shallow copy
        //this -> name = name;         //yaha par name ka address pass hota h toh jp change yaha karte h vo main wale name mei bhi reflect hoga
                                    // isiliye isse shallow copy bolte h
        
        //deep copy
        this -> name = new char[strlen(name)+1];    //+1 for null char
        strcpy(this -> name, name);

    }

    shallow_deep(shallow_deep const &s){  //yaha par ek inifinite loop create ho jaega vo avoid karne ke liye we used pass by ref cop cons ek dusre ko call karta rahega
                                          //ie why infinite loop create hoga const se bas read access milegi
        this -> age = s.age;

        //defalut mei shallow copy hota h cope constructor mei
        //this ->name = name;

        //shallow copy karnege kyuki naya array banana hh
        this -> name = new char[strlen(s.name)+1];
        strcpy(this -> name, s.name);


    }

    void display(){
        cout<< age <<" "<<name<<endl;
    }
    
};


