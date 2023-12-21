# Yisroel-Rosenblat-F23
the program ran using cmake on two separate machines

## Game
### untitled ghost game

[screen capture](Assets/Pictures/capture.png?raw=true)

In this game (no real game goal, just float around) you are able to control a ghost and move around a house additionally you have a baby ghost that for the most part follows you around, while the house itself is just one room and non-interactive I worked hard to make both the player's ghost and the baby ghost feel like they are breathing and simulating intelligence by having the baby ghost move around on its own.

controls:
- up key
- down key
- left key
- right key

mechanics:
- the player's ghost has a hovering animation that is always playing when it's not moving but turned off while in vertical motion so as not to interfere with the player's movement.
- bounded play area so both the player and non-player ghost cannot leave the screen.
- the baby ghost follows the player around for the most part and will usually stop just short of touching the player.
- I simulated boredom with the baby ghost so that if the player stays stagnant for too long it will go off on its own to explore.
- both the player and non-player ghost could turn around and switch directions when they do so.
- I made holding a key work as opposed to needing to press again for every movement.
- wait in one place for a while to activate the baby ghost's boredom and it will roam around for a bit and go to a random part of the room.


alterations to the game engine:
- I made a small change to the unit class so that two images are stored for left and right directions.
- I added a DrawAlt function to backspace.app to draw the alternate image
image sources:
    I lost the actual image sources when I switched phones (stored on WhatsApp) but both the background and player ghost were taken directly from the internet (except for things like flipping the images and removing the background), the baby ghost was modified visually and I changed things like the color so may be harder to find it.
