#include <iostream>
#include <math.h>
using namespace std;
struct point{
    float x,y,z;
};

float distanceBetweenPoint(float x1,float y1,float z1,float x2,float y2,float z2){
    float d;
    d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
    d = sqrt(d);
    return d;
}

int main()
{
    int n,i,j,index1=0,index2=1;
    float centerX,centerY,centerZ,minDiatance;
    cout<<"Enter total number of point : ";
    cin>>n;
    point p[n];


    for(i=0;i<n;i++){
        cout<<"Enter x coordinate of "<<i+1<<"th point : ";
        cin>>p[i].x;

        cout<<"Enter y coordinate of "<<i+1<<"th point : ";
        cin>>p[i].y;

        cout<<"Enter z coordinate of "<<i+1<<"th point : ";
        cin>>p[i].z;

        if(i>1){
            centerX = (p[index1].x+p[index2].x)/2;
            centerY = (p[index1].y+p[index2].y)/2;
            centerZ = (p[index1].z+p[index2].z)/2;
            minDiatance = distanceBetweenPoint(p[index1].x,p[index1].y,p[index1].z,p[index2].x,p[index2].y,p[index2].z);
            if(distanceBetweenPoint(centerX,centerY,centerZ,p[i].x,p[i].y,p[i].z)>minDiatance/2){
                float a,b;
                    a=distanceBetweenPoint(p[i].x,p[i].y,p[i].z,p[index1].x,p[index1].y,p[index1].z);
                    b=distanceBetweenPoint(p[i].x,p[i].y,p[i].z,p[index2].x,p[index2].y,p[index2].z);

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
        centerX = p[0].x;
        centerY = p[0].y;
        centerZ = p[0].z;
        minDiatance = 0;
    }
    else{
        centerX = (p[index1].x+p[index2].x)/2;
        centerY = (p[index1].y+p[index2].y)/2;
        centerZ = (p[index1].z+p[index2].z)/2;
        minDiatance = distanceBetweenPoint(p[index1].x,p[index1].y,p[index1].z,p[index2].x,p[index2].y,p[index2].z);
    }



    cout<<"("<<centerX<<" , "<<centerY<<" , "<<centerZ<<")\n";
    cout<<minDiatance/2;

}
