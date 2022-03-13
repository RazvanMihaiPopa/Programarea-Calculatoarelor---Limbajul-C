# Programarea-Calculatoarelor---Limbajul-C
2 teme in cadrul cursului „Programarea calculatoarelor si limbaje de programare”.
TEMA 1.
Am inceput cu problema 1, am inceput-o intr-o duminica si am inceput sa scriu functiile necesare, insa initial nu imi mergeau, apoi m am reapucat luni seara, am stat si m am gandit de ce nu imi afisa corect si pana la urma mi-am dat seama ce trebuia corectat si am terminat problema. Modul de gandire este destul de detaliat in comentariile codului.
Marti am inceput problema 4 si am terminat-o joi. Am facut functiile cerute, la cea cu sum_X_0 am "impartit" matricea in 4 mini matrici, am parcurs toate liniile, coloanele si diagonalele lor si daca acestea contineau numai 1, cresteam suma cu 1. La functiile de schimbare dintr-o baza in alta m-am gandit la procedeele uzuale. In main am luat un vector sir de caractere sa retin toate numerele in baza 2 si apoi am format o matrice cu cifrele continute, ca sa-mi fie mai usor. Dupa ce am apelat functiile de transpusa si apoi inmultire, deoarece era posibil ca inmultind sa am valori diferite de 0 si 1, la tot ce era diferit de 0 le-am dat valoarea 1, folosindu-ma de logica booleana. Am pus in 3 variabile cele 3 scoruri si in functie de scorul maxim si ordinea ceruta de problema, am afisat numerele castigatoare, transformandu-le din baza 2 in baza 10 inapoi.
Joi seara am inceput problema 2 si am terminat-o sambata. Initial voiam sa parcurg orice diagonala posibila ca sa aflu cati de 1 se afla pe diagonale, insa nu am reusit asa ca m-am gandit sa iau fiecare nebun(retinand pozitiile in 2 vectori in int main) si sa "trec" pe sus si jos la diagonelele "principale" si "secundare" si cand dadeam de un 1, adaugam +1 la numar, astfel afland perechile care se atacau cu acel 1. Ca sa nu il repet cand treceam la alt 1, l-am schimbat in 2. Pentru a doua cerinta, am scris detaliat comentariile in cod. 
TEMA 2.
Task 1:
Implementarea cerintelor mi-a luat in jur de 3 zile.
Am scris structura de date, iar continutul l-am alocat si realocat dinamic la nevoie.
Am initializat toate variabilele, am deschis fisierul si am verificat daca se deschide, 
iar apoi am inceput sa citesc fiecare linie. Am pregatit o realocare dinamica in cazul
in care ar mai fi de citit site-uri, deoarece vectorul de structuri este initializat
cu 3. Ca sa pot deschide site-urile cu fisiere, am scapat de '\n' pentru a le citi.
Pentru prima linie am folosit fscanf pentru a extrage fiecare "subiect" deoarece
cuvintele erau separate prin spatii. In continuare, am citit tot site-ul si daca gaseam
'<title>', eliminam tag-urile ca sa introduc titlul in structura, la fel si la 
continut. Cand gaseam '<p', daca pe acea linie gaseam si '</p>', doar copiam acea
linie in structura, insa daca nu era atribui lui ok valoarea 1 ca sa stiu ca inca
ma aflu in continut si sa copiez in continuare in structura. Am inchis de fiecare
data fisierele, am afisat ce a trebuit si am eliberat memoria alocata dinamic.

Task 2:
Implementarea cerintelor mi-a luat in jur de 2 zile.
Am copiat ce am scris la task 1, iar in plus am luat un p care afla dimensiunea maxima
a continutului, pentru o alocare dinamica ulterioara. Am citit cu fgets ca sa se
opreasca citirea la '\n' si fiecare cuvant l-am retinut intr-un vector sir de
caractere. Am luat alt vector de structuri de date in care am retinut site-urile
in care se gaseau cuvintele, iar apoi folosind functia sortare am sortat
site-urile in functie de criteriile cerute. Pe langa functia sortare, am mai
implementat o functie de comparare, ceruta de enunt, dar si o functie de
interschimbare pentru variabile de tip int si una pentru variabile de tip char.
La sfarsit am eliberat memoria alocata dinamic.
