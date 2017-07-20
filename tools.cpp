#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:  //code from lecture
    * Calculate the RMSE here.
  */
  VectorXd RMSE(4);
  RMSE << 0,0,0,0;
  
  for(unsigned int i=0; i<estimations.size(); ++i){
      VectorXd residual = estimations[i] - ground_truth[i];
      residual = residual.array()*residual.array();
      RMSE+=residual;
  
}
//mean of residual sum
RMSE=RMSE/estimations.size();

//square root of mean
RMSE=RMSE.array().sqrt();

//return rmse
return RMSE;
}