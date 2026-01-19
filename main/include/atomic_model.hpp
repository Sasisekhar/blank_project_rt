#ifndef ATOMIC_MODEL_HPP
#define ATOMIC_MODEL_HPP

#include <random>
#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"

using namespace cadmium;

struct atomic_modelState {
    double sigma;
    //you can have as many state variables as you want/ need

    explicit atomic_modelState(): sigma(1){
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const atomic_modelState& state) {
    out  << "{sigma: " << state.sigma << "}";
    return out;
}
#endif

class atomic_model : public Atomic<atomic_modelState> {
    public:

    //Declare your ports here

    atomic_model(const std::string id) : Atomic<atomic_modelState>(id, atomic_modelState()) {
        //Constructor of your atomic model. Initialize ports here.
    }

    // inernal transition
    void internalTransition(atomic_modelState& state) const override {
        //your internal transition function goes here
        state.sigma += 1;
    }

    // external transition
    void externalTransition(atomic_modelState& state, double e) const override {
        //your external transition function hoes here
    }
    
    
    // output function
    void output(const atomic_modelState& state) const override {
        //your output function goes here
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const atomic_modelState& state) const override {     
        return state.sigma;
    }
};

#endif