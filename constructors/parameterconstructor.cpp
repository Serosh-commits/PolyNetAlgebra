// this is a parametricbellpair made with the use of parameter constructor 
#include<bits/stdc++.h>
using namespace std;
class qubit
{
    std::complex<double> alpha,beta;
    public:
    //here the parameters are passed through the constructors
    qubit(std::complex<double> a,std::complex<double> b):alpha(a),beta(b)
    {

        double norm = std::abs(alpha)*std::abs(alpha)+std::abs(beta)*std::abs(beta);
        if(std::abs(norm-1.0)>1.0)
            throw std::runtime_error("qubit not normalized");
    }
};
class bellpair
{
    qubit q1,q2;
    public:
    bellpair()
            : q1(1/sqrt(2), 0), q2(1/sqrt(2), 0)
        {  // |Φ+> = (|00> + |11>)/√2
            std::cout << "Bell pair born in |Φ+>\n";
        }
};
int main()
{
    bellpair pair;
    return 0;
}
