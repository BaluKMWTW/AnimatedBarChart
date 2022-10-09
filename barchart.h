// barchart.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
 const string BLACK("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Replit (dark mode terminal)
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
    
 public:
    
    // default constructor:
    BarChart() {
    capacity = 0;
    size = 0;
    bars = nullptr;
    frame = "";
    
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
       
        bars = new Bar[n];
        // TO DO:  Write this constructor.
        this->capacity = n;
        this->size = 0;
        this->frame = "";
        
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        
        // TO DO:  Write this constructor.
        this->bars = new Bar[other.capacity];  // pointer to a C-style array

        try
        {
            for(int i=0; i<other.size; ++i)
                this->bars[i] = other.bars[i];
            this->frame = other.frame;//string can cause exception   
        }
        catch(const std::exception& e)
        {
            delete [] this->bars;
            std::cerr << e.what() << '\n';
            throw e;
        }
        
        this->capacity = other.capacity;
        this->size = other.size;     
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
/*
    BarChart& operator=(const BarChart& other) {
        BarChart temp(other);

        Bar* n_bars = this->bars;
        this->bars = temp.bars;
        temp.bars = n_bars;

        this->capacity = other.capacity;
        this->size = other.size;
        this->frame.swap(temp.frame);

        return *this;  
    }
*/
    BarChart& operator=(const BarChart& other) {

        Bar* n_bars = new Bar[other.capacity];  // pointer to a C-style array

        try
        {
            for(int i=0; i<other.size; ++i)
                n_bars[i] = other.bars[i];
            this->frame = other.frame;  //WYJATEK!?!?!      
        }
        catch(const std::exception& e)
        {
            delete [] n_bars;
            std::cerr << e.what() << '\n';
            throw e;
        }

        delete [] this->bars;
        this->bars = n_bars;

        this->capacity = other.capacity;
        this->size = other.size;

        return *this;

       // BarChart bc;
        
        // TO DO:  Write this operator.
        
        //return bc;   // TO DO:  update this, it is only here so code compiles.
    }

    /*int main()
    {
        BarChart bc1(45);

        // wypelniam bc1
        BarChart bc2(bc1);  //Jawne wywolanie konstrukora kopiującego
        BarChart bc3 = bc1; //wywolanie konstrukora kopiującego

        bc2 = bc3;  //wywołanie operator=

        (3 + 4) * 5
        (bc1 += bc2) += bc3;

    }*/

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        
        // TO DO:  Write this operator.
        delete [] bars;
        this->capacity = 0;
        this->size = 0;
        this->bars = nullptr;
        this->frame = "";
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {

        // TO DO:  Write this destructor.
        delete [] bars;
        
    }
    
    // setFrame
    void setFrame(string frame) {
    	
        this->frame = frame;
        
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        
        // TO DO:  Write this function.
        
        
        return this->frame; // TO DO:  update this, it is only here so code compiles.
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        
        // TO DO:  Write this function.
        
        if(size<capacity){
            Bar b(name, value, category);
            bars[size] = b;//possible exception
            size++;
            return true;
        }else{
            return false; //return false if no room
        }
        //wyjatek wartosci zwracane + wyjatek
        
        
      // TO DO:  update this, it is only here so code compiles.
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        
        // TO DO:  Write this function.
        
        return size;  // TO DO:  update this, it is only here so code compiles.
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        if(i>size){
            throw runtime_error("BarChart: i out of bounds");
        }
        // TO DO:  Write this function.
        
        return bars[i];  // TO DO:  update this, it is only here so code compiles.
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        
        for(int i=0; i<size; ++i){
            output<<bars[i]<<endl;
        }
       
        //output = cout;
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        string color = "\033[1;36m";  // you should get this from colorMap
        string barstr = "";
        
        // string bar_arr[top][lenMax];
        multimap<int, Bar*> sortedBars;
        int maxValue = 0;

        for(int i = 0; i<size; i++){
            Bar& b = bars[i];
            int value = b.getValue();
            if(value>maxValue)
                maxValue = value;
            sortedBars.insert(pair<int, Bar*> (value, &b));
        }
        
        //for(auto e: sortedBars){
        for(auto t = sortedBars.rbegin(); t!=sortedBars.rend(); ++t){//iterate through sortedBars
            auto e = *t;//e is the object that t is pointing to
            cout<<e.first<<" "<<*e.second<<endl;
            string color = BLACK;
            auto it = colorMap.find(e.second->getCategory());//look for the category, it doesnt exist return .end
            if(it != colorMap.end())
                color = it->second;

            int lenght = ((float)e.first/maxValue)*lenMax; //set relative lenght for bar
            for(int i = 0; i<lenght; i++ ){
                cout<<color<<BOX;
            }

            cout<<endl;

        }
        cout<<BLACK;

        
        // for(int i = size-1; i>=0; --i ){
        //     for( auto e: colorMap){
        //         if(e.first = n_bc[i].category){

        //         }else{
        //             //print black
        //         }
        //     }
        // }
        // for (int i = 0; i < lenMax; i++) {
        //     barstr += BOX;
        // }
        // output << color << barstr << endl;
    	
        // TO DO:  Write this function.
        
    }
    

};

