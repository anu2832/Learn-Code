#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <vector>
#include <string>

struct City_Information
{
    std::string name;
    double latitude;
    double longitude;
};

// calculating Haversine distance
double calculateHaversineDistance(const City_Information &loc1, const City_Information &loc2)
{
    const double Radius_of_Earth = 6371.0; // Earth's radius in kilometers

    // Converting latitude and longitude into radians
    double location1_Latitude = loc1.latitude * M_PI / 180.0;
    double location1_Longitude = loc1.longitude * M_PI / 180.0;
    double location2_Latitude = loc2.latitude * M_PI / 180.0;
    double location2_Longitude = loc2.longitude * M_PI / 180.0;

    double Longitude_Difference = location2_Longitude - location1_Longitude;
    double Latitude_Difference = location2_Latitude - location1_Latitude;

    double haversineA = std::sin(Latitude_Difference / 2) * std::sin(Latitude_Difference / 2) +
                        std::cos(location1_Latitude) * std::cos(location2_Latitude) * std::sin(Longitude_Difference / 2) * std::sin(Longitude_Difference / 2);

    double haversineC = 2 * std::atan2(std::sqrt(haversineA), std::sqrt(1 - haversineA));
    double distance = Radius_of_Earth * haversineC;

    return distance;
}

void readDataFromCsv(std::string file, std::vector<City_Information> &locations)
{
    std::ifstream inputFile(file);

    if (!inputFile.is_open())
    {
        std::cerr << "File is not there." << std::endl;
        return;
    }

    // Reading data from CSV file
    while (inputFile.good())
    {
        City_Information loc;
        std::getline(inputFile, loc.name, ',');
        inputFile >> loc.latitude;
        inputFile.ignore(1, ',');
        inputFile >> loc.longitude;
        inputFile.ignore(1, '\n');
        locations.push_back(loc);
    }
    inputFile.close();
    return;
}

int main()
{
    std::vector<City_Information> locations;
    readDataFromCsv("data.csv", locations);

    //  latitude radius in kilometers
    double Radius_of_Latitude = 1100.0;

    // Initialize clusters
    std::vector<std::vector<std::string>> totalClusters;
    std::vector<bool> clustered(locations.size(), false);

    for (size_t i = 0; i < locations.size(); ++i)
    {
        if (!clustered[i])
        {
            std::vector<std::string> group;
            group.push_back(locations[i].name);
            clustered[i] = true;

            for (size_t j = 0; j < locations.size(); ++j)
            {
                if (!clustered[j] && calculateHaversineDistance(locations[i], locations[j]) <= Radius_of_Latitude)
                {
                    group.push_back(locations[j].name);
                    clustered[j] = true;
                }
            }
            totalClusters.push_back(group);
        }
    }

    // Printing clusters
    int Number_of_Clusters = 1;
    for (const auto &group : totalClusters)
    {
        std::cout << "Cluster " << Number_of_Clusters++ << ": ";
        for (const std::string &locationName : group)
        {
            std::cout << locationName << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}