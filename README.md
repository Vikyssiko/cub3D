# 42 cub3D
Pseudo 3D game made with the help of raycasting algorithm

![screenshot](screenshot.png)

Requirements:
* The use of `miniLibX` library is mandatory.
* Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
* The program must be able to set the floor and ceiling colors to two different ones.
* The program displays the image in a window and respects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
  - The `W`, `A`, `S`, and `D` keys must allow you to move the point of view through the maze.
  - Pressing `ESC` must close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
  - The use of `images` of the `minilibX` is strongly recommended.
* Your program must take as a first argument a scene description file with the `.cub` extension.
  - The map must be composed of only 6 possible characters: `0` for an empty space, `1` for a wall, and `N`,`S`,`E` or `W` for the player’s start position and spawning orientation.
  - The map must be closed/surrounded by walls, if not the program must return an error.
  - Except for the map content, each type of element can be separated by one or more empty line(s).
  - Except for the map content which always has to be the last, each type of element can be set in any order in the file.
  - Except for the map, each type of information from an element can be separated by one or more space(s).
  - The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.
  - Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :
    + North texture: `NO ./path_to_the_north_texture`
    + South texture: `SO ./path_to_the_south_texture`
    + West texture: `WO ./path_to_the_west_texture`
    + East texture: `EO ./path_to_the_east_texture`
    + Floor color: `F 220,100,0` (identifier: `F`, R,G,B colors in range [0,255]: 0, 255, 255)
    + Ceiling color: `C 220,100,0` (identifier: `C`, R,G,B colors in range [0,255]: 0, 255, 255)
*  If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.\\

This is an example of a valid map:

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Bonus
* Wall collisions.
* A minimap system.
* Doors which can open and close. (The doors in the map are represented with `D` symbol)
* animated sprite.
* Rotate the point of view with the mouse.
 
## Launching the program

To launch the program use command `make`. Then execute `./cub3D` with one argument, which is a map, for example `maps\map2.cub`. If you want to see the bonus part compile with `make bonus`


### Compatibility
The project is done on `Linux` and it uses linux miniLibX library, that's why it will not work on `MacOS`
