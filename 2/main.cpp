#include "EredmenyHirdetes.cpp"

#ifdef NORMAL_MODE
#else
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

TEST_CASE("1) Különféle méretű versenyek betöltése.") {
//a)	Extrém méretű (0, 1, 1000) létrehozása
    REQUIRE_THROWS(new EredmenyEnumerator("bajnoksag_0.txt"));
    REQUIRE_NOTHROW(new EredmenyEnumerator("bajnoksag_1.txt"));
    REQUIRE_NOTHROW(new EredmenyEnumerator("bajnoksag_1000.txt"));
//b)	Nem létező fájl megadásával.
    REQUIRE_THROWS(new EredmenyEnumerator("nemLetezek.txt"));
}

TEST_CASE("2) egyHalatSeFogottElsoAListabol.") {
//a)	Van a betöltött állományban ilyen elem
    auto *eE = new EredmenyEnumerator("bajnoksag.txt");
    auto eh = new EredmenyHirdetes(*eE);
    CHECK_THAT((eh)->egyHalatSeFogottElsoAListabol().getVersenyzoAzonosito(), Catch::Equals( "FERI"));

//b)	Nincs a betöltött állományban ilyen elem
    auto *eE1 = new EredmenyEnumerator("bajnoksag_mindenkiFogottEgyHalat.txt");
    REQUIRE_THROWS((new EredmenyHirdetes(*eE1))->egyHalatSeFogottElsoAListabol());

//c)	A betöltött állományban több ilyen elem is van
    auto *eE2 = new EredmenyEnumerator("bajnoksag_senkiseFogottHalat.txt");
    CHECK_THAT((new EredmenyHirdetes(*eE2))->egyHalatSeFogottElsoAListabol().getVersenyzoAzonosito() , Catch::Equals("JANI"));
}

TEST_CASE("3) aVersenyAholALegtobbHalatFogtak.") {
//a)	Mindenhol ugyanannyit fogtak eset
    auto *eE1 = new EredmenyEnumerator("bajnoksag_mindenkiFogottEgyHalat.txt");
    CHECK_THAT((new EredmenyHirdetes(*eE1))->aVersenyAholALegtobbHalatFogtak().verseny, Catch::Equals("Kiliti0512")); // egyenlő az első verseny id-javal
//b)	Alapeset, ahol tényleg csak 1 versenyen fogtak sok halat
    auto *eE2 = new EredmenyEnumerator("bajnoksag.txt");
    CHECK((new EredmenyHirdetes(*eE2))->aVersenyAholALegtobbHalatFogtak().db == 8); // egyenlő 8
}

#endif