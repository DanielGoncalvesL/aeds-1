#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

#include "segregacao.h"
#include "geraGrafico.h"

Moore getLeftBelow(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i + 1;
    int coordX = j - 1;

    if (coordY > (society.size() - 1) || coordX < 0)
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = coordX, .type = society.at(coordY).at(coordX).type};
}

Moore getRightBelow(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i + 1;
    int coordX = j + 1;

    if (coordY > (society.size() - 1) || coordX > (society.size() - 1))
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = coordX, .type = society.at(coordY).at(coordX).type};
}

Moore getRightAbove(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i - 1;
    int coordX = j + 1;

    if (coordY < 0 || coordX > (society.size() - 1))
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = coordX, .type = society.at(coordY).at(coordX).type};
}

Moore getLeftAbove(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i - 1;
    int coordX = j - 1;

    if (coordY < 0 || coordX < 0)
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = coordX, .type = society.at(coordY).at(coordX).type};
}

Moore getBelow(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i + 1;
    if (coordY > (society.size() - 1))
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = j, .type = society.at(coordY).at(j).type};
}

Moore getAbove(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordY = i - 1;
    if (coordY < 0)
    {
        return {.type = -1};
    }

    return {.y = coordY, .x = j, .type = society.at(coordY).at(j).type};
}

Moore getRight(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordX = j + 1;
    if (coordX > (society.size() - 1))
    {
        return {.type = -1};
    }

    return {.y = i, .x = coordX, .type = society.at(i).at(coordX).type};
}

Moore getLeft(std::vector<std::vector<Agent>> society, int i, int j)
{
    int coordX = j - 1;
    if (coordX < 0)
    {
        return {.type = -1};
    }

    return {.y = i, .x = coordX, .type = society.at(i).at(coordX).type};
}

bool isItTheSame(Moore side, Agent position)
{
    return side.type == position.type && side.type > -1 && side.type != 2;
}

Moore findEmpty(std::vector<std::vector<Agent>> society)
{
    for (int i = 0; i < society.size(); i++)
    {
        for (int j = 0; j < society.size(); j++)
        {
            if (society.at(i).at(j).type == 2)
            {
                return {.y = i, .x = j, .type = 2};
            }
        }
    }

    return {};
}

SegregationStats segregate(std::vector<std::vector<Agent>> society)
{
    float threshold = 0.5;

    std::vector<Moore> unhappyAgents;

    for (int i = 0; i < society.size(); i++)
    {
        for (int j = 0; j < society.size(); j++)
        {
            Agent position = society.at(i).at(j);

            if (position.type != 2)
            {
                int similar = 0;

                Moore left = getLeft(society, i, j);
                Moore right = getRight(society, i, j);
                Moore leftAbove = getLeftAbove(society, i, j);
                Moore rightAbove = getRightAbove(society, i, j);
                Moore leftBelow = getLeftBelow(society, i, j);
                Moore rightBelow = getRightBelow(society, i, j);

                if (isItTheSame(left, position))
                {
                    similar += 1;
                }

                if (isItTheSame(right, position))
                {
                    similar += 1;
                }

                if (isItTheSame(leftAbove, position))
                {
                    similar += 1;
                }

                if (isItTheSame(rightAbove, position))
                {
                    similar += 1;
                }

                if (isItTheSame(leftBelow, position))
                {
                    similar += 1;
                }

                if (isItTheSame(rightBelow, position))
                {
                    similar += 1;
                }

                if (similar < (8 * threshold))
                {
                    unhappyAgents.push_back({.x = i, .y = j, .type = position.type});

                    // Moore empty = findEmpty(society);
                    // std::swap(society.at(empty.y).at(empty.x), society.at(i).at(j));

                    // iterations += 1;
                    // std::cout << i << " " << j << std::endl;
                }
            }
        }
    }

    for (Moore unhappy : unhappyAgents)
    {
        Moore empty = findEmpty(society);
        Agent aux = society.at(empty.y).at(empty.x);
        society.at(empty.y).at(empty.x) = society.at(unhappy.y).at(unhappy.x);
        society.at(unhappy.y).at(unhappy.x) = aux;
    }

    // std::cout << society.size() << " " << iterations << std::endl;
    return {.society = society};
}

std::vector<std::vector<Agent>> generateSociety(int matrixSize)
{
    std::random_device rd;
    std::uniform_int_distribution d(0, 2);
    std::uniform_int_distribution c(0, matrixSize - 1);

    std::vector<std::vector<Agent>> segregationVector;

    std::vector<std::string> coordinates;

    int matrixTotalSize = matrixSize * matrixSize;

    int maxBlank = matrixTotalSize * 0.1;

    for (int i = 0; i < matrixSize; i++)
    {
        std::vector<Agent> line;
        for (int j = 0; j < matrixSize; j++)
        {
            line.push_back({j});
        }
        segregationVector.push_back(line);
    }

    int positions = 0;
    int blank = 0;
    while (positions < matrixTotalSize)
    {
        int x = c(rd);
        int y = c(rd);
        std::string coord = std::to_string(x) + "-" + std::to_string(y);

        auto it = std::find(coordinates.begin(), coordinates.end(), coord);

        while (it != coordinates.end())
        {
            x = c(rd);
            y = c(rd);
            coord = std::to_string(x) + "-" + std::to_string(y);

            it = std::find(coordinates.begin(), coordinates.end(), coord);
        }

        int p = d(rd);
        if (p == 2)
        {
            if (blank == maxBlank)
            {
                while (p == 2)
                {
                    p = d(rd);
                }
            }
            else
            {
                blank += 1;
            }
        }

        segregationVector.at(x).at(y).type = p;
        coordinates.push_back(coord);

        positions += 1;
    }

    return segregationVector;
}

int main()
{
    int matrixSize;
    std::cout << "Insira o tamanha da matrix: ";
    std::cin >> matrixSize;

    std::cout << "Gerando Modelo de Segregação Social de Schelling..." << std::endl;

    std::vector<std::vector<Agent>> matrix = generateSociety(matrixSize);
    // for (std::vector<Agent> agents : matrix)
    // {
    //     for (Agent position : agents)
    //     {
    //         std::cout << position.type << " ";
    //     }
    // }
    // SegregationStats stats = segregate(matrix);
    // matrix = stats.society;

    // std::cout << std::endl;

    // for (std::vector<Agent> agents : matrix)
    // {
    //     for (Agent position : agents)
    //     {
    //         std::cout << position.type << " ";
    //     }
    // }

    geraGrafico(matrix);
}