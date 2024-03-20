// Shoot Them Up Game, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUTimeHUDWidget.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUTimeHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetFormatRoundTime() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    FGameData GetGameData() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetCurrentRound() const;
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetPlayerKills() const;

    virtual bool Initialize() override;
    
};
