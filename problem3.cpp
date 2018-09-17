#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

//Point object
class Point{
    public:
        void setPoint(int x, int y){
            xPos = x;
            yPos = y;
        }
        void printPoint(){
            printf("(%d, %d)\n",xPos, yPos);
        }
        int getX(){
            return xPos;
        }
        int getY(){
            return yPos;
        }

    private:
        int xPos;
        int yPos;
};

double Euclidean(Point p, Point q){
    double distance;
    distance = sqrt(pow((p.getY()-q.getY()),2) + pow((p.getX()-q.getX()),2));
    return distance;
}

double Manhattan(Point p, Point q){
    double distance;
    distance = abs(p.getY()-q.getY()) + abs(p.getX()-q.getX());
    return distance;
}

void fillVector (vector<Point>& vect, int n){
    Point tempPoint;
    for (int i = 0; i < n; i++){
        int x, y;
        x = (rand()%50+1);
        y = (rand()%50+1);
        tempPoint.setPoint(x,y);
        vect.push_back(tempPoint);
    }
    for (Point p : vect)
        p.printPoint();
}

int main(){

    srand(time(NULL));
    //min distancePoint p : vect
    double minimum = 1000;
    //min point
    Point minPoint;

    //User input number of points
    int numberOfPoints;
    cout << "Input number of points in the vector: ";
    cin >> numberOfPoints;

    //Randomly generate points for vector
    vector<Point> v(0);
    fillVector(v, numberOfPoints);

    //User input test point
    Point testPoint;
    int testX, testY;
    cout << "Enter a test point. What is the x position: ";
    cin >> testX;
    cout << "What is the y position: ";
    cin >> testY;
    testPoint.setPoint(testX,testY);

    //User determines distance calculation method
    int c;
    //temporary point values
    int tempX, tempY;

    do{
        cout << "\nWhich distance calculation method would you like to use?" << endl;
        cout << "\n[0] Euclidean" << endl;
        cout << "[1] Manhattan" << endl;
        cout << "[2] Exit" << endl;
        cin >> c;

        switch(c){
            case 0:
                minimum = 1000;
                minPoint.setPoint(0,0);
                for (Point p : v){
                    int tempX = p.getX();
                    int tempY = p.getY();
                    p.setPoint(tempX,tempY);
                    if (Euclidean(testPoint, p) < minimum){
                        minimum = Euclidean(testPoint, p);
                        minPoint = p;
                    }
                }
                //Display closest neighbor
                cout << "\nThe closest neighbor to the test point is the point at ";
                minPoint.printPoint();
                printf("With a distance of %.2f\n", minimum);
                break;
            case 1:
                minimum = 1000;
                minPoint.setPoint(0,0);
                for (Point p : v){
                    int tempX = p.getX();
                    int tempY = p.getY();
                    p.setPoint(tempX,tempY);
                    if (Manhattan(testPoint, p) < minimum){
                        minimum = Manhattan(testPoint, p);
                        minPoint = p;
                    }
                }
                //Display closest neighbor
                cout << "\nThe closest neighbor to the test point is the point at ";
                minPoint.printPoint();
                printf("With a distance of %.2f\n", minimum);
                break;
            case 2:
                break;
            default:
                cout << "That is not an option. Please choose a valid option" << endl;
        }
    }while(c!=2);


    return 0;
}
