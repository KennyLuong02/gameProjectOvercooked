// The x and y size in pixels of the "grid" cells.
// NOTE: This is also the size in pixels of all the graphic sprites
constexpr unsigned char CELL_SIZE               = 16; // Pixels

constexpr unsigned char FONT_HEIGHT             = 16; // Pixels

//Fix this
constexpr unsigned char MAP_HEIGHT              = 21; // Cells 
constexpr unsigned char MAP_WIDTH               = 21; // Cells 

constexpr unsigned char PLAYER_ANIMATION_FRAMES = 6;  // Number of frames in the animation series
constexpr unsigned char PLAYER_ANIMATION_SPEED  = 4;  // Not sure, Animation frames per update frame???
constexpr unsigned char PLAYER_SPEED            = 2;  // Pixels per update frame
constexpr unsigned char SCREEN_RESIZE           = 2;  // Seems to be a factor to double the size of the main game window

//Don't know
constexpr unsigned char PLAYER_DEATH_FRAMES     = 12; // Number of frames in the animation series

//This is in frames. So don't be surprised if the numbers are too big
constexpr unsigned short FRAME_DURATION         = 16667;// micro-seconds

//Don't know
constexpr unsigned short CHASE_DURATION         = 1024; // frames
constexpr unsigned short LONG_SCATTER_DURATION  = 512;  // frames
constexpr unsigned short SHORT_SCATTER_DURATION = 256;  // frames

enum ObjectType {
	Stove,
	Dishwasher,
	Wall,
	Empty,
	
	//We may need this
	BOWL,
	Onion,
	Tomato,
	Mushroom

};

struct Position {
		bool operator==(const Position& i_position) { //what is this and why bool
			return this->x == i_position.x && this->y == i_position.y;
		};

    	int x;
	    int y;
};
