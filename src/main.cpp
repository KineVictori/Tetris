
#include "threepp/threepp.hpp"
#include "MyKeyListener.hpp"
#include "Tetrino.hpp"
#include "TetrinoEnum.hpp"
#include "TetrisGame.hpp"

using namespace threepp;


int main() {

    // creates the canvas
    Canvas canvas("tetris", {{"aa", 5}});
    //canvas.size(int 1000, int 1000);

    GLRenderer renderer(canvas.size());
    renderer.setClearColor(0x183f3e); // use 0x for # in hex
//    renderer.shadowMap().enabled = true;
//    renderer.shadowMap().type = threepp::ShadowMap::PFCSoft;
//
//    const pointLight1 = THREEPP_POINTLIGHT_HPP(0x88aaff, 0.8, 20);
//    pointLight1.position.set(8, 4, -4);
//    pointLight1.shadowMap().enabled = true;
//    auto light = AmbientLight::create(Color::aliceblue, 0.5);
//    scene->add(light);

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

    // moves the objects instead of the camera with keys
    MyKeyListener l(*camera);
    canvas.addKeyListener(&l);

    auto scene = Scene::create();


//    // creates the boxes
//    auto group = Group::create();
//    group->add(createBox({-1, 0, 0}, Color::orange));
//    group->add(createBox({1, 0, 0}, Color::yellow));
//    scene->add(group);

    TetrisGame game{};
    game.Border(Vector3{0, 10, 0}, Color::grey);
    scene->add(game.getGroup());


    Tetrino T {
            shapes::T, Vector3{0, 10, 0}, Color::orange
    };
    scene->add(T.getGroup());

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
        l.setDeltaTime(dt);

        renderer.render(*scene, *camera);

        renderer.resetState(); // needed when using TextRenderer
        textRenderer.render();

        iterations++;

        if (iterations % 60 == 0) {
            T.getGroup()->position.add(Vector3(0, -1, 0));
        }
    });
}

