#include "Cargo.hpp"
#include "Item.hpp"
#include "Store.hpp"

#include "gtest/gtest.h"

#include "TimeMock.hpp"
#include "StoreMock.hpp"
#include "ObserverMock.hpp"

using ::testing::_;

TEST(store, observerShouldBeAddedWhenCargoCreated)
{
    testing::StrictMock<ObserverMock> obsMock;
    testing::StrictMock<TimeMock> timeMock;

    EXPECT_CALL(timeMock, addObserver(_));
    EXPECT_CALL(timeMock, removeObserver(_));
    Store storeA(timeMock);
}

TEST(store, streamOperatorShouldReturnDescription)
{
    testing::StrictMock<ObserverMock> obsMock;
    testing::StrictMock<TimeMock> timeMock;
    Store storeA(timeMock);
    size_t amount{10};
    Item itemA{amount, "item", 0, Item::Rarity::common}, itemB{amount, "item", 0, Item::Rarity::common};
//    storeA.Buy(&ItemA)
}
