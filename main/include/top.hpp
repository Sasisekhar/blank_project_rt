#ifndef SAMPLE_TOP_HPP
#define SAMPLE_TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "atomic_model.hpp"

using namespace cadmium;

struct top_coupled : public Coupled {

    /**
     * Constructor function for the top model.
     * @param id ID of the top model.
     */
    top_coupled(const std::string& id) : Coupled(id) {
        auto atomic_1 = addComponent<atomic_model>("model 1");
    }
};

#endif