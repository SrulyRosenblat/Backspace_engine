# BackSpace engine 

## Entry point
- first '#include "BackSpace.h" '
- create a class inherited from BackSpaceApp
- in class define on Update
- call #define START_BACKSPACE_GAME(randomclassname);

## event loop
```cpp
while(true){
	onUpdate();
}
```

use 
```cpp
class yourClass : be::BackSpaceApp
{
public
	virtual void onUpdate() override;
}
START_BACKSPACE_GAME(randomclassname);


