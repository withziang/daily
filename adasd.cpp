#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>
#include <limits>
#include <map>
#include <cmath>
#include <deque>
#include <utility>
#include <functional>
#include <fstream>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        //XL -> LX
        //RX -> XR

        //X L L L L L L   L L L L X       R X X X X X X 
        // RXXLRXRXL  XRLXXRRLX
        
        //order R > X > L
        // R and X can store, not for L, R cannot jump through L

        int rStored = 0;
        int xStored = 0;

        int startIndex = 0;
        int endIndex = 0;

        while (startIndex <= start.size()-1 && endIndex <= start.size()-1){
        	cout << startIndex << " " << endIndex << endl;
            // R store check 
            if (rStored != 0 && end[endIndex] == 'L')return false;
            // X store check 
            if (xStored != 0 && end[endIndex] == 'R')return false;

            if (start[startIndex] == end[endIndex]){
                startIndex++;
                endIndex++;
            }else if(start[startIndex] == 'X' && end[endIndex] == 'L'){
                // if start encounter a X
                xStored++;
                startIndex++;
            }else if(start[startIndex] == 'R' && end[endIndex] == 'X'){
                //if start encounter a R
                rStored++;
                startIndex++;
            }else if(end[endIndex] == 'X' && xStored > 0){ //pay back the X
                xStored--;
                endIndex++;
            }else if(end[endIndex] == 'R' && rStored > 0){ //pay back the R
                rStored--;
                endIndex++;
            
            }else{
                return false;
            }
        }
        cout << rStored << " " << xStored << endl;
        cout << startIndex << " " << endIndex << endl;

        //final assessment
        while (rStored != 0){
            if (end[endIndex] == 'R'){
                rStored--;
                endIndex++;
            }else{
                return false;
            }
            
        }
        cout << rStored << " " << xStored << endl;
        cout << startIndex << " " << endIndex << endl;


        while (xStored != 0){
            if (end[endIndex] == 'X'){
                xStored--;
                endIndex++;
            }else{
                return false;
            }
            
        }

        cout << rStored << " " << xStored << endl;
        cout << startIndex << " " << endIndex << endl;
        if (startIndex > start.size() || endIndex > start.size())return false;


        return true;
    }
};


int main(){
	string mystr = "RXXLRXRXL"; // 7
	string end =   "XRLXXRRLX"; // 7

	/*
	0 0 
	1 1 
	2 1
	


	*/
	Solution solu1;
	bool x = solu1.canTransform(mystr,end);
	cout << x;
}