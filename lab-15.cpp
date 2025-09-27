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
        string getTitle() {return title;}
        void setTitle(string t) {t = title;}
        string getWriter() {return writer;}
        void setWriter(string w) {w = writer;} 
        int getYear() {return year;}
        void setYear(int y) {y = year;}

        // Print function
        void print();
};

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
        while (fin >> t) {
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

    

}