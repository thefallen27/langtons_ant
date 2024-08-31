# Langton's Ant
Implementation of the Langton's ant Turing machine

## Description
This program is a simple implementation of the Langton's Ant Turing machine in C++. 
It uses the SDL2 library to visualize it. Simple DirectMedia Layer is a cross-platform
development library designed to provide low level access to graphic hardware via OpenGL
and Direct3D, as well as audio, keyboard, mouse, and joystick.It is used by video playback
software, emulators, and popular games including many Humble Bundle games which, not promoted,
I donwload a lot of games from.

I redid the program in Odin, a general-purpose programming language with distinct typing
built for high performance, modern systems and data-oriented programming. Odin is the C 
alternative for the Joy of Programming and it is used in multiple games nowadays. As part
of me learning this programming language, I redid it using this language to see how I fare.
I faced a lot of issues, and the way to overcome those was through a lot of reading of
the documentation. Sadly, there aren't a lot of resources available online, so the documentation
was the only option.

## The story behind...
Langton's ant is a two-dimensional Turing machine with a very simple set of rules but complex emergent
behaviour. It was invented by Chris Langton in 1986 and runs on a square lattice of black and white
cells. In this context, the ant is a virtual entity (in the program is represented by a red dot) that
moves on a grid of cells. The cells can be either black (initial state) or white. Langton's ant follows
two simple rules:<br>

&nbsp;&nbsp;&nbsp;&nbsp;1. The ant starts on a grid of white cells, facing in one of four cardinal directions<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i.e., north, south, east, or west.<br>
&nbsp;&nbsp;&nbsp;&nbsp;2. At each step:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a. If the ant is on a white cell, it turns 90 degrees to the right, flips the color of the cell<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to black, and moves forward one unit.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;b. If the ant is on a black cell, it turns 90 degrees to the left, flips the color of the cell to<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;white, and moves forward one unit.<br>

The initial behaviour (first thousand steps) seems to be chaotic and unpredictable. As the number
of steps increases (usually more than 10000), the ant will eventually start building a regular,
repeating pattern that moves off in a diagonal direction. This pattern is called a "highway".

Langton's ant has been modified in the past to include multiple ants (which means also multiple
initial states) and thus bring it closer to an actual Turing machine (simulating the head, state
and tape a Turing machine actually includes). This means that in theory, such a system could 
perform any computation a Turing machine can, thus turning it into Turing complete. It was also
demonstrated in the past to simulate logic gates by arranging multiple ants and setting them on 
the grid, creating AND, OR, and NOT gates.

Langton's ant and its variants are used to model and study natural processes with similar emergent
behaviour such as traffic flow, spread of information, and formation of patterns in biological
systems. They can also be used to inspire new algorithms in distributed computing, as well as being
used in education to teach the concepts of complexity theory and celllar automata.

## The code
The program is written in C++ 20 and uses the SDL2 library for visualization purposes. It initializes
an SDL2 window and renderer to use for drawing the grid and the ant. The grid is represented as a 2D
vector of booleans where `true` means the cell is black and `false` means it's white. For each step,
the grid is updated and refreshed to show the current state of the simulation. User gets to input the
number of steps the ant will take, thus enabling them to control the time the simulation runs, as 
well as seeing if they can spot patterns or just emergent behaviour.

In the program, the function SDL_DELAY is called. This function is basically a sleep function that will
determine how long will the program sleep between iterations. Here:

```
        SDL_RenderPresent(renderer);

        SDL_Delay(15); // Simulation speed (refresh rate) in ms
    }
```
it shows how fast the refresh rate will be. If the number is too low, the user will not be able to spot
the ant's movements clearly. If it is too big like here:

```
 SDL_Delay(5000); // Window display time in ms
```

it will take forever for the simulation to run. In the second case, I use it to display the whole
grid with the final step before closing the application.

To execute the code and play with it, you will first need to install the SDL2 library.
You can do so by executing the following on your Linux machine:

```
sudo apt-get install libsdl2-dev
```

If this does not work, try to update your Linux and use the --fix-missing option (it happenned to me
and these two things helped me). To run the program, type:

```
g++ -std=c++20 ant.cpp -lSDL2 -o l_ant
./l_ant
```

In the case of Odin, things are different. I used the raylib library to get the visualization
for Langton's ant. All of the documentation and instructions can be found in the links below.


## Notes
To download the SDL2 library you can visit their website here:<br>
[SDL2 Library](https://www.libsdl.org/)<br>
For more on Langton's ant:<br>
[Langton's ant](https://en.wikipedia.org/wiki/Langton%27s_ant)<br>
If you don't want to run the program, you can have a look at the implementation here:<br>
[Langton's ant online](https://www.langtonsant.com/)<br>

To install Odin:<br>
[Odin Installation Instruction](https://odin-lang.org/docs/install/)<br>
Odin's github page can be found here:<br>
[Odin github](https://github.com/odin-lang/Odin/releases/tag/dev-2024-08)<br>
A few examples that helped me get through the issues and writting of my code:<br>
[Odin examples](https://github.com/odin-lang/examples)

## License
This project is licensed under the MIT license.
