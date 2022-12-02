> * Kiegészítő követelmények: Az alábbi feladatok megoldásához több olyan osztályt kell használni, amelyek egy közös ősosztályból származnak és felüldefiniálják az ősosztály virtuális metódusait. Ezen osztályok objektumait egy gyűjteménybe kell elhelyezni, majd ezt a gyűjteményt kell bejárni, a benne levő objektumok megfelelő metódusait meghívni. Ez a bejárás a futásidejű polimorfizmusra támaszkodik. Használjon legalább két tervezési mintát is. A gyűjtemények bejárását továbbra is a tanult programozási tételek alapján végezze. A tesztkörnyezet biztosítson egységenkénti (osztály, metódus) tesztelési eseteket is a végfelhasználói teszteseteken kívül.

> * Dokumentáció: Tartalmazza a feladat szövegét, a megoldás osztály diagramját, a főprogram specifikációját.

A föld hidrológiai körfolyamatában a különböző földterületek befolyásolják az időjárást és a különböző időjárások
hatására a földterületek változnak. Minden földterületeknek van neve, fajtája (puszta, zöld, tavas), tárolt
vízmennyisége (km3 -ben). A földterületek feletti közös levegőnek ismerjük a páratartalmát (százalékban).

Az időjárás a levegő aznapi páratartalmától függ: Ha ez meghaladja a 70%-ot, esős idő lesz, és ekkor lecsökken a
páratartalom 30%-ra. 40%-os páratartalom alatt az időjárás napos lesz. 40 és 70% közötti páratartalom esetén az esős
időjárásnak (páratartalom-40)*3,3 százalék az esélye, egyébként felhős időjárás lesz. (Véletlenszám generátorral
állítsunk el egy számot 0 és 100 között, és ha ez kisebb, mint a (páratartalom-40)*3,3 érték, akkor esős, különben
felhős időjárás legyen.)

Az egyes földterületek – a megadásuk sorrendjében – reagálnak a különböző időjárásokra: először a vízmennyiségük
változik, majd befolyásolják a levegő páratartalmát. Egyetlen földterület vízmennyisége sem lehet negatív.

> Puszta:
>* napos idő hatására a vízmennyiség 3 km3 -rel csökken,
>* felhős idő hatására 1 km3 -rel nő,
>* eső hatására 5km3 -rel nő.
>* A levegő páratartalmát 3%-kal növeli.
>* 15 km3 -nél több tárolt víz esetén zölddé változik.

> Zöld:
>* napos idő hatására a vízmennyiség 6 km3 -rel csökken,
>* felhős idő hatására 2 km3 -rel,
>* eső hatására 10km3 -rel nő.
>* A levegő páratartalmát 7%-kal növeli.
>* 50km3 -es vízmennyiség fölött tavassá változik.
>* 16km3 alatt pusztává változik.

> Tavas:
>* napos idő hatására a vízmennyiség 10 km3 -rel csökken,
>* felhős idő hatására 3 km3 -rel,
>* eső hatására 15km3 -rel nő.
>* A levegő páratartalmát 10%-kal növeli.
>* 51km3 alatt zölddé változik.

Adjuk meg 10 kör után a legvizesebb földterület tulajdonosát, vízmennyiségével együtt! Körönként mutassuk meg a
földterületek összes tulajdonságát!

A program egy szövegfájlból olvassa be az adatokat! Ennek első sorában a földterületek száma szerepel. A következő sorok
tartalmazzák a földterületek adatait szóközökkel elválasztva: a terület tulajdonosát (szóköz nélküli sztring),
fajtáját (egy karakter azonosítja: p - puszta, z - zöld, t - tavas), és a kezdeti vízmennyiségét. Az utolsó sor a
földterületek feletti levegő kezdeti páratartalmát mutatja. A program kérje be a fájl nevét, majd jelenítse is meg a
tartalmát. (Feltehetjük, hogy a fájl formátuma helyes.) Egy lehetséges bemenet:

> 4
>
>Bean t 86
>
>Green z 26
>
>Dean p 12
>
>Teen z 35
>
>98 