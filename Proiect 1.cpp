#include <iostream>
#include <string>
#include <vector>

#include <cmath>

using namespace std;

double (*radical) (double) = sqrt;
int n;

class Numar_Complex
{
public:
    Numar_Complex(double x=0, double y=0)
    {
        a=x;
        b=y;
    };
    Numar_Complex(const Numar_Complex &nc2)
    {
        a=nc2.a;
        b=nc2.b;

    }
    ~Numar_Complex()
    {
        n=0;
    }
    void modif_a(double x)
    {
        a=x;
    }
    double getA()
    {
        return a;
    }
    double getB()
    {
        return b;
    }
    void modif_b(double y)
    {
        b=y;
    }
    void print()
    {
        cout<<a<<", i*"<<a<<", -i*"<<a<<", "<<a<<"+i*"<<b<<", "<<a<<"-i*"<<b;
    }

    double modul()
    {
        return radical(a*a+b*b);
    }
    Numar_Complex sqrt ()
    {
        double mod=modul();
        double atn = atan(b/a);
        double sinus=sin(atn/2);
        double cosinus=cos(atn/2);
        return Numar_Complex(radical(mod)*cosinus, radical(mod)*sinus);
    }

    Numar_Complex operator+(const Numar_Complex& x)
    {
        Numar_Complex n;
        n.a=this->a+x.a;
        n.b=this->b+x.b;
        return n;
    }

    Numar_Complex operator-(const Numar_Complex& x)
    {
        Numar_Complex n;
        n.a=this->a-x.a;
        n.b=this->b-x.b;
        return n;
    }

   friend istream& operator>>(istream& in,Numar_Complex &nr)
{
    in>>nr.a>>nr.b;
    return in;
}

    Numar_Complex operator*(const Numar_Complex& x)
    {
        Numar_Complex n;
        n.a=this->a*x.a-this->b*x.b;
        n.b=this->a*x.b-this->b*x.a;
        return n;
    }
    Numar_Complex operator/(const Numar_Complex& x)
    {
        Numar_Complex n;
        double a1,a2;
        double b1,b2;
        a1=this->a;
        a2=x.a;
        b1=this->b;
        b2=x.b;
        n.a=(a1*a2+b1*b2)/(a2*a2+b2*b2);
        n.b=(a2*b1-a1*b2)/(a2*a2+b2*b2);

        return n;
    }
    void EcComplex(Numar_Complex x1, Numar_Complex x2, Numar_Complex x3,Numar_Complex &x_prim,Numar_Complex &x_secund)
    {
        Numar_Complex var  (4,4);
        Numar_Complex delta(x2*x2-(var*x1*x3));
        var.modif_a(-1);
        var.modif_b(-1);
        x2=x2*var;
        var.modif_a(2);
        var.modif_b(2);
        x1=x1*var;
        x_prim = x2 + delta.sqrt() /x1;
        x_secund = x2 - delta.sqrt() /x1;

    }


private:
    double a;
    double b;

};



ostream& operator<<(ostream& out,Numar_Complex nr)
{
    out<<nr.getA()<<"+" << nr.getB() << "i ";
    return out;
}





int main()
{
    int m=3;

    Numar_Complex v[1000];

    cout<<"Introduceti coeficientii complecsi ai ecuatiei  ax^2 + bx + c :" <<endl<<endl;

    for(int i=0;i<m;i++)
    {

        cout<<"Introduceti valoarea coeficientului "<<char(97+i)<<" sub forma: {parte reala} {parte imaginara}  "<<endl; ;
        cin>>v[i];


    }

    cout<<"Coeficientii alesi sunt: ";
    for(int i=0;i<m;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v[0].EcComplex(v[0],v[1],v[2],v[3],v[4]);
    cout<<"Solutiile ecuatiei sunt : " <<v[3]<<" si "<<v[4];








}
