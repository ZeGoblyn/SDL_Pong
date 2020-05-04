#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "voidBalle.h"
#include "SDL2/SDL_TTF.h"


//void score(int, int, int, int);

//void depRebond(int, int, int, int, SDL_Rect, SDL_Rect);

int main(int argc, char* argv[])
{
	int pseudoBool = 0;
	int i = 1;
	int x = 400;
	int y = 100;

	int vitX = 8;
	int vitY = 8;

	int scJ1 = 0;
	int scJ2 = 0;

	SDL_Window* pWindow = NULL;           //Pointeur sur la fenêtre, ref d'un window win32
	SDL_Renderer* pRenderer = NULL;       //Pointeur sur le Rendus, ref rendu encapsulé dans window
	//SDL_Texture *pTexture=NULL;         //Pointeur sur la texture, qui possède l'image à afficher, ref image/texture/materiel
	SDL_Event event;


	//Requis pour utiliser la SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)    //INIT_EVERYTHING = initialise l'audio, la vidéo, les contrôles,... cf; SDL wiki/API by name/SDL_Init
	{
		//succès, créer window
		pWindow = SDL_CreateWindow("SDL_Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);//x,y,width,eight

	  //si succès, créer window et renderer
		if (pWindow != NULL)
		{
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
			/* }
			 else
			 {*/

			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderPresent(pRenderer);

			//Dessein raquête 1//
			SDL_Rect rect1;
			rect1.x = 0;
			rect1.y = 350;
			rect1.w = 25;
			rect1.h = 100;

			SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(pRenderer, &rect1);

			SDL_RenderFillRect(pRenderer, &rect1);

			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
			//-----------------//


			//Dessein raquête 2//
			SDL_Rect rect2;
			rect2.x = 775;
			rect2.y = 350;
			rect2.w = 25;
			rect2.h = 100;

			SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(pRenderer, &rect2);

			SDL_RenderFillRect(pRenderer, &rect2);

			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
			//-----------------//


			//Dessein filet//
			SDL_Rect rectF;
			rectF.x = 398;
			rectF.y = 0;
			rectF.w = 4;
			rectF.h = 800;

			SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(pRenderer, &rectF);

			SDL_RenderFillRect(pRenderer, &rectF);

			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
			//-----------------//


			cerclePlein(pRenderer, 700, 500, 10, 1000);

			SDL_Event event;

			while (i)
			{

				SDL_PollEvent(&event);
				switch (event.type)
				{
				case SDL_QUIT:
					i = 0;
					break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						i = 0;
						break;

						//Gestion des touches//
					case SDLK_UP:
						rect2.y -= 10;
						printf("UP");
						SDL_Delay(11);
						break;

					case SDLK_DOWN:
						rect2.y += 10;
						printf("DOWN");
						SDL_Delay(11);
						break;

					case SDLK_z:
						rect1.y -= 10;
						printf("UP");
						SDL_Delay(11);
						break;

					case SDLK_s:
						rect1.y += 10;
						printf("DOWN");
						SDL_Delay(11);
						break;
					}
					break;
				}

				//Vitesse_direction//
				x = x + vitX;

				y = y + vitY;

				if ((x <= rect1.x + 25) && (y >= rect1.y && y <= rect1.y + rect1.h))
				{
					vitX *= -1;
				}

				if ((x >= rect2.x) && (y >= rect2.y && y <= rect2.y + rect2.h))
				{
					vitX *= -1;
				}

				if (y <= 10 || y >= 790)
				{
					vitY *= -1;
				}
				//----------------//


				//depRebond(x, y, vitX, vitY, rect1, rect2);

				//score(x, y, scJ1, scJ2);

				//Gestion_score//
				if (x > 800)
				{
					x = 400;

					y = 100;

					scJ1++;

					printf("%d", scJ1);
				}

				if (x < 0)
				{
					x = 400;

					y = 100;

					scJ2++;

					printf("%d", scJ2);
				}
				//--------------//

				//Ecriture score//
				/*TTF_Font* fFont = TTF_OpenFont("calibri.ttf", 1000);

				SDL_Color cBlanc = { 255, 255, 255 };

				char cScore[5] = "";
				sprintf(cScore, "%d", scJ1);

				SDL_Surface* pSurface = TTF_RenderText_Solid(fFont, cScore, cBlanc);

				SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);

				SDL_Rect rRectText;
				rRectText.x = 200;
				rRectText.y = 50;
				rRectText.w = 50;
				rRectText.h = 50;

				SDL_RenderCopy(pRenderer, pTexture, NULL, &rRectText);

				SDL_FreeSurface(pSurface);
				SDL_DestroyTexture(pTexture);

				sprintf(cScore, "%d", scJ2);
				pSurface = TTF_RenderText_Solid(fFont, cScore, cBlanc);

				pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);

				rRectText.x = 600;
				rRectText.y = 50;

				SDL_RenderCopy(pRenderer, pTexture, NULL, &rRectText);

				SDL_FreeSurface(pSurface);
				SDL_DestroyTexture(pTexture);
				free(fFont);*/
				//-------------//


				cerclePlein(pRenderer, x, y, 10, 1000);

				SDL_RenderClear(pRenderer);

				SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);

				SDL_RenderDrawRect(pRenderer, &rect1);

				SDL_RenderFillRect(pRenderer, &rect1);

				SDL_RenderDrawRect(pRenderer, &rect2);

				SDL_RenderFillRect(pRenderer, &rect2);

				SDL_RenderDrawRect(pRenderer, &rectF);

				SDL_RenderFillRect(pRenderer, &rectF);

				SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

				SDL_RenderPresent(pRenderer);
			}



			/*
			SDL_DestroyTexture(spriteGuy);
			SDL_FreeSurface(image);
			SDL_FreeSurface(surfaceSprite);*/
			SDL_DestroyRenderer(pRenderer); //On supprime tout ce qui à été créer
			SDL_DestroyWindow(pWindow);
			SDL_Quit();

		}

	}

	return 0;
}