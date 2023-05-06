/**
 * \file ni/interpolant.h
 * Interpolant abstract class.
 * 
 * \copyright GPL
 * \author Artem Shepelin (4.shepelin@gmail.com)
 */
#pragma once

#include <stdexcept>
#include <vector>


namespace ni {


/**
 * Interpolant abstract class.
 */
class Interpolant {
 public:
  virtual ~Interpolant() = default;

  /**
   * Gets \f$y\f$ value corresponding to \f$x\f$ value of new \f${x, y}\f$ data
   * point.
   * 
   * \param x \f$x\f$ value of new data point.
   * \return \f$y\f$ value of new data point.
   */
  virtual double operator()(double x) const = 0;

  /**
   * Data points.
   * 
   * \param xs \f$x\f$ values.
   * \param ys \f$y\f$ values.
   * \exception length_error Interpolation data points must have same size.
   */
  void data_points(
    const std::vector<double>& xs,
    const std::vector<double>& ys
  );

 protected:
  /**
   * Left index \f$i: x_i < x < x_{i + 1}\f$.
   * 
   * \param x \f$x\f$ value.
   */
  int left_index_(double x) const;

  /**
   * Right index \f$i: x_{i - 1} < x < x_i\f$.
   * 
   * \param x \f$x\f$ value.
   */
  int right_index_(double x) const;

  /**
   * Nearest index \f$i\f$ if \f$x - x_i \leq x_{i + 1} - x\f$, \f$i + 1\f$,
   * otherwise.
   * 
   * \param x \f$x\f$ value.
   */
  int nearest_index_(double x) const;

  std::vector<double> x_;

  std::vector<double> y_;
};


inline void Interpolant::data_points(
  const std::vector<double>& xs,
  const std::vector<double>& ys
) {
  if (xs.size() != ys.size()) {
    throw std::length_error(
      "ni::Interpolant::data_points error: "
      "Interpolation data points must have same size."
    );
  }

  x_ = xs;
  y_ = ys;
}


inline int Interpolant::left_index_(double x) const {
  int i = 0;
  for (int j = 1; j < x_.size(); j++) {
    if (x <= x_[j]) {
      i = j - 1;
      break;
    }
  }
  return i;
}


inline int Interpolant::right_index_(double x) const {
  auto i = left_index_(x) + 1;
  return i;
}


inline int Interpolant::nearest_index_(double x) const {
  auto i = left_index_(x);
  if (x - x_[i] <= x_[i + 1] - x) {
    return i;
  }
  return i + 1;
}


}