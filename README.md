# 3D Tetris

---

This is a project making the game Tetris in 3D that uses `threepp` as a dependency.
It was made for an exam in the course AIS1003 - "Object oriented programming for cyber physical systems".

I made my own version of Tetris with the game board a bit bigger than the original game, and the shapes, ```Tetrinos```, in 3D and new colours.
You control the ```Tetrinos``` with the keys "ASD" for left, down and right, and use "W" to rotate.
The points system is more simplified than the original, so you get 100 points for every ```Tetrino``` you put down and 1200 for clearing a full row.

---
![img_1.png](img_1.png)

### Current state

As of December 7th, 2023 the game is still a work in progress and I keep finding more and more to improve.

The game works great as long as you only clear one row at the time, and don't look at the colours.
The logic behind works, but the rendering got complicated fast and only deletes boxes on the first full row.
So now, when you clear multiple rows at once, the new ```Tetrino``` will continue to fall as many boxes as should have been cleared into the ones that are still there.
This is a rendering problem I'm still trying to figure out. 
It could be fixed by instead of having two sets of the game board (one visual and one for logic),
to have only one and then a function which render the values in the grid that are ```true```.
This would also fix the problem with rotation at the border, since it then no longer can crash into itself (see comment in TetrisGame.cpp).

Also, if you try to rotate at the border you are supposed to get pushed out again so that the ```Tetrino``` won't rotate into it,
but this works only sometimes.

### Further improvements:

- Push back ```Tetrino``` when rotated into the sidewalls of the border.
- Clear the rendered boxes of all completed rows if more than one is cleared at once, not just the first.
- Shadows for better 3D effect.

---

### How to build

Since this project uses ```threepp``` to render, you will need these lines in the CMake build profile:

```shell
-DVCPKG_TARGET_TRIPLET=x64-mingw-[static|dynamic]  # choose either `static` or `dynamic`.
-DVCPKG_HOST_TRIPLET=x64-mingw-[static|dynamic]    # <-- needed only if MSVC cannot be found. 
```


---

### Planen:

- Fikse tall og småting på kollisjonssjekk
- Fikse moveRowDown for flere enn 1 rad (logikk er riktig, ikke render)
- README
- Tester!! Sjekk om random er random / kollisjon

finpussing, rydde i koden, ferdigstille

#### 12/12: innlevering + skriveoppgave

```shell
Bruk tester!! Sjekk om kollisjon funker
```
