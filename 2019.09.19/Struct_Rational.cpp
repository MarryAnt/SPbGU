#include <iostream>
#include <cmath>

using namespace std;

class Rational{
public:
    int a;
    unsigned int b;
public:
		Rational Add (const Rational&) const;
		Rational Sub (const Rational&) const;
		Rational Mult (const Rational&) const;
		Rational Div (const Rational&) const;
		Rational Compr (const Rational&) const;
		void Print () const;
public:
	int GCD(int, int) const;
};

Rational Rational::Add (const Rational&s) const{
	int c;
	Rational Sum;
	Sum.a = a*s.b+b*s.a;
	Sum.b = b*s.b;
	if (abs(Sum.a)>abs(Sum.b)){
		c = GCD(abs(Sum.a), abs(Sum.b));
	} else{
        c = GCD(abs(Sum.b), abs(Sum.a));
	}
	Sum.a = Sum.a/c;
	Sum.b = Sum.b/c;
	return Sum;
	}

Rational Rational::Sub (const Rational&s) const{
	int c;
	Rational Sum;
	Sum.a = a*s.b-b*s.a;
	Sum.b = b*s.b;
	if (abs(Sum.a)>abs(Sum.b)){
		c = GCD(abs(Sum.a), abs(Sum.b));
	} else{
        c = GCD(abs(Sum.b), abs(Sum.a));
	}
	Sum.a = Sum.a/c;
	Sum.b = Sum.b/c;
	return Sum;
	}

Rational Rational::Mult (const Rational&s) const
	{
	int c;
	Rational Sum;
	Sum.a = a*s.a;
	Sum.b = b*s.b;
    if (abs(Sum.a)>abs(Sum.b)){
		c = GCD(abs(Sum.a), abs(Sum.b));
	} else{
        c = GCD(abs(Sum.b), abs(Sum.a));
	}
	Sum.a = Sum.a/c;
	Sum.b = Sum.b/c;
	return Sum;
	}

Rational Rational::Div (const Rational&s) const{
	int c;
	Rational Sum;
	Sum.a = a*s.b;
	Sum.b = b*s.a;
	if (abs(Sum.a)>abs(Sum.b)){
		c = GCD(abs(Sum.a), abs(Sum.b));
	} else{
        c = GCD(abs(Sum.b), abs(Sum.a));
	}
	Sum.a = Sum.a/c;
	Sum.b = Sum.b/c;
	return Sum;
	}

Rational Rational::Compr (const Rational&s) const{
	Rational Sum;
	Sum.a = a*s.b;
	Sum.b = b*s.a;
	if (Sum.a>Sum.b){
		cout<<"First rational bigger than second"<<endl;
	} else{
        cout<<"Second rational bigger than first"<<endl;
	}
	return Sum;
	}

void Rational::Print () const{
    int c;
    if (abs(a)>abs(b)){
        c = GCD(abs(a),abs(b));
    } else{
        c = GCD(abs(b),abs(a));
    }
	cout<<a/c<<"/"<<b/c<<endl;
}

int Rational::GCD (int c, int d) const{
    if (d == 0){
        return c;
    } else{
        return GCD(d, c%d);
    }
}

int main(){
    Rational R1;
    R1.a = 7;
    R1.b = 8;
    Rational R2;
    R2.a = 2;
    R2.b = 3;
    Rational R3;
    R3 = R1.Add(R2);
    R1.Print();
    R2.Print();
    R3.Print();
    R3 = R1.Compr(R2);
    R3 = R1.Sub(R2);
    R3.Print();
    R3 = R2.Sub(R1);
    R3.Print();
    R3 = R1.Mult(R2);
    R3.Print();
    R3 = R1.Div(R2);
    R3.Print();

    return 0;
}
