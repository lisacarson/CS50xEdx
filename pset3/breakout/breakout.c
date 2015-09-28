//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

//
#define PADDLEW 50
#define PADDLEH 10
#define PADDLEMAX (WIDTH - PADDLEW)
#define PADDLEMIN 0

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    double velocityx = drand48() +1;
    double velocityy = drand48() + 1;
    
    GObject object;
    waitForClick();
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
      
        updateScoreboard(window,label, points);
        move(ball, velocityx, velocityy);
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                double y = HEIGHT - 50;
                if (x >= PADDLEMAX)
                {
                    setLocation(paddle, PADDLEMAX, y);
                }
                else if(x <= PADDLEMIN)
                {
                    setLocation(paddle, PADDLEMIN, y);
                }
                else
                setLocation(paddle, x ,y);
            }
        }
    
                       
                        
                            
        //move(ball, velocityx, velocityy);
            
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {      
            lives--;
            setLocation(ball, 190, 290);
            setLocation(paddle,175, 550);
            waitForClick();
        }
                            
            
        else if (getY(ball) <= 0)
        {
            velocityy = -velocityy;
        }
                            
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocityx = -velocityx;
        }
            
        else if (getX(ball) <= 0)
        {
            velocityx = -velocityx;
        }
        pause(10);
                            
               
        //move(ball, velocityx, velocityy);    
        detectCollision(window, ball);
        GObject object = detectCollision(window, ball);
        if (object != NULL)
        {
            if (object == paddle)
            {          
                velocityy = -velocityy;
            }     
             
           
                    
            else if (strcmp(getType(object), "GRect") == 0)
            {
                bricks--;
                points++;
                removeGWindow(window, object);
                if (getY(ball) >= getY(object))
                {
                    velocityy = -velocityy;                           
                }
                        
                
                
                         
             }        
             
         }
                                                   
     }
                        
               
               
         
                
                    
                
                        
        
    

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
     
    for (int rows = 0; rows < ROWS; rows++)
    {
        for(int column = 0; column < COLS; column++)
        {
            GRect bricks = newGRect(2.5 + (column * 40) ,(50 + (rows * 15)),35, 10);
            setColor(bricks, "ORANGE");
            setFilled(bricks, true);
            add(window, bricks);          
        }
        
        
    }
  
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(190,290,20,20);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(200 - (50 / 2), 600 - 50, 50, 10);
    setColor(paddle, "BLUE");
    setFilled(paddle, true);
    add(window, paddle);
    

    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    setColor(label, "LIGHT_GRAY");
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
