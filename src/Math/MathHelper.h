#pragma once

// Signum function [gets the sign of a value]
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}