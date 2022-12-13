#ifndef SEGREGATION_H
#define SEGREGATION_H

struct Agent
{
    int type;
};

struct Moore
{
    int type;
    int y;
    int x;
};

struct SegregationStats
{
    std::vector<std::vector<Agent>> society;
    bool hasSegregation;
};

struct Coordinates
{
    int i;
    int j;
};

std::vector<std::vector<Agent>> generateSociety(int matrixSize, float blankPercent);
SegregationStats segregate(std::vector<std::vector<Agent>> matrix, float tolerance);

#endif