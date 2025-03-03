#pragma once

#include <utility>

template <typename HookContext>
class PlayerOutlineGlowContext;

template <typename HookContext, typename Context = PlayerOutlineGlowContext<HookContext>>
class PlayerOutlineGlowCondition {
public:
    template <typename... Args>
    explicit PlayerOutlineGlowCondition(Args&&... args) noexcept
        : context{std::forward<Args>(args)...}
    {
    }

    [[nodiscard]] bool shouldRun() const noexcept
    {
        return context.state().enabledForPlayers;
    }

    [[nodiscard]] bool shouldGlowPlayer(auto&& playerPawn) const noexcept
    {
        return playerPawn.isAlive().value_or(true)
            && playerPawn.health().greaterThan(0).valueOr(true)
            && !playerPawn.isControlledByLocalPlayer()
            && playerPawn.isTTorCT()
            && (!context.state().showOnlyEnemies || playerPawn.isEnemy().value_or(true));
    }

private:
    Context context;
};
