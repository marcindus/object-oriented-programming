#include "Alcohol.hpp"
Alcohol::Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage)
    : Cargo(amount, name, base_price), percentage_(percentage)
{
}

void Alcohol::Print() const
{
}
std::string Alcohol::GetName() const
{
    return name_;
};

size_t Alcohol::GetPrice() const
{
    return Alcohol::GetBasePrice() * Alcohol::GetAmount();
}

size_t Alcohol::GetAmount() const
{
    return amount_;
}

size_t Alcohol::GetBasePrice() const
{
    return base_price_;
}

Alcohol& Alcohol::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Alcohol& Alcohol::operator-=(size_t amount)
{
    amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const
{
    if (typeid(cargo) == typeid(Alcohol))
    {
        const auto* pAlcohol = dynamic_cast<const Alcohol*>(&cargo);
        return name_ == pAlcohol->GetName() && amount_ == pAlcohol->GetAmount()
               && base_price_ == pAlcohol->GetBasePrice() && percentage_ == pAlcohol->GetPercentage();
    }
    return false;
}

bool Alcohol::operator!=(const Cargo& cargo) const
{
    return not operator==(cargo);
}

size_t Alcohol::GetPercentage() const
{
    return percentage_;
}

std::string Alcohol::GetDescription() const
{
    return "Name: " + name_ + " Amount: " + std::to_string(amount_) + " Price: " + std::to_string(this->GetPrice())
           + " Percentage: " + std::to_string(percentage_);
}

size_t Alcohol::NextDay()
{
    return amount_;
}
std::string Alcohol::GetUniqueStat() const
{
    return std::to_string(GetPercentage());
}
