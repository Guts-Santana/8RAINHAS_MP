#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"


TEST_CASE("Se o arquivo tem 8 linhas") {
   REQUIRE(chamada("teste2.txt") == -1);
   REQUIRE(chamada("teste3.txt") == -1);
   REQUIRE(chamada("teste4.txt") == -1);
   REQUIRE(chamada("teste5.txt") == -1);
}

TEST_CASE("Se o arquivo só tem linhas de 8 termos"){
   REQUIRE(chamada("teste6.txt") == -1);
   REQUIRE(chamada("teste7.txt") == -1);
   REQUIRE(chamada("teste8.txt") == -1);
   REQUIRE(chamada("teste9.txt") == -1);
}

TEST_CASE("Arquivos que resolvem o sistema") {
   REQUIRE(chamada("teste10.txt") == 0);
   REQUIRE(chamada("teste11.txt") == 0);
   REQUIRE(chamada("teste12.txt") == 0);
   REQUIRE(chamada("teste13.txt") == 0);
   REQUIRE(chamada("teste14.txt") == 0);
   REQUIRE(chamada("teste15.txt") == 0);
}