// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryPalaceConstellationVFXAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationVFXRenderedSignature, FVector, OriginLocation, FVector, TargetLocation);

/**
 * AAshenMemoryPalaceConstellationVFXAnchorActor
 *
 * World Actor rendering constellation lines connecting memory nodes in 3D level space (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceConstellationVFXAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryPalaceConstellationVFXAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConstellationVFX")
	void RenderConstellationLine(FVector Origin, FVector Target);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConstellationVFX|Events")
	FOnConstellationVFXRenderedSignature OnConstellationVFXRendered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ConstellationVFX")
	bool bIsConstellationRendered = false;
};
