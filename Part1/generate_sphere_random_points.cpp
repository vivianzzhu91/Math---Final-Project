#include<random>
#include<cmath>
#include<chrono>

int main(int argc, char *argv[]) {
	// Set up random number generators
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator (seed);
	std::uniform_real_distribution<double> uniform01(0.0, 1.0);

	// generate N random numbers
	int N = 1000;

	// the correct way
	FILE * correct;
	correct = fopen("correct.csv", "w");
	fprintf(correct, "Theta,Phi,x,y,z\n");
	for (int i = 0; i < N; i++) {
		double theta = 2 * M_PI * uniform01(generator);
		double phi = acos(1 - 2 * uniform01(generator));
		double x = sin(phi) * cos(theta);
		double y = sin(phi) * sin(theta);
		double z = cos(phi);
		fprintf(correct, "%f,%f,%f,%f,%f\n", theta, phi, x, y, z);
	}
	fclose(correct);
}