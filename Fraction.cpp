class Fraction{
    private:
    int numerator;
    int denominator;
    
    public:

    Fraction(){   
    }
    
    Fraction(int numerator,int denominator){
        this -> numerator=numerator;  //using this is like saying ki class wale numerator mein yeh argument copy kr do
        this -> denominator=denominator;
    }
    int getNumerator() const{
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
    void setNumerator(int n){
        numerator=n;
    }
    void setDenominator(int d){
        denominator=d;
    }
    void print() const{
        // cout<<this ->numerator<<"/"<<this ->denominator<<endl;  //both formats work using this is optional because there is no argument with the same name
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        int j=min(this-> numerator,this->denominator);
        for(int i=1;i<=j;i++){
            if(this->numerator%i==0 and this-> denominator%i==0){
                gcd=i;
            }
        }
        this -> numerator = this->numerator/gcd;
        this -> denominator= this ->denominator/gcd;
    }
    void add(Fraction const &f2){
        int lcm=denominator*f2.denominator;      //whenever you pass argument remember to pass const reference 
        int x=f2.denominator*numerator;
        int y=f2.numerator*denominator;
        numerator=x+y;
        denominator=lcm;
        simplify();
    }
    void multiply(Fraction const &f2){
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;

        simplify();
    }
    //operator overloading
    Fraction add1(Fraction const &f2){
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=x*numerator +(y*f2.numerator);
        Fraction fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }
    Fraction operator+(Fraction const &f2) const{
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=x*numerator +(y*f2.numerator);
        Fraction fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }
    Fraction operator*(Fraction const &f2) const{
        int n=numerator*f2.numerator;
        int d=denominator*f2.denominator;
        Fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }
    bool operator==(Fraction const &f2) const{
        return (numerator ==f2.numerator && denominator==f2.denominator);
    }
    //Pre-increment
    Fraction& operator++(){
        numerator=numerator+denominator;
        simplify();
        return *this;
    }
    //Post-increment
    Fraction operator++(int){
        int n=numerator;
        int d=denominator;
        numerator=numerator+denominator;
        simplify();
        Fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }
    Fraction& operator+=(Fraction const &f2){
        int n=(numerator*f2.denominator)+(denominator*f2.numerator);
        int d=denominator*f2.denominator;
        numerator=n;
        denominator=d;
        simplify();
        return *this;
    }

}; 