#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream fout;
	fout.open("output.txt");

	int N = atoi(argv[1]);
	cout << "Generating " << N << " strings..." << endl;

	srand(time(NULL));
	char ch;

	fout << N << endl;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=rand()%10; j++) {
			if (rand()%2 == 0) {
				// lower char
				ch = (char) (65+rand()%26);
				fout << ch;
			} else {
				// upper char
				ch = (char) (97+rand()%26);
				fout << ch;
			}
		}
		fout << endl;
	}
	fout.close();
	cout << "Done" << endl;
	return 0;
}
