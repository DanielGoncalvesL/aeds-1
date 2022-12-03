#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include "segregacao.h"

std::vector<SDL_Rect> RectMatrix(SDL_Rect (*rectFactory)(int, int, int, int), int xStart, int yStart, int squareSize, SDL_Renderer *renderer, int matrixSize, std::vector<std::vector<Agent>> segregationMatrix)
{
    std::vector<SDL_Rect> rects;

    std::vector<SDL_Rect> yellowRects;
    std::vector<SDL_Rect> redRects;

    for (long int i = 0; i < matrixSize; i++)
    {
        for (long int j = 0; j < matrixSize; j++)
        {
            SDL_Rect rect = (*rectFactory)(xStart + squareSize * i, yStart + squareSize * j, squareSize, squareSize);
            if (segregationMatrix.at(i).at(j).type == 1)
            {
                yellowRects.push_back(rect);
            }

            if (segregationMatrix.at(i).at(j).type == 0)
            {
                redRects.push_back(rect);
            }

            rects.push_back(rect);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect yellow[yellowRects.size()];
    std::copy(yellowRects.begin(), yellowRects.end(), yellow);
    SDL_RenderFillRects(renderer, yellow, yellowRects.size());

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect red[redRects.size()];
    std::copy(redRects.begin(), redRects.end(), red);
    SDL_RenderFillRects(renderer, red, redRects.size());

    return rects;
}

SDL_Rect rectFactory(int x, int y, int width, int height)
{
    SDL_Rect rect = {.w = width, .h = height, .x = x, .y = y};

    return rect;
}

void geraGrafico(std::vector<std::vector<Agent>> segregationMatrix)
{

    int squareSize = 10;
    int matrixSize = segregationMatrix.size();

    int windowWidth = squareSize * matrixSize + 450;
    int windowHeight = squareSize * matrixSize + 50;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING);
    int windowWasCreated = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, &window, &renderer);

    if (windowWasCreated > -1)
    {
        bool isRunning = true;
        while (isRunning)
        {
            SDL_Event event;

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    isRunning = false;
                }
            }

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);

            std::vector<SDL_Rect> rectsVector = RectMatrix(rectFactory, 10, 10, squareSize, renderer, matrixSize, segregationMatrix);
            SDL_Rect rects[rectsVector.size()];
            std::copy(rectsVector.begin(), rectsVector.end(), rects);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            int success = SDL_RenderDrawRects(renderer, rects, rectsVector.size());
            if (success < 0)
            {
                std::cout << SDL_GetError() << std::endl;

                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                isRunning = false;
            }

            SDL_RenderPresent(renderer);
            SDL_Delay(100);

            // segregationMatrix = generateSociety(matrixSize);

            SegregationStats stats = segregate(segregationMatrix);
            segregationMatrix = stats.society;

            // if (stats.haveSegregation)
            // {
            //     std::cout << "Iterações: " << stats.iterations << std::endl;
            // }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}