// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettGrappleComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenGrappleState : uint8
{
	Ready,
	Firing,
	PullingTarget,
	PullingSelf,
	Interposing,
	Retracting,
	Cooldown
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrappleFired, FVector, TargetLocation, EAshenGrappleState, State);

/**
 * UAshenGarrettGrappleComponent
 * Tactical component firing 700uu wrist-mounted grapple hook for pulling foes/terrain and interposing.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettGrappleComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettGrappleComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnGrappleFired OnGrappleFired;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bIsGrappling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float MaxRange = 700.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float FireSpeed = 4000.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	EAshenGrappleState CurrentGrappleState = EAshenGrappleState::Ready;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool FireGrapple(FVector TargetLocation, bool bIsCompanionInterpose);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool LaunchGrapplingHook(FVector TargetLocation);
};
