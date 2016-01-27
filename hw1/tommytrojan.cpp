#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;
  int **possessionsNum;

  input >> floors;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];
  possessionsNum = new int*[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  possessionsNum[i] =NULL;
  }
  getline(input, curr);
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command MOVEIN" << endl;
		  }
		  else {
		  		if(i> floors){
		  			output <<"Error - floor "<< i <<" does not exist" <<endl;
		  		}
		  		else if(floorsizes[i] > 0){
		  			output << "Error - floor "<< i <<" is not empty"<<endl;
		  		}
		  		else{
		  			trojans[i] = new string*[k];
		  			for(int f=0; f< k; f++){
		  				
		  				trojans[i][f] = NULL;
		  			}
		  			floorsizes[i] = k;

		  			possessionsNum[i] = new int [k];
		  			for(int f = 0; f<k; f++){
		  				possessionsNum[i][f] = 0;

		  			}
		  			
		  		}

		  }
	  }
	  else if (curr == "MOVEOUT") {
	  		int i;
	  		ss >> i;
	  		if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		    }
		    else{
		  		if(i> floors){
			  		output <<"Error - floor "<< i <<" does not exist" <<endl;
			  	}
		  		else if(floorsizes[i] == 0){
		  				output<< "Error - floor "<< i << " is empty"<<endl;
		  		}
		  		else{
		  			delete [] possessionsNum[i];
		  				
		  			
		  			possessionsNum[i] = NULL;
		  			for(int j =0; j< floorsizes[i]; j++){
			  			delete [] trojans[i][j];
			  		}
			  		delete [] trojans[i];
			  		trojans[i] = NULL;
		  			floorsizes[i] = 0;
		  		}
		  	}	
	  }
	  else if (curr == "OBTAIN") {
	  	int i, j, k;
	  	string temp;
	  	ss >> i >> j >> k;
	  	if (ss.fail()) {

			output << "Error - incorrect command" << endl;
		}
	  	else{
	  		if(i> floors){
				output <<"Error - floor "<< i <<" does not exist" <<endl;
			}
			else if(possessionsNum[i][j] != 0){
				output<< "Error - student "<< j << " has possessions already"<<endl;
			}
			else{
	  			possessionsNum[i][j] = k;

		  		trojans[i][j] = new string [k];
	  		
		  		for(int m = 0; m<k; m++){
			  		ss>> temp;
			  		if (ss.fail()) {			  			
						output << "Error - incorrect command" << endl;
			  		}  		
			  		else{

			  			trojans[i][j][m] = temp;
			  		}
		  		}
		  	}	
	  	}

	  }
	  else if (curr == "OUTPUT") {
	  	int i,j;
	  	ss>>i>>j;
	  	if (ss.fail()) {
			output << "Error - incorrect command OUTPUT" << endl;
		}
		else{

		  	if(j>floorsizes[i]){
		  		output<< "Error - there is not such a student"<<endl;

		  	}
		  	else if(possessionsNum[i][j] == 0){
		  		output<<"Error - this student has no possessions"<<endl;

		  	}
		  	else{

		  		for(int f =0; f<possessionsNum[i][j]; f++){

		  			output << trojans[i][j][f]<<endl;
		  		}
		  				  		
		  	}
		}
	  }
	  else{
	  	output<< "Error - incorrect command" << endl;
	  }
	  
  }
  for(int i=0; i<floors; i++){

  	delete [] possessionsNum[i];
  }
  delete [] possessionsNum;


  for(int i = 0; i<floors; i++){
  	for(int j=0; j<floorsizes[i]; j++){
  		delete [] trojans[i][j];
  	}
  	delete [] trojans[i];
  }
  delete [] trojans;


  delete [] floorsizes;

  input.close();
  output.close();
  return 0;
}
