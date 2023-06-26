#include <cmath>
#include <iostream>
#include <vector>

double getAverage(std::vector<float> vec){
	double avg;
	for(int i = 0; i < vec.size(); i++){
		if(i == 0) avg = vec[i];
		avg = (avg + vec[i])/2.0;
	}
	return avg;
}

double getDeviation(std::vector<float> vec){
	//calculate the mean
	double mean;
	double sum = 0;
	double deviation;
	double sumDev = 0;
	
	for(float t : vec){
		sum += t;
	}
	
	mean = sum/(vec.size()*1.0);
	
	for(float t : vec){
		sumDev += pow((t - mean), 2);
	}
	
	deviation = pow((sumDev / (vec.size()-1)), 0.5);
	
	return deviation;
}

void Alert(int i){
	if(i == 1){
		std::cout<<"\nDATA MISSING\n";
	}
	if(i == 2){
		std::cout<<"\nDATA OVERFLOW\n";
	}
}
