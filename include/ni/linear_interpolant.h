/**
 * \file ni/linear_interpolant.h
 * Linear interpolant class.
 * 
 * \copyright GPL
 * \author Artem Shepelin (4.shepelin@gmail.com)
 */
#pragma once

#include "./interpolant.h"


namespace ni {


/**
 * Linear interpolant class.
 * 
 * If \f$F(x)\f$ is interpolant, \f$\{x_i, y_i\}\f$ - data points,
 * \f$\{x, y\}\f$ - new data point, then:
 * 
 * \f$y = F(x) = y_l + \frac{(y_l - y_r)}{(x_l - x_r)} (x - x_l)\f$,
 * \f$y_l < y < y_r\f$, \f$y_l \in \{y_i\}\f$, \f$y_r \in \{y_i\}\f$,
 * \f$x_l < x < x_r\f$, \f$x_l \in \{x_i\}\f$, \f$x_r \in \{x_i\}\f$.
 */
class LinearInterpolant : public Interpolant {
 public:
  double operator()(double x) const override;
};


inline double LinearInterpolant::operator()(double x) const {
  if (x < x_[0] || x_.end()[-1] < x) {
    return 0.0;
  }

  auto i = left_index_(x);

  auto y =
    + (y_[i] * (x_[i + 1] - x) + y_[i + 1] * (x - x_[i]))
    / (x_[i + 1] - x_[i])
  ;

  return y;
}


}