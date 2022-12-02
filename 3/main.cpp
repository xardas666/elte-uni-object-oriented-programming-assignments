#ifdef NORMAL_MODE
#else
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Kornyezet.h"

TEST_CASE("1) Különféle méretű klímamodellek betöltése.") {
    SECTION( "Nem létező fájl megadásával." ) {
        REQUIRE_THROWS( new Kornyezet("testallomanyok/nemletezek.txt") );
    }
    SECTION( "Extrém méretű (0) létrehozása" ) {
        REQUIRE_THROWS( new Kornyezet("testallomanyok/0db.txt") );
    }
    SECTION( "Extrém méretű (1) létrehozása" ) {
        REQUIRE_NOTHROW( new Kornyezet("testallomanyok/1db.txt") );
    }
    SECTION( "Extrém méretű (100) létrehozása" ) {
        REQUIRE_NOTHROW( new Kornyezet("testallomanyok/100db.txt") );
    }
}

TEST_CASE("2) Puszta klímamodell tesztelése.") {
    int KEZDETI_VIZMENNYISEG=10;
    SECTION( "napos idő hatására a vízmennyiség 3 km3 -rel csökken") {
        Puszta puszta =* new Puszta("test",PUSZTA,KEZDETI_VIZMENNYISEG);
        puszta.idojarasHatas(NAPOS);
        CHECK(puszta.getVizmennyiseg()==KEZDETI_VIZMENNYISEG-3);
    }
    SECTION( "felhős idő hatására 1 km3 -rel nő") {
        Puszta puszta =* new Puszta("test",PUSZTA,KEZDETI_VIZMENNYISEG);
        puszta.idojarasHatas(FELHOS);
        CHECK(puszta.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+1);
    }
    SECTION( "eső hatására 5km3 -rel nő.") {
        Puszta puszta =* new Puszta("test",PUSZTA,KEZDETI_VIZMENNYISEG);
        puszta.idojarasHatas(ESOS);
        CHECK(puszta.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+5);
    }
    SECTION( "A levegő páratartalmát 3%-kal növeli.") {
        Puszta puszta =* new Puszta("test",PUSZTA,KEZDETI_VIZMENNYISEG);
        CHECK(puszta.paratartalomHatas()==3);
    }
    SECTION( "15 km3 -nél több tárolt víz esetén zölddé változik.") {
        Puszta puszta = *new Puszta("test", PUSZTA, KEZDETI_VIZMENNYISEG);
        puszta.idojarasHatas(ESOS);//vizmennyiség itt 15
        puszta.idojarasHatas(ESOS);//vizmennyiség itt 20 tehát mostmár zöld
        CHECK(puszta.getTipus()==ZOLD); // objektum konverzió a környezet osztályban történik
    }
}

TEST_CASE("3) Zold klímamodell tesztelése.") {
    int KEZDETI_VIZMENNYISEG=30;
    SECTION( "napos idő hatására a vízmennyiség 6 km3 -rel csökken") {
        Zold zold =* new Zold("test",ZOLD,KEZDETI_VIZMENNYISEG);
        zold.idojarasHatas(NAPOS);
        CHECK(zold.getVizmennyiseg()==KEZDETI_VIZMENNYISEG-6);
    }
    SECTION( "felhős idő hatására 2 km3 -rel nő") {
        Zold zold =* new Zold("test",ZOLD,KEZDETI_VIZMENNYISEG);
        zold.idojarasHatas(FELHOS);
        CHECK(zold.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+2);
    }
    SECTION( "eső hatására 10km3 -rel nő.") {
        Zold zold =* new Zold("test",ZOLD,KEZDETI_VIZMENNYISEG);
        zold.idojarasHatas(ESOS);
        CHECK(zold.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+10);
    }
    SECTION( "A levegő páratartalmát 7%-kal növeli.") {
        Zold zold =* new Zold("test",ZOLD,KEZDETI_VIZMENNYISEG);
        CHECK(zold.paratartalomHatas()==7);
    }
    SECTION( "16km3 alatt pusztává változik.") {
        Zold zold = *new Zold("test", ZOLD, KEZDETI_VIZMENNYISEG);
        zold.idojarasHatas(NAPOS);//vizmennyiség itt 24
        zold.idojarasHatas(NAPOS);//vizmennyiség itt 18
        zold.idojarasHatas(NAPOS);//vizmennyiség itt 12 tehát mostmár puszta
        CHECK(zold.getTipus()==PUSZTA); // objektum konverzió a környezet osztályban történik
    }
    SECTION( "50km3 -es vízmennyiség fölött tavassá változik.") {
        Zold zold = *new Zold("test", ZOLD, KEZDETI_VIZMENNYISEG);
        zold.idojarasHatas(ESOS);//vizmennyiség itt 40
        zold.idojarasHatas(ESOS);//vizmennyiség itt 50
        zold.idojarasHatas(ESOS);//vizmennyiség itt 60 tehát mostmár tavas
        CHECK(zold.getTipus()==TAVAS); // objektum konverzió a környezet osztályban történik
    }
}

TEST_CASE("4) Tavas klímamodell tesztelése.") {
    int KEZDETI_VIZMENNYISEG=65;
    SECTION( "napos idő hatására a vízmennyiség 10 km3 -rel csökken") {
        Tavas tavas =* new Tavas("test",TAVAS,KEZDETI_VIZMENNYISEG);
        tavas.idojarasHatas(NAPOS);
        CHECK(tavas.getVizmennyiseg()==KEZDETI_VIZMENNYISEG-10);
    }
    SECTION( "felhős idő hatására 3 km3 -rel nő") {
        Tavas tavas =* new Tavas("test",TAVAS,KEZDETI_VIZMENNYISEG);
        tavas.idojarasHatas(FELHOS);
        CHECK(tavas.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+3);
    }
    SECTION( "eső hatására 15km3 -rel nő.") {
        Tavas tavas =* new Tavas("test",TAVAS,KEZDETI_VIZMENNYISEG);
        tavas.idojarasHatas(ESOS);
        CHECK(tavas.getVizmennyiseg()==KEZDETI_VIZMENNYISEG+15);
    }
    SECTION( "A levegő páratartalmát 10%-kal növeli.") {
        Tavas tavas =* new Tavas("test",TAVAS,KEZDETI_VIZMENNYISEG);
        CHECK(tavas.paratartalomHatas()==10);
    }
    SECTION( "51 km3 -nél kevesebb tárolt víz esetén zölddé változik.") {
        Tavas tavas = *new Tavas("test", TAVAS, KEZDETI_VIZMENNYISEG);
        tavas.idojarasHatas(NAPOS);//vizmennyiség itt 55
        tavas.idojarasHatas(NAPOS);//vizmennyiség itt 40 tehát mostmár zöld
        CHECK(tavas.getTipus()==ZOLD); // objektum konverzió a környezet osztályban történik
    }
}

TEST_CASE("5) Kornyezet.") {
    SECTION( "Helyesen kiválasztja a legnagyobbat" ) {
        Kornyezet kornyezet = *new Kornyezet("testallomanyok/test.txt");
        kornyezet.playRoundsForTime(10);
        CHECK(kornyezet.legnagyobbVizmennyiseguFoldterulet()->getNev()=="Bean");
    }
    SECTION( "Az első legnagyobbat választja ki" ) {
        Kornyezet kornyezet = *new Kornyezet("testallomanyok/ugyanolyan.txt");
        kornyezet.playRoundsForTime(10);
        CHECK(kornyezet.legnagyobbVizmennyiseguFoldterulet()->getNev()=="Bean");
    }
}

#endif