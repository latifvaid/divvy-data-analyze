/*main.cpp*/
//
// Author: Latif Vaid, UIC, Spring 2021
// Assignment: Project 04
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

struct Stations {
    string ID;
    int Capacity;
    double Latitude;
    double Longitude;
    string Name;
    double distence;    
    int howManytimes = 0; //how many times the trip starts
};

struct Trips {
    string tripID;
    string bikeID;
    string startID;
    string endID;
    int duration;
    string startTime;
};

//checking and storig first file into an dy-array

Stations* fileInput(int &fileoneSize) {
    cout << "Please enter name of stations file>" << endl;
    string fileOne;
    cin >> fileOne;
    
    fstream inFile(fileOne);
    if(!inFile.good()){
        cout << "**Error: unable to open output file '" << fileOne << "'" << endl;
        return nullptr;
    }
    inFile >> fileoneSize;
    Stations* S = new Stations[fileoneSize];
    for(int i = 0; i < fileoneSize; i++){
        inFile >> S[i].ID >> S[i].Capacity >> S[i].Latitude >> S[i].Longitude;
        getline(inFile, S[i].Name);
        S[i].Name.erase(0,1);
    }
    return S;
}

//checking and storig sec file into an dy-array

Trips* filetwoInput(int &filetwoSize){
    cout << "Please enter name of bike trips file>" << endl;
    string fileTwo;
    cin >> fileTwo;
    
    fstream infile(fileTwo);
    if(!infile.good()){
        cout << "**Error: unable to open output file '" << fileTwo << "'" << endl;
        return nullptr;
    }
    infile >> filetwoSize;
    Trips* T = new Trips[filetwoSize];
    for(int i = 0; i < filetwoSize; i++){
        infile >> T[i].tripID >> T[i].bikeID >> T[i].startID >> T[i].endID >> T[i].duration >> T[i].startTime;
    }
    return T;
}

//stats command that prints the stats from the file

void cmdStats(Stations* S, int fileoneSize, int filetwoSize){
    int totalCapacity = 0;
//     the total capacity across all the stations
    for(int i = 0; i < fileoneSize; i++){
        totalCapacity += S[i].Capacity;
    }
    cout << "  stations: " << fileoneSize << endl
         << "  trips: " << filetwoSize << endl
         << "  total bike capacity: " << totalCapacity << endl;
}

//duration command (how long was the bike used for)

void cmdDurations(Trips* T, int filetwoSize){
    double* hours = new double[filetwoSize];
    
    int lessThenThirty = 0, 
        betweenThirtySixty = 0, 
        betweenOneTwo = 0,
        betweenTwoFive = 0,
        moreThenFive = 0;
    
    for(int i = 0; i < filetwoSize; i++){
        hours[i] = T[i].duration;
    }
    
    for(int i = 0; i < filetwoSize; i++){
        if(hours[i] <= 1800){
            lessThenThirty++;
        } else if(hours[i]  > 1800 && hours[i] <= 3600){
            betweenThirtySixty++;
        } else if(hours[i]  > 3600 && hours[i] <= 7200){
            betweenOneTwo++;
        } else if(hours[i]  > 7200 && hours[i] <= 18000){
            betweenTwoFive++;
        } else if(hours[i] > 18000){
            moreThenFive++;
        }
    }
    
    cout << "  trips <= 30 mins: " << lessThenThirty << endl
         << "  trips 30..60 mins: " << betweenThirtySixty << endl
         << "  trips 1-2 hrs: " << betweenOneTwo << endl
         << "  trips 2-5 hrs: " << betweenTwoFive << endl
         << "  trips > 5 hrs: " << moreThenFive << endl;
    delete[] hours;
}

void cmdStarting(Trips* T, int filetwoSize){
    //using a temp array so the real data is safe
    
    Trips* copyT = new Trips[filetwoSize];
    for(int i = 0; i < filetwoSize; i++){
        copyT[i] = T[i];
        
    }
    
    int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0,
        six = 0, seven = 0, eight = 0, nine = 0, ten = 0, eleven = 0,
        twelve = 0, thirteen = 0, fourteen = 0, fifteen = 0, sixteen = 0,
        seventeen = 0, eighteen = 0, nineteen = 0, twenty = 0, twenty_one = 0,
        twenty_two = 0, twenty_three = 0;
    for(int i = 0; i < filetwoSize; i++){
        if(copyT[i].startTime.length() == 5){
            copyT[i].startTime.erase(2,1);  //earising : from the time (in our temp array) 
            if(stoi(copyT[i].startTime) >= 1000 && stoi(copyT[i].startTime) < 1100){
                ten++;
            } else if(stoi(copyT[i].startTime) >= 1100 && stoi(copyT[i].startTime) < 1200){
                eleven++;
            } else if(stoi(copyT[i].startTime) >= 1200 && stoi(copyT[i].startTime) < 1300){
                twelve++;
            } else if(stoi(copyT[i].startTime) >= 1300 && stoi(copyT[i].startTime) < 1400){
                thirteen++;
            } else if(stoi(copyT[i].startTime) >= 1400 && stoi(copyT[i].startTime) < 1500){
                fourteen++;
            } else if(stoi(copyT[i].startTime) >= 1500 && stoi(copyT[i].startTime) < 1600){
                fifteen++;
            } else if(stoi(copyT[i].startTime) >= 1600 && stoi(copyT[i].startTime) < 1700){
                sixteen++;
            } else if(stoi(copyT[i].startTime) >= 1700 && stoi(copyT[i].startTime) < 1800){
                seventeen++;
            } else if(stoi(copyT[i].startTime) >= 1800 && stoi(copyT[i].startTime) < 1900){
                eighteen++;
            } else if(stoi(copyT[i].startTime) >= 1900 && stoi(copyT[i].startTime) < 2000){
                nineteen++;
            } else if(stoi(copyT[i].startTime) >= 2000 && stoi(copyT[i].startTime) < 2100){
                twenty++;
            } else if(stoi(copyT[i].startTime) >= 2100 && stoi(copyT[i].startTime) < 2200){
                twenty_one++;
            } else if(stoi(copyT[i].startTime) >= 2200 && stoi(copyT[i].startTime) < 2300){
                twenty_two++;
            } else if(stoi(copyT[i].startTime) >= 2300 && stoi(copyT[i].startTime) <= 2359){
                twenty_three++;
            }
            
        } else if(copyT[i].startTime.length() == 4){
            copyT[i].startTime.erase(1,1);
            if(stoi(copyT[i].startTime) >= 0 && stoi(copyT[i].startTime) < 100){
                zero++;
            } else if(stoi(copyT[i].startTime) >= 100 && stoi(copyT[i].startTime) < 200){
                one++;
            } else if(stoi(copyT[i].startTime) >= 200 && stoi(copyT[i].startTime) < 300){
                two++;
            } else if(stoi(copyT[i].startTime) >= 300 && stoi(copyT[i].startTime) < 400){
                three++;
            } else if(stoi(copyT[i].startTime) >= 400 && stoi(copyT[i].startTime) < 500){
                four++;
            } else if(stoi(copyT[i].startTime) >= 500 && stoi(copyT[i].startTime) < 600){
                five++;
            } else if(stoi(copyT[i].startTime) >= 600 && stoi(copyT[i].startTime) < 700){
                six++;
            } else if(stoi(copyT[i].startTime) >= 700 && stoi(copyT[i].startTime) < 800){
                seven++;
            } else if(stoi(copyT[i].startTime) >= 800 && stoi(copyT[i].startTime) < 900){
                eight++;
            } else if(stoi(copyT[i].startTime) >= 900 && stoi(copyT[i].startTime) <= 959){
                nine++;
            }
        }
    }
    //should have used a forloop
    cout << "  0: " << zero << endl
         << "  1: " << one << endl
         << "  2: " << two << endl
         << "  3: " << three << endl
         << "  4: " << four << endl
         << "  5: " << five << endl
         << "  6: " << six << endl
         << "  7: " << seven << endl
         << "  8: " << eight << endl
         << "  9: " << nine << endl
         << "  10: " << ten << endl
         << "  11: " << eleven << endl
         << "  12: " << twelve << endl
         << "  13: " << thirteen << endl
         << "  14: " << fourteen << endl
         << "  15: " << fifteen << endl
         << "  16: " << sixteen << endl
         << "  17: " << seventeen << endl
         << "  18: " << eighteen << endl
         << "  19: " << nineteen << endl
         << "  20: " << twenty << endl
         << "  21: " << twenty_one << endl
         << "  22: " << twenty_two << endl
         << "  23: " << twenty_three << endl;
    delete[] copyT;
}


//
// distBetween2Points
//
// Returns the distance in miles between 2 points (lat1, long1) and 
// (lat2, long2).  Latitudes are positive above the equator and 
// negative below; longitudes are positive heading east of Greenwich 
// and negative heading west.  Example: Chicago is (41.88, -87.63).
//
// NOTE: you may get slightly different results depending on which 
// (lat, long) pair is passed as the first parameter.
// 
// Originally written by: Prof. Hummel, U. of Illinois, Chicago, Spring 2021
// Reference: http://www8.nau.edu/cvm/latlon_formula.html
//
double distBetween2Points(double lat1, double long1, double lat2, double long2)
{
  double PI = 3.14159265;
  double earth_rad = 3963.1;  // statue miles:

  double lat1_rad = lat1 * PI / 180.0;
  double long1_rad = long1 * PI / 180.0;
  double lat2_rad = lat2 * PI / 180.0;
  double long2_rad = long2 * PI / 180.0;

  double dist = earth_rad * acos(
    (cos(lat1_rad) * cos(long1_rad) * cos(lat2_rad) * cos(long2_rad))
    +
    (cos(lat1_rad) * sin(long1_rad) * cos(lat2_rad) * sin(long2_rad))
    +
    (sin(lat1_rad) * sin(lat2_rad))
  );

  return dist;
}


void cmdnearMe (Stations* S, int fileoneSize, double lat1, double long1, double D){
    double lat2;
    double long2;
    int count = 0;
    for(int i = 0; i < fileoneSize; i++){
        lat2 = S[i].Latitude;
        long2 = S[i].Longitude;
        //adding distance to Stations struct so it is easy to maintain the distance with related station
        
        S[i].distence = distBetween2Points(lat1, long1, lat2, long2);
        if(S[i].distence < D){
            count++;   //to know the size
        }
    }
    cout << "  The following stations are within " << D << " miles of (" << lat1 << ", " << long1 << "):" << endl;
    if(count == 0){
        cout << "  none found";
        //storing all the stations found into an array
    } else {
        Stations* allDis = new Stations[count];
        count = 0;
        for(int i = 0; i < fileoneSize; i++){
            if(S[i].distence < D){
                allDis[count] = S[i];
                count++;
            }
        }
        for(int i = 0; i < count-1; i++){
            int next = i;
            for(int j = i+1; j < count; j++){
                if(allDis[next].distence > allDis[j].distence){
                    next = j;
                }
            }
            Stations temp;
            temp = allDis[i];
            allDis[i] = allDis[next];
            allDis[next] = temp;
        }
        for(int i = 0; i < count; i++){
            cout << "  station " << allDis[i].ID << " (" << allDis[i].Name << "): " << allDis[i].distence << " miles" << endl;
        }
        delete[] allDis;
    }
}

void sortByName(Stations* S, int fileoneSize){
    for (int i = 0; i < fileoneSize-1; i++){
      int min = i;
      
      for (int j = i+1; j < fileoneSize; j++){
         if (S[j].Name < S[min].Name){
            min = j;
         }
      }
        Stations temp = S[i];
        S[i] = S[min];
        S[min] = temp;
    }    
}

int searchByID(Stations* S, int fileoneSize, string name) {
    for(int i = 0; i < fileoneSize; i++){
        if (S[i].ID == name) {
            return i;
        }
    }
    return -1;
}

int searchByName(Stations* S, int fileoneSize, string name, int startAt) {
    for(int i = startAt; i < fileoneSize; i++){
        int index = S[i].Name.find(name);
        if (index != -1) {
            return i;
        }
    }
    return -1;
}



void cmdStation(Stations* S, int fileoneSize){
    for(int i = 0; i < fileoneSize; i++){
        cout << S[i].Name << " (" << S[i].ID << ") @ " << "(" << S[i].Latitude << ", " << S[i].Longitude << "), " << S[i].Capacity << " capacity, " << S[i].howManytimes << " trips" << endl;
    }
}


void cmdFind(Stations* S, int fileoneSize, string name){
    sortByName(S, fileoneSize);
    int index;
    int i = 0;
    int count = 0;
    int startAt = 0;
    while(i < fileoneSize){
        index = searchByName(S, fileoneSize, name, startAt);
        if(index != -1){
            cout << S[index].Name << " (" << S[index].ID << ") @ " << "(" << S[index].Latitude << ", " << S[index].Longitude << "), " << S[index].Capacity << " capacity, " << S[index].howManytimes << " trips" << endl;
            count += 1;
            startAt = index;
        } else if(index == -1 && i == fileoneSize - 1 && count == 0){
            cout << " none found" << endl;
        }
        i++;
        startAt++;
    }
}

void cmdtrips(Trips* T, int filetwoSize, Stations* S, int fileoneSize, string startT, string endT){
    int count = 0;
    int idx = 0;
    int start = 0;
    int end = 0;
    idx = startT.find(":");
    start = stoi(startT.erase(idx,1));
    idx = endT.find(":");
    end = stoi(endT.erase(idx,1));
    
    //copying array
    
    Trips* tempA = new Trips[filetwoSize];
    for(int i = 0; i < filetwoSize; i++){
        tempA[i] = T[i];
    }
    
    for(int i = 0; i < filetwoSize; i++){
        idx = tempA[i].startTime.find(":");
        tempA[i].startTime.erase(idx, 1);
        if(stoi(tempA[i].startTime) >= start && stoi(tempA[i].startTime) <= end){
            count++;
        } else if((start > end)){
            if((stoi(tempA[i].startTime) <= end or stoi(tempA[i].startTime) >= start)){
                count++;
            }
        }
    }
    if(count == 0){
        cout << "  none found" << endl;
    } else {
        Trips* range = new Trips[count];
        
//         storing all the trips found into an array so we can use it to find the name
        
        int j = 0;
        for(int i = 0; i < filetwoSize; i++){
            if(stoi(tempA[i].startTime) >= start && stoi(tempA[i].startTime) <= end){
                Trips temp;
                temp = T[i];
                range[j] = temp;
                j++;
            } else if((start > end)){
                if((stoi(tempA[i].startTime) <= end or stoi(tempA[i].startTime) >= start)){
                    Trips temp;
                    temp = T[i];
                    range[j] = temp;
                    j++;
                }
            }
        }
        cout << "  " << count << " trips found"<< endl;
        int avg = range[0].duration;
        for(int i = 1; i < count; i++){
            avg += range[i].duration;
        }
        avg = avg/count;
        avg = avg/60.0; //convert to mins
        cout << "  avg duration: " << avg << " minutes" << endl;
        
        
        
        Stations* removeDup = new Stations[count];
        int z = 0;
            for(int i = 0; i < count; i++){
                int index = searchByID(S, fileoneSize, range[z].startID);
                removeDup[i].Name = S[index].Name;
                z++;
                
            }
        cout << " ";
        sortByName(removeDup, count);   
        cout << " stations where trip started: ";
        int k = 0;
        while(k < count){
            if(k != count - 1 && removeDup[k].Name == removeDup[k + 1].Name){
                k++;
            } else if(k != count - 1 && removeDup[k].Name != removeDup[k + 1].Name ){
                cout << removeDup[k].Name << ", ";
                k++;
            } else {
                cout << removeDup[k].Name;
                k++;
            }
        }
        /* just a back up*/
//             for(int i = 0; i < count; i++){
//                 Stations Temp;
//                 Temp.Name = removeDup[i].Name;
//                 if(i != count - 1){
//                     if(Temp.Name == removeDup[i + 1].Name){
//                         continue;
//                     } else if(Temp.Name != removeDup[i + 1].Name){
//                         cout << Temp.Name;
//                     }
//                 } else {
//                     cout << Temp.Name;
//                 }
//                 if(i != count - 1){
//                     cout << ", ";
//                 }
//             }
        cout << endl;
        delete[] range;
        delete[] removeDup;
    }
    delete[] tempA;
    
}
//sorting the file as soon as they open so its easy to not run it everytime 

void startUp(Stations* S, int fileoneSize, Trips* T, int filetwoSize) {
    sortByName(S, fileoneSize);
    int a;
    int b;
    for(int i = 0; i < filetwoSize; i++){
        a = searchByID(S, fileoneSize, T[i].startID);
        b = searchByID(S, fileoneSize, T[i].endID);
        if (a == b) {
            S[a].howManytimes++;
        } else {
            S[a].howManytimes++;
            S[b].howManytimes++;
        }
    }
}

/* this function runs all the commands as user asks */


void userCommands(Stations* S, int fileoneSize, Trips* T, int filetwoSize){
    string cmd;
    double lat1;
    double long1;
    double D;
    string name;
    string startT;
    string endT;
    startUp(S, fileoneSize, T, filetwoSize);
    while(cmd != "#"){
        cout << "Enter command (# to stop)> ";
        cin >> cmd;
        if(cmd == "stats"){
            cmdStats(S, fileoneSize, filetwoSize);
        } else if(cmd == "durations"){
            cmdDurations(T, filetwoSize);
        } else if(cmd == "starting"){
            cmdStarting(T, filetwoSize);
        } else if(cmd == "nearme"){
            cin >> lat1;
            cin >> long1;
            cin >> D;
            cmdnearMe(S, fileoneSize, lat1, long1, D);
        } else if(cmd == "stations"){
            cmdStation(S, fileoneSize);
        } else if(cmd == "find"){
            cin >> name;
            cmdFind(S, fileoneSize, name);
        } else if(cmd == "trips"){
            cin >> startT;
            cin >> endT;
            cmdtrips(T, filetwoSize, S, fileoneSize, startT, endT);
                
        } else if(cmd == "#"){
            cout << "** Done **" << endl;
        } else {
            cout << "** Invalid command, try again..." << endl;
        }
        cout << endl;
    }
}
int main()
{
    cout << "** Divvy Bike Data Analysis **" << endl;
    //first file
    int fileoneSize;
    Stations* S = fileInput(fileoneSize);
    
    if(S == nullptr){ //invalid file
        return 0;
    }
    
    //Second file
    int filetwoSize; //number of stations
    Trips* T = filetwoInput(filetwoSize);
    
    if(T == nullptr){ 
        return 0;
    }
    userCommands(S, fileoneSize, T, filetwoSize);
    
    delete[] S;
    delete[] T;
    
    return 0;
}