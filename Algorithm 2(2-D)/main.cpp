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
    int n,i,j,index1=0,index2=1;
    float centerX,centerY,minDiatance;
    cout<<"Enter total number of point : ";
    cin>>n;
    point p[n];

    for(i=0;i<n;i++){
        cout<<"Enter x coordinate of "<<i+1<<"th point : ";
        cin>>p[i].x;

        cout<<"Enter y coordinate of "<<i+1<<"th point : ";
        cin>>p[i].y;

        if(i>1){
            centerX = (p[index1].x+p[index2].x)/2;
            centerY = (p[index1].y+p[index2].y)/2;
            minDiatance = distanceBetweenPoint(p[index1].x,p[index1].y,p[index2].x,p[index2].y);
            if(distanceBetweenPoint(centerX,centerY,p[i].x,p[i].y)>minDiatance/2){
                float a,b;
                    a=distanceBetweenPoint(p[i].x,p[i].y,p[index1].x,p[index1].y);
                    b=distanceBetweenPoint(p[i].x,p[i].y,p[index2].x,p[index2].y);

                    if(a>b){
                        index2=i;
                    }
                    else{
                        index1=i;
                    }

            }
        }

    }
    if(n==1){
        centerX=p[0].x;
        centerY=p[0].y;
        minDiatance=0;
    }
    else{
        centerX = (p[index1].x+p[index2].x)/2;
        centerY = (p[index1].y+p[index2].y)/2;
        minDiatance = distanceBetweenPoint(p[index1].x,p[index1].y,p[index2].x,p[index2].y);

    }
    cout<<"\nMinimum enclosing circle : \n";
    cout<<"("<<centerX<<"    "<<centerY<<")\n";
    cout<<minDiatance/2;

}
