#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main() {

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);

    std::cout << m.inverse() << std::endl;

    struct a {

      int b ;

    };


    a a_str;
    a_str.b = 2;


    std::cout << "Sup man" <<  std::endl;
    return 0;
}