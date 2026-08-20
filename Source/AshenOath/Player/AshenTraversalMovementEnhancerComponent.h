// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTraversalMovementEnhancerComponent.generated.h"

/**
 * UAshenTraversalMovementEnhancerComponent
 * Modulates player sprint acceleration, dash velocity curves, and slope climbing efficiency during stormy weather conditions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraversalMovementEnhancerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTraversalMovementEnhancerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Traversal")
	float BaseSprintSpeed = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Traversal")
	float CalculateAdjustedSprintSpeed(float WindResistanceFactor, bool bAetherDashActive) const;
};
