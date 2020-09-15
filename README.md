# Teme OOP_Vilceanu-Razvan-Arthur,gr134
 Cele 3 teme pentru laborator OOP
 
 Enunt tema 1:
 Tema 1. Clasa ”Numar_Complex”
- membrii privati pentru partea reala si partea imaginara (double);
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în
cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
- metode publice pentru setat/furnizat partea reala si partea imaginara;
- metoda publica de afisare (sub forma &quot;a&quot;, &quot;i*a&quot;, &quot;-i*a&quot;, &quot;a+i*b&quot;, &quot;a-i*b&quot;);
- metoda publica pentru determinarea modulului unui numar complex;
- suma a doua numere complexe, implementata prin supraincarcarea op +;
- produsul a doua numere complexe, implementat prin supraincarcarea op *;
- împărțirea a doua numere complexe, implementata prin supraincarcarea op /.
- metoda publica sqrt pentru furnizarea radicalului de ordinul 2 al unui complex.
Să se realizeze un program de rezolvare a ecuatiei de ordinul doi cu coeficienti complecsi.

Enunt tema 2:
Tema 2. vectori de numere complexe
Se dau urmatoarele clase:
- Complex (float re,im)
- Vector (int dim, Complex *v).
- Stiva : Vector - cu operatiile de adaugare și stergere modificate corespunzator.
- Coada: Vector - cu operatiile de adaugare și stergere modificate corespunzator.
Clasele derivate trebuie sa contina o metoda prin care sa verifice dacă stiva / coada este pur
"imaginara".

Enunt tema 3:
Tema 4. Dintr-un parc auto se poate cumpăra o gama variată de automobile din următoarele
clase: MINI (mașina de oraș de mic litraj, de obicei sub 4m lungime), MICA (mașini de oraș,
cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1), COMPACTA (mașini ușor
de folosit atât de oraș cât și la drum lung, de dimensiune 4.2 – 4.5m; modelele vin sub forma
de hatchback, combi sau sedan) și MONOVOLUME (automobile sub forma de van ce pot
transporta 5-7 persoane). Monovolumele pot și achiziționate atât noi cât și second hand. La
cele achizi4onate sh se percepe un discount proporțional cu numărul de ani vechime și, în
lunile de vară, beneficiază de zile promo4onale cu reducere fixa de 10% din preț.
Structura de date: set<pair<4p_automobil, bool nou>> (nou = false pentru cele sh)
Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se adauge campurile și metodele necesare pentru implementarea corecta;
- Să se construiască clasa template Vanzare care sa conțină nr total de mașini în stoc
(decrementat automat la vanzarea unei mașini), nr de mașini vândute (incrementat automat)
și două structuri de obiecte, alocate dinamic, prin care să se ges4oneze automobilele din stoc
și cele vandute. Sa se supraincarce operatorul -= care sa actualizeze datele din clasa la
vanzarea unei mașini.

- Să se construiască o specializare pentru 4pul MONOVOLUM care sa conțină și să afișeze
ges4oneze doar MONOVOLUMELE.
