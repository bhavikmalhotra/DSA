class student{
    //class by defalut private hoti h mtlb class ke bahar not accessible
    int pvt;
    public:
        int rollNo;
        int age;

        student(){
            cout<<"Default Constructort called"<<endl;
        }

        student(int n){
            cout<<"Parameterised construator called"<<endl;
            rollNo = n;
        }

        student(int n,int a){
            cout<<"Parameterised construator called"<<endl;
            age = a;
            rollNo = n;
        }

        ~student(){
            cout<<"destructor called"<<endl;
        }
        
        
        void display(){
            cout<<rollNo<<" "<<age<<endl;
        }
};