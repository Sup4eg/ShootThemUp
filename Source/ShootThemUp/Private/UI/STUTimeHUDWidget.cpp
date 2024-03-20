// Shoot Them Up Game, All Rights Reserved

#include "UI/STUTimeHUDWidget.h"
#include "STUGameModeBase.h"
#include "STUPlayerState.h"

bool USTUTimeHUDWidget::Initialize()
{
    check(GetWorld());
    return Super::Initialize();
}


FString USTUTimeHUDWidget::GetFormatRoundTime() const
{
    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
    const auto TimeLeft = GameMode->GetRoundCountDown();

    const int32 Minutes = TimeLeft / 60;
    const int32 Seconds = TimeLeft - Minutes * 60;
    FString MinutesStr = Minutes / 10 ? FString::FromInt(Minutes) : "0" + FString::FromInt(Minutes);
    FString SecondsStr = Seconds / 10 ? FString::FromInt(Seconds) : "0" + FString::FromInt(Seconds);
    return MinutesStr + ":" + SecondsStr;
}

FGameData USTUTimeHUDWidget::GetGameData() const
{
    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
    return GameMode->GetGameData();
}

int32 USTUTimeHUDWidget::GetCurrentRound() const
{
    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
    return GameMode->GetCurrentRound();
}

int32 USTUTimeHUDWidget::GetPlayerKills() const
{
    const auto PlayerState = Cast<ASTUPlayerState>(GetOwningPlayerState());
    if (!PlayerState) return 0;
    return PlayerState->GetKillsNum();
}
