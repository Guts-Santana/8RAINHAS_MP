#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"


TEST_CASE("Se o arquivo tem 8 linhas") {
   REQUIRE(chamada("teste2.txt") == -1);
   REQUIRE(chamada("teste3.txt") == -1);
   REQUIRE(chamada("teste4.txt") == -1);
//    REQUIRE(chamada("teste3.txt") == -1);
//    REQUIRE(chamada("teste2.txt") == -1);
//    REQUIRE(chamada("teste3.txt") == -1);
}