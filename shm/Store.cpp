//
// Created by adi on 07.07.2020.
//
#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>

#include "Item.hpp"
#include "Store.hpp"
#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Time.hpp"

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player)
{
    auto totalPrice = amount * cargo->GetPrice();

    if (cargo->GetAmount() < amount)
    {
        return Response::lack_of_cargo;
    }

    if (player->getAvailableSpace() < amount)
    {
        return Response::lack_of_space;
    }

    if (player->getMoney() < totalPrice)
    {
        return Response::lack_of_money;
    }

    player->spendMoney(totalPrice);
    player->getShip()->load(std::shared_ptr<Cargo>(cargo));
    return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player)
{
    auto foundCargoIt = std::find_if(player->getCargos().begin(), player->getCargos().end(), [cargo](auto otherCargo) {
        return *cargo == *otherCargo;
    });

    if (foundCargoIt == player->getCargos().end() || foundCargoIt->get()->GetAmount() < amount)
    {
        return Response::lack_of_cargo;
    }

    size_t totalPrice = foundCargoIt->get()->GetPrice() * amount;
    player->setMoney(player->getMoney() + totalPrice);

    cargo -= amount;
    if (cargo->GetAmount() == 0)
    {
        player->getShip()->unload(cargo);
    }

    return Response::done;
}

void Store::NextDay()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> amount(-100,100);
    for(const auto& cargo_ptr : cargo_)
    {
                *cargo_ptr += amount(gen);
    }

}

Store::Store(Time& time) : time_(time)
{
    time_.addObserver(this);
}

Store::~Store()
{
    time_.removeObserver(this);
}

void Store::GenerateCargo()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> Amount(0, 200);

    cargo_.push_back(std::make_unique<Fruit>(Amount(gen), "Apple", 3, 12));
    cargo_.push_back(std::make_unique<Fruit>(Amount(gen), "RottenApple", 1, 12, 11));
    cargo_.push_back(std::make_unique<Alcohol>(Amount(gen), "TemerskaZytnia", 10, 40));
    cargo_.push_back(std::make_unique<Alcohol>(Amount(gen), "KadwenskiLager", 2, 12));
    cargo_.push_back(std::make_unique<Alcohol>(Amount(gen), "MahakamskiSpirytus", 10, 197));

}
std::ostream& operator<<(std::ostream& out, const Store& store)
{
    const std::string horizontalSeparator(80, '=');
    size_t i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| AVAILABLE PRODUCTS "
        << std::setw(25) << "| QTY "
        << "| BUY PRICE "
        << "| SELL PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : store.cargo_) {
        std::string uniqueStat;
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(15) << std::left << el->GetName();
        if (typeid(*el) == typeid(Alcohol)) {
            uniqueStat += " (" + el->GetUniqueStat() + "% vol)";
        }
        else if (typeid(*el) == typeid(Fruit)) {
            uniqueStat += " (" + el->GetUniqueStat() + " days to rot)";
        }
        else if (typeid(*el) == typeid(Item)) {
            uniqueStat += " (" + el->GetUniqueStat() + ")";
        }
        out << std::setw(18) << std::left << uniqueStat << " | ";
        out << std::setw(3) << std::right << el->GetAmount() << " | "
            << std::setw(10) << std::right << el->GetPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
