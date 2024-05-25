#include <cstdio>
#include <cstdint>
#include <random>

// The function that we are working on
float getFunctionValue(float x)
{
    return x * x;
}

// The derivative of this function
float getFunctionValueDx(float x)
{
    return 2.0f * x;
}

// The integral of this function
float getFunctionValueInt(float x)
{
    return x * x * x / 3.0f;
}

float monteCarloIntegral(float begin, float end, uint32_t samples)
{
    // Create a random device and seed it
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution range
    std::uniform_real_distribution<> dis(begin, end);

    // Sum the calculated values
    float sum = 0.0f;
    for (uint32_t i = 0; i < samples; i++) {
        float x = dis(gen);
        float y = getFunctionValue(x);
        sum += y;
    }

    // Scale by number of samples
    sum /= (float)samples;

    // Scale by integral range
    sum *= (end - begin);

    // Generate and return the random float
    return sum;
}

int main(void)
{
    float begin = 4.0f;
    float end = 10.0f;

    printf("Analytical Integral from %g to %g is %g\n", begin, end, getFunctionValueInt(end) - getFunctionValueInt(begin));
    printf("Monte Carlo Integral from %g to %g is %g\n", begin, end, monteCarloIntegral(begin, end, 10000));
}