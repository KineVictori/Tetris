
#include "threepp/threepp.hpp"

using namespace threepp;

namespace {

    auto createBox(const Vector3& pos, const Color& color) {
        auto geometry = BoxGeometry::create();
        auto material = MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }

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
            if (evt.key == Key::W) {
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

    Canvas canvas("tetris", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;

    MyKeyListener l(*camera);
    canvas.addKeyListener(&l);

    auto scene = Scene::create();

    auto group = Group::create();
    group->add(createBox({-1, 0, 0}, Color::lightpink));
    group->add(createBox({1, 0, 0}, Color::lightblue));
    scene->add(group);

    Clock clock;
    canvas.animate([&] {
        auto dt = clock.getDelta();
        l.setDeltaTime(dt);

        renderer.render(*scene, *camera);
    });
}