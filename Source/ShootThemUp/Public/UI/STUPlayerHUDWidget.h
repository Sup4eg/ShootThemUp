// Shoot Them Up Game, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUPlayerHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    float Get_HealthPercent() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsPlayerAlive() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool isPlayerSpectating() const;

    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void OnTakeDamage();

protected:
    virtual void NativeOnInitialized() override;

private:
    void OnHealthChanged(float Health, float HealthDelta);
    void OnNewPawn(APawn* NewPawn);
};
