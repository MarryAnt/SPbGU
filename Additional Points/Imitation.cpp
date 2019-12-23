#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const double Pi = 3.141;
const int NumRep = 8;
const double initT = 20;
const double finT = 1;
const int P = 1;                // Размерность

struct PartArgu{
    double val;
    double X, Y;                // Начало и конец
};

struct Argu{
    PartArgu c[P];
};

double FuncA(Argu v){
    return 100 * cos(v.c[0].val - 3) / (1 + abs(v.c[0].val - 3));
}

double FuncB(Argu v){
    double al1 = (abs(sin(v.c[0].val / 8)) + 1);
    double al2 = (abs(cos(v.c[0].val + Pi * (abs(cos(v.c[0].val)) + 1))) + 1) * 0.5;

    return al1 * (3 * sin(v.c[0].val * (abs(cos(v.c[0].val + Pi / 3) / 5 + 1))) + al2 * cos(v.c[0].val * 20));
}

double FuncC(Argu v){
    return abs(8 * sin(v.c[0].val / 2) + 2 * cos(2 * v.c[0].val) + (1 + abs(cos(2 * v.c[0].val))) * sin(20 * v.c[0].val));
}

int sign(double x){
    if (x > 0){
        return 1;
    }
    else{
        return -1;
    }

    return 0;
}

double DecrT(int st){
    return initT * pow(0.95, st);
}

Argu GenRandPos(Argu v, double T){
    double ai = 0;
    double zi = 0;
    double xin = 0;
    Argu t;
    for (int i = 0; i < P; i++){
        do{
            ai = (double)(rand()) / RAND_MAX;
            zi = sign(ai - 0.5) * T * (pow(1 + 1 / T, abs(2 * ai - 1)) - 1);
            xin = v.c[i].val + zi * (v.c[i].Y - v.c[i].X);
        }
        while (xin < v.c[i].X || xin > v.c[i].Y);
        t.c[i].val = xin;
        t.c[i].X = v.c[i].X;
        t.c[i].Y = v.c[i].Y;
    }

    return t;
}

bool Event(double ch){
    double ev = (double)(rand()) / RAND_MAX;

    if (ev < ch){
        return true;
    } else{
        return false;
    }
}

double TransCh(double dE, double t){
    return exp(-dE / t);
}

Argu NewPosition(double (*f)(Argu), Argu v_old, double T){
    double dE = 0, E_old = f(v_old);
    Argu v_new;
    do{
        v_new = GenRandPos(v_old, T);
        dE = E_old - f(v_new);
    }
    while (!Event(TransCh(dE, T)));

    return v_new;
}

std::ostream& operator<< (std::ostream &out, Argu x){
    out << "{";
    for (int i = 0; i < P; i++){
        out << x.c[i].val;
        if (i < P - 1){
            out << ", ";
        }
    }
    out << "}";

    return out;
}

void Initial(Argu &vs){
    cout << "Write left and right : " << endl;
    for (int i = 0; i < P; i++){
        cout << i + 1 << "Coordinate : ";
        cin >> vs.c[i].X >> vs.c[i].Y;
        vs.c[i].val = vs.c[i].X + ((double)(rand()) / RAND_MAX) * (vs.c[i].Y - vs.c[i].X);
    }
}

double GlobalMax(double (*f)(Argu), Argu s, Argu &vm){
    Argu v;
    int st = 0;
    double max = 0, f_val = 0, T = initT;
    max = f(s);
    v = s;
    while (T > finT){
        st++;
        T = DecrT(st);
        v = NewPosition(f, v, T);
        f_val = f(v);
        if (max < f_val)
        {
            max = f_val;
            vm = v;
        }
    }

    return max;
}

int main()
{
    Argu vs, vm, prvm;
    double prmval = 0, mval = 0;
    srand(time(0));
    Initial(vs);
    mval = FuncB(vs);
    for (int i = 0; i < NumRep; i++){
        mval = GlobalMax(FuncB, vs, vm);
        if (mval > prmval || i == 0){
            prmval = mval;
            prvm = vm;
        }
    }
    cout << " > Max point : " << prvm << endl;
    cout << " > Max value : " << prmval << endl;

    system("Pause");
    return 0;
}
