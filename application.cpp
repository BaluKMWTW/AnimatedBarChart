/*
Jan Komorowski - jankomorowski.01@gmail.com
AnimatedBarChart is a program that creates and animated console chart that refreshes the console (where each refresh is a new frame)
it shows the comparsion of big data that changes with time such as population of x biggest cities in the world
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


// int main() {
	
// 	string filename = "cities.txt";
// 	ifstream inFile(filename);
// 	string title;
// 	getline(inFile, title);
// 	string xlabel;
// 	getline(inFile, xlabel);
// 	string source;
// 	getline(inFile, source);

// 	BarChartAnimate bca(title, xlabel, source);
	
// 	while (!inFile.eof()) {
// 		bca.addFrame(inFile);
// 	}
	
// 	bca.animate(cout, 12, -1);

//     return 0;
// }
int main()
    {
		Bar b1("adam", 16, "u");
		//cout<<b1<<endl;
        BarChart bc1(45);
		bc1.addBar("krzysztof", 17, "u");
		// bc1.dump(cout);

        // wypelniam bc1
        BarChart bc2(bc1);  //Jawne wywolanie konstrukora kopiującego
        BarChart bc3 = bc1; //wywolanie konstrukora kopiującego

        // bc2 = bc3;  //wywołanie operator= (wywoluje sie automatycznie jezeli nie ma zdefiniowanego)
		// bc2.addBar("ola", 18, "u");
		// cout<<"bc2"<<endl;
		// bc2.dump(cout);
		// cout<<"bc3"<<endl;
		// bc3.dump(cout);
        //cout<<"czesc "<<bc2[0]<<endl;
		BarChart bc4(5);
		bc4.addBar("n1", 17, "US");
		bc4.addBar("n2", 21, "US");
		bc4.addBar("n3", 3, "France");
		bc4.addBar("n4", 49, "POLAND");
		bc4.addBar("n5", 1, "France");

		string red("\033[1;36m");
		string blue("\033[1;33m");
		map<string, string> colorMap;
		colorMap["US"] = red;
		colorMap["France"] = blue;
		
		// bc4.setFrame("frame");
		// cout<<bc4.getFrame()<<'\n';
		// cout<<bc4.getSize()<<'\n\;
		//bc4.graph(cout, colorMap, 5);
		cout<<"Wczytywanie pliku"<<endl;
		ifstream file;
		file.open("cities.txt");
		

		string title;
        string xlabel;
        string source;
        string empty;
		getline(file, title);
        getline(file, xlabel);
        getline(file, source);
        getline(file, empty);//1st empy line
		BarChartAnimate bca1(title, xlabel, source);
		int count = 0;
		while(!file.eof()){
			bca1.addFrame(file);
			//++count;
		}
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		// bca1.addFrame(file);
		bca1.animate(cout, 12, -1);

		return 0;
    }
