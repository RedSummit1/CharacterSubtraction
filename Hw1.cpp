#include <iostream>

void removeLeadingZeros(char array[]){
	int k{0}, count{0};
	unsigned int j{0};
	while(array[k] < '1' && array[k] != 0){
		++k;
	}
	int size = strlen(array);
	if(k == size){
		for(int l = (size - 1); l > 0 ; --l){
			array[l] = 0;
		}
		return; 
	}
	while(array[k] && k && k != size){ 
		array[j] = array[k++]; //array[j + 1];
		if(!array[k]){
			for(int l = size - 1; l > j; --l){
				array[l] = 0;
			}
		}
		++j;
	}
	
}

void menu(int& i){
	std::cout<<"Please enter number for array " << i << std::endl;
}

void print(char array[]){
	int i{0};
	do{
		std::cout << array[i];
	}while(i++ < strlen(array) -1 );
	std::cout << std::endl;

}

void prompt(char array[]){
	std::cin.get(array,81);
	removeLeadingZeros(array);
	std::cout << "You entered: ";
	print(array);  
	std::cin.ignore();
}

void sub(char num1[], char num2[], char num3[]){
	int a = strlen(num1) - 1;
	int b = strlen(num2) - 1; 
	int count = b;  // relationship between the index of array one and array two
	int temp;
	bool check{false};  
	do{ 
		int r{-1};
		temp = num1[a] - num2[b];
		while(temp < 0){ // count the amount of zeros are in front of the one being subtracted 
			if(num1[a + r] < '1' && a + r > -1){ // Checks to see if the next number after the smaller number is zero
				--r;
				continue;
				
			}
			--num1[a + r++];
			for(;r < 0; ++r){
				num1[a + r] = 57;
			}
			check = true;
			temp += 58;	
		}
		num3[a] = temp + (check ? 0 : 48); 
		
		 
		--a;
		--b;
		
	}while(b > -1);    
	
	for(;a > -1; --a){
		num3[a] = num1[a];
	}
	
	removeLeadingZeros(num3);
	std::cout << std::endl << "Array 1 minus Array 2 equals ";print(num3);
}

int main(){
	int i{1}; 
	char num1[81], num2[81], num3[81];
	menu(i);
	prompt(num1);
	menu(++i);
	prompt(num2);
	sub(num1, num2, num3); 

}

