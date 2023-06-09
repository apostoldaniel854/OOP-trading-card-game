## PROIECT OOP

Pentru o reprezentare a progresului la proiect se poate accesa [TODO](TODO.md).

## Descriere
Joc video de tip trading card game inspirat din [Hearthstone](https://en.wikipedia.org/wiki/Hearthstone) si [Gwent](https://en.wikipedia.org/wiki/Gwent:_The_Witcher_Card_Game). 

Vei juca (player 1) impotriva unui inamic (player 2), fiecare avand viata egala cu 30 la inceput, cate un deck (din care se trag carti) si un hand din care la fiecare tura se pot juca carti care costa mana. La inceputul jocului fiecare jucator are 0 mana. 

La inceputul fiecarei ture, mana se regenereaza si se mai adauga 1 mana daca mana este < 10. 

Minionii pot fi jucati pe tabla (board) si incepand cu urmatoarea runda pot ataca minionii inamici sau pe opponent si dau damage egal cu atacul lor (daca ataca un alt minion vor pierde din viata o valoare egala cu atacul acelui minion atacat). 

Exista spell-uri care dau damage direct la opponent sau minionilor inamici.
Jucatorul al carui viata devine negativa sau egala cu 0, pierde. 

## Detalii tehnice

Entrypoint-ul este fisierul controller.cpp.
Jocul este text-based in terminal (e posibil ca versiuni urmatoarea sa foloseasca [Indicators](https://github.com/p-ranav/indicators) pentru a infrumuseta interfata).

## Documentatie

### Lista de comenzi
- `help` - afiseaza lista de comenzi
- `quit` - iesi din joc
- `end_turn` - termina tura
- `show_board` - afiseaza tabla
- `show_hand` - afiseaza mana ta
- `show_opponent` - afiseaza viata adversarului
- `show_player` - afiseaza viata ta
- `play <card_name>` - joaca o carte din mana
- `attack <friendlyMinion_id> <enemyMinion_id>` - ataca cu un minion de pe tabla (indexarea se face de la 1)
- `go_face <friendlyMinion_id> opponent` - ataca adversarul cu un minion de pe tabla (indexarea se face de la 1)
## Inspiratie
- https://github.com/An0n1mity/Hearthstone-Battleground-Clone
- https://github.com/Rymedy/hearthstone-web
## Folosit pentru ajutor
- https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container
- https://www.cppstories.com/2021/filter-cpp-containers/
- https://github.com/mcmarius/poo/tree/master/tema-3