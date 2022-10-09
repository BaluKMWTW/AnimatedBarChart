// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
#include <string.h>
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source):title(title),xlabel(xlabel), source(source) {
        
        // TO DO:  Write this constructor.
        barcharts = new BarChart[4];

        size = 0;
        capacity = 4;
        
       //colorMap.insert(pair<string, string>("", ""));//should I include that??
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
    
        // TO DO:  Write this destructor.
        delete [] barcharts;
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
    	
        // TO DO:  Write this constructor.
        // string title;
        // string xlabel;
        // string source;
        // string empty;
        // //BarChartAnimate(string title, string xlabel, string source)
        // //get first 3 lines of the file+empty line
        // getline(file, title);
        // getline(file, xlabel);
        // getline(file, source);
        // getline(file, empty);//1st empy line

        //loop getting the chunk of bars from the file
       
        string line;
        vector<stringstream> data;
        string frame;
        string name;
        string value;//needs conversion to int
        int val;//converted value
        string category;
        string s_number;
        
        string trash;

        getline(file, s_number, '\n');
        int number = stoi(s_number); //needed for the loop WYJATEK!!!!
        int actual_number = 0;
        while(getline(file, line)&&(!line.empty())){
            data.push_back(stringstream (line));//read in all data from each line into the vector
            actual_number++;           
           // cout<<line<<endl;
        }
        //cout<<"actual number: "<<actual_number<<endl;
        if(size == capacity){
            BarChart* temp = new BarChart[capacity*2];
            // memcpy(temp, barcharts, capacity*sizeof(BarChart));
            for(int i = 0; i< capacity; ++i){
                temp[i] = barcharts[i];
            }
            delete[] barcharts;
            barcharts = temp;
            capacity *= 2;
        }
        barcharts[size] = BarChart(number);
        BarChart& bc = barcharts[size];
        size++;
        for(int i = 0; i<number; ++i){//assign values and create barchart
            stringstream& s = data[i];
            getline(s, frame, ',');
            getline(s, name, ',');
            getline(s, trash, ',');
            getline(s, value, ',');
            getline(s, category, '\n');
            //cout<<frame<<"   ";
            // frame = data[0+i];
            // name = data[1+i];
            // //2+i is useless
            // value = data[3+i];
            //cout<<"value: "<<value<<endl;
            val = stoi(value);
            bc.setFrame(frame);
            // category = data[4+i];
            bc.addBar(name, val, category);
            //cout<<category<<endl;
        }
        //bc.graph(cout, colorMap, number);
        
        
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 10000;
        if(endIter == -1){
            endIter = size;
        }
        // TO DO:  Write this function.
        for(int i = 0; i<endIter; ++i){
            output<<CLEARCONSOLE;
            cout<<title<<endl;
            cout<<source<<endl;
            barcharts[i].graph(output, colorMap, top);
            cout<<xlabel<<endl;
            cout<<"Frame: "<<barcharts[i].getFrame()<<endl;
            usleep(3*microsecond);
        }
			
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return 0;  // TO DO:  update this, it is only here so code compiles.
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //


    //czy to nie jest metoda dla barchart?
    BarChart& operator[](int i){
       
        
        // TO DO:  Write this function.
        
        return barcharts[i]; // TO DO:  update this, it is only here so code compiles.
    }
};
