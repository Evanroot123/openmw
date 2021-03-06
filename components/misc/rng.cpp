#include "rng.hpp"

#include <chrono>
#include <random>

namespace Misc
{

    std::mt19937 Rng::generator = std::mt19937();

    void Rng::init()
    {
        generator.seed(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    }

    float Rng::rollProbability()
    {
        return std::uniform_real_distribution<float>(0, 1 - std::numeric_limits<float>::epsilon())(generator);
    }

    float Rng::rollClosedProbability()
    {
        return std::uniform_real_distribution<float>(0, 1)(generator);
    }

    int Rng::rollDice(int max)
    {
        return std::uniform_int_distribution<int>(0, max - 1)(generator);
    }

}
