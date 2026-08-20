// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_LockOnComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLockOnTargetChangedSignature, AActor*, NewTarget, bool, bIsLockedOn);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_LockOnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_LockOnComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Toggle lock-on state (find target if off, clear target if on) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|LockOn")
	void ToggleLockOn();

	/** Update owner controller's camera rotation to face target. Called in Character Tick. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|LockOn")
	void UpdateLockOnRotation(float DeltaTime);

	/** Set target explicitly */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|LockOn")
	void SetLockedTarget(AActor* Target);

	/** Clear lock-on status */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|LockOn")
	void ClearLockOn();

	/** Get current target */
	UFUNCTION(BlueprintPure, Category = "AshenOath|LockOn")
	AActor* GetLockedTarget() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|LockOn")
	bool IsLockedOn() const { return bIsLockedOn; }

public:
	/** Broadcast when the target changes or lock-on is toggled */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LockOn|Events")
	FOnLockOnTargetChangedSignature OnLockOnTargetChanged;

private:
	/** Scan the vicinity for targetable actors (using a sphere trace or overlap) */
	AActor* ScanForTargets();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess = "true"))
	float LockOnRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess = "true"))
	float RotationInterpolationSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess = "true"))
	bool bIsLockedOn;

	TWeakObjectPtr<AActor> LockedTarget;
};
