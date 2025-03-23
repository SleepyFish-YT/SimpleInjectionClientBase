// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "Player_Esp.h"
#include "../../sdkm/impl/entity/EntityPlayerSP.h"
#include "../../../Client.h"
#include "../../utils/unit/Vec2.h"
#include "../../utils/RenderUtils.h"

Player_Esp::Player_Esp() : Module("player esp", "render boxes around players") {

    this->addSetting(Player_Esp::invisOnly);

    Player_Esp::renderData = new std::vector<Data*>();

}

void Player_Esp::updateEnabled() {
    if (this->enabled) {
        Client::inst->minecraft->activeRenderInfo = new ActiveRenderInfo();
        Player_Esp::renderData->clear();
    }

    Interface::renderPlayerEsp = this->enabled;
}

void Player_Esp::onTick() {
    if (Interface::isGuiOpen) {
        Player_Esp::renderData = {};
        return;
    }

    auto* newData = new std::vector<Data*>();

    const RenderManager renderManager = Client::inst->minecraft->getRenderManager();
    if (renderManager.isNull())
        return;

    const Vec3 renderPos = renderManager.getRenderPosition() + Vec3 { 0, 3.4F, 0 };
    const EntityPlayerSP &player = Client::inst->minecraft->getPlayer();
    const Vec3 playerPos = player.getPosition();

    Player_Esp::modelView = Client::inst->minecraft->activeRenderInfo->getModelViewMatrix();
    Player_Esp::projection = Client::inst->minecraft->activeRenderInfo->getProjectionMatrix();

    CTimer timer = Client::inst->minecraft->getTimer();
    if (timer.isNull())
        return;

    const float renderPartialTicks = timer.getPartialTicks();
    const bool onlyShowInvisibleB = Player_Esp::invisOnly->value;

    const float entityHeight = 1.1F;

    const WorldClient wrld = Client::inst->minecraft->getWorld();
    if (wrld.isNull())
        return;

    for (EntityPlayer& entity : wrld.getPlayers()) {
        if (entity.isNull())
            continue;

        const Vec3 entityPos = entity.getPosition();

        const float dist = playerPos.distance(entityPos);
        if (dist > 300)
            continue;

        if (!entity.isAlive())
            continue;

        if (onlyShowInvisibleB && !entity.isInvisible())
            continue;

        const Vec3 entityLastPos = entity.getLastPosition();
        float entityWidth = 0.6F;

        const Vec3 origin { renderPos - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 top { (renderPos - Vec3 {0, entityHeight * 2, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 left { (renderPos - Vec3 {entityWidth, entityHeight, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 right { (renderPos - Vec3 {-entityWidth, entityHeight, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 back { (renderPos - Vec3 {0, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 front { (renderPos - Vec3 {0, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        entityWidth /= 1.388888F;
        const Vec3 left2 { (renderPos - Vec3 {entityWidth, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 right2 { (renderPos - Vec3 {-entityWidth, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 back2 { (renderPos - Vec3 {-entityWidth, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };
        const Vec3 front2 { (renderPos - Vec3 {entityWidth, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };

        std::vector<Vec3> vec {
            origin, top, left, right, back, front, left2, right2, back2, front2
        };

        newData->push_back( new Data {
            vec, entity.getHealth()
        });

        Player_Esp::renderData = newData;
    }
}

void Player_Esp::render(ImVec2 screenSize) {
    if (Interface::isGuiOpen)
        return;

    if (Player_Esp::renderData->empty())
        return;

    ImDrawList* drawList = ImGui::GetWindowDrawList();
    const ImColor col = ImColor(Interface::clientColor);

    for (const Data* data : *Player_Esp::renderData) {
        std::vector<Vec3> bv = data->boxVec;
        if (bv.empty())
            continue;

        float left = FLT_MAX;
        float top = FLT_MAX;
        float right = FLT_MIN;
        float bottom = FLT_MIN;

        bool skip = false;
            for (Vec3 position : bv) {
                Vec2 p = {0, 0};

                if (!RenderUtils::worldToScreen(position, Player_Esp::modelView, Player_Esp::projection, screenSize, p)) {
                    skip = true;
                    break;
                }

                left = fmin(p.x, left);
                top = fmin(p.y, top);
                right = fmax(p.x, right);
                bottom = fmax(p.y, bottom);
            }
        if (skip) continue;

        drawList->AddRect(ImVec2(left, top), ImVec2(right, bottom), col, 0, 0, 1.6f);
    }
}