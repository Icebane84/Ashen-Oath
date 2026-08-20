// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLockOnReticleComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLockOnTargetReticleUpdatedSignature, bool, bIsLockedOn, FVector2D, ScreenPosition, AActor*, TargetActor);

/**
 * UAshenLockOnReticleComponent
 *
 * Screen-space lock-on reticle component. Projects 3D locked-on target location to 2D UI screen space,
 * broadcasting coordinates for UMG reticle layout positioning.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLockOnReticleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenLockOnReticleComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|LockOn")
	bool bIsLockedOn = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|LockOn")
	FVector2D CurrentScreenPosition = FVector2D::ZeroVector;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LockOn|Events")
	FOnLockOnTargetReticleUpdatedSignature OnTargetReticleUpdated;
};
