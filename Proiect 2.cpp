#include <iostream>
#include <string>
#include <vector>

#include <cmath>

using namespace std;




class Complex
{
public:
    Complex(double x=0, double y=0)
    {
        a=x;
        b=y;
    }
    Complex(const Complex &nc2)
    {
        a=nc2.a;
        b=nc2.b;

    }
    ~Complex()
    {
        a=0;
        b=0;
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
    void afis()
    {
        cout<<a<<" "<<b<<"i ";
    }




    friend istream& operator>>(istream& in,Complex &nr)
    {
        in>>nr.a>>nr.b;
        return in;
    }

    friend ostream& operator<<(ostream& out,Complex nr)
    {
        out<<nr.a<<"+" << nr.b << "i ";
        return out;
    }

    void operator=(const Complex& x)
    {
        this->a=x.a;
        this->b=x.b;

    }

protected:
    double a;
    double b;

};

class Vector
{
public:
    Vector(int idim=0)
    {
        v=new Complex[idim];
        maxDim=idim;
        dim=0;
    }


    void adauga(Complex x, int poz)
    {
        dim+=1;
        for(int i=dim; i>poz; i--)
            v[i]=v[i-1];
        v[poz]=x;


    }

    void afisare()
    {
        for(int i=0; i<dim; i++)
            {
                cout<<v[i]<<" ";
            }
    }
    void stergePoz(int x)
    {
        for(int i=x; i<dim; i++)
            {
                v[i]=v[i+1];
            }
            dim--;
    }



protected:
    int maxDim;
    int dim;
    Complex *v;



};

class Coada : public Vector, public Complex
{
    int fata;
    int spate;
    int cont;


public:
    Coada(int idim)
    {
        dim=idim;
        fata=0;
        spate=-1;
        cont = 0;

    }
    ~Coada()
    {
        delete[]v;
    }
    void afis()
    {
        for (int i=0; i<cont; i++)
            {
                cout<<v[(fata+i)%dim]<<" ";
            }
            cout<<endl;
    }

    int size()
    {
        return cont;
    }
    bool plin()
    {
        return (cont==dim);
    }
    bool gol()
    {
        return (cont==0);
    }
    Complex verif()
    {
        return v[fata];
    }
    void pop()
    {
        try
            {
                if (gol())
                    throw "Coada este goala. Nu se poate executa operatia 'pop().'";


                cout<<"Elementul "<<v[fata]<< " a fost sters din coada"<<endl;
                fata=(fata+1)%dim;
                cont--;



            }
        catch (const char *e)
            {
                cout<<"S-a intalnit exceptia : "<<e<<endl;;


            }


    }



    void push(Complex x)
    {
        try
            {
                if (plin()) throw "Capacitatea maxima a cozii a fost atinsa";

                {
                    spate=(spate+1)%dim;
                    v[spate]=x;
                    cont++;
                }
            }
        catch (const char *e)
            {
                cout<<"S-a intalnit exceptia: "<<e;
            }
    }

    string checkIm()
    {
        try{
            if (gol())
                throw "Coada este goala";
        for (int i=0; i<cont; i++)
            {
                if (v[(spate+i)%dim].getA()!=0) return "Coada nu este pur imaginara";
            }
        return "Coada este pur imaginara";

    }
        catch (const char *e)
        {
            return e;
        }
    }


};

class Stiva : public Vector,public Complex
{

    int varf;


public:
    Stiva (int idim)
    {
        dim=idim;
        varf=0;

    }
    ~Stiva()
    {
        delete[] v;
    }
    void afis()
    {
        for(int i=0; i<varf; i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }

    int size()
    {
        return varf;
    }
    bool plin()
    {
        return (size()==dim);

    }

    bool gol()
    {
        return (size()==0);
    }
    void push(Complex x)
    {
        try
            {
                if (plin()) throw "Stiva a ajuns la capacitatea maxima";

                v[varf]=x;
                varf++;


            }
        catch (const char *e)
            {
                cout<<"S-a intalnit exceptia: "<<e;
            }
    }
    void verif()
    {
         try
            {
                if (gol())
                    throw "Stiva este goala";


                cout<< v[varf]<<endl;
            }
            catch(const char *e)
            {
                cout<<"S-a intalnit exceptia: "<<e<<endl;;

            }

    }
    void pop()
    {
        try
            {
                if (gol())
                    throw "Stiva este goala";


                varf--;
                cout<<"Elementul "<< v[varf+1]<<" a fost extras"<<endl;;
            }
        catch(const char *e)
            {
                cout<<"S-a intalnit exceptia: "<<e<<endl;;

            }
    }
    string checkIm()
    {
        try
            {
                if (gol())
                    throw "Stiva este goala";


                for (int i=0; i<varf; i++)
            {
                if (v[i].getA()!=0) return "Stiva nu este pur imaginara";
            }
            return "Stiva este pur imaginara";
            }
            catch(const char *e)
            {
                return e;
            }




    }


};

void CazVector()
{
    int dim,poz;
    Complex x;
    cout<<"Introduceti dimensiunea vectorului: ";
    cin>>dim;
    Vector v(dim);
    cout<<"Operatii disponibile: "<<endl;
    int caz;
    bool t=true;
    while (t)
        {

            cout<<"1 -Afisare vector"<<endl<<"2 -Adauga element la pozitia x"<<endl<<"3 -Sterge element de pe pozitia x"<<endl;
            cin>>caz;
            switch (caz)
                {
                case 0:
                    t=false;
                    break;
                case 1:
                    v.afisare();
                    break;
                case 2:
                    cout<<"Introduceti numarul complex x sub forma {parte reala} {parte fractionala}"<<endl;
                    cin>>x;
                    cout<<"Introduceti pozitia "<<endl;
                    cin>>poz;
                    v.adauga(x,poz);
                    break;
                case 3:
                    cout<<"Introduceti pozitia elementului sters "<<endl;
                    cin>>poz;
                    v.stergePoz(poz);
                    break;
                default:
                    cout<<"Input incorect!"<<endl;



                }
            cout<<"Pentru a opri programul introduceti '0' "<<endl;
        }



}

void CazCoada()
{
    int dim;
    Complex x;
    cout<<"Introduceti dimensiunea cozii: ";
    cin>>dim;
    Coada v(dim);
    cout<<"Operatii disponibile: "<<endl;
    int caz;
    bool t=true;
    while (t)
        {

            cout<<"1 -Afisare coada"<<endl<<"2 -push (x) -> Introduce elementul x in coada"<<endl<<"3 -pop ()-> Extrage element din coada"<<endl<<"4 -Verifica daca coada este pur imaginara"<<endl;
            cin>>caz;
            switch (caz)
                {
                case 0:
                    t=false;
                    break;
                case 1:
                    v.afis();
                    break;
                case 2:
                    cout<<"Introduceti numarul complex x sub forma {parte reala} {parte fractionala}"<<endl;
                    cin>>x;
                    v.push(x);
                    break;
                case 3:
                    v.pop();
                    break;
                case 4:
                    cout<<v.checkIm()<<endl;;
                    break;
                default:
                    cout<<"Input incorect!"<<endl;



                }
            cout<<"Pentru a opri programul introduceti '0' "<<endl;
        }



}

void CazStiva()
{
    int dim;
    Complex x;
    cout<<"Introduceti dimensiunea stivei: ";
    cin>>dim;
    Stiva v(dim);
    cout<<"Operatii disponibile: "<<endl;
    int caz;
    bool t=true;
    while (t)
        {

            cout<<"1 -Afisare stiva"<<endl<<"2 -push (x) -> Introduce elementul x in stiva"<<endl<<"3 -pop ()-> Extrage element din stiva"<<endl<<"4 -peek ()-> Citeste ultimul element din stiva"<<endl<<"5 -Verifica daca stiva este pur imaginara"<<endl;  ;
            cin>>caz;
            switch (caz)
                {
                case 0:
                    t=false;
                    break;
                case 1:
                    v.afis();
                    break;
                case 2:
                    cout<<"Introduceti numarul complex x sub forma {parte reala} {parte fractionala}"<<endl;
                    cin>>x;
                    v.push(x);
                    break;
                case 3:
                    v.pop();
                    break;
                case 4:
                    v.verif();
                    break;
                case 5:
                    cout<<v.checkIm()<<endl;;
                    break;
                default:
                    cout<<"Input incorect!"<<endl;



                }
            cout<<"Pentru a opri programul introduceti '0' "<<endl;
        }



}

int main()
{
    int caz;
    while (true)
        {

            cout<<"Introduceti '1' pentru Vector, '2' pentru Coada sau '3' pentru Stiva"<<endl;
            cin>>caz;
            switch (caz)
                {
                case 1:
                    CazVector();
                    return 0;
                case 2:
                    CazCoada();
                    return 0;
                case 3:
                    CazStiva();
                    break;
                    return 0;
                default:
                    cout<<"Input incorect!"<<endl;



                }
        }













}
