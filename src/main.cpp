
#include "threepp/threepp.hpp"
#include "MyKeyListener.hpp"
#include "Tetrino.hpp"
#include "TetrinoEnum.hpp"
#include "TetrisGame.hpp"

using namespace threepp;


int main() {

    // creates the canvas
    Canvas canvas("tetris", {{"aa", 5}});

    GLRenderer renderer(canvas.size());
    renderer.setClearColor(0x183f3e); // use 0x for # in hex

    // sets the camera position
    auto camera = PerspectiveCamera::create(); // OrthographicCamera for 2D
    camera->position.z = 30;
    camera->aspect = canvas.size().aspect();
    camera->updateProjectionMatrix();

    canvas.onWindowResize([&] (WindowSize size) {
        camera->aspect = size.aspect(); // needed only for PerspectiveCamera
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });

//    Tetrino T {
//            shapes::T, Vector3{0, 10, 0}, Color::orange
//    };

    auto scene = Scene::create();


    // implements TetrisGame in main
    TetrisGame game{};

    // sets the Tetrino (via TetrisGame) to move with keys
    MyKeyListener l(game);
    canvas.addKeyListener(&l);

    // adds the boarder in the scene
    scene->add(game.getBorderGroup());
    scene->add(game.getTetrinoGroup());


    // creates text for Points
    TextRenderer textRenderer;

    auto& textHandle = textRenderer.createHandle("Points: ");
    textHandle.verticalAlignment = threepp::TextHandle::VerticalAlignment::TOP;
    textHandle.setPosition(0, 0);
    textHandle.scale = 2;


    // makes stuff move at a specific speed
    Clock clock;

    int iterations = 0;

    canvas.animate([&] {
        auto dt = clock.getDelta();
        //l.setDeltaTime(dt);

        renderer.render(*scene, *camera);

        renderer.resetState(); // needed when using TextRenderer
        textRenderer.render();

        iterations++;

        if (iterations % 60 == 0) {
            game.getTetrinoGroup()->position.add(Vector3(0, -1, 0));
        }
    });
}

