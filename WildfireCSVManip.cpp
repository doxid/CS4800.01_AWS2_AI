// WildfireCSVManip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
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
    // Code to filter out all the dates that we don't need from the weather station data
    fstream fireIn("WildfireAndWeatherData.csv");
    string header, date, fireLine;
    map<string, int> dates;
    getline(fireIn, header);

    while (getline(fireIn, fireLine)) {
        stringstream fireS(fireLine);

        getline(fireS, date, ',');

        dates[date] = 1;
    }
    fireIn.close();

    fstream weatherIn("test.csv");
    fstream weatherOut("filteredWeatherData.csv", ios::out);
    getline(weatherIn, header);
    weatherOut << header << endl;
    string weatherLine;
    while (getline(weatherIn, weatherLine)) {
        stringstream weatherS(weatherLine);

        getline(weatherS, date, ',');
        
        auto it = dates.find(date);
        if (it != dates.end())
            weatherOut << weatherLine << endl;
    }
    weatherIn.close();
    weatherOut.close();

    /*
    // Code to print out the data from the dates map
    for (auto itr = dates.begin(); itr != dates.end(); ++itr) {
        cout << "Date: " << itr->first << " Value: " << itr->second << endl;
    }
    */

    /*
    // Code to test things.
    struct Stn s1; s1.lat = 37.718167; s1.lng = -122.197111; s1.county = "Alameda";
    struct Stn s2; s2.lat = 37.598758; s2.lng = -122.053230; s2.county = "Alameda";
    struct Stn s3; s3.lat = 37.663969; s3.lng = -121.885030; s3.county = "Alameda";
    unordered_map<int, Stn> stations1;
    stations1[254] = s1;
    stations1[171] = s2;
    stations1[191] = s3;
    */

    /*
    // Code to get data from the Station Text file and store it in a hash map
    unordered_map<int, Stn> stations2;
    fstream stnData("StationLatLong.txt");
    string stnLine, stnID, stnLat, stnLong, stnCounty;
    while (getline(stnData, stnLine)) {
        stringstream stnS(stnLine);
        getline(stnS, stnID, ',');      // Get the station ID from the text file
        getline(stnS, stnLat, ',');     // Get the station Latitude from the text file
        getline(stnS, stnLong, ',');     // Get the station Longitude from the text file
        getline(stnS, stnCounty, ',');     // Get the station County from the text file
        struct Stn s; s.lat = stod(stnLat); s.lng = stod(stnLong); s.county = stnCounty;

        stations2[stoi(stnID)] = s;
    }

    // Code to print all of the station data in the hash map
    for (auto itr = stations2.begin(); itr != stations2.end(); ++itr) {
        cout << "Station: " << itr->first << " County: " << itr->second.county << endl;
        cout << setprecision(9) << "Latitude: " << itr->second.lat << "\nLongitude: " << itr->second.lng << endl << endl;
    }
    stnData.close();
    */

    //// Code to add data from a previous file and then county, latitude, and longitude
    //// to a new csv file
    //fstream fout("modDaily.csv", ios::out);
    //fstream fin("daily.csv");

    //string line, word, temp, stationID;

    //getline(fin, temp);
    //fout << temp << ",County,Latitude,Longitude\n";

    //// cout << setprecision(9) << stations1[191].lat;

    //while (getline(fin, line)) {

    //    stringstream s(line);

    //    getline(s, stationID, ',');

    //    fout << setprecision(9) << line << "," << stations1[stoi(stationID)].county
    //         << "," << stations1[stoi(stationID)].lat
    //         << "," << stations1[stoi(stationID)].lng << "\n";
    //}
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
