#include<iostream>
#include<vector>

using namespace std;

vector<double>data;
vector<double>searched_data;
vector<int>data_mode;

double mean=0;
double mode=0;
double median=0;
double data_sum=0;
double smallest=0;
double data_value=0;

int option=0;
int middle_index=0;

bool is_exist=false;

void sort(int);				//An Algorithm to sort a list.
void find_middle_index();	//Finds the middle index of a list.
void sum_data(int);			//Sums the values of list.
int find_mode();		//Finds the modal value in a list.
bool is_searched(double);	//Checks if a search is a repeated search.
void data_frequency(int);	//Determine the frequency of unique item in a list.
void find_median();
void find_mean();


int main()
{
	cout<<"Enter the value of the data set and terminate it with a non-number character"<<endl;
	cout<<"Data: ";

	//Collecting dataset
	while(cin>>data_value){

		data.push_back(data_value);
	}

	//Evaluating the size of the data input
	const int data_size=data.size();


	sort(data_size);


	cout<<"\n Choose the analysis you want to see"<<endl;
	cout<<"\n \t\t\t Menu: "<<endl;
	cout<<"1."<<"Mean"<<endl;
	cout<<"2."<<"Median"<<endl;
	cout<<"3."<<"Mode"<<endl;
	cout<<"4."<<"All Analysis"<<endl;

	cin>>option;


}

void sort(int data_size){

	double temp=0;

	for(int i=0; i<data_size; ++i){

		smallest=data[i];

		//Compare the chosen value to its right-values in the container
		for(int x=i+1; x<data_size; ++x){
			if(data[x]<smallest){
				temp=smallest;
				smallest=data[x];
				data[x]=temp;
			}
		}

		data[i]=smallest;
	}
}

void sum_data(int data_size){

	//Summing all data values
	for(int i=0; i<data_size; ++i){
		data_sum +=data[i];
	}
}

bool is_searched(double temp){

	int data_size=searched_data.size();
	int counter=0;

	while(counter<data_size){
		if(temp==searched_data[counter])
			return true;
		counter++;
	}

	return false;
}

void data_frequency(int data_size){

	double temp=0;
	int frequency_counter=0;
	bool repeated_search=false;

	for(int i=0; i<data_size; ++i){
		temp=data[i];
		repeated_search=is_searched(temp);

		if(repeated_search==false){
			cout<<temp<<endl;
			searched_data.push_back(temp);
			++frequency_counter;

			for(int x=i+1; x<data_size; ++x){
				if(data[x]==temp)
					++frequency_counter;
			}

			data_mode.push_back(frequency_counter);
			frequency_counter=0;
		}
	}
}

void find_middle_index(int data_size){
		middle_index=data_size/2;
}

int find_mode(){
	int max=0;
	int modal_index=0;
	for(int i=0; i<data_mode.size(); ++i){
		if(data_mode[i]>max){
			modal_index=i;
		}
	}

	return modal_index;
}

void find_median(){
	int middle_index=find_middle_index(data_size);










