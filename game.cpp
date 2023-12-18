#include "game.hpp"
#include "entity.hpp"
#include "fly.hpp"
#include "vampire.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assetsNPC = NULL;
SDL_Texture* Drawing::assetsPlayer = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Vampire Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	Drawing::assetsNPC = loadTexture("finalSprite.png");
	Drawing::assetsPlayer = loadTexture("finalVampire.png");
    gTexture = loadTexture("background.png");
	if(Drawing::assetsNPC==NULL || gTexture==NULL || Drawing::assetsPlayer==NULL)

    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assetsPlayer);
	Drawing::assetsPlayer = NULL;
	SDL_DestroyTexture(Drawing::assetsNPC);
	Drawing::assetsNPC = NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

// Inside the Game class, add a variable to track the scrolling offset
int scrollingOffset = 0;

void Game::run()
{
    bool quit = false;
    SDL_Event e;

	Vampire vampire({0, 0, 90, 150}, {50, 385, 45, 75}, PLAYER);
	Entity* fly = new Fly({180, 0, 90, 90}, {105, 400, 60, 60}, NPC);

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
			else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_a:
						// Make sure the vampire is on the ground and that it doesn't already have a laser before changing direction or moving
						if ((vampire.m_moverRect.y + vampire.m_moverRect.h == 460) && (vampire.laser == nullptr))
							vampire.moveLeft();
                        break;
                    case SDLK_d:
						// Make sure the vampire is on the ground and that it doesn't already have a laser before changing direction or moving
						if ((vampire.m_moverRect.y + vampire.m_moverRect.h == 460) && (vampire.laser == nullptr))
                        vampire.moveRight();
                        break;
					case SDLK_l:
						// Make sure the vampire is on the ground and that it doesn't already have a laser 
						if ((vampire.m_moverRect.y + vampire.m_moverRect.h == 460) && (vampire.laser == nullptr))
							vampire.shootLaser();
                    default:
                        break;
                }
            }
        }

        // Update the scrolling offset to create the scrolling effect
        scrollingOffset -= 2; // Adjust the scrolling speed as needed

        // Render the background texture at the current scrolling offset
        SDL_Rect renderQuad = { scrollingOffset, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_RenderClear(Drawing::gRenderer);
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, &renderQuad);

        // Render a second copy of the background texture to create the continuous scrolling effect
        SDL_Rect renderQuad2 = { scrollingOffset + SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, &renderQuad2);

        // Check if the first copy of the texture has scrolled completely off-screen
        if (scrollingOffset <= -SCREEN_WIDTH)
        {
            scrollingOffset = 0;
        }

		// Draw the vampire and the fly
		vampire.drawEntity();
		fly->drawEntity();

		// Update the vampire's laser
		if (vampire.laser != nullptr)
		{
            vampire.laser->update();
            if (vampire.laser->reachedEnd())
			{
                delete vampire.laser;
                vampire.laser = nullptr;
            }
        }

        SDL_RenderPresent(Drawing::gRenderer);
        SDL_Delay(10); // Adjust the delay to control the frame rate
    }
}