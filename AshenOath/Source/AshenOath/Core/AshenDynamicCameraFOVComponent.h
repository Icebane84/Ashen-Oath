// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDynamicCameraFOVComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraFOVUpdatedSignature, float, CurrentFOV);

/**
 * UAshenDynamicCameraFOVComponent
 *
 * Dynamically interpolates camera Field of View (FOV 75 -> 95) during high-speed sprint dashes
 * and intense boss combat encounters using FInterpTo over delta time.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDynamicCameraFOVComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDynamicCameraFOVComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Camera")
	void SetTargetFOV(float TargetFOV, float InterpSpeed = 3.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float CurrentFOV = 75.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float TargetFOV = 75.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Camera")
	float DefaultFOV = 75.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Camera")
	float SprintFOV = 95.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Camera|Events")
	FOnCameraFOVUpdatedSignature OnFOVUpdated;

private:
	float CurrentInterpSpeed = 3.0f;
};
