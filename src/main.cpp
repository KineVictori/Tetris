
#include "threepp/threepp.hpp"

using namespace threepp;

namespace {

    // usikker
    auto createBox(const Vector3& pos, const Color& color) {
        auto geometry = BoxGeometry::create();
        auto material = MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }

    // sets the keys to control the boxes (mulig å forkorte koden?)
    class MyKeyListener: public KeyListener {

    public:
        MyKeyListener(Object3D& obj): obj_(obj) {}

        void onKeyPressed(KeyEvent evt) override {
            if (evt.key == Key::D) {
                obj_.position.x -= 1 * dt_;
            }
            if (evt.key == Key::A) {
                obj_.position.x += 1 * dt_;
            }
            if (evt.key == Key::W) {
                obj_.position.y -= 1 * dt_;
            }
            if (evt.key == Key::S) {
                obj_.position.y += 1 * dt_;
            }
        }

        void onKeyRepeat(KeyEvent evt) override {
            if (evt.key == Key::D) {
                obj_.position.x -= 1 * dt_;
            }
            if (evt.key == Key::A) {
                obj_.position.x += 1 * dt_;
            }
            if (evt.key == Key::W) {            // rotate later
                obj_.position.y -= 1 * dt_;
            }
            if (evt.key == Key::S) {
                obj_.position.y += 1 * dt_;
            }
        }

        void setDeltaTime(float dt) {
            dt_ = dt;
        }

    private:
        float dt_{0};
        Object3D& obj_;
    };
} // namespace

int main() {

    // creates the canvas
    Canvas canvas("tetris", {{"aa", 5}});
    //canvas.size(int 1000, int 1000);

    GLRenderer renderer(canvas.size());
    renderer.setClearColor(0x183f3e); // use 0x for # in hex
    //renderer.shadowMap().enabled = true;
    //renderer.shadowMap().type = threepp::ShadowMap::PFCSoft;

    const pointLight1 = THREEPP_POINTLIGHT_HPP(0x88aaff, 0.8, 20);
    pointLight1.position.set(8, 4, -4);
    pointLight1.shadowMap().enabled = true;


    // sets the camera position
    auto camera = PerspectiveCamera::create(); // OrthographicCamera for 2D
    camera->position.z = 22;

    canvas.onWindowResize([&] (WindowSize size) {
        camera->aspect = size.aspect(); // needed only for PerspectiveCamera
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });

    // moves the objects instead of the camera with keys
    MyKeyListener l(*camera);
    canvas.addKeyListener(&l);

    auto scene = Scene::create();
    //auto light = AmbientLight::create(Color::aliceblue, 0.5);
    //scene->add(light);



    // creates the boxes
    auto group = Group::create();
    group->add(createBox({-1, 0, 0}, Color::orange));
    group->add(createBox({1, 0, 0}, Color::yellow));
    scene->add(group);

    // creates text for Points
    TextRenderer textRenderer;

    auto& textHandle = textRenderer.createHandle("Points: ");
    textHandle.verticalAlignment = threepp::TextHandle::VerticalAlignment::TOP;
    textHandle.setPosition(0, 0);
    textHandle.scale = 2;

    // makes stuff move at a specific speed
    Clock clock;
    canvas.animate([&] {
        auto dt = clock.getDelta();
        l.setDeltaTime(dt);

        renderer.render(*scene, *camera);

        renderer.resetState(); // needed when using TextRenderer
        textRenderer.render();

    });
}

