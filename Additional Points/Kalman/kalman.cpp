#include <iostream>
#include <stdexcept>
#include "kfilter.h"

KalmanFilter::KalmanFilter(
    double d,
    const Eigen::MatrixXd& A,
    const Eigen::MatrixXd& B,
    const Eigen::MatrixXd& Q,
    const Eigen::MatrixXd& R,
    const Eigen::MatrixXd& P)
    : A(A), B(B), Q(Q), R(R), P0(P),
    m(B.rows()), n(A.rows()), d(d), initialized(false),
    I(n, n), xh(n), xhn(n)
{
    I.setIdentity();
}

KalmanFilter::KalmanFilter() {}

void KalmanFilter::init(double t0, const Eigen::VectorXd& x0) {
    xh = x0;
    P = P0;
    this->t0 = t0;
    t = t0;
    initialized = true;
}

void KalmanFilter::init() {
    xh.setZero();
    P = P0;
    t0 = 0;
    t = t0;
    initialized = true;
}

void KalmanFilter::update(const Eigen::VectorXd& y) {

    if (!initialized)
        throw std::runtime_error("Filter is not initialized!");

    xhn = A * xh;
    P = A * P * A.transpose() + Q;
    K = P * B.transpose() * (B * P * B.transpose() + R).inverse();
    xhn += K * (y - B * xhn);
    P = (I - K * B) * P;
    xh = xhn;

    t += d;
}

void KalmanFilter::update(const Eigen::VectorXd& y, double d, const Eigen::MatrixXd A) {

    this->A = A;
    this->d = d;
    update(y);
}
