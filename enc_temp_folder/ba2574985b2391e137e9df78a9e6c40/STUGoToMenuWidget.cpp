// Shoot Them Up Game, All Rights Reserved


#include "UI/STUGoToMenuWidget.h"
#include "STUGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGoToMenuWidget, All, All)


void USTUGoToMenuWidget::NativeOnInitialized() {
    Super::NativeOnInitialized();
    if (MainMenuButton)
    {
        UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("-=------------------HERE HERE-----------------"));

        MainMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnMainMenu);
    }
    else
    {
        UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("-=------------------NOT MENU BUTTON-----------------"));

    }
}

void USTUGoToMenuWidget::OnMainMenu() {
  
        UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("-=------------------HERE-----------------"));

  
  if (!GetWorld()) return;
    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance) return;

    if (STUGameInstance->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("Menu level name is NONE"));
        return;
    }
    UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}
