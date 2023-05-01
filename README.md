# NI

Numetical interpolation C++11 header-only library.

## Installation

Add repo (just once):

```sh
conan remote add astro https://gitea.zarux.ru/api/packages/astro/conan
```

Install:

```sh
conan install --remote=astro --requires=ni/<VERSION>
```

## Documentation

### Nearest Neighbor Interpolation

```c++
#include <ni/ni.h>

std::vector<double> data;
// Fill data...

auto interpolant = ni::NearestNeighborInterpolant();
interpolant.data_points(data);

auto y = interpolant(x);
```

### Linear Interpolation

```cpp
#include <ni/ni.h>

std::vector<double> data;
// Fill data...

auto interpolant = ni::LinearInterpolant();
interpolant.data_points(data);

auto y = interpolant(x);
```

### Common Logarithmic Interpolation

```cpp
#include <ni/ni.h>

std::vector<double> data;
// Fill data...

auto interpolant = ni::CommonLogarithmicInterpolant();
interpolant.data_points(data);

auto y = interpolant(x);
```

## License

[GPL-3](./LICENSE)