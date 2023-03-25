#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//entity of the car
class Car
{

public:

	Car() : Car("", 0, 0, 0) {}
	Car(std::string _name, int _year, double _capacity, int _price)
		:name{ _name }, year{ _year }, capacity{ _capacity }, price{ _price } {}

	std::string Name() { return name; }
	int Year() { return year; }
	double Capacity() { return capacity; }
	int Price() { return price; }

	friend std::ostream& operator<<(std::ostream& out, const Car& temp)
	{
		out << temp.name << " " << temp.year << " " << temp.capacity << " " << temp.price << "$" << std::endl;
		return out;
	}

	//overloading the comparison function for the correct operation of deleting a vector element by its value
	friend bool operator==(const Car& temp1, const Car& temp2)
	{
		if (temp1.name == temp2.name && temp1.capacity == temp2.capacity && temp1.year == temp2.year && temp1.price == temp2.price)
			return true;
		else
			return false;
	}


protected:

	std::string name;
	int year;
	double capacity;
	int price;

};

class Dealer
{
	
public:

	//function of adding a car to the dealer
	void addCar(Car temp) { list.push_back(temp); }

	//car removal function
	void delCar(Car temp) { list.erase(std::remove(list.begin(), list.end(), temp), list.end()); }

	//sorting the catalog by the selected value
	void Sort(std::string type)
	{
		bool flag = false;
		for (int i = 0; i < list.size(); i++)
		{
			if (flag)
				break;
			for (int j = 0; j < list.size()-1; j++)
			{
				if (type == "Name")
				{
					if (list[j].Name()[0] > list[j + 1].Name()[0]) 
					{
						Car b = list[j];
						list[j] = list[j + 1];
						list[j + 1] = b;
					}
				}
				else if (type == "Year")
				{
					if (list[j].Year() > list[j + 1].Year())
					{
						Car b = list[j];
						list[j] = list[j + 1];
						list[j + 1] = b;
					}
				}
				else if (type == "Capacity")
				{
					if (list[j].Capacity() > list[j + 1].Capacity())
					{
						Car b = list[j];
						list[j] = list[j + 1];
						list[j + 1] = b;
					}
				}
				else if (type == "Price")
				{
					if (list[j].Price() > list[j + 1].Price())
					{
						Car b = list[j];
						list[j] = list[j + 1];
						list[j + 1] = b;
					}
				}
				else
				{
					std::cout << "Invalid choice" << std::endl;
					flag = true;
					break;
				}
			}
		}
	}

	void Find(std::string type, std::string value)
	{
		for (auto item : list)
		{
			if (type == "Name")
			{
				if (item.Name() == value)
					std::cout << item << std::endl;
			}

			else if (type == "Year")
			{
				if (item.Year() == stoi(value))
					std::cout << item << std::endl;
			}

			else if (type == "Capacity")
			{
				if (item.Capacity() == stoi(value))
					std::cout << item << std::endl;
			}

			else if (type == "Price")
			{
				if (item.Price() == stoi(value))
					std::cout << item << std::endl;
			}
			else
			{
				std::cout << "Invalid choice" << std::endl;
				break;
			}
		}
		std::cout << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Dealer& temp)
	{
		if (!temp.list.empty())
			for (auto item : temp.list)
				out << item.Name() << " " << item.Year() << " " << item.Capacity() << " " << item.Price() << "$" << std::endl;
		else
			out << "This dealer doesn't have any cars" << std::endl;
		
		return out;
	}


protected:

	std::vector<Car>list;

};

int main()
{
	Car mazda("Miata", 1989, 1.6, 2000);
	Car toyota("GT86", 2012, 2.0, 10000);
	Car mitsubishi("Evolution VI", 1999, 2.0, 20000);

	Dealer deal;
	deal.addCar(mazda);
	deal.addCar(toyota);
	deal.addCar(mitsubishi);

	std::cout << deal << std::endl;

	deal.Sort("Name");
	std::cout << deal << std::endl;

	deal.Sort("Year");
	std::cout << deal << std::endl;

	deal.Sort("Capacity");
	std::cout << deal << std::endl;

	deal.Sort("Price");
	std::cout << deal << std::endl;

	deal.Find("Year", "1999");

	deal.delCar(mazda);

	std::cout << deal << std::endl;
	return 0;
}