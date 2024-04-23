#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Animal{
    string species;
    string name;
    string age;
    string color;
};

istream& operator>>(istream& i, Animal& animal){
    i >> animal.species >> animal.name >> animal.age >> animal.color;
    return i;
}

ostream& operator<<(ostream& os, Animal& animal){
    os << animal.species << " " << animal.name << " " << animal.age << " " << animal.color;
    return os;
}

void search (string attribute, string value, vector<Animal>& shelter){
    if (attribute != "fajta" && attribute != "nev" && attribute != "kor" && attribute != "szin"){
        cout<<"Wrong attribute" << endl;
    }
    for(Animal animal : shelter){
        if(attribute == "fajta" && animal.species == value){
            cout << animal << endl;
        } else if(attribute == "nev" && animal.name == value){
            cout << animal << endl;
        }else if(attribute == "kor" && animal.age == value){
            cout << animal << endl;
        }else if(attribute == "szin" && animal.color == value){
            cout << animal << endl;
        }
    }
}

vector<Animal> fileReader(string fileName){
    vector<Animal> shelter;
    ifstream infile(fileName);
    Animal animal;
    while (infile >> animal){
        shelter.push_back(animal);
    }
    return shelter;
}

int main() {

    vector<Animal> shelter = fileReader("menhely.txt");


    for_each(shelter.begin(),shelter.end(), [](Animal animal) {cout << animal << endl;});

    string attribute;
    cout << "Mi alapjan szeretnel keresni? (fajta, nev, kor, szin)" << endl;
    cin >> attribute;
    string value;
    cout << "Mit keresel? "<< endl;
    cin >> value;

    search(attribute, value, shelter);

    return 0;
}
