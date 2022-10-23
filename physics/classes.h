class SquareLeft {
    public: 
     static double velox;
     static double veloy;
     static double acceleration;
     static double xpos;
     static double ypos;
     static double KE;
     static double PE;
     static int width;
     static int height;
     static double mass;
};

class Counter {
    public: 
    static int collisions;
};

int Counter::collisions = 0;


class SquareRight {
    public: 
     static double velox;
     static double veloy;
     static double acceleration;
     static double xpos;
     static double ypos;
     static double KE;
     static double PE;
     static int width;
     static int height;
     static double mass;
};

class Constants {
    public:
    static double gravity;
    static double G;
    static double k;
};
    
    

    double gravity = 10;


    double SquareLeft::mass = 100;
    double SquareLeft::velox = rand() % 5;
    double SquareLeft::veloy = 0;
    
    int SquareLeft::height = 100;
    int SquareLeft::width = 100;
    
    double SquareLeft::xpos = 1000;
    double SquareLeft::ypos = 600;
    

    
    double SquareRight::mass = 1;
    double SquareRight::velox = 2;
    double SquareRight::veloy = 0;

    int SquareRight::height = 10;
    int SquareRight::width = 10;

    double SquareRight::xpos = 900;
    double SquareRight::ypos = 100 - SquareRight::height + SquareLeft::height;