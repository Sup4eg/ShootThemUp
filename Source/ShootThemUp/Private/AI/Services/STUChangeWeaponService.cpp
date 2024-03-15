// Shoot Them Up Game, All Rights Reserved

#include "AI/Services/STUChangeWeaponService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/STUAIWeaponComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(ChangeWeaponServiceLog, All, All)

USTUChangeWeaponService::USTUChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void USTUChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (!Controller || !Blackboard) return;
    bool IsNextWeapon = FMath::RandRange(0.01f, 1.f) <= Probability;
    if (IsNextWeapon)
    {
        const auto AIWeaponComponent = STUUtils::GetSTUPlayerComponent<USTUAIWeaponComponent>(Controller->GetPawn());
        if (!AIWeaponComponent) return;
        AIWeaponComponent->NextWeapon();
    }
}
