## evaluation

40% of exam
current: 29/40

<hr>

## To-Do

- *dynamic memory allocation (new)*
- *dynamic memory removing (delete)*
- *correct and useful usage of command line parameters* **(Want to print highscore?)**

## Polymorphism
- useful and correct inheritance -> no child class in this project
- useful and correct multiple inheritance -> no child class in this project
- correct base class -> no child class in this project
- correct abstract base class -> no child class in this project
- useful virtual function -> no child class in this project
- useful proven (dynamic) polymorphism -> no child class in this project
- correct protections -> no child class in this project

## Too much work
- everything in one or more self-made namespace(s)
- correctly using const in almost all places (almost everywhere possible)
- useful string class usage
- useful container class
- useful operator overloading
- useful function overloading (non operator)
- useful function overriding (non virtual)
- useful template function or class
- useful non-type template arguments
- useful friend function or class
- correct useage of inline function
- useful recursive function
- useful usage of signals/slots
- useful usage of lambda function
- test-driven development (= written test plan or unit tests)
- solved on 8 bug tickets
- reported 8 bug tickets on other projects
- usage of a GUI
- project that works with hardware

## The ones i can truly confirm:

- clean main (i.e. nothing in the main that shoud be in a class)
- useful class (explain why)
- useful pointer declaration and usage -> food::reset(Snake *snake)
- at least 2 default constructors -> Food(), Snake() & Game()
- *at least 2 specific constructors -> Food(), Snake() & Game()*
- useful useage of "this" -> food::reset(Snake *snake)
- *at least 2 destructors -> ~Food(), ~Snake() & ~Game()*
- *member initialization in constructors (the stuff behind a colon) -> Food::Food()*
- useful member variabel
- useful member function
- seperate header files
- 2 useful unsigned chars or other better usage of memory efficient type
- useful usage of (modern) file-I/O
- default values in function definition
- at least 4 useful bool -> isRunning, fullscreen, badColission(), foodColission()
- 2 useful (modern) call-by-references -> printNewAlltimeHighscore(), printAllTimeHighscore()
- usage of OpenGL or other 3D engine -> SDL
- useful usage of an external library -> SDL
- one complete project that compiles and does not crash
- working build manual as readme on GitHub (project must be possible to build from scratch on a clean PC)
- maintanability by clean uniform code style and good function naming and/or comments everywhere
- no mistake in object-oriented programming
- using the best suited type on a lot of places (almost everywhere possible)
- at least 4 useful const references
- *no globals, but statics if needed*
- useful usage of nullptr
- useful and correct encapsulation (explain why)
- useful getters and setters for member variables
- useful and correct object composition (explain why) -> "Snake \*snake = nullptr" in Game class;
- a nice extra that you think that should deserve grading (stuff you put time in and is not rewarded by an item above) -> making .exe?
