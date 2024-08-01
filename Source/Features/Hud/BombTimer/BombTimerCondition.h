#pragma once

template <typename Context>
struct BombTimerCondition {
    explicit BombTimerCondition(Context context) noexcept
        : context{context}
    {
    }

    [[nodiscard]] bool shouldRun() const noexcept
    {
        return context.state().enabled;
    }

    [[nodiscard]] bool shouldShowBombTimer() const noexcept
    {
        return context.bombPlantedPanel().isVisible().value_or(true) && context.hasTickingC4();
    }

private:
    Context context;
};
