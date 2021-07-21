#include <iostream>
using namespace std;
//function oberloading
class overloading {
    public :
    void sum(int x,int y);
    void sum(double x,double y);
    void sum(double x ,int y);
};
//function overriding
class overriding{
    public:
    void diff(int x,int y);
};
class overridingchild : public overriding {
    public :
    void diff(int x,int y);
};
// . :: ?: sizeof cannot be overloaded
//operator overloading
class Example {
    public:
    int a,b;
    void getvalue()
    {
        cin>>a>>b;
    }
    void operator-(){
        a=-a;
        b=-b;
    }
    void display()
    {
        cout<<a<<" "<<b<<endl;
    }
    /* Example obj;
	obj.getvalue();
	obj.display();
	-obj;
	obj.display();
	cout<<obj.a<<endl; */
};
//this keyword - current object parameter to another method , current class instance variable
class useofthis {
    public :
    int id;
    string str;
    useofthis(int id ,string name)
    {
        this->id=id;
        str=name;
    }
};
class enscapsulation{
    private : int emp_id;
    public :
    void set_id(int id)
    {
        emp_id=id;
    }
    void display()
    {
        cout<<emp_id<<endl;
    }
    /* enscapsulation e;
	e.set_id(40);
	e.display(); */
};
class datashadowing{
    public : 
     int id=0;
     string name="abc";
     datashadowing(int id,string name)
     {
        id=id;
        name=name;
     }
     void display()
     {
         cout<<id<<" ";
         cout<<name<<endl;
     }
  
  /* datashadowing d(32,"rana");
    d.display(); */
};
//abstract class
class abstractclass{
    public :
    virtual void display()=0;
    virtual void fun()
    {
        
    }
};
class childofabstractclass : public abstractclass{
  
  void display(){
      
  }  
  /* // this will give error ..... abstractclass* p=new abstractclass(); 
	abstractclass *p;
	childofabstractclass* c;
	p=c; */
};

class sample{
    public :
    static int count;
    static int newcount;
    sample()
    {
       // cout<<"New Object Constructed"<<endl;;
        count++;
    }
    ~sample()
    {
      //  cout<<"Object destructed"<<endl;
        count--;
    }
   void* operator new (size_t sz)
   {
       newcount++;
   }
   void operator delete(void* p)
   {
       cout<<"Overloaded delete"<<endl;
      --newcount;
       //delete p;
   }
    /*
    	sample a,b,c,d,e; //local--->stack
	
	sample* x=(sample*)malloc(sizeof(sample));
	sample *mp=new sample(); //dynamic --> heap
	sample *fd=new sample();
	free(mp);
	delete mp;
	
	cout<<sample::count<<endl;
	cout<<sample::newcount<<endl; */
};
int sample :: count=0;
int sample :: newcount=0;
class vfb{
    public :
    virtual void print(){cout<<"Base class"<<endl;}
};
class vfc : public vfb{
    public :
    void print(){cout<<"derived class"<<endl;}
};
/* 
	vfb b;
	vfc c;
	b.print();
	c.print();

    vfb *ptr;
    ptr=&c;
    ptr->print(); */
    
/*double division(int a,int b) 
{
    if(b==0)
    throw "division by zero";
    return a/b;
}
int main() {
	
	try{
	    int z=division(5,0);
	    cout<<z<<endl;
	}
	catch (const char* msg){
	    cout<<msg<<endl;
	    
	}
	return 0;
}*/
int main()
{
    
    return 0;
}