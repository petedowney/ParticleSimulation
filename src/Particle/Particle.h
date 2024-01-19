
#pragma once

class Particle{

public:
    Particle();
    ~Particle();

    virtual void update(auto* particles) = 0;
    virtual void draw() = 0;
};