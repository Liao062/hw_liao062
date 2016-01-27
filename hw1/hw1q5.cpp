#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;
void reverse(ifstream &filein){
	string buffer;
	filein >> buffer;

	if(filein.fail()){
		return;
	}
	else{
		reverse(filein);

		cout<<buffer<<endl;
	}
	

return;
}

int main(int argc, char *argv[]) {

	int num;
	stringstream ss;
	ifstream filein(argv[1]);
	filein >>num;
	reverse(filein);
	

	filein.close();
	return 0;
}