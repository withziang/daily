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
#include <stdio.h>
#include <unistd.h>

using namespace std;

/*common variable*/
float incrementSpeed = 0.5;
int distancefromcamera = 60;
float angle1, angle2, angle3; /*x-axis, y-axis, z-axis*/
int width = 160, hwight = 80;
float kbuffer[width * height];   
char buffer[width * height];
int backgroundASCIICode = ' ';


/*individual variable*/
float x,y,z;
float cubewidth = 10;


float xAxisCalculator(int i, int j, int k){
	return cos(angle1)*cos(angle2)*i + 
		   cos(angle1)*sin(angle2)*sin(angle3)*j - sin(angle1)*cos(angle3)*j
		   + cos(angle1)*sin(angle2)*cos(angle3)*k - sin(angle1)*sin(angle3)*k;
}

float yAxisCalculator(int i, int j, int k){
	return sin(angle1)*sin(angle2)*i +
			sin(angle1)*sin(angle2)*sin(angle3)*j +cos(angle1)*cos(angle3)*j +
			sin(angle1)*sin(angle2)*cos(angle3)*k -cos(angle1)*sin(angle3)*k;
}

float zAxisCalculator(int i, int j, int k){
	return -sin(angle2)*i
			+cos(angle2)*sin(angle3)*j
			+cos(angle2)*cos(angle3)*k;
}


void surfaceCalculate(float cubeX, float cubeY, float cubeZ, int ch){
	x = xAxisCalculator(cubeX,cubeY,cubeZ);
	y = yAxisCalculator(cubeX,cubeY,cubeZ);
	z = zAxisCalculator(cubeX,cubeY,cubeZ) + distancefromcamera;

	
}

int main(){

	printf("\x1b[2J");  /*clear the terminal*/

	while (1){
		/*assign ' ' and 0  to all the buffer and kbuffer */
		memset(rotatingObject1.buffer, rotatingObject1.backgroundASCIICode, rotatingObject1.width * rotatingObject1.height); 
		memset(rotatingObject1.kbuffer, 0, rotatingObject1.width*rotatingObject1.height*4);

		for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      		for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
       			calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
		        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
		        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
		        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
		        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
		        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

		printf("\x1b[H"); //put cursor at the top of the screen

		for (int k = 0; k< width*height;k++){
			putchar(k % width ? buffer[k] : 10);  /*10(ASCII))*/
		}
		

		usleep(100);
	}
	angle1 += 0.05;
	angle2 += 0.05;
	angle3 += 0.01;

	return 0;
}