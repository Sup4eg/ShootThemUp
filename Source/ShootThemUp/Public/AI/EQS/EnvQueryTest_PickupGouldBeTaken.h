// Shoot Them Up Game, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_PickupGouldBeTaken.generated.h"

UCLASS()
class SHOOTTHEMUP_API UEnvQueryTest_PickupGouldBeTaken : public UEnvQueryTest
{
    GENERATED_BODY()

public:
    UEnvQueryTest_PickupGouldBeTaken(const FObjectInitializer& ObjectInitializer);

protected:
    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
};
