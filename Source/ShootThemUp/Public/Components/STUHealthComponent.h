// Shoot Them Up Game, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    USTUHealthComponent();

    float GetHealth() const { return Health; }

    UFUNCTION(BlueprintCallable)
    bool IsDead() const { return Health <= 0.0; }

    
    UFUNCTION(BlueprintCallable)
    bool isAutoHeal() const { return AutoHeal; }

    FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

protected:
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0", ClampMax = "1000"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (ClampMin = "0", ClampMax = "10"))
    float HealUpdateTime = 0.3f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (ClampMin = "0", ClampMax = "10"))
    float HealDelay = 3.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (ClampMin = "1", ClampMax = "1000"))
    float HealModifier = 1.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal")
    bool AutoHeal = true;


    // Called when the game starts
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnTakeAnyDamage(
        AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

private:
    float Health = 0.0f;
    FTimerHandle TimerHandle;
    void TakeHeal();
};
