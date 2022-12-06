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
    bool hasUnhappy;
};

struct Coordinates
{
    int i;
    int j;
};

std::vector<std::vector<Agent>> generateSociety(int matrixSize);
SegregationStats segregate(std::vector<std::vector<Agent>> &matrix);

#endif