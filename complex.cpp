class ComplexNumbers{
    private:
    int r;
    int i;
    public:
    ComplexNumbers(int r,int i){
        this -> r=r;
        this -> i=i;
    }
    void plus(ComplexNumbers const &c2){
        r=r+c2.r;
        i=i+c2.i;
    }
    void multiply(ComplexNumbers const &c2){
        int ar=(r*c2.r)-(i*c2.i);
        int ai=(r*c2.i)+(i*c2.r);
        r=ar;
        i=ai;
    }
    void print(){
        cout<<r<<" +"<<" i"<<i<<endl;
    }
};