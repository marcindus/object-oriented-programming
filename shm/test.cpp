#include <vector>
#include <set>
#include <algorithm>

#include "Cargo.hpp"
#include "Island.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "gtest/gtest.h"

TEST(cargo, TwoCargosWithTheSameAmountShouldBeEqual)
{
    Cargo cargoA, cargoB;
    cargoA += 10;
    cargoB += 10;
    ASSERT_EQ(cargoA, cargoB);
}

TEST(cargo, TwoCargosWithDifferentAmountShouldNotBeEqual)
{
    Cargo cargoA, cargoB;
    cargoA += 10;
    cargoB += 100;
    ASSERT_NE(cargoA, cargoB);
}

TEST(cargo, TwoCargosWithDifferentAmountShouldNotBeEqualWithGetters)
{
    Cargo cargoA(10, 1), cargoB(100, 2);
    EXPECT_FALSE(cargoA.getAmount() == cargoB.getAmount());
    cargoA += 90;
    EXPECT_EQ(cargoA.getAmount(), cargoB.getAmount());
}

TEST(island, twoIslandsPositionsShouldBeEqual)
{
    Island A(9, 9), B(9, 9);
    EXPECT_EQ(A.getPosition(), B.getPosition());
}

TEST(player, newSpaceWasSet)
{
    Ship ship;
    Player player(ship, 0, 0);
    size_t space = 10;
    player.setAvailableSpace(space);
    EXPECT_EQ(player.getAvailableSpace(), space);
}

TEST(player, newMoneyAmountWasSet)
{
    Ship ship;
    Player player(ship, 0, 0);
    size_t money = 10;
    player.setAvailableSpace(money);
    EXPECT_EQ(player.getAvailableSpace(), money);
}

TEST(Map, mapWithOneIsland)
{
    Map map_(1, 1, 1);
    Island island_{Island(0, 0)};
    EXPECT_EQ(map_.getIslands().at(0).getPosition(), island_.getPosition());
}

TEST(Map, mapWith10uniqueIslands)
{
    Map map_;
    std::vector<Island> islands = map_.getIslands();
    std::set<std::pair<int, int>> set_;
    for (auto& is : islands)
        set_.insert(std::make_pair(is.getPosition().position_x, is.getPosition().position_y));

    EXPECT_EQ(map_.getIslands().size(), set_.size());
}


TEST(Map, getIslandShouldRTeturnIsland)
{
    Map map_;
    std::vector<Island> islands = map_.getIslands();
    Island island_ = islands[4];
    Coordinates corr{99999,99999};

    EXPECT_EQ(map_.getIsland(corr).getPosition(), corr);
}








