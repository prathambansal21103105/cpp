class Student{
    public:
    int rollNumber;
    private:
    int age;
    int dob;
    public:
    //Default constructor
    Student(){
        cout<<"Constructor 1 called"<<endl;
    }
    //Parameterized Constructor
    Student(int r){
        cout<<"Constructor 2 called"<<endl;
        this -> rollNumber=r;
    }
    Student(int a,int r){
        cout<<"this :"<<this<<endl;
        cout<<"Constructor 3 called"<<endl;
        this -> age=a;
        this -> rollNumber=r;
    }
    void display(){
        cout<<age<<" "<<rollNumber<<endl;
    }
    int getage(){
        return age;
    }
    void setage(int a,int password){
        if(password!=123){
            return;
        }
        if(a<0){
            return;
        }
        age=a;
    }
    public:
    ~Student(){
        cout<<"Destructor called !"<<endl;
    }
};