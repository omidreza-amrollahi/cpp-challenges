// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void ruler()
{
    int total_width = 80;
    std::cout << std::setw(total_width) 
                << std::setfill('-') 
                << "" 
                << std::endl; 
    std::cout << std::setfill(' ');
}


int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };
    ruler();
    int fieldWidth = 20;
    std::cout << std::endl;
    std::cout << std::setw(fieldWidth) << " " << tours.title << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(fieldWidth) << std::left << "Country" 
        << std::setw(fieldWidth) << std::left << "City" 
        << std::setw(fieldWidth) << std::left << "Population" 
        << std::setw(fieldWidth) << std::left << "Cost" 
        << std::endl;
    ruler();
    for (const auto& country : tours.countries) {
        for (size_t i = 0; i<country.cities.size(); ++i) {
            std::cout << std::setw(fieldWidth) << std::left << ((i == 0) ? country.name : "")
                << std::setw(fieldWidth) << std::left << country.cities[i].name
                << std::setw(fieldWidth) << std::left << country.cities[i].population
                << std::setw(fieldWidth) << std::left << country.cities[i].cost
                << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    return 0;
}