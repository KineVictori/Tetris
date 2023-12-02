
#include "ThreeppHelper.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

// makes it easier to create boxes for the tetrinos
std::shared_ptr<Mesh> ThreeppHelper::createBox(const Vector3& pos, const Color& color) {
    auto geometry = BoxGeometry::create();
    auto material = MeshBasicMaterial::create();
    material->color.copy(color);
    auto mesh = Mesh::create(geometry, material);
    mesh->position.copy(pos);

    return mesh;
}

//Mesh* ThreeppHelper::createBoxNormalPointer(const Vector3& pos, const Color& color) {
//    auto geometry = BoxGeometry::create();
//    auto material = MeshBasicMaterial::create();
//    material->color.copy(color);
//    auto mesh = Mesh::create(geometry, material);
//    mesh->position.copy(pos);
//
//    return *mesh;
//}