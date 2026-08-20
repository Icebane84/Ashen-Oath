// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettShieldWallFormationAdapterComponent.generated.h"

/**
 * UAshenGarrettShieldWallFormationAdapterComponent
 * Positions Garrett into a defensive shield wall in front of Kaelen.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettShieldWallFormationAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettShieldWallFormationAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FVector CalculateShieldWallOffset(const FVector& KaelenLocation, const FVector& KaelenForwardVector, float GarrettTrust);
};
