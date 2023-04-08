## PROIECT OOP

## Descriere
Joc video de tip trading card game inspirat din [Hearthstone](https://en.wikipedia.org/wiki/Hearthstone) sau [Gwent](https://en.wikipedia.org/wiki/Gwent:_The_Witcher_Card_Game). 

Vei juca (player 1) impotriva unui inamic (player 2), fiecare avand viata egala cu 30 la inceput, cate un deck (din care se trag carti) si un hand din care la fiecare tura se pot juca carti care costa mana. La inceputul jocului fiecare jucator are 0 mana. 

La inceputul fiecarei ture, mana se regenereaza si se mai adauga 1 mana daca mana este < 10. 

Minionii pot fi jucati pe tabla (board) si incepand cu urmatoarea runda pot ataca minionii inamici sau pe opponent si dau damage egal cu atacul lor (daca ataca un alt minion vor pierde din viata o valoare egala cu atacul acelui minion atacat). 

Vor exista si spell-uri in versiuni urmatoare. 

Jucatorul al carui viata devine negativa sau egala cu 0, pierde. 

## Detalii tehnice

Entrypoint-ul este fisierul controller.cpp.

## Inspiratie
- https://github.com/An0n1mity/Hearthstone-Battleground-Clone
- https://github.com/Rymedy/hearthstone-web