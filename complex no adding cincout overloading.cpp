#include <iostream>
using namespace std;

class complex {
	private:
		int real , img;

	public:
//		default constructor
		complex() {
			real = 0;
			img = 0;
		}
		
//		constructor for parameterized objects
		complex(int real, int img) {
			this->real = real;
			this->img = img;
		}

//		display function
		void display() {
			cout<<real<<" + "<<img<<"i ";
		}

//		taking input function
		void takingInput() {
			cout<<"Enter real number: ";
			cin >> real;

			cout<<"Enter imaginary number: ";
			cin >> img;
		}

//		operator overloading for +
		complex &operator + (complex &obj) {
			complex temp;

			temp.real = this->real + obj.real;
			temp.img = this->img + obj.img;

			return temp;
		}

//		increment with prefix
		complex &operator ++() {
			real++;
			img++;

			return *this;
		}

//		decreamnet with postfix logic
		complex &operator -- (int) {
			complex temp = *this;
			real--;
			img--;

			return temp;
		}

//		calling iostream as a frind
		friend istream &operator >> (istream &input, complex &com);
		friend ostream &operator << (ostream &output, complex &com);
};

//istream
istream &operator >> (istream &input, complex &com) {
	cout<<"Enter real number: ";
	input >> com.real;

	cout<<"Enter imaginary number: ";
	input >> com.img;

	return input;
}

//ostream
ostream &operator << (ostream &output, complex &com) {
	output << com.real<<" + "<<com.img<<"i ";
	return output;
}

int main() {
	complex c1, c2, c3;

	cout<<"----Enter your 1st Equation ---- \n";
	cin>>c1;   //taking input by istream
	cout<<"\n----Enter your 2nd Equation ---- \n";
	c2.takingInput();

	cout<<endl;

	cout<<"Your 1st Equation is =  "<<c1<<endl; //taking output by ostream
	cout<<"Your 2md Equation is =  ";
	c2.display();

	cout<<endl;

	++c1;  //imcreament by prefix
	cout<<"\nThe 1st equation after Incremnet is = "<<c1<<endl;

	c2--;  // decreament by postfix
	cout<<"The 2nd equation after Decrement is = "<<c2<<endl;

	cout<<"\n====================";
	cout<<"\nThe answer is: \n";
	c3 = c1 + c2;
	c3.display();
}
