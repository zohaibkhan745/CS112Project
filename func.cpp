#include <iostream>
#include "Container.h"
using namespace std;
const int size = 10;
bool is_visited(Container<Stack,Axis,size*size>& S,int x,int y){
	bool found=false;
	Container<Stack,Axis,size*size> temp("temp");
	Axis current;
	while(!S.is_empty()){
		temp.push_back(S.pop_back());
		current = temp.peek();
		if(current.x==x && current.y==y){
			found=true;
		}
	}
	while(!temp.is_empty()){
		S.push_back(temp.pop_back());
	}
	return found;
}

int main(){
	int map[size][size]=
	{
		{0,1,1,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,1,1,1,1},
		{1,0,1,1,0,0,1,1,0,0},
		{1,0,1,1,0,0,0,1,1,0},
		{1,1,0,0,0,1,1,1,1,0},
		{1,1,1,1,0,1,1,1,1,0},
		{1,0,0,0,0,1,1,1,1,0},
		{1,0,1,1,1,1,1,1,1,0},
		{1,1,0,1,1,1,0,1,1,0},
		{1,1,0,0,0,0,0,0,0,0},
	};
	Container<Stack,Axis,size*size> S("Stack");

	int i=0,j=0;//initial axis
	Axis current(i,j);
	bool found = false;
	int lasti,lastj;
	while(true){
		found = false;
		if(current.x == size-1 && current.y == size-1){
			S.push_back(Axis(current.x,current.y));
			cout<<"solved"<<endl;
			break;
		}

		i=current.x,j=current.y;
		for(int k=i+1;k>=i-1;k--){//check kardan hamsaye haye rast
			if(k<0)
				continue;
			if(k>=size)
				continue;
			if(j+1 >= size)
				continue;
			if(map[k][j+1]==0){
				if(is_visited(S,k,j+1)){
					continue;
				}
				if(k==lasti && j+1==lastj)
					continue;
				found=true;
				S.push_back(current);
				current.x = k;
				current.y = j+1;
				break;
			}
		}
		if(found)
			continue;

		for(int k=j-1;k<=j+1;k++){//check kardan hamsaye haye paein
			if(k<0)
				continue;
			if(k>=size)
				continue;
			if(i+1>=size)
				continue;
			if(map[i+1][k]==0){
				if(is_visited(S,i+1,k)){
					continue;
				}
				if(i+1==lasti && k==lastj)
					continue;
				found=true;
				S.push_back(current);
				current.x = i+1;
				current.y = k;
				break;
			}
		}
		if(found)
				continue;

		for(int k=j-1;k<=j+1;k++){//check kardan hamsaye haye bala
			if(k<0)
				continue;
			if(k>=size)
				continue;
			if(i-1<0)
				continue;
			if(map[i-1][k]==0){
				if(is_visited(S,i-1,k)){
					continue;
				}
				if(i-1==lasti && k==lastj)
					continue;
				found=true;
				S.push_back(current);
				current.x = i-1;
				current.y = k;
				break;
			}
		}
		if(found)
			continue;

		if(j-1>=0 && j-1<size)
			if(map[i][j-1]==0){
				found=true;
				S.push_back(current);
				current.x = i;
				current.y = j-1;
			}
		if(found)
			continue;

		lasti=current.x;
		lastj=current.y;
		map[lasti][lastj]=1;
		current = S.pop_back();
		if(S.is_empty()){
			cout<<"unsolved"<<endl;
			break;
		}
	}

	while(!S.is_empty()){
		current = S.pop_back();
		cout<<current.x<<","<<current.y<<endl;
	}
	return 0;
}