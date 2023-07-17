/*!
Наследование - Множественное и ромбовидное
Задание на композицию
Используя механизм множественного наследования разработайте класс “Существо”. Должны
быть классы “Конечности», «Голова», «Тело» и т.д. Все классы органов должны иметь
общий базовый класс "Орган".
Продемонстрируйте в функции main работу класса "Существо" как с методами радителе так
и общего базового класса. А так же передачу объекта по интерфесу любого из родителских
классов включая базовый.
``` задание сдаётся в виде архива проекта либо ссылки на репозиторий
*/
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <string>

class Organ
{
public:
	Organ() = default;
	Organ(std::string name) : name_(name) {}
	std::string GetName()
	{
		return name_;
	}
protected:
	void SetName(const std::string& name)
	{
		name_ = name;
	}

private:
	std::string name_;
};

class Limb : virtual public Organ
{
public:
	Limb() = default;
	Limb(std::string name, size_t numberOfLimbs)
		: Organ(), numberOfLimbs_(numberOfLimbs)
	{
		SetName(name);
	}
	size_t GetNumberOfLimbs() const
	{
		return numberOfLimbs_;
	}
	std::string GetNameOfLimb()
	{
		return GetName();
	}

private:
	size_t numberOfLimbs_=0;

};

class Head : virtual public Organ
{
public:
	Head() = default;
	Head(std::string name, size_t numberOfEyes, std::string colorOfHair)
		: Organ(), numberOfEyes_(numberOfEyes), colorOfHair_(colorOfHair)
	{
		SetName(name);
	}
	size_t GetNumberOfEyes() const
	{
		return numberOfEyes_;
	}
	std::string GetColorOfHair() const
	{
		return colorOfHair_;
	}
	std::string GetNameOfHead()
	{
		return GetName();
	}
	
private:
	size_t numberOfEyes_=0;
	std::string colorOfHair_;

};

class Torso : virtual public Organ
{
public:
	Torso() = default;
	Torso(std::string name, std::string description)
		: Organ(), description_(description) 
	{
		SetName(name);
	}
	std::string GetDescription()
	{
		return description_;
	}
	std::string GetNameOfTorso()
	{
		return GetName();
	}

private:
	std::string description_;

};

class Creature : public Torso, public Limb, public Head
{
public:
	//Creature() {}
	Creature(std::string nameOfLimb, size_t numberOfLimbs, 
		std::string nameOfHead, size_t numberOfEyes, std::string colorOfHair,
		std::string nameOfTorso, std::string description)
		: limb_(nameOfLimb, numberOfLimbs),
		head_(nameOfHead, numberOfEyes, colorOfHair),
		torso_(nameOfTorso, description){}
	Limb& GetLimb()
	{
		return limb_;
	}
	Head& GetHead()
	{
		return head_;
	}
	Torso& GetTorso()
	{
		return torso_;
	}

private:
	Limb limb_;
	Head head_;
	Torso torso_;
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	/*Limb limb_octopus("tentacle", 8);
	Head head_octopus("head-torso", 2, "no hair");
	Torso torso_octopus("no torso", "head is the torso");
	Creature octopus(limb_octopus, head_octopus, torso_octopus);*/
	Creature octopus("tentacle", 8, "head-torso", 2, "no hair", "no torso", "head is the torso");
	std::cout << "Осьминог имеет:\n";
	std::cout << octopus.GetHead().GetNameOfHead()
		<< " c волосами цвета - " << octopus.GetHead().GetColorOfHair() << "\n"
		<< "количество глаз - " << octopus.GetHead().GetNumberOfEyes() << "\n"
		<< "количество " << octopus.GetLimb().GetNameOfLimb() << " - " << octopus.GetLimb().GetNumberOfLimbs() << "\n"
		<< "туловище - " << octopus.GetTorso().GetNameOfTorso() << "\n"
		<< "описание туловища - " << octopus.GetTorso().GetDescription() << "\n\n\n";

	Creature bear("paw", 4, "head", 2, "brawn", "torso", "torso with small tail");
	std::cout << "Медведь имеет:\n";
	std::cout << bear.GetHead().GetNameOfHead()
		<< " c волосами цвета - " << bear.GetHead().GetColorOfHair() << "\n"
		<< "количество глаз - " << bear.GetHead().GetNumberOfEyes() << "\n"
		<< "количество " << bear.GetLimb().GetNameOfLimb() << " - " << bear.GetLimb().GetNumberOfLimbs() << "\n"
		<< "туловище - " << bear.GetTorso().GetNameOfTorso() << "\n"
		<< "описание туловища - " << bear.GetTorso().GetDescription() << "\n";
	return 0;
}
