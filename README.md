# LAN-Party
Tema Proiectarea Algoritmilor

## Descriere
Tema Proiectarea Algoritmilor - facultatea de Automatică și Calculatoare, Universitatea Politehnica București.

## Main

* Argumentele de linie de comandă sunt extrase pentru a obține căile către fișierul de task-uri, fișierul de intrare și fișierul de ieșire.
* Se declară variabilele necesare, inclusiv vectorul tasksArr și două structuri TEAMNODE pentru stocarea informațiilor despre echipe.
* Fișierul de sarcini este deschis și se verifică erorile de deschidere.
* Task-urile sunt citite din fișierul de task-uri și stocate în vectorul tasksArr.
* Task-urile sunt executate în funcție de vectorul de task-uri.
* Memoria alocată dinamic este eliberată și fișierele deschise sunt închise.

## TASK 1

* Citește datele despre echipe dintr-un fișier dat și le salvează într-o structură de date de tip listă simplu înlănțuită.
* Afișează informațiile despre echipe într-un fișier specificat.

## Funcționalitate

Această funcție primește trei parametri:

* inPath - calea către fișierul de intrare care conține datele despre echipe.
* outPath - calea către fișierul de ieșire în care vor fi afișate informațiile despre echipe.
* head - un pointer către o structură de tip TEAMNODE reprezentând lista de echipe.

### Funcția task1 îndeplinește următoarele acțiuni:

1. Deschide fișierul de intrare specificat utilizând calea inPath.
2. Verifică dacă fișierul s-a deschis cu succes, altfel afișează un mesaj de eroare.
3. Inițializează un nou nod de echipă utilizând memoria alocată dinamic și îl adaugă la începutul listei.
4. Citește dimensiunea listei de echipe din fișierul de intrare și o atribuie variabilei listSize a nodului de echipă.
5. Parcurge fiecare echipă din fișierul de intrare și adaugă informațiile corespunzătoare în structura de date.
6. Afișează informațiile despre echipe în fișierul de ieșire.

## TASK 2

* Calculează punctajul pentru fiecare echipă din lista realizată la task-ul 1.
* Elimină echipele cu cel mai mic punctaj iterativ, până când numărul total de echipe rămase este cea mai mare putere a lui 2, mai mică decât numărul de echipe din listă.

## Funcționalitate

Această funcție primește doi parametri:

* head - un pointer către o structură de tip TEAMNODE, care reprezintă lista de echipe.
* outPath - calea către fișierul de ieșire în care vor fi afișate rezultatele.

### Funcția task2 îndeplinește următoarele acțiuni:

1. Calculează punctajul pentru fiecare echipă din lista specificată utilizând funcția teamPoints.
2. Inițializează o variabilă minimVal cu cel mai mic punctaj din lista de echipe.
3. Inițializează o constantă epsilon cu o valoare foarte mică pentru compararea numerelor floating point (float).
4. Parcurge lista de echipe și elimină iterativ echipele cu cel mai mic punctaj, până când numărul total de echipe rămase este cea mai mare putere a lui 2 mai mică decât numărul de echipe din listă.
5. Actualizează valoarea minimului după fiecare eliminare a echipei.
6. Afișează informațiile despre echipele rămase în fișierul de ieșire specificat utilizând funcția display.

## TASK 3 

* Realizează un turneu folosind echipele din lista principală.
* Implementează structurile de date necesare pentru organizarea meciurilor: o coadă pentru meciuri, două stive pentru învinși și câștigători.
* În fiecare rundă a turneului, se formează meciuri în ordinea în care echipele se află în lista de la punctul anterior.
* Echipele învingătoare vor fi adăugate în stiva câștigătorilor, iar punctajul lor va fi incrementat cu 1. În cazul în care două echipe au același punctaj, se va alege prima echipă adăugată în meciul respectiv.
* Echipele învinse vor fi eliminate și șterse din stiva de învinși.
* Echipele câștigătoare vor fi extrase din stiva de câștigători și vor fi reintroduse în coada de meciuri, formându-se noi meciuri cu echipe consecutive.
* Procesul se repetă până când se obțin echipele de pe primele 8 locuri, care vor fi salvate într-o altă listă.
* Turneul continuă până când este determinată echipa câștigătoare.

## Funcționalitate

Această funcție primește trei parametri:

* head - un pointer către o structură de tip TEAMNODE reprezentând lista principală de echipe.
* outPath - calea către fișierul de ieșire în care vor fi afișate informațiile despre meciuri.
* head_last8 - un pointer către o structură de tip TEAMNODE reprezentând lista în care vor fi salvate ultimele 8 echipe.

### Funcția îndeplinește următoarele acțiuni:

1. Deschide fișierul de ieșire specificat utilizând calea outPath.
2. Verifică dacă fișierul s-a deschis cu succes, altfel afișează un mesaj de eroare.
3. Creează o coadă pentru meciuri și un pointer către o structură de tip Queue.
4. Creează o copie a listei principale de echipe utilizând pointerul head.
5. Elimină spațiile din numele echipelor din lista copie utilizând funcția removeSpaceList.
6. Parcurge lista copie și adaugă meciurile în coadă utilizând funcția enQueue, astfel încât primele două echipe vor forma primul meci, și așa mai departe.
7. Parcurge lista copie și afișează numele echipelor în fișierul de ieșire.
8. Eliberează memoria ocupată de lista copie utilizând free.
9. Adaugă un separator de linie în fișierul de ieșire.
10. Calculează numărul maxim de runde pentru turneu folosind logaritmul în baza 2 al dimensiunii listei principale de echipe.
11. Inițializează doi pointeri către structuri de tip Node pentru stivele de învinși și câștigători și le setează inițial la NULL.
12. Într-o buclă, pentru fiecare rundă a turneului:
    * Afișează numărul rundei în fișierul de ieșire.
    * Afișează conținutul cozii de meciuri utilizând funcția printQueue.
    * Adaugă câștigătorii în stiva câștigătorilor și înregistrează punctajele de echipă corespunzătoare.
    * Afișează câștigătorii rundei în fișierul de ieșire.
    * Dacă runda curentă nu este ultima, adaugă un separator de linie în fișierul de ieșire.
    * Șterge învinșii din stiva de învinși utilizând deleteStack.
    * Parcurge stiva câștigătorilor și adaugă echipele în coada de meciuri, formându-se noi meciuri cu echipe consecutive.
    * Salvează ultimele 8 echipe în lista head_last8 utilizând funcția last8_save.
    * Incrementează numărul rundei.
    * Eliberează memoria ocupată de stiva câștigătorilor utilizând deleteStack.
13. Eliberează memoria ocupată de coadă utilizând deleteQueue.
14. Eliberează memoria ocupată de stiva câștigătorilor utilizând deleteStack.
15. Eliberează memoria ocupată de stiva învinșilor utilizând deleteStack.
16. Închide fișierul de ieșire.

## TASK 4

* Realizează un clasament al ultimelor 8 echipe sub forma unui Arbore de Căutare Binăra (BST).
* Clasamentul este ordonat după punctajul pe echipă și în cazul în care două echipe au același punctaj, sunt ordonate în funcție de nume în ordine descrescătoare.
* Afisează conținutul clasamentului în ordine descrescătoare într-un fișier specificat.

## Funcționalitate

Această funcție primește doi parametri:

* head_last8 - un pointer către primul nod al listei salvate de la task-ul 3, care conține ultimele 8 echipe rămase în competiție.
* outPath - calea către fișierul de ieșire în care va fi salvat conținutul clasamentului.

### Funcția task4 îndeplinește următoarele acțiuni:

1. Deschide fișierul de ieșire specificat utilizând calea outPath.
2. Verifică dacă fișierul s-a deschis cu succes, altfel afișează un mesaj de eroare.
3. Creează o copie a pointerului head_last8 pentru a parcurge lista de echipe.
4. Inițializează un Arbore de Căutare Binăra (BST) cu valoarea NULL.
5. Inserează fiecare echipă din lista head_last8 în Arborele de Căutare Binăra utilizând funcția insert pentru a le ordona după punctaj și nume.
6. Scrie un separator și antetul în fișierul de ieșire.
7. Parcurge Arborele de Căutare Binara în ordine descrescătoare și scrie informațiile despre echipe în fișierul de ieșire

## TASK 5

* Realizează un Arbore AVL utilizând ultimele 8 echipe (salvate conform cerințelor task-ului 3 și sortate conform cerințelor task-ului 4).
* Afisează echipele de pe nivelul 2 al Arborelui AVL într-un fișier specificat.

## Funcționalitate

Această funcție primește doi parametri:

* head_last8 - un pointer către primul nod al listei care conține ultimele 8 echipe.
* outPath - calea către fișierul de ieșire în care vor fi afișate echipele de pe nivelul 2 al Arborelui AVL.

### Funcția task5 îndeplinește următoarele acțiuni:

1. Deschide fișierul de ieșire specificat utilizând calea outPath.
2. Verifică dacă fișierul s-a deschis cu succes, altfel afișează un mesaj de eroare.
3. Alocă memorie pentru un vector de dimensiune 8, head_last8Arry, pentru a stoca echipele.
4. Creează o copie a pointerului head_last8 pentru a parcurge lista de echipe.
5. Copiază echipele din lista head_last8 în vectorul head_last8Arry.
6. Sortează vectorul head_last8Arry în ordine crescătoare utilizând funcția qsort și funcția de comparație compareTeams.
7. Inițializează un Arbore AVL (root) cu valoarea NULL.
8. Inserează fiecare echipă din vectorul head_last8Arry în Arborele AVL utilizând funcția insertAVL.
9. Scrie un separator și antetul în fișierul de ieșire.
10. Afișează echipele de pe nivelul 2 al Arborelui AVL utilizând funcția printLevel.
11. Eliberează memoria alocată pentru vectorul head_last8Arry și Arborele AVL (root).
12. Închide fișierul de ieșire.

## Problema: Erori neașteptate din cauza caracterelor "\r" în output

### Descriere
În timpul rezolvării temei, am întâmpinat o problemă legată de apariția unor erori neașteptate în output. Am descoperit că aceste erori erau cauzate de caracterul special "\r" (carriage return) care apare în anumite locuri din input sau textul prelucrat.

### Cauza
Diferențele în formatarea caracterelor de sfârșit de linie ("\r\n" pentru Windows și "\n" pentru sistemele bazate pe Unix) pot cauza probleme de compatibilitate între diferite sisteme sau tehnologii. În cazul meu, numele echipelor conțineau caractere "\r" care provoacă comportament neașteptat, cum ar fi deplasarea cursorului la începutul liniei.

### Soluție
Pentru a remedia această problemă, am modificat codul astfel încât să elimine atât caracterele "\n" cât și "\r" de la sfârșitul numelor echipelor înainte de a le utiliza sau afișa.

## Impresii finale 
Tema a fost primul proiect în C de dimensiunea asta la care am lucrat și consider că am învățat multe din ea, nu doar despre structuri de date și algoritmi cât și despre gestionarea problemelor care pot să apară, mi-am dezvoltat atenția și dorința de a programa. De asemenea, a fost pentru prima dată când am încărcat un proiect pe Git și consider că m-a ajutat să învăț cum se folosește și la ce ajută asta.
