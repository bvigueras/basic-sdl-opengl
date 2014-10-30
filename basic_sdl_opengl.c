/*********************************************************************
 * Basic SDL OpenGL example.
 * 
 * This program is free software: you can redistribute and/or modify
 * this file under the terms of the GNU General Public License ad 
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) and later version.
 * See <http://www.gnu.org/licenses/>.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.  
 *********************************************************************/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    SDL_Surface *screen;
    // SDL Init
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n",
            SDL_GetError());
        return -1;
    }
    
    // Upon any exit condition, we execute SDL_Quit to clean up everything
    atexit(SDL_Quit);
    // Double buffering on.
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    // Set video mode with OpenGL support.
    screen = SDL_SetVideoMode(640, 480, 16, SDL_OPENGL);
    if (screen == NULL) {
        fprintf(stderr, "Unable to set video mode: %s\n",
            SDL_GetError());
        return -1;
    }
    
    SDL_WM_SetCaption("OpenGL with SDL!", "OpenGL");
    // Now we can use OpenGL commands!
    glViewport(80, 0, 480, 480);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Simple triangle.
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); glVertex3f(0.0, 1.0, -2.0);
    glColor3f(0.0, 1.0, 0.0); glVertex3f(1.0, -1.0, -2.0);
    glColor3f(0.0, 0.0, 1.0); glVertex3f(-1.0, -1.0, -2.0);
    glEnd();

    glFlush();
    SDL_GL_SwapBuffers();
    SDL_Delay(5000);  // Wait 5sec and exit.

    return 0;
}
