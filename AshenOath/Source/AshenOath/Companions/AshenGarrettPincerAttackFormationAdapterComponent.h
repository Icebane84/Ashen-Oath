// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettPincerAttackFormationAdapterComponent.generated.h"

/**
 * UAshenGarrettPincerAttackFormationAdapterComponent
 * Positions Garrett to flank target from opposite side of Kaelen.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettPincerAttackFormationAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettPincerAttackFormationAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FVector CalculatePincerFlankLocation(const FVector& TargetLocation, const FVector& KaelenLocation);
};
