
/*
 *  2048.cpp
 *  Created on: 10 February 2017, Imperial College London, Library
 *  Author: Konstantinos Barmpas
 *  Making of 2048 Game, Spring Assignment 2017, EEE Year 1 Software Engineering
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;
#define size1 4 //defining the size of the 4x4 array

struct zero_points{
    int r,c;
};

struct Game{

int a[size1][size1],b[size1];
bool created,zero_founded,can_create,check;

void Constructor(int &i,int &j,int x){ //creates my sizexsize array
	a[i][j]=x;
	j++;

		if (j==size1){
			j=0;
			i++;
		}
}

void Show (){ //displays my array
	for (int i=0; i<size1; i++) {
		for (int j=0; j<size1; j++) {
			cout<<a[i][j] <<"\t";
		}
		cout<<endl;
	}
}

void Zero_founder(){ //founds zero in my function. once it finds one stops
	zero_founded=false;

	int i=0,j;

		while (i<=size1-1 and zero_founded==false){
			j=0;
			while (j<=size1-1 and zero_founded==false){
				if (a[i][j]==0){
					zero_founded=true;
				}
				j++;
			}
			i++;
		}
	}

void Prob_Creator (){ //creates the random 2 if we have found a zero in the 4x4 array
    zero_points p;
    vector <zero_points> v;

        for (int i=0; i<size1; i++){
            for (int j=0; j<size1; j++){
                if (a[i][j]==0){
                p.r=i;
                p.c=j;
                v.push_back(p);
                }
            }
        }

    int luck= rand() % (v.size());
    a[v[luck].r][v[luck].c]=2;

}

void Rotation (int ar[size1][size1],char c){ //rotates row and column to make it look like swift and adding a row to the left. (More info see Reflection)

	created=false; //if there has been done a change
	can_create=false;  //if a change can be done

	if (c=='d'){
		for (int i=0; i<=size1-1; i++){ //rotation
			for (int k=0; k<=size1-1; k++){
		      b[k]=ar[i][size1-1-k];//change to the buffer
		    }
			if (zero_founded){ //if we have zero swift the elements
					Gravity();
			}
			can_create=Move(); //return if move is possible or not
		for (int k=0; k<=size1-1; k++){ //anti-rotation
			ar[i][k]=b[size1-1-k];//give back
		}
	  }
	}

	else if (c=='w'){
		for (int j=0; j<=size1-1; j++){ //rotation
		  for (int k=0; k<=size1-1; k++){
			  b[k]=ar[k][j];//change to the buffer
		   }
		  if (zero_founded){//if we have zero swift the elements
		  	  Gravity();
		  }
		  can_create=Move(); //return if move is possible or not
        for (int k=0; k<=size1-1; k++){ //anti-rotation
			ar[k][j]=b[k];//give back
		}

	 }
   }

	else if (c=='s'){
		for (int j=0; j<=size1-1; j++){ //rotation
		  for (int k=0; k<=size1-1; k++){
		     b[k]=ar[size1-1-k][j];//change to the buffer
		   }

		  if (zero_founded){//if we have zero swift the elements
		  		  Gravity();
		  }

		  can_create=Move(); //return if move is possible or not

		  for (int k=0; k<=size1-1; k++){ //anti-rotation
			ar[size1-1-k][j]=b[k];//give back
		   }
        }
	}

	else{
		for (int i=0; i<=size1-1; i++){ //rotation
			for (int k=0; k<=size1-1; k++){
			   b[k]=ar[i][k];//change to the buffer
			}

			if (zero_founded){//if we have zero swift the elements
					Gravity();
		    }

			can_create=Move(); //return if move is possible or not

			for (int k=0; k<=size1-1; k++){ //anti-rotation
			   ar[i][k]=b[k];//give back
		    }
		}
	}
}

void Gravity (){
		for (int m=0; m<=size1-2; m++){ //passing the one dimentional table 3 times
			for (int n=0; n<=size1-2; n++){ //searching for elements to swap
				if (b[n]==0 and b[n+1]!=0){
					swap (b[n],b[n+1]);  //swaps the two elements
					created=true;
			}
		}
	}
}

bool Move (){
 int k=0;
 int p=size1-1;
 bool done=false;

 	 while (k<=size1-2){
 		 if (b[k]==b[k+1] and b[k]!=0){
 			 done=true; //used to see if we can create an element
 			 	 if (!check){ //if !check means we do additions and changes
 			 		 b[k]=b[k]+b[k+1];
 			 		 created=true;
 			 		 	 for (int l=k+1; l<=size1-2; l++){
 			 		 		 b[l]=b[l+1];
 			 		 	 }
 			 		 b[p]=0;
 			 		 p--;
 			 	 }
 		 }
	 k++;
  }

 	 if (can_create){ //if we have can_create already true no need to change it and get possibly a wrong result
 		 return true;
 	 }
 	 else{
 		 return done;
 	 }
}

bool Possible (){

 bool right_left,up_down; //since we call Possible when no zero. Then left is same right and up as down. That is why two variables.

 check=true;   //set Rotation for check only.

 Rotation (a,'w');
 up_down=can_create;
 Rotation (a,'a');
 right_left=can_create;

 	 if (!up_down and !right_left){ //no move allowed
 		 return false;
 	 }else{
 		 return true;
 	 }
}

bool Play (char c,bool &gameOn){
 bool y;

 Zero_founder();
 check=false; //set Rotation for additions and changes.
 Rotation(a,c);
 Zero_founder();
 y=created;

     if (zero_founded and created){ //if we have zero and the square has changed before then new 2 added.
			Prob_Creator();
	 }

 Zero_founder(); //check again for zero.

     if (!zero_founded){ //if no zero check for possible moves or game over.
	   gameOn=Possible();
	 }

 return y;
}

};

int main(){

 srand(time(NULL)); //seed my random function
 bool doit,gameOn=true; //doit is for Show the array or not possible move-command has been given.
 char c;

 string message="game over";

 ifstream infile;
 string filename;

 int i=0,j=0,x;

 Game g; //creates object-structure type Game

 cout << "enter initial configuration file name: " << endl;
 cin >> filename;
 infile.open(filename.c_str());

 	 if (!infile.is_open()){
 		 cout << "file not found, using default start configuration"<< endl;
 		 	 while (i<=size1-1){
 		 		 g.Constructor(i,j,0); //makes an all-zero array
 		 	 }
 		 i--;
 		 j=size1-1;
 		 g.Constructor(i,j,2); //adds the 2 in the bottom right corner
     }

 	 else{
 		 	 while (infile>>x and j<=size1-1){  //j<=size-1 condition to make sure it reads only 16elements
 		 	 g.Constructor(i,j,x);
    	 }
     }

    g.Show();

    cout<<" "<<endl;

    	g.Zero_founder(); //check if game can be done or is game over initial condition.
    	if (!g.zero_founded){
    		gameOn=g.Possible();
    	}

    	else{
    		gameOn=true;
    	}

    	while (gameOn){
    		cin>>c;
    		doit=g.Play(c,gameOn);

    		if (doit){
    				g.Show();
    				cout<<" "<<endl;
    			}
    	}
	cout<<message;
	return 0;
}
















