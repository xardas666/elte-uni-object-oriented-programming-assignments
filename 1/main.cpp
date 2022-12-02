#include <iostream>
#include "sakktabla_matrix.cpp"

//#define NORMAL_MODE
#ifdef NORMAL_MODE
#else
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

TEST_CASE("1)Különféle méretű mátrixok létrehozása, feltöltése és kiírása.") {
    //a)	1, 2, 5 dimenziójú mátrix
    REQUIRE_NOTHROW((new SakktablaMatrix(1, 1))->writeOutMatrix());
    REQUIRE_NOTHROW((new SakktablaMatrix(2, 2))->writeOutMatrix());
    REQUIRE_NOTHROW((new SakktablaMatrix(5, 5))->writeOutMatrix());

    //b)	Extrém méretű (-1, 0, 1, 1000) mátrix létrehozása
    REQUIRE_THROWS(new SakktablaMatrix(-1, -1));
    REQUIRE_THROWS(new SakktablaMatrix(0, 0));
    REQUIRE_NOTHROW(new SakktablaMatrix(1, 1));
    REQUIRE_NOTHROW(new SakktablaMatrix(1000, 1000));
}

TEST_CASE("2)Mátrix adott pozíciójú értékének lekérdezése. ") {
    auto *sm = new SakktablaMatrix(2, 2);

    //a)	„sakktábla” mátrixra eső elem lekérdezése
    CHECK((sm->getValueByCordinate(0, 0)) == 1);

    //b)	„sakktábla” mátrixon kívüli elem lekérdezése
    REQUIRE_THROWS(sm->getValueByCordinate(-1, 0));
}

TEST_CASE("3)A c:=a+b mátrixösszeadás kipróbálása (teljes mátrix összehasonlítás hiányában csak az első koordinátára).") {
    auto *a = new SakktablaMatrix(2, 2);
    auto *b = new SakktablaMatrix(2, 2);
    auto *c = new SakktablaMatrix(2, 2);
    auto *kivetel = new SakktablaMatrix(3, 3);

    //a)	Kommutativitás ellenőrzése (a + b == b + a)
    CHECK((a->addition(*b)).getValueByCordinate(0, 0) == (b->addition(*a)).getValueByCordinate(0, 0));
    //b)	Asszociativitás ellenőrzése (a + b + c == (a + b) + c == a + (b + c))
    CHECK(((a->addition(*b)).addition(*c)).getValueByCordinate(0, 0) ==
          ((b->addition(*c)).addition(*a)).getValueByCordinate(0, 0));
    //c)	Eltérő méretű mátrixoknál exception ellenörzése
    REQUIRE_THROWS(kivetel->addition(*a));
}


TEST_CASE("4)A c:=a*b mátrixszorzás kipróbálása (teljes mátrix összehasonlítás hiányában csak az első koordinátára). ") {
    auto *a = new SakktablaMatrix(2, 2);
    auto *b = new SakktablaMatrix(2, 2);
    auto *c = new SakktablaMatrix(2, 2);
    auto *kivetel = new SakktablaMatrix(3, 3);

    //a)	Kommutativitás ellenőrzése (a * b == b * a)
    CHECK(a->multiplication(*b).getValueByCordinate(0, 0) == b->multiplication(*a).getValueByCordinate(0, 0));
    //b)	Asszociativitás ellenőrzése (a * b * c == (a * b) * c == a * (b * c))
    CHECK((a->multiplication(*b)).multiplication(*c).getValueByCordinate(0, 0) ==
          (b->multiplication(*c)).multiplication(*a).getValueByCordinate(0, 0));
    //c)	Eltérő méretű mátrixoknál exception ellenörzése
    REQUIRE_THROWS(kivetel->multiplication(*a));
}

#endif