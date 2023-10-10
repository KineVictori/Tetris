# Tetris

This is a project making the game Tetris that uses `threepp` as a dependency.

### Planen:
3D tetris! Prøv å hold koden ryddig, del opp i flere filer. Hold ukesmålene 
små nok til å kunne fullføres, ikke bli utbrent. Begynn heller litt på neste mål
enn å sette større mål for uka.

3/10: sette opp oppgaven i CLion.

10/10: sette opp brettet (tekst poeng), lage en kloss som kan beveges.

17/10: må boksene mindre (zoome ut?), fikse arrays? (/dt) så klossen 
flyttes en hel kloss bort om gangen

24/10: lage ulike klossfigurer som klasser(?) og få de til å kunne rotere.

31/10: kunne markere en full rad som "fullført", og få den vekk

7/11: delvis innlevering

...

12/12: endelig innlevering!

Etterhvert: effekter når en rad fullføres, kunne lagre en kloss til senere og hente den inn igjen

# threepp vcpkg test

This is a standalone demo project that uses `threepp` as a dependency.

In order to update `threepp`, replace the baseline value in [vcpkg-configuration.json](vcpkg-configuration.json).
The baseline should point to a [commit](https://github.com/Ecos-platform/vcpkg-registry/commits/main) 
from the [custom vcpkg registry](https://github.com/Ecos-platform/vcpkg-registry) that hosts the port.

In the future, it could be added to the main vcpkg registry.

As `vcpkg` is used, you need to tell CMake about it in order for dependency resolution to work: 

`-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`

###### Building under MinGW

Under MinGW you'll need to specify the vcpkg triplet:
```shell
-DVCPKG_TARGET_TRIPLET=x64-mingw-[static|dynamic]  # choose either `static` or `dynamic`.
-DVCPKG_HOST_TRIPLET=x64-mingw-[static|dynamic]    # <-- needed only if MSVC cannot be found. 
```
