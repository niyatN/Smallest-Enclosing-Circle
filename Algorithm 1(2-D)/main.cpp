#include <iostream>
#include <math.h>
using namespace std;
struct point{
    float x;
    float y;
};

float distanceBetweenPoint(float x1,float y1,float x2,float y2){
    float d;
    d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    d = sqrt(d);
    return d;
}

int main()
{
    int n,i,j;
    cout<<"Enter total number of points : ";
    cin>>n;
    point p[n];

    for(i=0;i<n;i++){
        cout<<"Enter x coordinate of "<<i<<"th point : ";
        cin>>p[i].x;

        cout<<"Enter y coordinate of "<<i<<"th point : ";
        cin>>p[i].y;

    }

    int index1 = -1,index2 =-1;
    float maxDistance = -1;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){

                float d = distanceBetweenPoint(p[i].x,p[i].y,p[j].x,p[j].y);
                if(d>maxDistance){
                    maxDistance = d;
                    index1 = i;
                    index2 = j;


            }
        }
    }
    cout<<"\nMinimum enclosing circle : \n";
    if(n==1){
        cout<<"center :"<<"("<<p[0].x<<","<<p[0].y<<")"<<"\n";
        cout<<"radius : 0";
    }
    else{
        cout<<"center :"<<"("<<(p[index1].x+p[index2].x)/2<<","<<(p[index1].y+p[index2].y)/2<<")"<<"\n";
        cout<<"radius : "<<maxDistance/2;
    }

}
