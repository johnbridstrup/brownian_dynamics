//implementation file for proteins class

#include "headers/proteins.h"

using namespace std;

//constructors

//Default: constructs only non-crowder parameter proteins
protein::protein()
{
	for(int i=0;i<dim;i++){coordinates.push_back(0);}
	mass=M;
	radius=r;
	crowder=0;
}

//specific constructor. 
protein::protein(double x,double y, double z, double ms, double rad, bool crow)
{	
	crowder=crow;
	for(int i=0;i<dim;i++){coordinates.push_back(0); newcoords.push_back(0);}
	coordinates[0]=x; newcoords[0]=x;
	coordinates[1]=y; newcoords[1]=y;
	coordinates[2]=z; newcoords[2]=z;
	mass=ms;
	radius=rad;
}

// member functions



void protein::setNNs(vector<int> nns, vector<int> nnns)
{
	NNs=nns;
	notNNs=nnns;
}


vector<double> protein::getinfo(const char* a)
{
	if(a="coords"){return coordinates;}
	else if(a="new coords"){return newcoords;}
	else if(a="velocity"){return vel;}
}





double protein::getmass()
{
	return mass;
}
double protein::getrad()
{
	return radius;
}
vector<int> protein::getNNs(bool nn)
{
	if(nn){return NNs;}
	else{return notNNs;}
}


void protein::move(mt19937& gen, normal_distribution<> distro)
{
	double xx,yy,zz;
	xx=distro(gen);
	yy=distro(gen);
	zz=distro(gen);
	newcoords[0]+=xx; vel[0]=xx/h;
	newcoords[1]+=yy; vel[1]=yy/h;
	newcoords[2]+=zz; vel[2]=zz/h;	
}

void protein::newpos(vector<double> pos)
{
	newcoords[0]+=pos[0];
	newcoords[1]+=pos[1];
	newcoords[2]+=pos[2];
}

void protein::update()
{
	for(int i=0;i<dim;i++){coordinates[i]=newcoords[i];}

}

	
