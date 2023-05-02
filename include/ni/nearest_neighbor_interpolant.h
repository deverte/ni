/**
 * \file ni/nearest_neighbor_interpolant.h
 * Nearest-neighbor interpolant class.
 * 
 * \copyright GPL
 * \author Artem Shepelin (4.shepelin@gmail.com)
 */
#pragma once

#include <cmath>

#include "./interpolant.h"


namespace ni {


/**
 * Nearest neighbor interpolant class.
 * 
 * If \f$F(x)\f$ is interpolant, \f$\{x_i, y_i\}\f$ - data points,
 * \f$\{x, y\}\f$ - new data point, then:
 * 
 * \f$F(x) = y = y_i\f$ if \f$|x - x_i| < |x - x_{i + 1}|\f$,
 * \f$F(x) = y = y_{i+1}\f$ otherwise.
 */
class NearestNeighborInterpolant : public Interpolant {
 public:
  double operator()(double x) const override;
};


inline double NearestNeighborInterpolant::operator()(double x) const {
  auto i = nearest_index_(x);

  auto y = y_[i];

  return y;
}


}