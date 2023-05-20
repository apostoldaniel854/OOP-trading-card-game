## Ideas

- [ ] if time make TERMINAL UI look better by using indicators
- [ ] put the catalogs in separate files and read them from there
- [ ] make a file for the commands and read them from there too
- [ ] Singleton for Board and Game
- [ ] Factory and object pull for deck generation
- [ ] Minion is an abstract class and all types of minions (dragons, beasts, murlocs, demons) inherit from it
- [X] Card in an abstract class and all types of cards (minions, spells, secrets) inherit from it
- [X] lista de smart pointeri la catalog de carti pentru deck si hand

## Fixes
- [ ] modificat catch try (acum nu pun in interiorul functiei) + exceptii proprii (poate .at folosit de asemenea?) - probabil scapat de comparatia cu nullpointer (in loc sa returnez nullptr, dau throw)
- [X] pus exemplu random de date de intrare
- [X] sa se fac copieri corecte: apelat clone în cc, de făcut cu copy&swap în op=
- [ ] schimbat dynamic_cast cu functii virtuale si gandit la un dynamic cast cu sens (la card)
- [X] schimbat dynamic_cast si functii virtuale la player
- [X] rezolvat problema cu atacul (trebuie)
- [X] mai multe tipuri de carti
- [ ] pus instantele de carti in fisier separat (optional)


