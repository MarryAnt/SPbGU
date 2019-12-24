#include <Eigen/Dense>
#pragma once

class Kalman{   //Create a Kalman filter with the specified matrixes:

public:
    KalmanFilter(
        double d,
        const Eigen::MatrixXd& A, //System dynamics matrix
        const Eigen::MatrixXd& C, //Output matrix
        const Eigen::MatrixXd& Q, //Process noise covariance
        const Eigen::MatrixXd& R, //Measurement noise covariance
        const Eigen::MatrixXd& P  // Estimate error covariance
    );
    KalmanFilter(); //Create a blank estimator
    void init(); //Initialize the filter with initial states as zero
    void init(double t0, const Eigen::VectorXd& x0); //Initialize the filter with a guess for initial states
    void update(const Eigen::VectorXd& y); //Update the estimated state based on measured values
    void update(const Eigen::VectorXd& y, double d, const Eigen::MatrixXd A); //Update the estimated state based on measured values, using the given time step and dynamics matrix

    Eigen::VectorXd state() { return xh; }; //Return the current state and time
    double time() { return t; };

private:
    Eigen::MatrixXd A, C, Q, R, P, K, P0; //Matrixes for computation
    int m, n; //System dimensions
    double t0, t; //Starting (initial) and current time
    double d; //Discrete time step
    bool initialized; 
    Eigen::MatrixXd I; //n-size identity
    Eigen::VectorXd xh, xhn; //Estimated states
};
