// WildfireCSVManip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
 
// Maybe need to use a structure or a class instead of pairs for the map?
struct Stn{
    double lat;
    double lng;
    string county;
};


int main()
{
    struct Stn s1; s1.lat = 37.718167; s1.lng = -122.197111; s1.county = "Alameda";
    struct Stn s2; s2.lat = 37.598758; s2.lng = -122.053230; s2.county = "Alameda";
    struct Stn s3; s3.lat = 37.663969; s3.lng = -121.885030; s3.county = "Alameda";

    unordered_map<int, Stn> stations1;
    stations1[254] = s1;
    stations1[171] = s2;
    stations1[191] = s3;

    /*
    unordered_map<int, pair<float, float>> stations2;
    stations2[254] = make_pair(float(37.718167), float(-122.197111));
    stations2[171] = make_pair(float(37.598758), float(-122.053230));
    stations2[191] = make_pair(float(37.663969), float(-121.885030));

    for (auto itr = stations1.begin(); itr != stations1.end(); ++itr) {
        cout << "Stations: " << itr->first << " County: " << itr->second.county << endl;
        cout << setprecision(9) << "Latitude: " << itr->second.lat << "\nLongitude: " << itr->second.lng << endl << endl;
    }*/

    fstream fout("modDaily.csv", ios::out);
    fstream fin("daily.csv");

    string line, word, temp, stationID;

    getline(fin, temp);
    fout << temp << ",County,Latitude,Longitude\n";

    // cout << setprecision(9) << stations1[191].lat;

    while (getline(fin, line)) {

        stringstream s(line);

        getline(s, stationID, ',');

        fout << setprecision(9) << line << "," << stations1[stoi(stationID)].county
             << "," << stations1[stoi(stationID)].lat
             << "," << stations1[stoi(stationID)].lng << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
