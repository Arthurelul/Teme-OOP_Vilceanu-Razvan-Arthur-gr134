#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
enum MASINA {MINI, MICA, COMPACTA, MONOVOLUME};
ostream& operator<< (ostream& out, MASINA m) {
    switch (m) {
    case MINI:
        out << "MINI";
        break;
    case MICA:
        out << "MICA";
        break;
    case COMPACTA:
        out << "COMPACTA";
        break;
    case MONOVOLUME:
        out << "MONOVOLUME";
        break;
    }
    return out;
}
int crt_year, month;
class Automobil {
private:
    MASINA tip;
    double lungime;
    int nrPers;
    int year;
    bool nou;
    double pret;
    double discount;
public:
    Automobil(MASINA tip, double lungime, bool nou = false, int nrPers = 1, double pret = 10000, double discount = 0, int anFab = 1999) {
        if (tip == MONOVOLUME) {
            this->nou = nou;
            if (nou == false) {
                // doar daca masina este sh atunci are discount
                this->discount = discount;
            }
            else {
                this->discount = 0;
            }
        } else {
            this->nou = false;
            this->discount = 0;
        }
        this->year = anFab;
        this->nrPers = nrPers;
        this->pret = pret;
        this->tip = tip;
        this->lungime = lungime;
    }
    MASINA getTip() {
        return this->tip;
    }
    double getBasePrice() {
        return this->pret;
    }
    double getPrice() {
        cout << this->discount << " " << this->year << endl;
        double finalPrice = (crt_year - this->year)*this->discount;
        if (month == 7 || month == 6 || month == 8) {
            // daca este luna de vara, atunci se reduce pretul cu 10%
            finalPrice += 0.1;
        }
        finalPrice = this->pret * (1 - finalPrice);
        if (finalPrice > 0.1 and finalPrice > 0) {
            // cazul in care e fabricat in 2020 sau discount-ul este 0
            return finalPrice;
        }
        else {
            if (finalPrice > 0) {
                return this->getBasePrice();
            }
            else {
                return 0;
            }
        }
    }
    bool IsNew() {
        return this->nou;
    }
    int getPers() {
        return this->nrPers;
    }
};
void addToTheSet(Automobil a, set<pair<MASINA, bool>> &s) {
    pair<MASINA, bool> p;
    p.first = a.getTip();
    p.second = a.IsNew();
    s.insert(p);
}
template <typename Y, typename T>
class Vanzare {
private:
    T peStoc;
    T vandute;
    int v, s;
public:
    Vanzare(T stocNou, T vanduteMomentan) {
        this->peStoc = stocNou;
        this->s = stocNou.size();
        this->vandute = vanduteMomentan;
        this->v = vanduteMomentan.size();
    }

    void Catalog (MASINA tip, bool nou = false) {
        string stare;
        if (nou == true) {
            stare = "noi ";
        }
        else {
            stare = "second hand ";
        }
        cout << "Acestea sunt masinile " << stare << "de tipul " << tip << endl;
        int index = 0;
        for (auto automobile: peStoc) {
            if (automobile.first == tip && automobile.second == nou) {
                cout <<"cod = "<< index << ": " << automobile.first << endl;
            }
            index++;
        }
    }
    void Tot() {
        cout << "Acestea sunt masinile pe stoc din parcul auto!\n";
        int index = 0;
        for (auto automobile: peStoc) {
            cout << "cod = " << index << ": "<< automobile.first << endl;
            index++;
        }
    }
    void Vinde(int cod) {
        this->vandute.push_back(this->peStoc[cod]);
        {
            this->peStoc[cod] = this->peStoc[this->peStoc.size() -1];
            this->peStoc.pop_back();
        }
        this->v++;
        this->s--;
    }
    int Stoc() {
        return this->s;
    }
    int Vandute() {
        return this->v;
    }
    void MasinaNoua(Y masina_noua) {
        this->peStoc.push_back(masina_noua);
        this->peStoc.shrink_to_fit();
        this->s++;
    }
    void Raport() {
        cout << "Exista " << this->Stoc() << " masini pe stoc, iar compania a vandut " << this->Vandute() << " masini pana in momentul de fata!\n";
    }
    void MasiniVandute() {
        cout << "Pana acum s-au vandut urmatoarele automobile!\n";
        int index = 0;
        for (auto automobile: this->vandute) {
            cout << "cod= " << index << ": " << automobile.first << "\n";
        }
    }
};
void operator-= (Vanzare<pair<MASINA, bool>, vector<pair<MASINA, bool>>> &v, int cod) {
    v.Vinde(cod);
}


void Test();
int main()
{
    function<void()> setTime = [&](){
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        crt_year = timePtr->tm_year + 1900;
        month = timePtr->tm_mon + 1;
    };
    setTime();
    //cout << year << " " << month;

    Test();
    return 0;
}
void Test()
{
    //creare automobile
    Automobil a0 (MINI, 3.4, false, 2, 1000);
    Automobil a1 (MONOVOLUME, 10, false, 5, 100000, 0.01, 1953);
    Automobil a2 (MINI, 4.085);
    Automobil a3 (MINI, 3.985);
    Automobil a4 (MINI, 2.95);
    Automobil a5 (MONOVOLUME, 9.59, true, 5, 20000, 0.010, 1995);


    {
        //creare seturi
        set<pair<MASINA, bool>> s;
        set<pair<MASINA, bool>> v;

        addToTheSet(a0, s);
        addToTheSet(a1, s);
        addToTheSet(a2, s);
        addToTheSet(a3, s);
        addToTheSet(a4, s);
        addToTheSet(a5, s);


        //folosire set
        Vanzare<pair<MASINA, bool>, set<pair<MASINA, bool>>> CatalogAutomobile(s, v);

        CatalogAutomobile.Tot();
        CatalogAutomobile.Catalog(MONOVOLUME, false);


    }

    {
        //folosire vector in loc de set
        vector<pair<MASINA, bool>> stoc;
        vector<pair<MASINA, bool>> vandute;

        stoc.push_back(pair<MASINA, bool> (a0.getTip(), a0.IsNew()));
        stoc.push_back(pair<MASINA, bool> (a1.getTip(), a1.IsNew()));
        stoc.push_back(pair<MASINA, bool> (a2.getTip(), a2.IsNew()));
        stoc.push_back(pair<MASINA, bool> (a3.getTip(), a3.IsNew()));
        stoc.push_back(pair<MASINA, bool> (a4.getTip(), a4.IsNew()));
        stoc.push_back(pair<MASINA, bool> (a5.getTip(), a5.IsNew()));


        stoc.shrink_to_fit();

        vandute.shrink_to_fit();

        cout << stoc.size() << " " << vandute.size() << endl;

        Vanzare<pair<MASINA, bool>, vector<pair<MASINA, bool>>> CatAuto(stoc, vandute);
        CatAuto.Tot();
        CatAuto.Raport();
        CatAuto.Vinde(2);
        CatAuto.Vinde(0);
        CatAuto -= 0;
        Automobil a(MINI, 3.60, false, 2, 1000, 0, 2005);
        CatAuto.MasinaNoua(pair<MASINA, bool> (a.getTip(), a.IsNew()));
        CatAuto.Raport();
        CatAuto.MasiniVandute();
        CatAuto.Catalog(MONOVOLUME, false);
        CatAuto.Tot();

    }

    /* pentru a functiona corect si a mai adauga cateva facilitati se poate realiza structura
    struct pereche {
        MASINA first;
        bool second;
        double price;
        int year;.... ;
    };
    */
    return;
}

