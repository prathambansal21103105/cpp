class Student{
    public:
    int age;
    int const rollNumber;
    int &x; //age reference variables

    Student(int r, int age): rollNumber(r),age(age),x(this -> age){ //initialization list
    }
};