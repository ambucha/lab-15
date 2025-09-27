// COMSC-210 | Lab 15 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Create movie class with three private member variables: title, writer, year
// Public member functions, getters and setters, and print
class Movie {
    private:
        string title;
        string writer;
        int year;
    public:
        // Getters and setters
        string getTitle() const {return title;}
        void setTitle(string t) {title = t;}
        string getWriter() const {return writer;}
        void setWriter(string w) {writer = w;} 
        int getYear() const {return year;}
        void setYear(int y) {year = y;}

        // Print function
        void print();
};

// print() function with no arguments and no returns
// Goes through and prints each private member variable fo the movie class
void Movie::print() {
    cout << "Movie: " << title << endl;
    cout << "\tYear released: " << year << endl;
    cout << "\tScreenwriter: " << writer << endl << endl;

}

int main() {
    // create the vector to hold the movies
    vector<Movie> movies;

    // create variables to temporarily hold the class components
    string t;
    string w;
    int y;

    // collect the data
    ifstream fin ("data.txt");
    if(fin.good()) {
        // create a while loop that collects the data into temporary variables and then inputs it into the array at the end
        while (getline(fin,t)) {
            fin >> y;
            fin.ignore();
            getline(fin, w);
            Movie tmp;
            tmp.setTitle(t);
            tmp.setWriter(w);
            tmp.setYear(y);
            movies.push_back(tmp);
        }
        fin.close();
    }
    else {
        cout << "Input file not there" << endl;
    }

    // Create a for loop to go through each element in the vector
    for (auto m : movies) {
        m.print();
    }
}