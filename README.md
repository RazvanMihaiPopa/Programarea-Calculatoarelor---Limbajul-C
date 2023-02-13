# Programarea-Calculatoarelor---Limbajul-C

My first 2 homework assignments from the "Computer programming and programming languages" course.

## Assignment 1
* An is_anagram problem
* Chess problem
* Matrix operations
* Converting decimal to binary and vice versa

## Assignment 2
* mostly handling files in C, below you can find more details about what i was thinking:

#### Task 1
Implementarea cerintelor mi-a luat in jur de 3 zile.
Am scris structura de date, iar continutul l-am alocat si realocat dinamic la nevoie.
Am initializat toate variabilele, am deschis fisierul si am verificat daca se deschide, 
iar apoi am inceput sa citesc fiecare linie. Am pregatit o realocare dinamica in cazul
in care ar mai fi de citit site-uri, deoarece vectorul de structuri este initializat
cu 3. Ca sa pot deschide site-urile cu fisiere, am scapat de '\n' pentru a le citi.
Pentru prima linie am folosit fscanf pentru a extrage fiecare "subiect" deoarece cuvintele erau separate prin spatii. In continuare, am citit tot site-ul si daca gaseam '<title>', eliminam tag-urile ca sa introduc titlul in structura, la fel si la continut. Cand gaseam '<p', daca pe acea linie gaseam si '<//p>', doar copiam acea linie in structura, insa daca nu era atribui lui ok valoarea 1 ca sa stiu ca inca ma aflu in continut si sa copiez in continuare in structura. Am inchis de fiecare data fisierele, am afisat ce a trebuit si am eliberat memoria alocata dinamic.

#### Task 2
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
