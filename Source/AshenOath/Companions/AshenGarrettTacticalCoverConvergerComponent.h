// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTacticalCoverConvergerComponent.generated.h"

/**
 * UAshenGarrettTacticalCoverConvergerComponent
 * Converges Garrett's cover points closer to Kaelen during high combat pressure.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalCoverConvergerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettTacticalCoverConvergerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FVector CalculateTargetCoverLocation(const FVector& KaelenLocation, const FVector& NominalCover, float GarrettTrust);
};
