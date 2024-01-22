class Student{
    public:
    int age;
    const int rollNumber;
    int &x;
    Student(int r,int a): rollNumber(r),age(a),x(this->age){      
    }

};