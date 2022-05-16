//
// Created by etudiant on 22-05-03.
//
#include "Pile.h"
#include "gtest/gtest.h"

TEST(Pile, constructeur_noexcept) {
    EXPECT_NO_THROW(Pile<int> p) ;
}

TEST(Pile, constructeur_capacite_non_valide_throw) {
    EXPECT_THROW(Pile<int> p(0), std::runtime_error) ;
}

TEST(Pile, pop_pile_vide_throw) {
    Pile<int> p ;
    EXPECT_THROW(int v = p.pop(), std::runtime_error) ;
}

TEST(Pile, push_pile_pleine_throw) {
    Pile<int> p(1) ;
    p.push(4) ;
    EXPECT_THROW(p.push(5), std::runtime_error) ;
}

TEST(Pile, pile_initiale_vide) {
    Pile<int> p ;
    EXPECT_TRUE(p.vide()) ;
}

TEST(Pile, push_non_vide) {
    Pile<int> p ;
    p.push(1) ;
    EXPECT_FALSE(p.vide()) ;
}

TEST(Pile, push_pop_recupere_valeur) {
    Pile<int> p ;
    p.push(1) ;
    EXPECT_EQ(1, p.pop()) ;
}

TEST(Pile, push_pop_redevient_vide) {
    Pile<int> p ;
    p.push(1) ;
    p.pop() ;
    EXPECT_TRUE(p.vide()) ;
}

TEST(Pile, push_pop_sequence) {
    Pile<int> p ;
    std::vector<int> vtest {1, 2, 3, 4, 5, 6} ;
    for (auto e: vtest) p.push(e) ;
    for (int j = static_cast<int> (vtest.size()) - 1 ; j >= 0  ; --j)
        EXPECT_EQ(vtest.at(j), p.pop()) ;
    EXPECT_THROW(p.pop(), std::runtime_error) ;
}