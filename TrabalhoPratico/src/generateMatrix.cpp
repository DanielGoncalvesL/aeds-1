#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include "segregation.h"

// std::vector<SDL_Rect> RectMatrix(SDL_Rect (*rectFactory)(int, int, int, int), int xStart, int yStart, int squareSize, SDL_Renderer *renderer, int matrixSize, std::vector<std::vector<Agent>> segregationMatrix)
// {
//     std::vector<SDL_Rect> rects;

//     std::vector<SDL_Rect> yellowRects;
//     std::vector<SDL_Rect> redRects;

//     SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//     SDL_Rect yellow[yellowRects.size()];
//     std::copy(yellowRects.begin(), yellowRects.end(), yellow);
//     SDL_RenderFillRects(renderer, yellow, yellowRects.size());

//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//     SDL_Rect red[redRects.size()];
//     std::copy(redRects.begin(), redRects.end(), red);
//     SDL_RenderFillRects(renderer, red, redRects.size());

//     return rects;
// }

SDL_Rect rectFactory(int x, int y, int width, int height)
{
    SDL_Rect rect = {.x = x, .y = y, .w = width, .h = height};

    return rect;
}

void plotRect(int x, int y, Agent citizen, int width, int height, SDL_Renderer *renderer)
{
    SDL_Rect rect = rectFactory(x, y, width, height);

    if (citizen.type == 1)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    }

    if (citizen.type == 0)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    if (citizen.type == 2)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }

    SDL_RenderFillRect(renderer, &rect);
}

void generateMatrix(std::vector<std::vector<Agent>> &segregationMatrix)
{

    int squareSize = 10;
    int matrixSize = segregationMatrix.size();

    int windowWidth = squareSize * matrixSize + 450;
    int windowHeight = squareSize * matrixSize + 50;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool appIsRunning = true;

    int numMillisToThrottle = 6;
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow(
        "Modelo de Segregação Social de Schelling", // window title
        SDL_WINDOWPOS_UNDEFINED,                    // initial x position
        SDL_WINDOWPOS_UNDEFINED,                    // initial y position
        windowWidth,                                // width, in pixels
        windowHeight,                               // height, in pixels
        SDL_WINDOW_SHOWN                            // flags - see below
    );

    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        printf("Could not create renderer: %s\n", SDL_GetError());
        return;
    }

    int cont = 0;

    while (appIsRunning)
    {
        // slowing things down a little, you can delete this if you like
        while (SDL_GetTicks64() - lastDrawTime < numMillisToThrottle)
        {
        }

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_QUIT)
            {
                appIsRunning = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // std::vector<SDL_Rect> rectsVector = RectMatrix(rectFactory, 10, 10, squareSize, renderer, matrixSize, segregationMatrix);
        // SDL_Rect rects[rectsVector.size()];
        // std::copy(rectsVector.begin(), rectsVector.end(), rects);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        for (size_t i = 0; i < segregationMatrix.size(); i++)
        {
            for (size_t j = 0; j < segregationMatrix.size(); j++)
            {
                plotRect(10 + squareSize * i, 10 + squareSize * j, segregationMatrix[i][j], squareSize, squareSize, renderer);
            }
        }

        // int success = SDL_RenderDrawRects(renderer, rects, rectsVector.size());
        // if (success < 0)
        // {
        //     std::cout << SDL_GetError() << std::endl;

        //     SDL_DestroyRenderer(renderer);
        //     SDL_DestroyWindow(window);
        //     SDL_Quit();
        //     appIsRunning = false;
        // }

        SDL_RenderPresent(renderer);

        // segregate(segregationMatrix);

        lastDrawTime = SDL_GetTicks64();
    }

    for (size_t i = 0; i < segregationMatrix.size(); i++)
    {
        for (size_t j = 0; j < segregationMatrix.size(); j++)
        {
            std::cout << segregationMatrix[i][j].type << " ";
        }
        std::cout << std::endl;
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return;
}