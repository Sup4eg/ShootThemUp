// Shoot Them Up Game, All Rights Reserved

#include "AI/Decorators/STUNeedAmmoDecorator.h"
#include "Weapon/STUBaseWeapon.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"

USTUNeedAmmoDecorator::USTUNeedAmmoDecorator()
{
    NodeName = "Need Ammo";
}

bool USTUNeedAmmoDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    if (!WeaponType) return false;
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;
    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;
    auto CurrentWeapon = WeaponComponent->GetCurrentWeapon();
    if (!CurrentWeapon) return false;
    return CurrentWeapon->IsA(WeaponType) && !CurrentWeapon->IsAmmoFull();
}
